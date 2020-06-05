#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int length,i;

    printf("Enter count of number:");
    scanf("%d",&length);
    
    int *ptr;
    ptr=(int*)calloc(length,sizeof(int));
    
    if(ptr==NULL)
    {
        printf("Cannot allocate memory");
        exit(1);
    }
    
    printf("Before assigning values\n");
    for(i=0;i<length;i++)
    {

        printf("%d\t",*(ptr+i));
    }
    printf("\n");
    
    for(i=0;i<length;i++)
    {
        printf("Enter a number %d: ",i);
        scanf("%d",&ptr[i]);
    }
    
    printf("After assigning values\n");
    
    for(i=0;i<length;i++)
    {
        printf("%d\t",*(ptr+i));
    }
    
    return 0;
}
