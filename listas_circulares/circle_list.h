#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H

#include <stdlib.h>

struct Node{
	void *info;
	struct Node *prox, *prev;
};

struct Header{
	int tam;
	struct Node *inicio, *fim;
	int (*comparador)(void*,void*);
	int (*igualdade)(void*, void*);
};

//assinaturas 
typedef struct Header header;
typedef struct Node node;


header *inicializar(){
	header *tmp = (header*)malloc(sizeof(header));
	tmp->tam=0;
	tmp->inicio=tmp->fim=NULL;
	return tmp;	
}

node *makeNode(void *data){
	node *tmp=(node*)malloc(sizeof(node));
	tmp->info=data;
	tmp->prox=tmp->prev=tmp;
	return tmp;
}

void toLinear(header *list){
	list->inicio->prev=NULL;
	list->fim->prox=NULL;
}

void toCircle(header *list){
	list->inicio->prev=list->fim;
	list->fim->prox=list->inicio;
}

//somente para listas lineares (como a operação para deixa a lista lienar é O(1) é preferível trabalhar com elas)
void inserir_vazio(header *list, void *data){
	printf("[inserir vazio]\n");
	node *tmp=makeNode(data);
	list->inicio=list->fim=tmp;
	list->tam++;
}

void inserir_inicio(header *list, void *data){
	printf("[inserir inicio]\n");
	node *tmp=makeNode(data);
	tmp->prox=list->inicio;
	list->inicio=tmp;
	list->tam++;
	toCircle(list);
}

void inserir_fim(header *list, void *data){
	printf("[inserir fim]\n");
	node *tmp = makeNode(data);
	list->fim->prox= tmp;
	list->fim=tmp;
	list->tam++;
	toCircle(list);
}

void generic_inserction(header *list, void* data){
	if(list->tam==0)inserir_vazio(list,data);
	else{
		toLinear(list);
		node *cpy=list->inicio, *p=list->inicio;

		while(cpy!=NULL && list->comparador(data,cpy->info)){
			p=cpy;
			cpy=cpy->prox;
		}
		if(p==cpy)inserir_inicio(list,data);
		else if(cpy==NULL)inserir_fim(list,data);
		else{
			node *tmp =makeNode(data);
			tmp->prox=cpy;
			tmp->prev=p;
			p->prox=tmp;
			cpy->prev=tmp;
		}
	}
	list->tam++;
	toCircle(list);
}
#endif
