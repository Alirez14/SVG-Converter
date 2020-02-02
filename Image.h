//
// Created by arezs on 01/02/2020.
//

#ifndef SVG_CONVERTER_IMAGE_H
#define SVG_CONVERTER_IMAGE_H

struct Line {
    int x0, x1, y0, y1;
    char *Color;

};
struct Pixel {

    char *Color;



};

void Draw(int width, int height, char *name, struct Pixel Pixels[width][height]) {

    FILE *fptr;
    fptr = fptr = fopen(name, "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, "%s\n", "P3");
    fprintf(fptr, "%d %d\n", width, height);
    fprintf(fptr, "%d\n", 255);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            fprintf(fptr, "%s  ",Pixels[i][j].Color );
        }
        fprintf(fptr, "\n");
    }


    fclose(fptr);

}

char *Converter(char *Color) {

    char *Beggin = "#";


    char *first = strstr(Color, Beggin);

    if (strcmp(Color, "black") == 0) {
        return "0 0 0";


    } else if (strcmp(Color, "red") == 0) {

        return "255 0 0";
    } else if (strcmp(Color, "green") == 0) {
        return "0 255 0";

    } else if (strcmp(Color, "blue") == 0) {
        return "0 0 255";


    } else if (strcmp(Color, "cyan") == 0) {
        return "0 255 255";


    } else if (strcmp(Color, "yellow") == 0) {
        return "255 255 0";


    } else if (first != NULL) {

        char *str = strtok(first, "#");
        int r, g, b;
        sscanf(str, "%02x%02x%02x", &r, &g, &b);
        char *stro[11];
        sprintf((char *) stro, "%d %d %d", r, g, b);
        char *Ret = (char *) stro;
        return Ret;


    } else {
        return NULL;


    }


}

int Width(char *in) {

    int Width = 0;
    char *Beggin = "<svg";


    char *first = strstr(in, Beggin);

    if (first != NULL) {
        int count = 0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                Width = (int) (val);
                break;


            } else {
                p++;
            }
        }
        return Width;

    } else {

        return -1;
    }


}

int Height(char *in) {

    int Height = 0;
    char *Beggin = "<svg";


    char *first = strstr(in, Beggin);

    if (first != NULL) {
        int count = 0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count == 1) {
                    Height = (int) (val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return Height;

    } else {

        return -1;
    }


}

int X0(char *in) {

    int X0 = 0;
    char *Beggin = "<line";


    char *first = strstr(in, Beggin);

    if (first != NULL) {
        int count = 0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count == 1) {
                    X0 = (int) (val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else {

        return -1;
    }


}

int Y0(char *in) {
    int X0 = 0;
    char *Beggin = "<line";


    char *first = strstr(in, Beggin);

    if (first != NULL) {
        int count = 0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count == 3) {
                    X0 = (int) (val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else {

        return -1;
    }


}

int X1(char *in) {
    int X0 = 0;
    char *Beggin = "<line";


    char *first = strstr(in, Beggin);

    if (first != NULL) {
        int count = 0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count == 5) {
                    X0 = (int) (val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else {

        return -1;
    }


}

int Y1(char *in) {
    int X0 = 0;
    char *Beggin = "<line";


    char *first = strstr(in, Beggin);

    if (first != NULL) {
        int count = 0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count == 7) {
                    X0 = (int) (val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else {

        return -1;
    }


}

char *Stroke(char *in) {
    char *Beggin = "stroke";


    char *first = strstr(in, Beggin);

    char *pch = strtok(first, "\"");
    pch = strtok(NULL, "\"");
    return pch;
}

int counter(FILE *fp) {
    char ch;
    int lines = 0;
    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == '\n') {
            lines++;
        }
        else if(ch=='<'){
            ch=fgetc(fp);
            if (ch=='/'){
                break;
            }
        }
    }

    return lines;
}


#endif //SVG_CONVERTER_IMAGE_H
