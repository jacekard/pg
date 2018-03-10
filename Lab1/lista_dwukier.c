#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
} node;

node* newNode(int data) {
	node* tmp = malloc(sizeof(node));
	tmp->value = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}

void push_front(node **head, int data) {
	node* tmp = *head;
	node* New = newNode(data);
	if (tmp == NULL) {
		*head = New;
		return head;
	}

	tmp->prev = New;
	New->next = tmp;
	*head = New;
}

void push_back(node* head, int data) {
	node* tmp = head;
	node* New = newNode(data);

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	New->prev = tmp;
	tmp->next = New;
}

int deleteIndex(node** head, int index) {
	node *tmp = *head;
	int val = tmp->value;
	if (index == 0 && tmp->next == NULL)
		free(tmp);
	else if(index == 0 && tmp->next != NULL) {
		tmp->next->prev = NULL;
		*head = tmp->next;
		return val;
	}

	for (int i = 0; i < index; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL) {
			printf("index out of range exception\n");
			return -216521;
		}
	}

	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	free(tmp);
	return val;

}

void showAll(node* head) {
	node* tmp = head;
	do {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	} while (tmp != NULL);
	printf("\n");
}

main() {

	node* head = newNode(1);
	push_back(head, 1);
	push_back(head, 2);
	push_back(head, 3);

	push_front(&head, 0);
	showAll(head);

	deleteIndex(&head, 0);
	showAll(head);
	deleteIndex(&head, 2);
	showAll(head);
	deleteIndex(&head, 2);
	showAll(head);
	deleteIndex(&head, 10);
	return 0;
}
