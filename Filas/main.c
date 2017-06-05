#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct Dado{
	int value;
}dado;

void *init(int value){
	dado *tmp =(dado*)malloc(sizeof(dado));
	tmp->value=value;
	return (void*)tmp;
}

void listar(header *list){
	node *cpy=list->inicio;
	if(list->inicio==NULL)printf("BASE VAZIA");
	while(cpy!=NULL){
		printf("%d ", ((dado*)cpy->data)->value);
		cpy=cpy->prox;
	}
	printf("\n");
}

int main(){

	header *lista=inicializar();
	int vet[]={1,4,3,2};
	int i;

	for(i=0; i<4; i++)push(lista,init(vet[i]));
	listar(lista);
	for(i=0; i<3; i++)pop(lista);
	listar(lista);

 return 0;
}
