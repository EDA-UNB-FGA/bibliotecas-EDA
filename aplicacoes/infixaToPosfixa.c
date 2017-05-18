#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5000

void debug(char name[], int tam){
	int i;
	for(i=0; i<tam; ++i)printf("%c", name[i]);
	printf("\n");
}


/*Essa questão é simples no entanto os casos podem ser um pouco chatinhos se não prestarmos atenção

Pontuaremos o nescessário para o tratamento de cada caso no switch:

1º se encontrar '(' você simplesmente o empilha
2º se encontrar ')' desempilha-se tudo até o '(' (lembrando que o mesmo não é para ser empilhado)
3º ao encontrar o '+' ou o '-' desempilha tudo até o '(' no entanto dessa vez deixamos ele empilhado (está é a diferença com o passo 2)
4º ao encontrar um '*' ou um '/' desempilhamos tudo até encontrar um '(' (não desempilhamos esse, assim como no passo acima)
   ou até encontramos um + ou -
5º caso encontre uma letra ela é empilhada normalmente



OBS 1 :no passo 3º e 4º talvez não fique explicito mas devemos empilhar o '+' '-' '/' '*' assim que terminamos de desempilhar todo o resto
OBS 2 :o código funciona caso a função esteja com parenteses (f(x)), por isso é melhor que ela sofra um pré tratamento antes de passar 
       pelo cálculo
 */

char * process_string(char *input){
	int tam = strlen(input);
	char *tmp =(char*)malloc(sizeof(char)*(tam+2)); //tam já garante que terá espaço para o '\0' e para os novos 2 caracteres
	tmp[0]='(';
	tam=1; //reaproveitando 
	while(1){
		if(input[tam-1]=='\0'){
			tmp[tam++]=')';
			tmp[tam++]='\0';
			break;
				
		}
		tmp[tam++]=input[tam-2];
	}
	return tmp;	
}

int main(){
	// cont1 para a pilha
	//cont2 para a string posfixa (lembre de colocar o terminador na string)
	char pilha[N], *infixa, posfixa[N],tmp;
	int cont1=0,cont2=0,i,tam;
	infixa=(char*)malloc(sizeof(char)*N);

	scanf("%s", infixa);//leitura da string
	infixa=process_string(infixa);//pré processamento da string (vide observações)

	tam=strlen(infixa);
	printf("infixa : %s\n", infixa);
	for(i=0; i<tam; i++){
		switch(infixa[i]){
			case '(':
				pilha[cont1++]=infixa[i];
			 break;
			case ')':
				while(1){
					if(pilha[--cont1]=='(')break;//verfica se o último elemento é o '(' e desempilha
					posfixa[cont2++]=pilha[cont1]; //adiciona na postixa
				}
			 break;
			case '+':
			case '-': //nesse caso não tiramos o ( 
				while(1){
					if(pilha[cont1-1]=='(')break;
					posfixa[cont2++]=pilha[--cont1];
				}
				pilha[cont1++]=infixa[i];
			 break;
			case '*':
			case '/':
				while(1){
					if(pilha[cont1-1]=='+' || pilha[cont1-1]=='-' || pilha[cont1-1]=='(')break;
					posfixa[cont2++]=pilha[--cont1];
				}
				pilha[cont1++]=infixa[i];	//nesse caso desempilhamos tudo e colocamos o * ou /
			 break;
			default : posfixa[cont2++]=infixa[i];
		}
		
	}
	posfixa[cont2++]='\0';
	printf("Posfixa %s\n", posfixa);

 return 0;
}
