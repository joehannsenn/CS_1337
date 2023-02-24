#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>


//Define Constants
#define MAX_CHARS 8
#define BASE 16
#define MAX_ARRAY_SIZE 100


//Function Definitions
void clearBuffer();
char promptOperator();
bool validOperator(char c);
int promptOperandCount();
unsigned int * promptOperands(unsigned int n);
unsigned int getUInt();
void compute(unsigned int * operands, int size, char operator);
void toBinaryString(unsigned int val);


//normally wouldn't use global variables, but I am having troubles using memory allocation, and I don't have time to do it right.
unsigned int debug_operands[ MAX_ARRAY_SIZE ];
//char bin_str[36];



void main(){
	while(true){
		char operator = promptOperator();

		int n = promptOperandCount();
		//instantiate operands array
		unsigned int *operands = calloc( n, sizeof(unsigned int));
		free(operands);
		//fill operands array with operands
		operands = promptOperands(n);
	
		compute(operands, n, operator);

		clearBuffer();
		
	}
	return;
}


void clearBuffer(){	
	/* Empties the stdin buffer.
	 */
	int c;
	while( ( c  = getchar()) != '\n' &&  c != EOF);
}


char promptOperator(){
	/* Prompts the user for an operation that will be performed later.
	* Operation stored as a char, validated by validOperator()
	*/
	bool valid_input = false;
	char operation;
	while(!valid_input){
		printf("\nEnter operation: ");	
		
		operation = getchar();

		if(validOperator(operation)){ valid_input = true; }
		else{ 
			printf("Please enter |, &, ^, or q");
			clearBuffer();
		}	
	}
	return operation;
}
bool validOperator(char c){
	/* Used by promptOperator().
	* determines if a given character is a valid input.
	* Valid Inputs: & | ^ q
	*/
	if( c == 'q'){ exit(1); }
	return (c == '|' || c == '&' || c == '^');
}


int promptOperandCount(){ //how will I cope with unexpected input?
	/* Prompts the user for a positive number n.
	 * n used to delcare the size of the array.
	*/
	int operand_count;
	while(true){
		printf("Enter number of integers: ");
		
		bool gotInteger =  scanf("%d", &operand_count);
		
		if( gotInteger && operand_count > 0 ){ break;}	
		else{ 
			printf("Please enter an integer greater than 1\n");
			clearBuffer(); 
		}
	}
	return operand_count;
}


unsigned int * promptOperands(unsigned int n ){
	/* Creates and fills array of size n with ints from getUInt()
	*/
	//unsigned int *a = (unsigned int *) calloc(n, sizeof(unsigned int)); //No idea why this works:

	for(int i=0; i < n; i++){ debug_operands[i] = getUInt(i); }

	return debug_operands;
}
unsigned int getUInt(int int_num){
	bool gotInput;
	char input[MAX_CHARS+1];		
	unsigned int to_return;
	long int raw_value;

	//GET STRING FROM USER
	while(true){
		//set default values
		clearBuffer();
		gotInput = false;

		//Prompt user input
		printf("Enter integer %i: ", int_num+1);

		//Get Raw user input
		gotInput= scanf("%s", input);
		
		//Try to convert to Int
		char * endptr;
		raw_value = strtol(input, &endptr, BASE); 
		//input validation
		if( !gotInput || raw_value < 0 || raw_value > UINT_MAX  ||  endptr == input || *endptr != '\0' ){
			printf("Please enter an %i-digit hexadecimal integer\n", MAX_CHARS);
			continue;
		}

		to_return = (unsigned int) raw_value;
		printf("You entered: %X\n", to_return);
		return to_return;
	}	
}


void compute(unsigned int *operands, int size, char operator){
	/*  Calculates bitwise operation (and/or/xor)
	 *  Prints out formatted calculations.
	*/
	unsigned int answer= operands[0];

	switch(operator){

		case '|': //BITWISE OR
			for(int i=1; i<size; i++){ answer |= operands[i]; }
			break;

		case '&': //BITWISE AND
			for(int i=1; i<size; i++){ answer &= operands[i]; }
			break;

		case '^': //BITWISE XOR
			for(int i=1; i<size; i++){ answer ^= operands[i]; }
			break;
	}

	//HEXADECIMAL PRINT STATEMENTS
	printf("\nHexadecimal operation:");
	for(int i = 0; i < size; i++){
		printf("\n\t%c %X", operator, operands[i] );
	}
	printf("\n\t= %X", answer);

	//BINARY PRINT STATEMENTS
	printf("\nBinary Operation:");
	for(int i = 0; i < size; i++){
		printf("\n\t%c ", operator);
		toBinaryString(operands[i]);
	}
	printf("\n\t= ");
	toBinaryString(answer);
}

void toBinaryString(unsigned int val){
	/* Turns a int into a binary string. and prints it out. 
	*  originally wanted this to return a string to print out. but segmentation faults. C sucks.
	*/

	int size = 37; //32-bit int dividided into 4 8-bit segments ... 32 binary + 4 spaces + 1 null terminator
	//char * bin_str[size];

	unsigned int bitmask = 1 << 31;
	for(int i = 0; bitmask != 0; bitmask = bitmask >> 1){
		if(val & bitmask){ printf("1"); }
		else{ printf("0"); }
		i++;

		if(i%8 == 0){
			printf(" ");
		}
	}

	//printf(bin_str);
	//return bin_str;
}