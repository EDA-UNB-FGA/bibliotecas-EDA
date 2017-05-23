#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101

int main(){
	 /*vale lembrar que esse algoritmo tem muitas falhas, so resolve o caso onde a equação
	 tem parenteses ao redor de toda a expressão e os números no cálculo tiverem apenas um dígito
	*/

	char string[N];
	char pilha[N],posfixa[N];
	int tampi=0, tampos=0,i;

	scanf("%[^\n]s", string);

	//para calcular expressões vamos transfomar a equação na notação polonesa e depois usar as filas para calcular o valor da expressão

	//transformando em notação posfixa
	for(i=0; string[i]!='\0'; ++i){
		switch(string[i]){
		case '(':
			pilha[tampi++]=string[i]; //adiciona todos os '('
		 break;
		case ')':
			while(pilha[--tampi]!='(')posfixa[tampos++]=pilha[tampi]; // quando encontrar um ')' desempilha até o '(' 
										  //(ordem de precedencia)
		 break;
		case '+':
		case '-':
			while(pilha[tampi-1]!='(')posfixa[tampos++]=pilha[--tampi]; //quando encontrar um '+' ou um '-'
			pilha[tampi++]=string[i];				    //desempilhe até o '('
		 break;
		case '/':
		case '*':
			while(pilha[tampi-1]!='+' && pilha[tampi-1]!='-' && pilha[tampi-1]!='(')posfixa[tampos++]=pilha[--tampi];
			pilha[tampi++]=string[i];
			/*a precedência do '*' e '/' é maior que a '+' e '-' portanto quando encontrarmos eles
			devemos para de desempilhar
			*/
		 break;
		default : posfixa[tampos++]=string[i]; //adiciona os digitos 
		}
	}
	posfixa[tampos]='\0'; //colocando o terminado na string
	printf("%s\n", posfixa);

	/*
		passamos na posfixa até encontrarmos uma operação,
		caso encontre operamos os 2 primeiros elementos da pilha 
		e retornamos o resultado
	*/

	int conta[N];
	tampi=0;
	//calculando resultado
	int a,b;
	for(i=0; posfixa[i]!='\0'; ++i){
		switch(posfixa[i]){
		case '+':
			tampi--;
			a = conta[tampi-1];
			b = conta[tampi];
			conta[tampi-1]=a+b;
		 break;
		case '-':
			tampi--;
			a = conta[tampi-1];
			b = conta[tampi];
			conta[tampi-1]=a-b;
		 break;
		case '/':
			tampi--;
			a = conta[tampi-1];
			b = conta[tampi];
			conta[tampi-1]=a/b;
		 break;
		case '*':
			tampi--;
			a = conta[tampi-1];
			b = conta[tampi];
			conta[tampi-1]=a*b;
		 break;
		default : conta[tampi++]=(int)(posfixa[i]-'0');
		}
	}

	printf("%d\n", conta[0]);
 return 0;
}
