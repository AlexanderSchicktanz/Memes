
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
int main(int argc, char **argv)
{
    /*
    Dieser Programmrahmen ist nur zur Hilfe gedacht, er kann gerne geändert werden.
    Die Fehlerbehandlung sollte jedoch in etwa so aussehen.
    */

    if (argc < 2)
    {
        printf("Too few arguments specified. Please provide a ppm file path.");
        return 1;
    }

    char *inputPPMPath = /* TODO: get from argv */
    FILE *ppmFile = fopen(inputPPMPath, "r");

    if (ppmFile == NULL)
    {
        perror("Opening file failed: ");
        return 2;
    }

    /*
    You can read data from a file using fscanf.
    https://cplusplus.com/reference/cstdio/fscanf/

    Hint: fscanf can ignore whitespace characters like '\n' or ' ' if you specify a whitespace character in the format string.
    e.g. fscanf(file, "%d %d", ...) will read two integers separated by ANY whitespace character. Leading whitespace is ignored.
    */

    // Example: Read P3 magic string
    char p3[3];
    fscanf(ppmFile, "%s", p3);
    if (p3[0] != 'P' || p3[1] != '3' || p3[2] != '\0')
    {
        printf("Invalid file format. Expected P3, got %s", p3);
        return 3;
    }

    int width = 0;
    int height = 0;
    // TODO: Read width and height from file
    // TODO: print width and height

    int valueRange;
    // TODO: Read value range from file. Optional: Make sure it is 255, abort and return 4 otherwise.


    /*
    TODO: Read pixel data
    */

    // Don't forget to close the file
    fclose(ppmFile);

    // ----------------------

    // Create and open output file
    FILE *outputFile = fopen("ascii_meme.txt", "w");

    /*
    You can write individual characters to a file using fputc: https://cplusplus.com/reference/cstdio/fputc/
    or an entire string with fputs: https://cplusplus.com/reference/cstdio/fputs/
    */

    /*
    TODO: Convert to ascii art and write to file
    */

    // Don't forget to close the file
    fclose(outputFile);

    printf("End of process.\n");
    return 0;
}