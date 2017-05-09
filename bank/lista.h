#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	void *info;
	struct Node *prox;
}node;

node* cria(void *input){
	node *tmp=(node*)malloc(sizeof(node));
	tmp->info=input;
	tmp->prox=NULL;
	return tmp;
}

node* inserction(node *list, void *input, int (*f)(void*,void*)){
	node *aux = cria(input);
	if(list==NULL)return aux;
	else{
		node *cpy=list,*p=list;
		while(cpy!=NULL && f(cpy,input)){
			p=cpy;
			cpy=cpy->prox;
		}

		//caso seja no inicio
		if(p==cpy){
			aux->prox=list;
			return aux;
		}else if(p->prox==NULL) p->prox=aux;
		else{
			aux->prox=cpy;
			p->prox=aux;	
		}
	}
	return list;
}



#endif
