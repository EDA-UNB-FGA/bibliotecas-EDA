#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H

#include <stdlib.h>

//note heterogêneo
struct Node{
	void *info;
	struct Node *prev, *prox;
};

//header completo
struct Header{
	struct Node *head; //cabeça da lista (inicio e fim)
	int tam;	

	//funções definidas pelo usuário 
	int (*compare)(void*,void*); //para comparação
	int (*equals)(void*, void*); //igualdade
	void (*print)(void*); //mostrar um nó na listagem
};

//--assinaturas--
typedef struct Header header;
typedef struct Node node;
node *makeNode(void*);
header *inicializar();
void generic_inserction(header*,void*); 
void generic_remove(header*,void*);
void listar(header*);

/*
-----------------------------------------
preciso implementar as funções recursivas
-----------------------------------------
*/

//cria um novo node circular
node *makeNode(void *data){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->info=data;
	tmp->prox=tmp->prev=tmp;
	return tmp;
}

//inicializa o header
/*
vale observar que essa função não inicializa os ponteiros 
das funções no header, fica a cargo do usuário esse tratamento.
Não coloquei pois nem sempre usaremos todas as funções dessa lib.
*/
header *inicializar(){
	header *top = (header*)malloc(sizeof(header));
	top->tam=0;
	top->head=NULL;
	return top;
}

//insere um elemento na lista usando a função de comparação
void generic_inserction(header *list, void *data){
	node *tmp = makeNode(data);
	if(list->head==NULL)list->head=tmp; //caso lista vazia
	else{
		if(!list->compare(tmp->info,list->head->info)){
			tmp->prox=list->head;			//inserção no inicio
			tmp->prev=list->head->prev;	
			tmp->prox->prev=tmp;
			tmp->prev->prox=tmp;
			list->head=tmp;
		}else if(list->compare(tmp->info,list->head->prev->info)){
			tmp->prox=list->head;		//inserção no final (perceba que é parecido)
			tmp->prev=list->head->prev;
			tmp->prox->prev=tmp;
			tmp->prev->prox=tmp;
		}else{
			printf("Entrei aqui\n");
			node * cpy = list->head->prox; //inserção no inicio já olhamos portanto começamos do próximo
			while(cpy!=list->head && list->compare(data,cpy->info))cpy=cpy->prox; //navegando
			tmp->prox=cpy;
			tmp->prev=cpy->prev;
			tmp->prev->prox=tmp;
			tmp->prox->prev=tmp;
		}
	}
	list->tam++; //adiciona um elemento na lista
}

//remove um elemento da lista usando a função de igualdade
//caso não encontre o elemento a função nas altera a lista
void generic_remove(header *list, void *data){
	node *cpy=list->head;
	if(list->head!=NULL){
		do{
			if(list->equals(data,cpy->info)){
				if(cpy==list->head)list->head=list->head->prox;
				cpy->prox->prev=cpy->prev;
				cpy->prev->prox=cpy->prox;
				free(cpy);
				
			}
			cpy=cpy->prox;
		}while(cpy!=list->head);	
		list->tam--;
		if(list->tam==0)list->head=NULL;	
	}
}

//imprime na tela todos os elementos da lista
void listar(header *list){
	if(list->head!=NULL){
		node *cpy=list->head;
		do{
			list->print(cpy->info);
			cpy=cpy->prox;
		}while(cpy!=list->head);
	}else printf("Lista Vazia");
	printf("\n");
}



#endif
