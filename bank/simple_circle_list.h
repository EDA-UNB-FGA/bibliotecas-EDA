#ifndef circle_list
#define circle_list

#include <stdlib.h>

typedef struct Node{
	void *info;
	struct Node *prox;
}node;

typedef struct Header{
	node *inicio,*fim;
	int tam;
}header;

node *cria(void *data){
	node *aux=(node*)malloc(sizeof(node));
	node->info=data;
	aux->prox=aux;
	return aux;
}


#endif
