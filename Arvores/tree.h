#ifndef TREE_H
#define TREE_H
#define MAX(x,y) (x>=y)? x : y
#define N 100
#include <stdio.h>
#include <stdlib.h>

struct Node{
	void *info;
	struct Node *left, *right;
};

typedef struct Node node;

//funções na forma recursiva
node *novo(void*);
node *generic_insert(node*, node*, int (*)(void*,void*));
node *remove_by_merging(node*, void*, int (*)(void*,void*));
node *remove_by_copy(node*, void*, int (*)(void*,void*));
int get_nivel(node*,void*,int,int (*)(void*,void*));
int get_altura(node*);

//funções interativas
void busca_por_largura(node*,void (*)(void*),int (*)(void*,void*));
node* rightRotate(node*);
node* leftRotate(node*);


//retorna um nó com a informação de data
node *novo(void *data){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->info=data;
	tmp->left=tmp->right=NULL;
	return tmp;
}
/* IMPLEMENTAÇÃO DAS FUNÇÕES RECURSIVAS */


//inserção um nó na ordem 
node *generic_insert(node *root, node* element, int (*comp)(void*,void*)){
	if(root==NULL)return element;
	else{
		if(comp(root->info,element->info)==1)root->left=generic_insert(root->left,element,comp);
		else root->right=generic_insert(root->right,element,comp);
	}
	return root;
}

//aproveitando a pilha de recursão
node *avl_insert(node *root, node *element, int (*comp)(void*,void*)){
	if(root==NULL)return element;
	else{
		if( comp(root->info,element->info)==1)root->left=avl_insert(root->left,element,comp);
		else root->right=avl_insert(root->right,element,comp);
		int v = get_altura(root->left) - get_altura(root->right);
		if(v>1 && comp(element->info,root->left->info)==-1)return rightRotate(root);
		if(v<-1 && comp(element->info,root->right->info)==1) return leftRotate(root);
		if(v>1 && comp(element->info,root->left->info)==1){
			root->left=leftRotate(root->left);
			return rightRotate(root);
		}
		if(v<-1 && comp(element->info,root->right->info)==-1){
			root->right=rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}

//reliza um percuso in_ordem na árvore 
void list_in_ordem(node *root,void (*my_print)(void*)){
	if(root!=NULL){
		if(root->left!=NULL)list_in_ordem(root->left,my_print);
		my_print(root->info);
		if(root->right!=NULL)list_in_ordem(root->right,my_print);
	}else printf("VAZIA\n");
}

//remove um elemento da arvore por fusão
node * remove_by_merging(node *arv, void *key, int (*comp)(void*a, void*b)){
	node *cpy=arv;
	if(cpy!=NULL){
		if(comp(arv->info,key)==0){
				cpy=generic_insert(cpy->left,cpy->right,comp);
				free(arv);
		}
		else if(comp(arv->info,key)==1)cpy->left=remove_by_merging(cpy->left,key,comp);
		else cpy->right=remove_by_merging(cpy->right,key,comp);
	}
	return cpy;
}


//remove um elemento da árvore por cópia
node *remove_by_copy(node* arv, void *key, int (*comp)(void*,void*)){
	if(arv!=NULL){
		if( comp(key,arv->info)==0){
			node *tmp=arv;
			if(arv->right==NULL)arv=arv->left;
			else if(arv->left==NULL)arv=arv->right;
			else {	
				node *prev;
				tmp=arv->left;
				prev=arv;
				while(tmp->right!=NULL){
					prev=tmp;
					tmp=tmp->right;
				}
				arv->info=tmp->info;
				if(prev==arv)prev->left=tmp->left;
				else prev->right=tmp->left;				
			}
			free(tmp);
		}else if( comp(key,arv->info)==1)arv->right=remove_by_copy(arv->right,key,comp);
		else arv->left=remove_by_copy(arv->left,key,comp);
	}
	return arv;
}

//retorna um nível de uma arvore a partir do valor do nível de sua raiz (generica para subarvores)
int get_nivel(node *arv, void *key, int nivel,int (*comp)(void*,void*)){
	if(comp(arv->info,key)==0)return nivel;
	else if(comp(arv->info,key)==1)nivel=MAX(nivel,get_nivel(arv->left,key,nivel+1,comp));
	else nivel=MAX(nivel,get_nivel(arv->right,key,nivel+1,comp));
}

int get_altura(node *arv){
	int altura=0;
	if(arv!=NULL){
		if(arv->left!=NULL)altura=MAX(altura,get_altura(arv->left));
		if(arv->right!=NULL)altura=MAX(altura,get_altura(arv->right));
	}else return 0;
	return altura+1;
}


//balanceamento de vetor ordenado (ainda não funcional)
node* balance_vet(void* matriz[], int first, int last, int (*comp)(void*,void*)){
	node *cpy=NULL;
	int mid=(first+last)/2;
	printf("Você é um BOSTA\n");
	while(first<=last){
		cpy=generic_insert(cpy,novo(matriz[mid]),comp);
		cpy->left=balance_vet(matriz,first,mid-1,comp);
		cpy->right=balance_vet(matriz,mid+1,last,comp);
	}
	return cpy;
}


/* FIM DAS FUNÇÕES RECURSIVAS */

/* IMPLEMENTAÇÃO DAS FUNÇÕES INTERATIVAS */

//mostra em forma de pirâmide a arvores (funcional)
void busca_por_largura(node *arv, void (*p)(void*), int (*comp)(void*,void*)){
	int inicio=0, fim=0, nivel=0, tmp, i;

	node *fila[N];
	fila[fim++]=arv;

	while(inicio!=fim){
		if(fila[inicio]->left!=NULL)fila[fim++]=fila[inicio]->left;
		if(fila[inicio]->right!=NULL)fila[fim++]=fila[inicio]->right;
		if((tmp=get_nivel(arv,fila[inicio]->info,0,comp))!=nivel){
			printf("\n");
			nivel=tmp;
		}
		p(fila[inicio++]->info);
	}
}

node* rightRotate(node *y){
	node *x=y->left;
	node *t2=x->right;
	x->right=y;
	y->left=t2;
	return x;
}

node* leftRotate(node *x){
	node *y=x->right;
	node *t2=y->left;
	y->left=x;
	x->right=t2;
	return y;
}


#endif
