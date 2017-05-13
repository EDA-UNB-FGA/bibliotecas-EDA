#include <stdio.h>
#include <stdlib.h>
#include "circle_list.h"

typedef struct Data{
	int value;
}data;


//simplesmente cria a struct com o valor int e retorna como ponteiro void
void *init(int a){
	data *tmp = (data*)malloc(sizeof(data));
	tmp->value=a;
	return (void*)tmp;
}

//lista os elementos da lista duplamente encadeada 
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
//essa comparação coloca na ordem de inserção
int comp(void *a, void *b){
	return ((data*)a)->value <= ((data*)b)->value;
}

int main(){

	header *list=inicializar();
	list->compare=comp;
	int vet[]={1,2,3,4,5,6,7,8,9};
	int i;
	for(i=0;i<9; ++i){
		generic_inserction(list,init(vet[i]));
		printf("Valor inicio %d valor final %d \n", ((data*)(list->inicio->info))->value, ((data*)(list->fim->info))->value );
		listar(list);
	}
	
 return 0;
}
