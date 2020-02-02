#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Image.h"

int main() {

    ////////////////GLOBALS
    int width, height;

    FILE *fp;
    int Count;
    size_t bufsize = 32;
    char *filename = "Hi.svg";

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
        printf("%s", Lines[i]);
        Lines[i + 1] = NULL;
        i++;
    }
    fclose(fp);


    struct Line Inputs[Count - 2];

    /////////////////////////////////REAlCODE////////////////////////
    /////////////////////////////////////////////////////////////////


    //////////////////////////////INPUT FILLING///////////////

    for (int j = 1; j < Count - 1; ++j) {


        Inputs[j - 1].x0 = X0(Lines[j]);
        Inputs[j - 1].x1 = X1(Lines[j]);
        Inputs[j - 1].y0 = Y0(Lines[j]);
        Inputs[j - 1].y1 = Y1(Lines[j]);
        Inputs[j - 1].Color = Converter(Stroke(Lines[j]));
        if (Inputs[j - 1].Color == NULL) {
            for (int l = 0; l < Count; ++l) {
                free(Lines[l]);
            }

            exit(EXIT_FAILURE);
        }
    }
////////////////////////////////////////////////////////



    for (int l = 0; l < Count; ++l) {
        free(Lines[l]);
    }


    exit(EXIT_SUCCESS);
}