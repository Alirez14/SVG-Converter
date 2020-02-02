//
// Created by arezs on 01/02/2020.
//

#ifndef SVG_CONVERTER_IMAGE_H
#define SVG_CONVERTER_IMAGE_H

struct Line{
    int x0 ,x1,y0,y1;
    char* Color;

};
struct Pixel{

    char*ColorHash;
    char*Color;

    char*ColorPP;




};


char * Converter(char* ColorHash,char* Color){



}

int Width (char* in ){

    int Width=0;
    char * Beggin = "<svg";




        char *first = strstr(in, Beggin);

        if (first!=NULL){
            int count =0;
            char *p = in;
            while (*p) {
                if (isdigit(*p)) {
                    long val = strtol(p, &p, 10);
                        Width=(int)(val);
                    break;


                } else {
                    p++;
                }
            }
            return Width;

        } else{

            return -1;
        }





}
int Height (char* in ){

    int Height=0;
    char * Beggin = "<svg";




    char *first = strstr(in, Beggin);

    if (first!=NULL){
        int count =0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count==1){
                    Height=(int)(val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return Height;

    } else{

        return -1;
    }





}

int X0 (char* in ){

    int X0=0;
    char * Beggin = "<line";




    char *first = strstr(in, Beggin);

    if (first!=NULL){
        int count =0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count==1){
                    X0=(int)(val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else{

        return -1;
    }





}
int Y0 (char* in ){
    int X0=0;
    char * Beggin = "<line";




    char *first = strstr(in, Beggin);

    if (first!=NULL){
        int count =0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count==3){
                    X0=(int)(val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else{

        return -1;
    }





}
int X1 (char* in ){
    int X0=0;
    char * Beggin = "<line";




    char *first = strstr(in, Beggin);

    if (first!=NULL){
        int count =0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count==5){
                    X0=(int)(val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else{

        return -1;
    }




}
int Y1 (char* in ){
    int X0=0;
    char * Beggin = "<line";




    char *first = strstr(in, Beggin);

    if (first!=NULL){
        int count =0;
        char *p = in;
        while (*p) {
            if (isdigit(*p)) {
                long val = strtol(p, &p, 10);
                if (count==7){
                    X0=(int)(val);
                    break;
                }
                count++;

            } else {
                p++;
            }
        }
        return X0;

    } else{

        return -1;
    }





}
char* Stroke(char*in){
    char * Beggin = "stroke";




    char *first = strstr(in, Beggin);

    char* pch = strtok (first,"\"");
    pch = strtok (NULL, "\"");
    return pch;
}
int counter (FILE * fp){
    char ch;
    int lines=0;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }

    return lines;
}


#endif //SVG_CONVERTER_IMAGE_H
