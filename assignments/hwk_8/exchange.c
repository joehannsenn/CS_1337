#include <stdio.h>

long exchange(long *xp, long y)
{
    long x = *xp;
    *xp = y;
    return x;
}

int main(){
	long x = 32;
	exchange(&x, 16);
	printf("x = %li\n", x);
}
