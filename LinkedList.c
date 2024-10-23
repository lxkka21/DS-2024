#include<stdio.h>
#include<stdlib.h>

// Define the structure for the node
typedef struct node {
    int data;
    struct node *next;
} *Node; // Node is now a pointer to struct node

// Function to create a new node
Node newNode(int temp){
    Node newNode = (Node)malloc(sizeof(struct node)); // Correct memory allocation
    newNode->data = temp;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void DisplayNode(Node head) {
    Node temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data); // Corrected printf syntax
        temp = temp->next;
    }
}

int main() {
    Node head, second, last;

    // Create nodes and link them
    head = newNode(1);
    second = newNode(2);
    last = newNode(3);

    head->next = second; // Link first node to second
    second->next = last; // Link second node to last

    printf("Linked List:\n");
    DisplayNode(head); // Display the linked list

    // Free allocated memory
    free(last);
    free(second);
    free(head);

    return 0;
}
