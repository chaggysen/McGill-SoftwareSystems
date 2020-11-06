/*
Program to implement a scientific calculator
***************************************************************
* Author Dept . Date Notes
***************************************************************
* Sen W. Engineering. Nov 4 2020 Initial Version.
*/
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

// methods declarations
bool isWholeNumber (char * s);
long double myAtoi(char* str);
long double calculateAddition(long double number1,long double number2);
void findSum(char *nb1, char *nb2);
void reverse(char *x, int begin, int end);
void reverse_array(char a[], int n);

// main
int main( int argc, char *argv[]) {
	// error handlings
	// check valid nb of arguments
	if (argc != 4){
		printf("Error: invalid number of arguments!\n");
		printf("scalc <operand1> <operator> <operand2>\n");
		return 1;
	}
	// check if operator is +
	if (*argv[2] != '+'){
		printf("Error: operator can only be + !\n");
		return 1;
	}
	//check if operand1/operand2 are integers and positive
	if (*argv[1] < 0 || *argv[3] < 0){
		printf("Error!! operand can only be positive integers\n");
		return 1;
	}
	if (!isWholeNumber(argv[1]) || !isWholeNumber(argv[3])){
		printf("Error!! operand can only be positive integers\n");
		return 1;
	}

	// find sum
	findSum(argv[1], argv[3]);
	return 0;
}

void findSum(char *nb1, char *nb2){
	// find lenght of each value
	int nb1_length = 0;
	for (; nb1[nb1_length] != '\0'; nb1_length++);
	int nb2_length = 0;
        for (; nb2[nb2_length] != '\0'; nb2_length++);
	// make sure length string 2 is larger
	if (nb1_length > nb2_length){
		char *temp = nb1;
		nb1 = nb2;
		nb2 = temp;
	}
	nb1_length = 0;
	nb2_length = 0;
	char result[1000];
	int resultIndex = 0;
	for (; nb1[nb1_length] != '\0'; nb1_length++);
	for (; nb2[nb2_length] != '\0'; nb2_length++);

	// reverse both numbers
	reverse(nb1, 0, nb1_length - 1);
	reverse(nb2, 0, nb2_length - 1);

	int carry = 0;
	for (int i = 0; i < nb1_length; i++){
		int sum = ((int) (nb1[i] - '0') + (int) (nb2[i] - '0') + carry);
		result[resultIndex] = (char) (sum % 10 + '0');
		carry = sum / 10;
		resultIndex ++;
	}
	for (int i = nb1_length; i < nb2_length; i++){
		int sum = ((int) (nb2[i] - '0') + carry);
		result[resultIndex] = (char) (sum % 10 + '0');
		carry = sum / 10;
                resultIndex ++;
	}
	if (carry > 0){
		result[resultIndex] = (char) (carry + '0');
	}
	int result_counter = resultIndex;
	for (; result_counter >= 0; result_counter--){
		if (result[result_counter] < 48 || result[result_counter] > 57){
			continue;
                }else{
			printf("%c", result[result_counter]);
		}
	}
	printf("\n");

}

// reverse a string
void reverse(char *x, int begin, int end)
{
   char c;

   if (begin >= end)
      return;

   c          = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end)   = c;

   reverse(x, ++begin, --end);
}

void reverse_array(char a[], int n)
{
  int c, t;

  for (c = 0; c < n/2; c++) {
    t = a[c];                  // Swapping
    a[c] = a[n-c-1];
    a[n-c-1] = t;
  }
}


long double calculateAddition(long double number1, long double number2){
	long double result = (long double) number1 + (long double) number2;
	return result;
}

bool isWholeNumber (char * s) {
	char * t; // first copy the pointer to not change the original

	for (t = s; *t != '\0'; t++) {
	// compare to ascii values of 0-9 for each char
		if (*t < 48 || *t > 57){
			return false;
		}
	}

	return true;
}

long double myAtoi(char* str){
	long double result = 0;
	for (int i = 0; str[i] != '\0'; ++i){
		result = result * (long double)10 + (long double)str[i] - (long double)'0';
	}
	return result;
}
