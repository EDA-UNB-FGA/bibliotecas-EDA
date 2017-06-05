#include <stdio.h>
#include <stdlib.h>

/*Essa implementação é apenas para entender o conceito a implementação genérica esta na lib */

struct Node{
	int value;
	struct Node *left, *right;
};


typedef struct Node node;

//cria o no com o valor
node *novo(int val){
	node *tmp=(node*)malloc(sizeof(node));
	tmp->value=val;
	tmp->right=tmp->left=NULL;
	return tmp;
}


//em arvores os elementos não podem se repetir pois atrapalham no percurso 
//essa implementação conta com a elementos não repetidos
node* generic_insert(node *tree, node *new){
	if(tree==NULL)return new;
	else{
		if(tree->value<new->value)tree->right =generic_insert(tree->right,new);
		else tree->left=generic_insert(tree->left,new);
	}
	return tree;
}

//percuso : left center right
void listar(node *tree){
	if(tree!=NULL){	
		if(tree->left!=NULL)listar(tree->left);
		printf("[%d]",tree->value);
		if(tree->right!=NULL)listar(tree->right);
	}else printf("Base Vazia");
}

node* clear(node *root){
	node *cpy=root;
	if(root->left!=NULL)clear(root->left);
	if(root->right!=NULL)clear(root->right);
	free(root);
	return NULL;
}

node* remove_by_merge(node *in,int value){
	node *cpy=in;
	if(cpy!=NULL){
		if(cpy->value==value)cpy=generic_insert(cpy->left,cpy->right);
		else if(cpy->value>value)cpy->left=remove_by_merge(cpy->left,value);
		else cpy->right=remove_by_merge(cpy->right,value);
	}
	return cpy;
}
//cria uma arvore balanceada atraves de um array ordenado
node *balance(int matriz[],int first, int last){
	node *cpy=NULL;
	if(first<=last){
		int middle = (first+last)/2;
		cpy=generic_insert(cpy,novo(matriz[middle]));
		cpy->left=balance(matriz,first,middle-1);
		cpy->right=balance(matriz,middle+1,last);
	}
	return cpy;
}
//lista mostrando as ligações (ainda terá melhorias)
void list2(node *in,int number){
	node *cpy=NULL;
	printf("[%d] %3d: ",number,in->value);
	if(in->left!=NULL)printf("%3d ",in->left->value);
	if(in->right!=NULL)printf("%3d ",in->right->value);
	printf("\n");
	if(in->left!=NULL)list2(in->left,++number);
	if(in->right!=NULL)list2(in->right,++number);
}
int main(){

	node *arv=NULL; //necessário inicializar

	int values[]={-20,1,2,3,6,9,10,63}; // 7 elementos;
	int i;

	arv=balance(values,0,7);
	listar(arv);
	printf("\n");
	arv=remove_by_merge(arv,1);
	listar(arv);
	printf("\n");

	

 return 0;
}
