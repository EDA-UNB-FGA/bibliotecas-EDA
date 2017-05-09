#include <stdio.h>
#include <stdlib.h>
#include "circle_list.h"

typedef struct Data{
	int value;
}date;

void *init(int val){
	date *novo = (date*)malloc(sizeof(date));
	novo->value=val;
	return (void*)novo;
}

void listar(header *list){
	node *cpy=list->inicio;

	do{
		printf("%d ", ((date*)cpy->info)->value);
		cpy=cpy->prox;
	}while(cpy!=list->inicio);
	printf("\n");
}

int comp(void *a, void *b){
	return *((int*)a)==*((int*)b);
}

int main(){

	header *list=inicializar();
	list->compare=comp;
	int vet[]={4,1,3,2};
	int i;

	for(i=0; i<4; ++i){
	inserction(list,init(vet[i]));
	printf("Tamanho da lista: %d\n", list->tam);
	listar(list);
	}
	
 return 0;
}
