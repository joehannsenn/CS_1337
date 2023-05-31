#include <stdio.h>
#include <inttypes.h>

typedef unsigned __int128 uint128_t;

// When compiled, the assembly uses lea to perform arithmetic
// x = 2, y = 4, z = 1
long scale(long x, long y, long z) {
	long t = 3 * x + y + 10 * z;
	return t;
}

// The assembly for this function demos shift instructions
// assembly will include two "get" instructions
// x = 2, n = 1
long shift_left4_rightn(unsigned long x, unsigned long n)
{
	x >>= n;
	x <<= 4;
	return x;
}

/*
 *The expression z*48 is computed by a combination of leaq and shift instructions.
 */
// x = 2, y = 4, z = 1
long arith(long x, long y, long z)
{
	long t1 = x | y;
	long t2 = z * 32;
	long t3 = t1 & 0x0F;
	long t4 = t2 + t3;
	return t4;
}

/*
 * The assembly first copies x to multiplicand
 * Then multiplies by y
 * Then stores the lower 8 bytes at the dest
 * Then the upper 8 bytes at dest+8
 */
// x = 9, y = 5
void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
	*dest = x * (uint128_t) y;
}

/*
 * The assembly first copies qp
 * Moves x to lower 8 bytes of dividend
 * sign-extends to upper 8 bytes of dividend
 * performs the division
 * stores the quotient at qp
 * stores the remainder at rp
 */
// x = 9, y = 5
void remdiv(long x, long y,
            long *qp, long *rp) {
    long q = x/y;
    long r = x%y;
    *qp = q;
    *rp = r;
}

int main(){
	long x = 2;
	long y = 4;
	long z = 1;
	long t = scale(x,y,z);

	printf("%li\n", t);

	long res = shift_left4_rightn((unsigned long) x, (unsigned long) z);

	printf("%li\n", res);

	res = arith(x,y,z);

	printf("%li\n", res);

	uint128_t dest = 0; // We just need this as a place to put the result
	uint64_t x1 = 9;
	uint64_t y1 = 5;

	store_uprod(&dest, x1, y1);

	printf("%llx\n", (unsigned long long) dest);

	long q = 0;
	long r = 0;

	y = 9;
	x = 5;

	remdiv(y, x, &q, &r);

	printf("%li,%li",q,r);

}
