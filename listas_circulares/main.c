#include <stdio.h>
#include <stdlib.h>
#include "circle_list.h"

typedef struct Data{
	int value;
}data;

void *init(int a){
	data *tmp = (data*)malloc(sizeof(data));
	tmp->value=a;
	return (void*)tmp;
}

void listar(header *list){
	if(list->inicio==NULL)printf("BASE VAZIA");
	else{
		node *cpy=list->inicio;
		do{
			printf("%d ", ((data*)(cpy->info))->value);
			cpy=cpy->prox;
		}while(cpy!=list->inicio);
		
	}
	printf("\n");
}

int comp(void *a, void *b){
	return ((data*)a)->value >= ((data*)b)->value;
}

int main(){

	header *list=inicializar();
	list->compare=comp;
	int vet[]={4,2,1,3};
	int i;
	for(i=0;i<4; ++i){
		generic_inserction(list,init(vet[i]));
		listar(list);
	}
	


 return 0;
}
