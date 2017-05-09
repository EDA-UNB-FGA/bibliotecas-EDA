#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
	stack *pilha=NULL;

	int vet[]={4,3,2,1};

	int i;
	for(i=0; i<4; i++)pilha=push(pilha,&vet[i]);
	for(i=0; i<4; ++i){
		printf("%d\n", *((int*)pilha->info));
		pilha=pop(pilha);
		if(empty(pilha))printf("Estou vazia\n");
		else printf("Não estou vazia\n");
	}

	
	
	

 return 0;
}
