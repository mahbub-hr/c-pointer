#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; // to store the content of the node
    struct node  *next; // to store the address of another node
} * head;

void addFirst(struct node * head, int d) {
    struct node * newnode = (struct node *) malloc(sizeof(struct node)); // memory allocation for newnode
    newnode->data = d; // set data of the newnode to d
    
    newnode->next = head->next;
    head->next = newnode;
}

void addLast(struct node * head, int d) {
    struct node * newnode = (struct node *) malloc(sizeof(struct node)); // memory allocation for newnode
    newnode->data = d; // set data of the newnode to d
    
    struct node * tmp = head;
	while(tmp->next!= NULL) {
		 tmp = tmp->next; // jump to the next node using the next pointer
	}
    // now tmp point to the last node
    newnode->next = NULL;
    tmp->next= newnode;
}

void print(struct node * head) {
    if ( head == NULL) return;
    struct node * tmp = head->next;
    while (tmp  != NULL) {
        printf("%d ", tmp->data);   
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    head = (struct node *) malloc(sizeof(struct node));
    head->next = NULL;
    for (int i = 1; i <= 10; i++) {
        addFirst(head, i);
        //addLast(head, i);
    }
    print(head);
 }
 