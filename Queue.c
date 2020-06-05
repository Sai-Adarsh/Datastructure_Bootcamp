#include<stdio.h>
#include<stdlib.h>

struct Node* front = NULL; //Global front 
struct Node* rear = NULL; //Global rear

//Linkedlist node representation
struct Node
{
    int data;
    struct Node* next;
};


struct Node* enqueue(struct Node* front, int x)
{
    //Dynamic node creation
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    
    //if the queue is empty front and rear points to the same node
    if(rear==NULL)
    {
        front=rear=temp;
    }
    
    //else insert elements in the rear end of the queue
    else
    {
        rear->next = temp;
        rear = temp;
    }
    
    return front;
}

void dequeue()
{
    struct Node* temp;
    
    //if the queue is empty no elements to display
    if(front==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    
    //else delete from the front end of the queue
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}

void print(struct Node* front)
{
    while(front!=NULL)
    {
        printf("%d\t",front->data);
        front = front->next;
    }
}

int main()
{
    //Inserting elements in the queue
    front = enqueue(front,1);
    front = enqueue(front,2);
    front = enqueue(front,3);
    front = enqueue(front,4);
    
    //printing the queue elements
    print(front);
    
    printf("\n");
    //Deleting elements from the queue
    dequeue();
    
    //printing the queue elements
    print(front);
}
