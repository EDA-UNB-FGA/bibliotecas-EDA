#ifndef DLIST
#define DLIST

#include <stdlib.h>



//---my structs---
struct Node{
	void *info;
	struct Node *prev,*prox;
};

struct Header{
	int tam;
	int (*comparador)(void*,void*);
	int (*igualdade)(void*,void*);
	struct Node *inicio,*fim;
};

//---header---
typedef struct Header header;
typedef struct Node node;
node *makeNode(void*);
header* inicializar();
void inserir_vazio(header*,void*);
void inserir_inciio(header*, void*);
void inserir_fim(header*, void*);
void generic_inserction(header*, void*);


//cria um node com a informação "data" e seus ponteiros nulos
node *makeNode(void *data){
	node *novo=(node*)malloc(sizeof(node));
	novo->info=data;
	novo->prev=novo->prox=NULL;
	return novo;
}

//inicializar um header com ponteiros nulos e tamanho 0 
header *inicializar(){
	header *novo = (header*)malloc(sizeof(header));
	novo->inicio=novo->fim=NULL;
	novo->tam=0;
	return novo;
}

//caso em que a lista está vazia
void inserir_vazio(header *list,void *data){
	list->inicio=list->fim=makeNode(data);
	list->tam++;
}

//caso em que a inserção é no inicio
void inserir_inicio(header *list, void *data){
	node *tmp = makeNode(data);
	tmp->prox = list->inicio;
	list->inicio->prev=tmp;	
	list->inicio=tmp;
	list->tam++;
}

//caso em que a inserção é no fim
void inserir_fim(header *list, void *data){
	node *tmp = makeNode(data);
	list->fim->prox=tmp;
	tmp->prev=list->fim;
	list->tam++;
	list->fim=tmp;
}

//inserção genérica seguindo a comparação do header
void generic_inserction(header *list,void *data){
	//caso da lista vazia
	if(list->tam==0)inserir_vazio(list,data);
	else{
		node *cpy=list->inicio, *p=list->inicio;
		while(cpy!=NULL && list->comparador(cpy->info,data)){
			p=cpy;
			cpy=cpy->prox;
		}
		if(cpy==list->inicio)inserir_inicio(list,data);
		else if(p->prox==NULL)inserir_fim(list,data);
		else{
			node *tmp=makeNode(data);
			tmp->prox=cpy;
			tmp->prev=cpy->prev;
			cpy->prev->prox=tmp;
			cpy->prev=tmp	;
		}
		
	}
}

//na exclusão o noso 

void generic_remove(header *list, void *data){
	
}

#endif
