#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a>b)? a : b

typedef struct Node{
	int value;
	int h; //fator de balanceamento
	struct Node *left, *right;
}node;

void altura(node *);

node* right_rotate(node * a){
	node *b=a->left;
	node *tmp = b->right;
	b->right=a;
	a->left=tmp;
	altura(a);
	altura(b);
	return b;
}

void altura(node *root){
	root->h=MAX(((root->left!=NULL)? root->left->h : 0),((root->right!=NULL)? root->right->h : 0));
}

node * left_rotate(node * a){
	node *b= a->right;
	node *tmp = b->left;
	a->right=tmp;
	b->left=a;
	altura(a);
	altura(b);
	return b;
}

node *novo(int v){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->value=v;
	tmp->h=0;
	return tmp;
}

node *arv_insert(node *root, node *element){
	if(root==NULL)return element;
	else{
		
		if(root->value<element->value)root->right=arv_insert(root->right,element);
		else root->left=arv_insert(root->left,element);

		root->h=MAX(((root->left==NULL)? 0 :root->left->h+1),((root->right==NULL)? 0 : root->right->h+1));//nova altura da árvore
		int balance=((root->right==NULL)? -1 :root->right->h)-((root->left==NULL)? -1 : root->left->h);
		
		if(balance>1 && element->value>root->right->value) return left_rotate(root);
		if(balance<-1 && element->value<root->left->value) return right_rotate(root);
		if(balance>1 && element->value < root->left->value){
			root->right=right_rotate(root->right);
			return left_rotate(root);
		}
		if(balance<-1 && element->value > root->right->value){
				root->left=left_rotate(root->left);
				return right_rotate(root);
		}
	}
	return root;
}

void listar(node *root){
	if(root==NULL)printf("Arvore vazia\n");
	else{
		if(root->left!=NULL)listar(root->left);
		printf("[%d] : %d\n", root->value,root->h);
		if(root->right!=NULL)listar(root->right);
	}
}
int main(){

	int vet[]={1,2,3,4};
	int i;
	node *mp = NULL;
	for(i=0; i<4; ++i){
		printf("interação %d\n" ,i);
		mp=arv_insert(mp,novo(vet[i]));
	}
	listar(mp);
	
	
 return 0;
}
