#include <stdio.h>

int main( int argc, char *argv[] )  {
    int begin, middle, end, length = 0;
    for (; argv[1][length] != '\0'; length++);

    end = length - 1;
    middle = length/2;

    for (begin = 0; begin < middle; begin++){
        if (tolower(argv[1][begin]) != tolower(argv[1][end])){
            printf("Not a palindrome.\n");
            break;
        }
        end --;
    }

    if (begin == middle)
    printf("Palindrome.\n");

    return 0;
}