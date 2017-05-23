#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	 /*vale lembrar que esse algoritmo tem muitas falhas, so resolve o caso onde a equação
	 tem parenteses ao redor de toda a expressão e os números no cálculo tiverem apenas um dígito
	*/

	char string[101];
	char pilha[100],posfixa[101];
	int tampi=0, tampos=0,i;

	scanf("%[^\n]s", string);

	//para calcular expressões vamos transfomar a equação na notação polonesa e depois usar as filas para calcular o valor da expressão

	//transformando em notação posfixa
	for(i=0; string[i]!='\0'; ++i){
		switch(string[i]){
		case '(':
			pilha[tampi++]=string[i];
		 break;
		case ')':
			while(pilha[--tampi]!='(')posfixa[tampos++]=pilha[tampi];
		 break;
		case '+':
		case '-':
			while(pilha[tampi-1]!='(')posfixa[tampos++]=pilha[--tampi];
			pilha[tampi++]=string[i];
		 break;
		case '/':
		case '*':
			while(pilha[tampi-1]!='+' && pilha[tampi-1]!='-' && pilha[tampi-1]!='(')posfixa[tampos++]=pilha[--tampi];
			pilha[tampi++]=string[i];
		 break;
		default : posfixa[tampos++]=string[i];
		}
	}
	posfixa[tampos]='\0'; //colocando o terminado na string
	printf("%s\n", posfixa);

	int conta[100];
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
