#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


//Global top node
struct Node* top = NULL;

//Node representation with data and reference to next node
struct Node
{
    int data;
    struct Node* next;
};

//Checks if the stack is empty
bool isEmpty(struct Node* top)
{
    if(top==NULL)
    {
        return true;
    }
    return false;
}

//Returns the top element of the stack
int topElement(struct Node* top)
{
    if(isEmpty(top))
    {
        return 0;
    }
    else
    {
        return top->data;
    }
}


struct Node* push(struct Node* top, int x)
{
    //Dynamic memory node creation
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    
    //if stack empty make temp as the top 
    if(isEmpty(top))
    {
        top = temp;
    }
    
    //else make temp->next point to the top and make temp as new top 
    else
    {
        temp->next = top;
        top = temp;
    }
    
    printf("%d\n",x);
    return top;
}

void pop()
{
    struct Node* temp;
    
    //if stack is empty there are no elements to show
    if(isEmpty(top))
    {
        printf("No elements to show stack underflow");
        return;
    }
    
    //else make the top point the next of the top and free the memory
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void print(struct Node* temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

int main()
{
    //inserting element into the stack
    top = push(top,1);
    top = push(top,2);
    top = push(top,3);
    top = push(top,4);
    top = push(top,5);
    
    //Poping element from the stack
    pop();
    
    //top element of the stack
    printf("%d\n",topElement(top));
    
    //Print the stack
    print(top);
}
