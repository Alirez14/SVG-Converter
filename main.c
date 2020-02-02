#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Image.h"

int main() {

    ////////////////GLOBALS
    int width,height;

    FILE *fp;
    int Count;
    size_t bufsize = 32;
    char* filename = "Hi.svg";

    fp = fopen(filename, "r");

    ///////////////////OPENFILE GET LINES


    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    Count=counter(fp)+1;
    char* Lines[Count];
    for (int k = 0; k < Count; ++k) {
        Lines[k]="";
    }

//////////////////////////////////////OPEN AGAIN SAVE LINES IN ARRAY

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    Lines[0] = NULL;
    int i=0;
    while ((getline(&Lines[i], &bufsize, fp)) != -1) {
        printf("%s", Lines[i]);
        Lines[i + 1] = NULL;
        i++;
    }
    fclose(fp);




    /////////////////////////////////REAlCODE////////////////////////

int x0=X0(Lines[1]);
int x1=X1(Lines[1]);
int y0=Y0(Lines[1]);
int y1=Y1(Lines[1]);


    for (int l = 0; l < Count; ++l) {
        free(Lines[l]);
    }


    exit(EXIT_SUCCESS);
}