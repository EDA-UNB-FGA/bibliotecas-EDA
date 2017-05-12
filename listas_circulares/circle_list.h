#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H

#include <stdlib.h>

struct Node{
	void *info;
	struct Node *prev, *prox;
};

struct Header{
	int tam;
	int (*compare)(void *,void *);
	int (*igualdade)(void*,void*);
	struct Node *inicio, *fim;
};

typedef struct Header header;
typedef struct Node node;

header *inicializar(){
	header *aux=(header*)malloc(sizeof(header));
	aux->tam=0;
	aux->inicio=aux->fim=NULL;
	return aux;
}

node *cria(void *data){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->info=data;
	tmp->prev=tmp->prox=tmp;
	return tmp;
}


void inserir_vazio(header *list, void *data){
	printf("sjdfkajsdlkf\n");
	list->inicio=list->fim=cria(data);
}

void inserir_inicio(header *list, void *data){
	node *tmp=cria(data);
	tmp->prox=list->inicio;
	tmp->prev=list->fim;
	
	list->inicio->prev=tmp;
	list->fim->prox=tmp;
		
	list->inicio=tmp;
}
//da pra melhor... a função é a mesma mas o set no final muda
void inserir_fim(header *list, void *data){
	node *tmp=cria(data);
	tmp->prox=list->inicio;
	tmp->prev=list->fim;
	
	list->inicio->prev=tmp;
	list->fim->prox=tmp;
	
	list->fim=list->fim->prox;
}

//inserção genérica as funções inserir_inicio e inserir_fim existem para manipularmos os ponteiros do header
//PS* a inserção organizada ainda não está funcionando como deveria
void generic_inserction(header *list, void *data){
	list->tam++;
	if(list->inicio==NULL)inserir_vazio(list,data);
	else{
		node *cpy=list->inicio;
		while(cpy->prox!=list->inicio && list->compare(cpy->info,data))cpy=cpy->prox;
		if(cpy==list->inicio)inserir_inicio(list,data);
		else if(cpy==list->fim)inserir_fim(list,data);
		else{
			node *tmp = cria(data);
			tmp->prox=cpy;
			tmp->prev=cpy->prev;
			cpy->prev->prox=tmp;
			cpy->prev=tmp;
		}
	}
}

#endif
