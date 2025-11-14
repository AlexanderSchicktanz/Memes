
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

int main(int argc, char **argv){
    //Init
    char asciiMap[10] = "@%#ox;:,. ";
    if (argc < 2)
    {
        printf("Too few arguments specified. Please provide a ppm file path.");
        return 1;
    }
    char *inputPPMPath = argv[1];
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
    printf("%s\n",p3);
    int width = 0;
    int height = 0;
    int valueRange;
    if(fscanf(ppmFile, "%d %d %d",&width, &height, &valueRange)!=3) return 1;
    if(valueRange!=255) return 4;
    Color* colors = (Color*)malloc(sizeof(Color)*width*height);
    if(!colors) printf("Malloc-Fault");
    Color currentCol = {0};
    int i = 0;
    while(fscanf(ppmFile,"%d %d %d",&currentCol.r, &currentCol.g, &currentCol.b)==3){
      if(i>=width*height) break;
      colors[i]=currentCol;
      i++;
    }
    printf("i: %d\nw: %d\nh: %d\n",i,width,height);
    if(i<width*height) return 5;
    fclose(ppmFile);


    FILE *outputFile = fopen("ascii_meme.txt", "w");
    if((int)(outputFile)==0) return (int)(-1);
    for(int j = 0; j < i; j++){ 
      fprintf(outputFile,"%c",asciiMap[(colors[j].r+colors[j].g+colors[j].b)/77]);
      if((j+1)%width==0) fprintf(outputFile,"\n");
    } 
    fclose(outputFile);
    printf("End of process.\n");
    return 0;
}
