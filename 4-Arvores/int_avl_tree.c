#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a>b)? a : b )

typedef struct Node {
	int value;
	int h;
	struct Node *left, *right;
}node;

node *novo(int value){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->h=0;
	tmp->value=value;
	tmp->left=tmp->right=NULL;
	return tmp;
}

void altura(node *root){
	int a=  ((root->right!=NULL)? root->right->h+1 : 0);
	int b =((root->left!=NULL)? root->left->h+1: 0 );
	root->h= MAX(a,b);
}

node *left_r(node *a){
	node *b=a->right;
	node *tmp = b->left;
	a->right=tmp;
	b->left=a;
	altura(a);
	altura(b);
	return b;
}

node *right_r(node *a){
	node *b= a->left;
	node *tmp = b->right;
	b->right=a;
	a->left=tmp;
	altura(a);
	altura(b);
	return b;
}

node *insert(node *root, node *element){
	if(root==NULL)return element;
	else {
		if(element->value > root->value)root->right=insert(root->right,element);
		else root->left=insert(root->left,element);
		altura(root);
		int v = ((root->right==NULL)? -1 : root->right->h) - ((root->left==NULL)?-1 : root->left->h);
		if(v>1 && element->value > root->right->value) return left_r(root);
		if(v<-1 && element->value < root->left->value) return right_r(root);
		if(v>1 && element->value < root->right->value){
			root->right=right_r(root->right);
			return left_r(root);
		}
		if(v<-1 && element->value > root->left->value){
			root->left=left_r(root->left);
			return right_r(root);
		}
	}
	return root;
}

node *remove_by_copy(node *root, int value){
	node *cpy;
	if(root!=NULL){
		if(root->value==value){
			if(root->left==NULL)root=root->right;
			else if(root->right==NULL)root=root->left;
			else{
				cpy=root->left;
				node  *prev=root;
				while(cpy->right!=NULL){
					prev=cpy;
					cpy=cpy->right;
				}
				root->value=cpy->value;
				if(prev==root)prev->left=cpy->left;
				else prev->right=cpy->left;
				
			}
			free(cpy);
		}else if(value > root->value)root->right=remove_by_copy(root->right,value);	
		else root->left=remove_by_copy(root->left,value);
	}
	return root;
}

void listar(node *root){
	if(root==NULL)printf("Base vazia\n");
	else{
		if(root->left!=NULL)listar(root->left);
		printf("[%d,%d]", root->value, root->h);
		if(root->right!=NULL)listar(root->right);
	}
}

int main(){
	int i;
	int vet[]={1,2,3,4,5};
	node *map =NULL;

	for(i = 0; i<5; ++i){
		listar(map);
		printf("\n");
		map=insert(map,novo(vet[i]));
	}

 return 0;
}
