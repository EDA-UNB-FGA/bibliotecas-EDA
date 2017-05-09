#include <stdio.h>

#include "lista.h"


int verde(void *a, void *b){
	int l=*((int*)a);
	int k=*((int*)b);
	return k>l;
}

void listar(node *list){
	node *cpy=list;
	while(cpy!=NULL){
		printf("%d-", *((int*)cpy->info));
		cpy=cpy->prox;
	}
	printf("\n");
}

int main(){

	node *lista=NULL;
	int v[]={1,2,3,4};
	lista=inserction(lista,&v[0],verde);
	lista=inserction(lista,&v[1],verde);
	listar(lista);
	

 return 0;
}
