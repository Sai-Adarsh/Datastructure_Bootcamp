#include <stdio.h>

int main()
{
    int arr[5];
    printf("Base address: %d\n",arr);

    for(int i=0;i<5;i++)
    {
        arr[i] = i + 1;
    }

    for(int i=0;i<5;i++)
    {
        printf("%d\t",arr[i]);
    }

}