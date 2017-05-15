#include <stdio.h>
#include <stdlib.h>
#include "circle_list.h"

typedef struct Data{
	int value;
}data;

void* init(int value){
	data *tmp=(data*)malloc(sizeof(data));
	tmp->value=value;
	return (void*)tmp;
}

void listar(header *list){
	if(list->tam==0)printf("Lista Vazia\n");
	else{
		node *cpy = list->inicio;
		do{
			printf("%d ", ((data*)cpy->info)->value);
			cpy=cpy->prox;
		}while(cpy!=list->inicio);
		printf("\n");
	}
}

int comp(void *a, void *b){
	return  ((data*)a)->value >= ((data*)b)->value;
}

int equals(void *a, void *b){
	return ((data*)a)->value==((data*)b)->value;
}

int main(){

	header *list =inicializar();
	list->comparador=comp;
	list->igualdade=equals;
	int vet[]={4,2,3,1,9,19,29};
		int i;

	for(i=0; i<7; i++){
		printf("Amostra %d:\n", i+1);
		generic_inserction(list,init(vet[i]));
		listar(list);
	}
	generic_remove(list,init(vet[0]));
	listar(list);

 return 0;
}
