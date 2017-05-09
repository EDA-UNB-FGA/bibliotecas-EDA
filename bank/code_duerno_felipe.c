#include <stdio.h>
#include <stdlib.h>

struct Data {
	int value;
};

void *init(int value) {
	struct Data *new = malloc(sizeof(struct Data));
	new->value = value;
	return (void *) new;
}

int compare(void *a, void *b) {
	return ((struct Data *) a)->value < ((struct Data *) b)->value;
}

struct Node {
	void *data;
	struct Node *next;
	struct Node *prev;
};

struct Header {
	struct Node *head;
	struct Node *tail;
};

struct Node *create(void *data) {
	struct Node *new = malloc(sizeof(struct Node));
	new->data = (void *) data;
	new->next = new->prev = NULL;
	return new;
}

void insert(struct Header *header, void *data) {
	struct Node *new = create(data);
	
	if(header->head == NULL) {
		header->head = new;
		header->tail = new;
		return;
	}
	
	struct Node *aux = header->head;
	while(aux != NULL && compare(aux->data, data))
		aux = aux->next;
	
	if(aux == header->head) {
		new->next = header->head;
		header->head->prev = new;
		header->head = new;
		return;
	}
	
	if(aux == NULL) {
		new->prev = header->tail;
		header->tail->next = new;
		header->tail = new;
		return;
	}
		
	new->next = aux;
	new->prev = aux->prev;
	aux->prev->next = new;
	aux->prev = new;
}

void print_forward(struct Node *head) {
	while(head != NULL) {
		printf("%d\n", ((struct Data *) head->data)->value);
		head = head->next;
	}
}

void print_backward(struct Node *tail) {
	while(tail != NULL) {
		printf("%d\n", ((struct Data *) tail->data)->value);
		tail = tail->prev;
	}
}

int main () {
	struct Header *header = malloc(sizeof(struct Header));
	header->head = NULL;
	header->tail = NULL;
	
	insert(header, init(3));
	insert(header, init(4));
	insert(header, init(1));
	insert(header, init(2));
	
	printf("Forward:\n");
	print_forward(header->head);
	
	printf("Backward:\n");
	print_backward(header->tail);

	return 0;
}
