#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H

#include <stdlib.h>
#include <stdio.h>

#define debug printf("AQUI\n");

//struct do nó
struct Node{
	void *info;
	struct Node *prev, *prox;
};

//struct da tail
struct Tail{
	int tam;
	struct Node *inicio, *fim;
	//essa função de comparação é uma função que substitui o operador <=
	int (*compare)(void*, void*);
};

//---header---
typedef struct Node node;
typedef struct Tail header;


header* inicializar(){
	header *list=(header*)malloc(sizeof(header));
	list->inicio=list->fim=NULL;
	list->tam=0;
	return list;
}

//função auxiliar para criar o node
node * cria(void *data){
	node *aux=(node*)malloc(sizeof(node));
	aux->info=data;
	aux->prev=aux->prox=aux;
	return aux;
}

//inserção na lista de forma organizada
void inserction(header *list, void *data){
	node *tmp = cria(data);
	list->tam++;
	if(list->inicio==NULL){list->inicio=list->fim=tmp;
		printf("Nenhum elemento\n");
	}else if(list->inicio==list->fim){
		printf("Um único elemento\n");
		//caso tenha apenas um elemento
		list->fim=tmp;
		tmp->prox=list->inicio;
		tmp->prev=list->inicio;
		list->inicio->prox=tmp;
		list->inicio->prev=tmp;
	return;
	}else{
		node *cpy=list->inicio, *p=list->inicio;
		printf("Acima de um elemento\n");
		while(cpy!=list->fim->prox && list->compare(cpy->info,data)){
			p=cpy;
			cpy=cpy->prox;
		}
		//caso seja no ponteiro atual
		if(cpy==p){
			tmp->prox=cpy;
			tmp->prev=cpy->prev;
			cpy->prev->prox=tmp;
			cpy->prev=tmp;
		}else{
			p->prox=tmp;
			tmp->prev=p;
			tmp->prox=cpy;
			cpy->prev=tmp;
		}
	}
	list->fim=list->inicio->prev;
}

#endif
