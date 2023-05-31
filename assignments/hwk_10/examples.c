#include <stdio.h>
#include <stdlib.h>

long le_cnt = 0;
long gt_cnt = 0;

long absdiff(long x, long y)
{
	long result;
	
	if(x>y){
		gt_cnt++;
		result = x - y;
	}
	else {
		le_cnt++;
		result = y - x;
	}
	return result;
}

int main(int argc, char *argv[]) {

	if (argc < 3){
		printf("Insufficient arguments. Expected 2 integer inputs.\n");
		return -1;
	}

	// define vars from commandline args
	long x = strtol(argv[1], NULL, 10);
	long y = strtol(argv[2], NULL, 10);

	return absdiff(x, y);
}
