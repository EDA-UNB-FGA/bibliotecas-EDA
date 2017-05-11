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

void inserir_vazio(header *list, node *input){
	list->inicio=input;	
	list->fim=input;
}

//na lista circular inserir no inicio e no fim é a mesma operação
void inserir_inicio(header *list, node *input){
	input->prox=list->inicio;
	input->prev=list->fim;

	list->fim->prox=input;
	list->inicio->prev=input;
		
	list->inicio=input;
}

void generic_inserction(header *list, void *data){
	node *tmp = cria(data);
	list->tam++;
	if(list->inicio==NULL)inserir_vazio(list,tmp);
	else{
		//inserção em qualquer posição de forma organizada
		node *cpy=list->inicio;	
		while(cpy->prox!=list->inicio && list->compare(cpy->info,data)) cpy=cpy->prox;
			if(cpy==list->inicio)inserir_inicio(list,tmp);
			else{
				tmp->prox=cpy;
				tmp->prev=cpy->prev;
				cpy->prev->prox=cpy;
				cpy->prev=tmp;	
				
			}
	}
}

//recebe uma informação como argumento de busca, uma função para procurar o elemento e libera a memória daquele elemento
void excluir(header *list, void *data, int (*equals)(void *, void*)){
	node *cpy = list->inicio;

	while(cpy!=NULL && equals(cpy->info,data)) cpy=cpy->prox;
	//lista vazia
	if(list->inicio==NULL)return;
	//caso tenha apenas um elemento 
	if(cpy==list->inicio){
		free(list->inicio);
		list->inicio=list->fim=NULL;
	}else{
		cpy->prox->prev=cpy->prev;
		cpy->prev->prox=cpy->prox;
		free(cpy);
	}
	
}

#endif
