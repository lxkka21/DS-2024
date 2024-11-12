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
        return;
    }
    (*rear)->next=node;
    *rear=node;
}

void dequeue(Node *front){
    if(*front==NULL){
        printf("No element found");
        return;
    }
    Node temp=*front;
    int key=temp->data;
    *front=temp->next;
    printf("Dequeued %d",key);
    free(temp);
}

void display(Node *front){
 if(*front==NULL){
        printf("No element found");
        return;
    }
    Node temp=*front;
    while(temp!=NULL){
        temp=temp->next;
        printf("%d",temp->data);
    }
}

int main(){
    Node front=NULL;
    Node rear=NULL;
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 10);
    
    dequeue(&front);
    dequeue(&front);
    return 0;
    
}


    
    
    
