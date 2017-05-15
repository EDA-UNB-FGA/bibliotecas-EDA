#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

typedef struct Data{
	int value;
}data;


void *init(int value){
	data *novo =(data*)malloc(sizeof(data));
	novo->value=value;
	return (void*)novo;
}

void listar(header *list){
	if(list->inicio==NULL)printf("Base Vazia\n");
	else{
		node *cpy=list->inicio;
		while(cpy!=NULL){
			printf("%d ", ((data*)cpy->info)->value);
			cpy=cpy->prox;
		}
	}
	printf("\n");
}

int compar(void *a, void *b){
	return ((data*)a)->value >= ((data*)b)->value;
}

int equals(void *a, void* b){
	return ((data*)a)->value == ((data*)b)->value;
}

int main(){

	header *list=inicializar();
	list->comparador=compar;
	list->igualdade=equals;
	int vet[]={4,1,3,2,5,9};
	int i;

	for(i=0; i<6; i++){
		generic_inserction(list,init(vet[i]));
		listar(list);
	}	
	generic_remove(list,init(4));
	listar(list);
 return 0;
}
