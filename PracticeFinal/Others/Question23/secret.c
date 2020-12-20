#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// The algorithm used to get reversed string is very simple:
// Original string: "hello 206 students"
// We first reverse individual words of the string:
// Output: "olleh 602 stneduts"
// We then reverse the whole string
// Output: "students 206 hello"

// Function that reverse a string
void reverseString (char *start, char *end){
    // create temp char to store data
    char temp;
    while (start < end) {
        temp = *start;
        // start is now end. Increment start
        *start++ = *end;
        // end is now the original start. Decrement end
        *end-- = temp;
    }
}

// Function that reverse the words of a line (string)
void reverseWordsOfLine(char *line){
    // remove the trailing newline char
    line[strlen(line) - 1] = 0;

    //printf("Reversing line: %s", line);

    // declare start and end of word variables
    char *start_of_word = line;
    char *end_of_word = line;

    // iterate the string
    while(*end_of_word){
        // increment end_of_word ptr
        end_of_word++;
        // if the char is '\0' : end of string. Reverse the word
        if (*end_of_word == '\0'){
            reverseString(start_of_word, end_of_word - 1);
        }
        // if the char is ' ' : end of word. Reverse the word
        else if (*end_of_word == ' '){
            reverseString(start_of_word, end_of_word - 1);
            start_of_word = end_of_word + 1;
        }
    }

    // reverse the entire string
    reverseString(line, end_of_word - 1);

    //printf("Reversed Line: %s", line);
}

// Function that writes to output file
void writeToOutput(char *line, FILE *outputFile){
    if (outputFile == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(outputFile, "%s\n", line);
}
