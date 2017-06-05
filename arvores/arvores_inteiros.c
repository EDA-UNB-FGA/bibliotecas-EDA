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

int main(){

	node *arv=NULL; //necessário inicializar

	int values[]={1,3,6,2,9,10,63,-20}; // 7 elementos;
	int i;

	for(i=0; i<7; ++i){
		arv=generic_insert(arv,novo(values[i]));
		listar(arv);
		printf("\n");
	}

 return 0;
}
