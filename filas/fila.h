#ifndef FILA_H
#define FILE_H

#include <stdlib.h>

//--structs--
struct Node{
	void *data;
	struct Node *prox, *prev;
};

struct Header{
	int tam;
	struct Node *inicio, *fim;
};

//--assinaturas das funções
typedef struct Header header;
typedef struct Node node;

//funções
header* inicializar(){
	header * tmp =(header*)malloc(sizeof(header));
	tmp->tam=0;
	tmp->inicio=tmp->fim=NULL;
	return tmp;
}

node* cria(void *data){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data=data;
	tmp->prox=tmp->prev=NULL;
	return tmp;
}

void lista_vazia(header *list, node *tmp){
	list->inicio=list->fim=tmp;
}

void push(header *list, void *date){
	node *tmp = cria(date);
	list->tam++;
	if(list->inicio==NULL)lista_vazia(list,tmp);
	else{
		list->fim->prox=tmp;
		tmp->prev=list->fim;
		list->fim=list->fim->prox;
	}
}

void pop(header *list){
	if(list->inicio!=NULL){
		list->tam--;
		node *excluir=list->inicio;
		list->inicio=list->inicio->prox;
		if(list->inicio!=NULL)list->inicio->prev=NULL;
		free(excluir);
	}
}

#endif
