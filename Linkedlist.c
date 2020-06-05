#include<stdio.h>
#include<stdlib.h>

//Global head and tail pointers
struct Node* head=NULL;
struct Node* tail = NULL;

//Linked list node representation
struct Node
{
    int data;
    struct Node* next;
}; 

//inserts nodes in the linkedlist
struct Node* addNode(struct Node* head,int val)
{
    //Dynamic memory creation
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    
    //if the list is NULL points head and tail points to the same node
    if(head == NULL)
    {
        head = tail =  temp;
    }
    
    //else add the values to the tail node and adjust 
    else
    {
        tail->next = temp;
        tail = temp;
    }
    
    return head;
}

void print(struct Node* temp)
{
    //Traverse the linked list nodes and print the node values
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

int main()
{
    //Inserting element into the linkedlist
    head = addNode(head,1);
    head = addNode(head,2);
    head = addNode(head,3);
    
    //print the linkedlist 
    print(head);
}
