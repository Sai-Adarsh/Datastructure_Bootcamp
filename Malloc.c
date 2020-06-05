#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,length,sum=0;
    printf(" Enter the count of numbers:");
    scanf("%d", &length);
    
	int *p;
	//Allocates memory in the heap section and returns the address the pointer
    p=(int*) malloc((sizeof(int)*length)); 
    
	for(i=0; i<length;i++)
    {
        printf("Enter a number :");
        scanf("%d",p+i);
    }
    
	for(i=0; i<length;i++)
    {
        sum=sum+*(p+i);
    }
    
    printf("The total sum : %d", sum);
    
	return 0;
}
