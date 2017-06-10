#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	if(root!=NULL){
		clear(root->left);
		clear(root->right);
		free(root);
	}
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

int max(int a, int b){
	if(a>=b)return a;
	else return b;
}

//lista mostrando as ligações (ainda terá melhorias)
void list2(node *in,int number){
	node *cpy=NULL;
	printf("[%d] %3d: ",number,in->value);
	if(in->left!=NULL)printf("L: %3d ",in->left->value);
	if(in->right!=NULL)printf("R: %3d ",in->right->value);
	printf("\n");
	if(in->left!=NULL)list2(in->left,++number);
	if(in->right!=NULL)list2(in->right,++number);
}

void swap(void *a, void *b){
	void *c=b;
	b=a;
	a=c;
}
void list2_upgrade(node *in, int nivel){
	node *cpy=in;
	if(cpy!=NULL){
		node *exec[100], *filhos[100];
		int einicio=0, efim=0, finicio=0, ffim=0;
		exec[efim++]=in;
		while(einicio!=efim){
			
		}
	}
	
	
}

int grau_arvore(node *arv){
	int cont=0;
	if(arv!=NULL){
		if(arv->left!=NULL)cont++;
		if(arv->right!=NULL)cont++;
		if(arv->left!=NULL)cont=max(cont,grau_arvore(arv->left));
		if(arv->right!=NULL)cont=max(cont,grau_arvore(arv->right));
	}
	return cont;
	
}

void listar_preOrdem(node *root){
	if(root!=NULL){
		printf("[%d]",root->value);
		if(root->left!=NULL)listar_preOrdem(root->left);
		if(root->right!=NULL)listar_preOrdem(root->right);
	}else printf("Base Vazia\n");
}

void listar_inOrdem(node *root){
        if(root!=NULL){
                if(root->left!=NULL)listar_preOrdem(root->left);
                printf("[%d]",root->value);
                if(root->right!=NULL)listar_preOrdem(root->right);
        }else printf("Base Vazia\n");
}

void listar_posOrdem(node *root){
        if(root!=NULL){
                if(root->left!=NULL)listar_preOrdem(root->left);
                if(root->right!=NULL)listar_preOrdem(root->right);
                printf("[%d]",root->value);
        }else printf("Base Vazia\n");
}


void trocar(node *a, node *b){
	node *c;
	c=b;
	a=b;
	b=c;
}

void swap2(int *a, int *b){
	*a^=*b;
	*b^=*a;
	*a^=*b;
}

void printf_parents(node *arv){
	node fila[500];
	int inicio, fim;
	inicio=fim=0;
	fila[fim++]=*arv;
	int value=10000;

	while(inicio!=fim){
		printf("[%d]", fila[inicio].value);
		if(fila[inicio].left!=NULL)fila[fim++]=*fila[inicio].left;
		if(fila[inicio].right!=NULL)fila[fim++]=*fila[inicio].right;
		value=fila[fim-1].value;
		inicio++;
	}
	
}


int main(){

	node *arv=NULL; //necessário inicializar

	int values[]={-20,1,2,3,6,9,10,63}; // 8 elementos;
	int op,flag=1;
	
	while(flag){
		printf("0-Sair\n");
		printf("1-Criar árvore\n");
		printf("2-Imprimir em pre ordem\n");
		printf("3-Imprimir em ordem\n");
		printf("4-Imprimir pos ordem\n");
		printf("5-Destruir Arvores\n");
		printf("6-Grau da árvores\n");
		printf("7-Remover elemento\n");
		printf("8-Show Arvore\n");

		scanf("%d", &op);
		switch(op){
			case 0: flag=0;
	 		 break;
			case 1: arv=balance(values,0,7);
			 break;
			case 2: listar_preOrdem(arv);
			 break;
			case 3: listar_inOrdem(arv);
			 break;
			case 4: listar_posOrdem(arv);
			 break;
			case 5: arv=clear(arv);
			 break;
			case 6: printf("\nGrau da árvore: %d\n", grau_arvore(arv));
			 break;
			case 7: printf("\nDigite um elemento para ser retirado\n");
				scanf("%d",&op);
				arv=remove_by_merge(arv,op);
			 break;
			case 8: printf("\n Mostrando as relações da árvore\n");
				printf_parents(arv);
			 break;
			default:printf("Opeção inválida\n");
		}
		printf("\n");
	}
	

 return 0;
}
