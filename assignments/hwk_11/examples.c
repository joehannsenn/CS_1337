#include <stdio.h>
#include <stdlib.h>

long lt_cnt = 0;
long ge_cnt = 0;

long absdiff(long x, long y)
{
	long result;

	if(x < y){
		lt_cnt++;
		result = y - x;
	}
	else {
		ge_cnt++;
		result = x - y;
	}
	return result;
}

long absdiff_succinct(long x, long y)
{
	return x < y ? y-x : x-y;
}

long factorial_do_while(long n) {
	long result = 1;
	do {
		result *= n;
		n = n-1;
	} while (n > 1);
	return result;
}

long factorial_while(long n) {
	long result = 1;
	while (n > 1) {
		result *= n;
		n = n-1; }
	return result;
}

long factorial_for(long n)
{
	long i;
	long result = 1;
	for (i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

void switch_example (long x, long n, long *dest) {
	long val = x;

	switch (n) {

		case 100:
			val *= 13;
			break;
		case 102:
			val += 10;
			/* Fall through */
		case 103:
			val += 11;
			break;
		case 104:
		case 106:
			val *= val;
			break;
		default:
			val = 0;
	}
	*dest = val;
}

int main(int argc, char *argv[]) {

	if (argc < 4){
		printf("Insufficient arguments. Expected 3 integer inputs.\n");
		return -1;
	}

	// define vars from commandline args
	long x = strtol(argv[1], NULL, 10);
	long y = strtol(argv[2], NULL, 10);
	long n = strtol(argv[3], NULL, 10);

	printf("%li\n",absdiff(x, y));
	printf("%li\n",absdiff_succinct(x, y));

	printf("%li\n",factorial_do_while(x));
	printf("%li\n",factorial_while(x));
	printf("%li\n",factorial_for(x));

	long result;
	switch_example(x, n, &result);
	printf("%li\n",result);
}
