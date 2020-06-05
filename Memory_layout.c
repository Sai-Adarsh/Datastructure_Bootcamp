#include<stdio.h>

int total;  //Global Variable

int sqaure(int x)
{
    return x*x;
}

int sqaureofsum(int x, int y)
{
    int z = sqaure(x+y);
    return z;
}

int main()
{
    int a = 4, b = 8;  //Local variables
    total = sqaureofsum(a,b);
    printf("Output: %d",total);
}