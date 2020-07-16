#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node  *next;
} * head;

void addFirst(struct node * head, int d) {
    struct node * newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = head->next;
    head->next = newnode;
}

void addLast(struct node * head, int d) {
    struct node * newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = d;
    struct node * tmp = head;
	while(tmp->next!= NULL) {
		 tmp = tmp->next;
	}
    newnode->next = NULL;
    tmp->next= newnode;
}

int deleteFirst(struct node * head) {
	struct node * tmp = head->next;
	if (tmp == NULL) {
		printf("List is Empty\n");
		return -1;
	}
	int ret =  tmp->data;
	head->next = tmp->next;
	free(tmp);
	return ret;
}

int deleteLast(struct node * head) {
    struct node * tmp = head;
	struct node * tmp2 = head->next;
	if (tmp2 == NULL) {
		printf("List is Empty\n");
		return -1;
	}
	while (tmp2->next != NULL) {
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	int ret = tmp2->data;
	tmp->next = NULL;
	free(tmp2);
	return ret;
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
    for (int i = 0; i < 10; i++) {
        //addFirst(head, i);
        addLast(head, i);
    }
    print(head);
    deleteFirst(head);
    deleteFirst(head);
    deleteFirst(head);
    deleteFirst(head);
    deleteLast(head);
    deleteLast(head);
    deleteLast(head);
    deleteLast(head);
    print(head);

 }
 