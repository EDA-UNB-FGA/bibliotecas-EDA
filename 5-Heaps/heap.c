#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a>b)? a : b )
#define M 100


/*swap para inteiros */
void swap(int *a, int *b){
	*a^=*b;
	*b^=*a;
	*a^=*b;
}

/*A inserção nesse tipo de heap é apenas inserir no final*/
/*função para fazer um heap a partir de um array*/
void build_heap(int array[], int size, int i){
	int maior = i; 
	int l= 2*i+1;
	int r= 2*i+2;
	
	if(l<size && array[l]>array[maior])maior=l;
	if(r<size && array[r]>array[maior])maior=r;
	if(maior!=i){
		swap(&array[i],&array[maior]);
		build_heap(array, size,maior);
	}
}


int main(){
	int heap[M],n,i,value;
	printf("Quantos registros irá inserir\n");
	scanf("%d", &n);
	
	for(i=0; i<n; ++i){
		scanf("%d", &value);
		/*Aqui entra a inserção no heap*/
	}
 return 0;
}
