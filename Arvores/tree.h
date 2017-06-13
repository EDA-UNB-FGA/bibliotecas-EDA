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
int get_nivel(node*,void*,int,int (*)(void*,void*));

//funções interativas
void busca_por_largura(node*,void (*)(void*),int (*)(void*,void*));
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

//retorna um nível de uma arvore a partir do valor do nível de sua raiz (generica para subarvores)
int get_nivel(node *arv, void *key, int nivel,int (*comp)(void*,void*)){
	if(comp(arv->info,key)==0)return nivel;
	else if(comp(arv->info,key)==1)nivel=MAX(nivel,get_nivel(arv->left,key,nivel+1,comp));
	else nivel=MAX(nivel,get_nivel(arv->right,key,nivel+1,comp));
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

#endif
