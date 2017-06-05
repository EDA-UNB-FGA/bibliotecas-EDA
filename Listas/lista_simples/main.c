#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

typedef struct Data{
	int value;
}data;

void *init(int value){
	data *tmp=(data*)malloc(sizeof(data));
	tmp->value=value;
	return (void*)tmp;
}

int comp(void *a, void *b){
	return ((data*)a)->value >= ((data*)b)->value;
}

void listar(node *inicio){
	node *cpy=inicio;
	if(cpy==NULL)printf("Base vazia\n");
	else{
		while(cpy!=NULL){
			printf("%d ", ((data*)cpy->info)->value);
			cpy=cpy->prox;
		}
	}
	printf("\n");
}

int main(){

	node *list=NEWLIST;

	int vet[]={2,3,6,7,0,12};
	int i;	
	
	for(i=0; i<6; ++i){
		list=inserction(list,init(vet[i]),comp);
		listar(list);
	}
	

 return 0;
}
