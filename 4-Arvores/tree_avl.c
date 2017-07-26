#include <stdio.h>

typedef struct Node{
	int valor;
	int h;
	struct Node *left, *right;
}node;

node *insert(node *root ,node *element){
	if(root==NULL)return element;
	else {
		if(element->valor > root->valor)root->right=insert(root->right,element);
		else root->left=insert(root->left,element);
		int v = ((root->right==NULL)? -1 : root->right->h)-((root->left==NULL)? -1 : root->left->h);

		if(v>1 && 
	}
}


int main(){

 return 0;
}
