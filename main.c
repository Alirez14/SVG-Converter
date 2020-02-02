#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include "Image.h"

int main(int argc, char **argv) {
    ////////////////GLOBALS
    int width = -1, height = -1;
    double scaling_factor_x=1;
    double scaling_factor_y=1;

    FILE *fp;
    int Count;
    size_t bufsize = 32;
    int c;

    char *name = "test", *sizec=NULL, *Color = "255 255 255";
    opterr = 0;


    ///////////////////////////////OPTIONS
    while ((c = getopt(argc, argv, ":s:b:")) != -1) {
        switch (c) {

            case 's':
                sizec = optarg;
                break;

            case 'b':
                Color = Converter(optarg);
                break;
            case '?':

                fprintf(stderr, "Unknown option character \n");
                return 1;
            default:
                abort();


        }
    }
    char *token;
    if (sizec!=NULL) {
        token = strtok(sizec, "x");
        width = atoi(token);
        token = strtok(NULL, "x");
        height = atoi(token);
    }
    char *filename = argv[argc - 2];
    char *FileOut = argv[argc - 1];

    fp = fopen(filename, "r");

    ///////////////////OPENFILE GET LINES


    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }
    Count = counter(fp) + 1;
    char *Lines[Count];
    for (int k = 0; k < Count; ++k) {
        Lines[k] = NULL;
    }

//////////////////////////////////////OPEN AGAIN SAVE LINES IN ARRAY

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }
    Lines[0] = NULL;
    int i = 0;
    while ((getline(&Lines[i], &bufsize, fp)) != -1) {

        Lines[i + 1] = NULL;
        i++;
    }
    fclose(fp);


    struct Line Inputs[Count - 2];

    /////////////////////////////////REAlCODE////////////////////////
    /////////////////////////////////////////////////////////////////


    //////////////////////////////INPUT FILLING///////////////

    //////////////////////////////BOARD ////////////////////////

    int svgwidth, svgheight;
    svgwidth = Width(Lines[0]);
    svgheight = Height(Lines[0]);

    if (width == -1 || height == -1) {
        width = svgwidth;
        height =svgheight;

        if (width == -1 || height == -1) {
            for (int l = 0; l < Count; ++l) {
                free(Lines[l]);
            }
            exit(EXIT_FAILURE);
        }
    } else {
         scaling_factor_x = ((double) width / svgwidth);
         scaling_factor_y = ((double)height / svgheight);

    }


    struct Pixel Pixels [width][height];



    ///////////////////////////////////////////////////////////////

    for (int j = 1; j < Count - 1; ++j) {


        Inputs[j - 1].x0 =(int) (X0(Lines[j])*scaling_factor_x);
        Inputs[j - 1].x1 = (int)(X1(Lines[j])*scaling_factor_x);
        Inputs[j - 1].y0 = (int)(Y0(Lines[j])*scaling_factor_y);
        Inputs[j - 1].y1 = (int)(Y1(Lines[j])*scaling_factor_y);
        Inputs[j - 1].Color = Converter(Stroke(Lines[j]));
        if (Inputs[j - 1].Color == NULL) {
            for (int l = 0; l < Count; ++l) {
                free(Lines[l]);
            }

            exit(EXIT_FAILURE);
        }
    }
///////////////////////////////////CRATE BOARD PIXELS

    for (int m = 0; m < width; ++m) {
        for (int j = 0; j < height; ++j) {
            Pixels[m][j].Color=Color;
        }
    }

    for ( int n = 0; n < Count - 2; ++n) {
      int x0=Inputs[n].x0,  y0=Inputs[n].y0,  x1=Inputs[n].x1,  y1=Inputs[n].y1;

            int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
            int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
            int err = dx+dy, e2; /* error value e_xy */

            while (1) {
                Pixels[y0][x0].Color=Inputs[n].Color;
                if (x0==x1 && y0==y1) break;
                e2 = 2*err;
                if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
                if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
            }
        printf("next lien ");
        }






    ///////////////////////DRAW ON File

Draw(width, height, FileOut, Pixels);




    for (int l = 0; l < Count; ++l) {
        free(Lines[l]);
    }


    exit(EXIT_SUCCESS);
}