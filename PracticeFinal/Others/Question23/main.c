#include <stdio.h>
#include <stdlib.h>
#include "secret.h"
#include "crypto.h"
#define MAXCHAR 1000

int main(int argc, char* argv[]){

    // key variable. Here we assume that  key is always the argument at index 2
    int key = atoi(argv[2]);

    // line array
    char line[MAXCHAR];

    // file variable names. Here we assume that input files always exist
    FILE *inputFile, *outputFile;
    // here we assume that input file is always the argument at index 3
    inputFile = fopen(argv[3], "rt");
    // here we assume that output file is always the argument at index 4 and we open with append
    outputFile = fopen(argv[4], "a");

    // looping each line and reverse the words. 
    while (fgets(line, MAXCHAR, inputFile) != NULL){
        // create a pointer
        char *linePtr = line;
        // reverse the words
        reverseWordsOfLine(linePtr);
        // encode the words
        encode(linePtr, key);
        // write to output file
        writeToOutput(linePtr, outputFile);
    }

    // close the files
    fclose(inputFile);
    fclose(outputFile);

    // exit the program
    return 0;
}