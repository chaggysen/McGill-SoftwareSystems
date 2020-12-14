/*
 Program to implement a scientific calculator
 ***************************************************************
 * Author         Dept.             Date          Notes
 ***************************************************************
 * Joseph D       Comp. Science. Oct 10 2020    Initial version.
 * Joseph D       Comp. Science. Oct 11 2020    Added error handling.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	const char* usage = "scalc <operand1> <operator> <operand2>";
	const char* operanderr = "Error!! operand can only be positive integers";
	char digit = '\0';
	int operand1len = 0, operand2len = 0;
	char *operand1 = NULL, *operand2 = NULL;
	const int MAXRESULT = 1001;
	char result[MAXRESULT];
	int resultindex = MAXRESULT;
	int carry = 0;

	// Check for sufficient number of arguments.
	if(argc != 4)
	{
		printf("Error: invalid number of arguments!\n");
		printf("%s\n", usage);
		return 1;
	}

	// Check if the operator is a valid one.
	if( !(argv[2][0] == '+' && argv[2][1] == '\0') ) 
	{
		printf("Error: operator can only be + !\n");
		return 1;
	}

	// Traverse the first operand, check if it is valid, find the number of digits.
	operand1 = argv[1];
	while((digit = operand1[operand1len]) != '\0')
	{
		if( ! (digit >= '0' && digit <= '9') )
		{
			printf("%s\n", operanderr);
			return 1;
		}
		operand1len++;
	}
	if(operand1len == 0) // make sure that we did not get an empty operand.
	{
		printf("%s\n", operanderr);
		return 1;
	}

	// Traverse the second operand, check if it is valid, find the number of digits.
	operand2 = argv[3];
	while((digit = operand2[operand2len]) != '\0')
	{
		if( ! (digit >= '0' && digit <= '9') )
		{
			printf("%s\n", operanderr);
			return 1;
		}
		operand2len++;
	}
	if(operand2len == 0) // make sure that we did not get an empty operand.
	{
		printf("%s\n", operanderr);
		return 1;
	}

	result[--resultindex] = '\0'; // put a null at the end of the result string array.
	while (operand1len > 0 && operand2len > 0) //start with the least significant digits of the operands and add
	{
		int digit1, digit2, sum;
		digit1 = operand1[--operand1len] - '0'; // convert each digit's character to actual integers using ASCII
		digit2 = operand2[--operand2len] - '0';
		sum = digit1 + digit2 + carry;	// add two digits along with any from previous addition.
		result[--resultindex] = sum%10 + '0'; // store the ascii character corresponding to the last digit of sum in the result.
		carry = sum/10;	// store any carry for the next step.
	}

	while(operand1len >0) // There are more digits to process from operand1 (Eg 100 + 1)
	{
		int digit1, sum;
		digit1 = operand1[--operand1len] - '0';
		sum = digit1 + carry;
		result[--resultindex] = sum%10 + '0';
		carry = sum/10;
	}

	while(operand2len >0) // OR maybe there are more digits to process from operand2.
	{
		int digit2, sum;
		digit2 = operand2[--operand2len] - '0';
		sum = digit2 + carry;
		result[--resultindex] = sum%10 + '0';
		carry = sum/10;
	}

	if (carry != 0) // The last carry, if any, will have to be incorporated into the result (Eg 9 + 9)
		result[--resultindex] = carry + '0';

	// alternative would be to use putchar and loop through the result array.
	printf("%s\n", result+resultindex); // print the final result.
	return 0;
}
