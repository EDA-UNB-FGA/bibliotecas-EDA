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

int main(){

	int vet[]={3,1,6,8,2,4};
	int i;
	node *arv=NULL;

	for(i=0; i<6; ++i){
			arv=generic_insert(arv,novo(init(vet[i])),comparator);
	}
		printf("--------------\n");
		list_in_ordem(arv,print);
		printf("\n");
		printf("Nível %d\n", get_nivel(arv,init(2),0,comparator));
	

 return 0;
}
