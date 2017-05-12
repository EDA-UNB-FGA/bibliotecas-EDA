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
//essas comparação coloca na ordem de inserção
int comp(void *a, void *b){
	return 1;
}

int main(){

	header *list=inicializar();
	list->compare=comp;
	int vet[]={4,2,3,1};
	int i;
	for(i=0;i<4; ++i){
		printf("Entrar o %d\n", i );
		generic_inserction(list,init(vet[i]));
		listar(list);
	}
	
 return 0;
}
