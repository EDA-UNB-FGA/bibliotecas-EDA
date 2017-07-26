#include <stdio.h>
#include <stdlib.h>
#include "circle_list.h"

//essa struct é definida pelo usuário sempre
typedef struct Data{
	int value;
}data;

void *init(int value){
	data *novo = (data*)malloc(sizeof(data));
	novo->value=value;
	return (void*)novo;
}

int comp(void *i1, void *i2){
	data *a=(data*)i1;
	data *b=(data*)i2;
	return a->value >= b->value;
}

int eque(void *i1, void *i2){
	return ((data*)i1)->value== ((data*)i2)->value;
}

void mostrar(void *input){
	data *cpy = (data*)input;
	printf("%d ", cpy->value);
}




int main(){
	header *list = inicializar();
	list->equals=eque;	//inicializando o header com as funções
	list->compare=comp;
	list->print=mostrar;

	int vet[]={3,2,6,9,1,0};
	int i;
	for(i=0; i<6; ++i){
		generic_inserction(list, init(vet[i]));
		listar(list);
	}
	for(i=0; i<6; ++i){
		generic_remove(list,init(vet[i]));
		listar(list);
	}

 return 0;
}
