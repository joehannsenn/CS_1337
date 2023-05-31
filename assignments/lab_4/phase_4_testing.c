# include <stdio.h> 

void func4(int* x, int* y, int* z);

int main(int argc, char *argv[])
{
    int x, y, z;
    int iterations = 20;
    for(int j=0; j <= 4; j++){
        for(int i = 0; i < iterations; i++)
        {
            x = 7;
            y = j;
            z = 0;
            func4(&x, &y, &z);
            printf("\nIteration #%d\nx= %d.\ny=%d.\nz=%d\n", i, x, y, z);
            if(z == 15){ break;}
        }
    }
    

    return 0;
}

void func4(int* x, int* y, int* z)
{
    *z = 0;
    //base case
    if(*x==0 || *y==1)
    {   //if value x = 0 or y = 1, return.
        return;
    }
    *z = *y;

    int a, b, c;

    a = *y;
    b = *x;
    *x -= 1;
    //printf("\n%d", *x);
    func4(x, y, z);
    c = *z + a;
    *x = b - 2;
    *y = a;
    func4(x, y, z);
    *z += c;

    return;
}