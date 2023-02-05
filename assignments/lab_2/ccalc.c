#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

void clearBuffer();
char promptOperator();
bool validOperator(char c);
int promptOperandCount();
bool validOperandCount(int operand_count);
int * promptOperands(int n);
void compute(int * operands, int size, char operator);



void main(){
	

	while(true){
		char operator = promptOperator();
		if(operator == 'q'){ break;} 
	
		int n = promptOperandCount();
		
		//instantiate operands array
		int *operands =(int *) malloc( n * sizeof(int));
		//fill operands array with operands
		operands = promptOperands(n);
	
		compute(operands, n, operator);

		clearBuffer();
	}

	return;
}

void clearBuffer(){	
	int c;
	while( (c  = getchar()) != '\n' &&  c != EOF);
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
		else{ printf("Please enter a valid operation."); }	
	}
	return operation;
}


bool validOperator(char c){
	/* Used by promptOperator().
	 * determines if a given character is a valid input.
	 * Valid Inputs: + - * / q
	 */

	if( c == 'q'){ return true;}

	if( c == '+' || c == '-' || c == '/' || c == '*'){ return true; }
	else{ return false;}
}


int promptOperandCount(){ //how will I cope with unexpected input?
	/* Prompts the user for a positive number n.
	 * n used to delcare the size of the array.
	 */

	bool valid_input = false;
	int operand_count;
	while(!valid_input){
		printf("Enter number of integers: ");
		
		bool gotInteger =  scanf("%d", &operand_count);
		
		if( gotInteger && validOperandCount(operand_count) ){ valid_input = true;}	
		else{ clearBuffer(); }

	}
	return operand_count;
}

bool validOperandCount(int operand_count){
	/* Validates the user's operand count.
	 * Must be > 0.
	 * Also alerts the user to the improper input.
	 */
	
	if(operand_count > 0){ return  true;}
	else{ 
		printf("Please enter an integer greater than 1.\n");
		return false;
	}
}


int * promptOperands( int n ){
	/* Prompts user for integers, and fills array of size n.
	 */

	int *a = (int *) malloc(n * sizeof(int));

	for(int i=0; i < n; i++){
		bool valid_input = false;
		int temp;

		
		while(!valid_input){
			printf("Enter integer %i: ", i+1);

			bool gotInteger = scanf("%i", &temp); //returns true if an integer is successfully read.
			
			if(gotInteger){ valid_input = true;}
			else{ clearBuffer(); } 
		}

		a[i] = temp;
	}

	return a;
}

//an operandValidator() function is unneccesary. 
//scanf() will return a 0 (false) if no input were successfully read.


void compute(int *operands, int size, char operator){
	/*  Calculates answers, and shows math.
	 *  Uses a switch to choose which operation to do.
	 */

	int answer= operands[0];
	bool divByZeroDetected = false;

	switch(operator){

		case '+':
			for(int i=1; i < size; i++){
			answer += operands[i];	
			}
			break;

		case '-':
			for(int i=1; i < size; i++){
			answer -= operands[i];	
			}
			break;

		case '*':
			for(int i=1; i < size; i++){
			answer *= operands[i];	
			}
			break;

		case '/': 
			for(int i=1; i < size; i++){
				//check for division by zero
				if(operands[i] == 0){ divByZeroDetected = true; }
				else{ answer /= operands[i];} // avoids div by 0.
				// ^ is this allowed?
			}
			break;
	}

	
	printf("\nComputing: %i ", operands[0]);
	for(int i=1; i < size; i++){
		printf( "%c %i ", operator, operands[i]);	
	}
	printf("= %i\n", answer);

	if(divByZeroDetected){ printf("Cannot divide by zero. Zeroes skipped in calculation.\n");}
}
