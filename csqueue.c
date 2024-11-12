// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} *Node;

Node newnode(int data){
    Node node=(Node)malloc(sizeof(struct node));
    node->data=data;
    node->next=NULL;
    return node;
}

void enqueue(Node *front, Node *rear, int data){
    Node node=newnode(data);
    if(*rear==NULL){
        *front=*rear=node;
        (*rear)->next=node;
        return;
    }
    Node temp=*rear;
    temp->next=node;
    *rear=node;
    (*rear)->next=*front;
}

void dequeue(Node *front, Node *rear){
    if (*front == NULL) {  // Queue is empty
        printf("Queue is empty\n");
        return;
    }
Node temp=*front;
*front=temp->next;
(*rear)->next=*front;
int data=temp->data;
free(temp);
printf("Dequeued %d", data);
}

int main(){
    Node front=NULL;
    Node rear=NULL;
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 10);
    
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    return 0;
    
}


    
    
    
