#ifndef SIMPLE_LIST
#define SIMPLE_LIST

#define NEWLIST NULL

#include <stdlib.h>

/*---NODE---*/
struct Node{
	void *info;
	struct Node *prox;
};

/*---HEADER---*/
typedef struct Node node;

//cria um node com ponteiro nulo 
node* makeNode(void *data){
	node *tmp=(node*)malloc(sizeof(data));
	tmp->info=data;
	tmp->prox=NULL;
	return tmp;
}

//insere um elemento na lista de arcodo com um determinado critério(*comp)
node* inserction(node *list, void *data, int (*comp)(void*,void*)){
	node *cpy=list, *p=list, *tmp=makeNode(data);
	while(cpy!=NULL && comp(data,cpy->info)){
		p=cpy;
		cpy=cpy->prox;
	}
	//inserção no inicio
	if(cpy==p){
		tmp->prox=cpy;	
		list=tmp;
	}
	else if(cpy==NULL)p->prox=tmp;
	else{
		tmp->prox=cpy;
		p->prox=cpy;
	}
	return list;;
}


#endif
