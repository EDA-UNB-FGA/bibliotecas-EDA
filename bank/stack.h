#ifndef	STACK_H
#define STACK_H

//essa é uma implementação de uma estrutrura de dados FIFO por meio de uma lista restringida apenas a inserção e remoção no inicio

#include <stdlib.h>

struct Node{
	void *info;
	struct Node *prox;
};

typedef struct Node stack;

//função que cria um node heterogêneo
stack * cria(void *data){
	stack *tmp=(stack*)malloc(sizeof(stack));
	tmp->info=data;
	tmp->prox=NULL;
	return tmp;
}
//insere no inicio de uma lista o node
stack* push(stack *input,void *info){
	stack *tmp=cria(info);
	if(input!=NULL){
		tmp->prox=input;
	}
	return tmp;
}
//retira do inicio da lista o node
stack* pop(stack *input){
	stack *cpy=input;
	input=input->prox;
	free(cpy);
	return input;
}
//retorna 1 caso a lista esteja vazia e 0 caso esteja com ao menos 1 elemento
unsigned empty(stack *list){
	return	list==NULL;
}


#endif
