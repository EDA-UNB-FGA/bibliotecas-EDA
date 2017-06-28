#include<stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a>b)? a : b)

typedef struct Node{
	int value;
	int h;
	struct Node *left, *right;
}node;

node *novo(int value){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->value=value;
	tmp->h=0;
	tmp->left=tmp->right=NULL;
	return tmp;
}

void altura(node *root){
	int l = (root->left!=NULL)? root->left->h+1 : 0 ;
	int r = (root->right!=NULL)? root->right->h+1 : 0;
	root->h=MAX(l,r);
}

node *left_rotate(node *a){
	node *b=a->right;
	node *tmp=b->left;
	b->left=a;
	a->right=tmp;
	altura(a);
	altura(b);
	return b;
	
}

node *right_rotate(node *a){
	node *b=a->left;
	node *tmp=b->right;
	b->right=a;
	a->left=tmp;
	altura(a);
	altura(b);
	return b;
}

void listar(node *root){
	if(root==NULL)printf("Base vazia\n");
	else{
		if(root->left!=NULL)listar(root->left);
		printf("[%d-%d]\n", root->value,root->h);
		if(root->right!=NULL)listar(root->right);
	}
}

node *insert( node *root, node *element){
	if(root==NULL)return element;
	else{
		if(element->value > root->value)root->right=insert(root->right,element);
		else root->left=insert(root->left,element);

		int v=((root->right!=NULL)? root->right->h : -1)- ((root->left!=NULL)?root->left->h : -1 );
		altura(root);
		printf("--[%d]--\n", v);
		if(v>1 && root->right->value < element->value)return left_rotate(root);
		if(v<-1 && root->left->value > element->value) return right_rotate(root);

		if(v>1 && root->right->value > element->value){
			root->right=right_rotate(root->right);
			return left_rotate(root);
		}
		if(v<-1 && root->left->value < element->value){
			root->left=left_rotate(root->left);
			return right_rotate(root);
		}
	}
	return root;
}

int main(){

	int i, v[]={1,2,3,4};
	node *mp = NULL;
	for(i=0; i<4; ++i){
		mp=insert(mp,novo(v[i]));
	listar(mp);
	}
	


 return 0;
}


