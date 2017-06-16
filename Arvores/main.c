#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void* init(int data){
	int *date=(int*)malloc(sizeof(int));
	*date=data;
	return (void*)date;
}

int comparator(void *a, void *b){
	//greater
	if(*((int*)a)>*((int*)b))return 1;
	//less
	if(*((int*)a)<*((int*)b))return -1;
	//the same
	if(*((int*)a)==*((int*)b))return 0;
}

void print(void *a){
	printf("[%d]", *((int*)a));
}

node* insert(node *arv,int k,int (*comp)(void*,void*)){
	return generic_insert(arv,novo(init(k)),comp);
}

//lista os pesos da árvore -- apenas pra teste--
void listar(node *arv){
	if(arv!=NULL){
		if(arv->left!=NULL)listar(arv->left);
		printf("[%d][%d]", get_altura(arv->right),get_altura(arv->left));
		if(arv->right!=NULL)listar(arv->right);
	}else printf("Arvore vazia\n");
}



int main(){

	int vet[]={3,1,6,8,2,4,12,18,11};
	int i;
	node *arv=NULL;
	for(i=0; i<9; ++i)
			arv=avl_insert(arv,novo(init(vet[i])),comparator);
	busca_por_largura(arv,print,comparator);
	printf("\n");
 return 0;
}
