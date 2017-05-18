#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
	char info;
	struct Node *prox, *prev;
}node;

node *makeNode(char info){
	node *tmp=(node*)malloc(sizeof(node));
	tmp->info=info;
	tmp->prox=tmp->prev=NULL;
	return tmp;
	
}

node *push(node *topo, node *input){
	input->prox=topo;
	if(topo!=NULL)input->prox->prev=input;
	return input;
}

node *pop(node *topo){

	if(topo!=NULL){
	node *cpy=topo;
	topo=topo->prox;
	free(cpy);
	return topo;
	}else return NULL;
}

void listar(node *topo){
	node *cpy=topo;
	if(cpy!=NULL)
	while(cpy!=NULL){
		printf("%c", cpy->info);
		cpy=cpy->prox;
	}
	printf("\n");
}

char *vetorLista(node *list){
	node *cpy=list;
	int tam=0;
	char *name =(char*)malloc(sizeof(char)*400);
	while(cpy->prox!=NULL)cpy=cpy->prox;
	while(cpy!=NULL){
		name[tam++]=cpy->info;
		cpy=cpy->prev;
	}
	name[tam++]='\0';
	return name;
}

int processando_string(char * in){
	int tam = strlen(in),i,tnum=0;
	int numbers[100],a,b;
	

	for(i=0; i<tam; ++i){
		switch(in[i]){
			case '+':	
				a=numbers[tnum-1];
				b=numbers[tnum-2];
				numbers[tnum-2]=(b+a);
				 --tnum;
			break;
			case '-':
				a=numbers[tnum-1];
				b=numbers[tnum-2];
				 numbers[tnum-2]=b-a;						
				 --tnum;
			break;
			case '/':
				a=numbers[tnum-1];
				b=numbers[tnum-2];
				 numbers[tnum-2]=b/a;
				 --tnum;
			break;
			case '*':
				a=numbers[tnum-1];
				b=numbers[tnum-2];
                                 numbers[tnum-2]=b*a;
				 --tnum;
			break;
			default: numbers[tnum++]=(int)(in[i]-'0');
		}
	}
	
	return numbers[0];
}

int main(){

	node *pilha=NULL, *posfixa=NULL;
	char string[100], *nomes;
	int tam,i;

	scanf("%s", string);
	tam=strlen(string);

	for(i=0; i<tam; i++){
		switch(string[i]){
			case '(':
				pilha=push(pilha,makeNode(string[i]));
			break;
			case ')':
				while(1){
					if(pilha->info=='('){
						pilha=pop(pilha);
						break;
					}
					posfixa=push(posfixa,makeNode(pilha->info));
					pilha=pop(pilha);
				}
			break;
			case '+':
			case '-':
				while(1){
					if(pilha->info=='(')break;
					posfixa=push(posfixa,makeNode(pilha->info));
					pilha=pop(pilha);
				}
				pilha=push(pilha,makeNode(string[i]));
			break;
			case '*':
			case '/':
				while(1){
					if(pilha->info=='(' || pilha->info=='+' || pilha->info=='-')break;
					posfixa=push(posfixa,makeNode(pilha->info));
					pilha=pop(pilha);
				}
				pilha=push(pilha,makeNode(string[i]));	

			break;
			default : posfixa=push(posfixa,makeNode(string[i]));
				
		}

	}
	nomes = vetorLista(posfixa);
	printf("%d\n", processando_string(nomes));
 return 0;
}
