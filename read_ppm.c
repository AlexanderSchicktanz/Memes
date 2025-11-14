#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct{
  int r;
  int g;
  int b;
} Color;

int main(void)
{   
    /*
    Dieser Programmrahmen ist nur zur Hilfe gedacht, er kann gerne geändert werden.
    */

    char inputPPMPath[] = "beispiel_tricky.ppm";
    FILE *ppmFile = fopen(inputPPMPath, "r");

    if (ppmFile == NULL)
    {
        perror("Opening file failed: ");
        return 2;
    }

    char p3[3];
    fscanf(ppmFile, "%s", p3);
    if (p3[0] != 'P' || p3[1] != '3' || p3[2] != '\0')
    {
        printf("Invalid file format. Expected P3, got %s", p3);
        return 3;
    }

    int width = 0;
    int height = 0;
    int valueRange;
    if(fscanf(ppmFile, "%d %d %d",&width, &height, &valueRange)!=3) return 1;
    if(valueRange!=255) return 4;
    Color* colors = (Color*)malloc(sizeof(Color)*width*height);
    Color currentCol = {0};
    int i = 0;
    printf("Test1\n");
    while(fscanf(ppmFile,"%d %d %d",&currentCol.r, &currentCol.g, &currentCol.b)==3){
      colors[i]=currentCol;
      i++;
    }
    if(i<width*height) return 5;
    printf("i: %d\nW*H: %d",i,(width*height));
    fclose(ppmFile);

    for(int j = 0; j < i; j++){
      if(j%width==0) printf("\n");
      printf("(%d, %d, %d) ",colors[j].r,colors[j].g,colors[j].b);
      
    } 

    return 0;
}
