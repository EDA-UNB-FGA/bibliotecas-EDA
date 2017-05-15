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
header *inicializar();
node *makeNode(void*);


//inicia o header com o comportamento adequado para o restante do programa 
//inicializar tem um comportamento parecido com um construtor, portanto é NECESSÁRIO que esse método seja chamado
header *inicializar(){
	header *tmp = (header*)malloc(sizeof(header));
	tmp->tam=0;
	tmp->inicio=tmp->fim=NULL;
	return tmp;	
}

//cria um nó que aponta para ele mesmo
node *makeNode(void *data){
	node *tmp=(node*)malloc(sizeof(node));
	tmp->info=data;
	tmp->prox=tmp->prev=tmp;
	return tmp;
}

//inicia o header com o primeiro elemento
void inserir_vazio(header *list, void *data){
	node *tmp=makeNode(data);
	list->inicio=list->fim=tmp;
	list->tam++;
}


//caso receba o 3º argumento como 1 a inserção será no inicio, com o argumento 0 a inserção é no final
void inserir_pontas(header *list, void *data, int modo){
	node *tmp = makeNode(data);
	tmp->prox=list->inicio;
	tmp->prev=list->fim;
	tmp->prox->prev=tmp;
	tmp->prev->prox=tmp;
	list->tam++;

	if(modo==1)list->inicio=tmp;
	else if(modo==0)list->fim=tmp;
}

//a inserção foi chamada de générica pois terá o comportamento da função de comparação (vide main.c)
void generic_inserction(header *list, void* data){
	//caso a lista não tenha nenhum elemento
	if(list->tam==0)inserir_vazio(list,data);
	else{
		//como a inserção é organizada (por questões de busca) vamos linearizar a lista
		list->inicio->prev=list->fim->prox=NULL;
		node *cpy=list->inicio, *p=list->inicio;
		while(cpy!=NULL && list->comparador(data,cpy->info)){
			p=cpy;
			cpy=cpy->prox;
		}

		if(cpy==p)inserir_pontas(list,data,1);
		else if(cpy==NULL)inserir_pontas(list,data,0);
		else{
		
			node *tmp=makeNode(data);
			tmp->prox=cpy;
			tmp->prev=p;
			tmp->prox->prev=tmp;
			tmp->prev->prox=tmp;
			list->tam++;
		//voltando a circular 
		list->fim->prox=list->inicio;
		list->inicio->prev=list->fim;
		}
	}
}
#endif
