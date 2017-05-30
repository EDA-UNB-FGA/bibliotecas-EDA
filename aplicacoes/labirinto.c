#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <time.h> 
#define MAX 100 // capacidade de armazenamento da pilha e da fila 
typedef int titem; // tipo dos itens armazenados na pilha e na fila 
#define N 22 // tamanho da matriz que representa o labirinto 
#define LIVRE 0 // marca de posicao livre no labirinto 
#define PAREDE 32767 // marca de posicao com parede no labirinto 

/*struct do para o vetor*/

/*Felipe Borges de Souza Chaves - 160049733*/
typedef struct Ponto{
	int x,y;
}ponto;



void cria(int L[N][N]) { // funcao para criacao de um labirinto 
	int i, j; 
	for(i=0; i<N; i++) { 
		L[i][0] = PAREDE; 
		L[i][N-1] = PAREDE; 
	} 
	for(j=0; j<N; j++) { 
		L[0][j] = PAREDE; 
		L[N-1][j] = PAREDE; 
	}
	
	for(i=1; i<N-1; i++) 
		for(j=1; j<N-1; j++) 
			if( rand()%3==0 ) L[i][j] = PAREDE; 
			else L[i][j] = LIVRE; 
	L[1][1] = LIVRE; 
	L[N-2][N-2] = LIVRE;
} /* fim-cria */

void exibe(int[][N]);

//Adicione aqui o codigo da função anota() - exercício 2 
void anota(int mapa[][N]){
	ponto fila[1000];
	int  inicio=0,fim=0;
	mapa[1][1]=1;///set a solução
	fila[inicio].x=1;
	fila[fim++].y=1;
	while(inicio!=fim){
		ponto tmp = fila[inicio++]; //remove passo 3.1
		if(mapa[tmp.x+1][tmp.y]==0){
			mapa[tmp.x+1][tmp.y]=mapa[tmp.x][tmp.y]+1;
			fila[fim].x=tmp.x+1;
			fila[fim++].y=tmp.y;
		}
		if(mapa[tmp.x-1][tmp.y]==0){
			mapa[tmp.x-1][tmp.y]=mapa[tmp.x][tmp.y]+1;;
			fila[fim].x=tmp.x-1;
			fila[fim++].y=tmp.y;
		}
		if(mapa[tmp.x][tmp.y+1]==0){
			mapa[tmp.x][tmp.y+1]=mapa[tmp.x][tmp.y]+1;
			fila[fim].x=tmp.x;
			fila[fim++].y=tmp.y+1;
		}
		if(mapa[tmp.x][tmp.y-1]==0){
			mapa[tmp.x][tmp.y-1]=mapa[tmp.x][tmp.y]+1;
			fila[fim].x=tmp.x;
			fila[fim++].y=tmp.y-1;
		}
	}
}


void exibe(int L[N][N]) { // funcao para exibicao de um labirinto 
	int i, j; 
	for(i=0; i<N; i++) { 
		for(j=0; j<N; j++) 
			switch( L[i][j] ) { 
				case LIVRE : printf(" "); break; 
				case PAREDE: printf("#"); break; 
				case 67 : printf("x"); break;
				default : putchar(126); 
			} 
		printf("\n"); 
	} 
} 
//Adicione aqui o codigo da função extrai() - exercício 3

void extrai(int map[][N]){
	if(map[N-2][N-2]==0)printf("Não tem solução\n");
	else{
		printf("Existe solução\n");
		int solucao[N][N],sol,tam=0;
		ponto pilha[1000];
		ponto tmp;
		tmp.x=N-2; tmp.y=N-2;
		pilha[tam++]=tmp; //adicionado o primeiro elemento
		memset(solucao,0,sizeof(solucao));
	
		while(!(tmp.x==1 && tmp.y==1)){
			tmp=pilha[tam-1]; //acessando o topo; //passo 4.1
			sol= map[tmp.x][tmp.y] - 1; //pegando o valor -1
			if(map[tmp.x+1][tmp.y]==sol){
				pilha[tam].x=tmp.x+1;
				pilha[tam++].y=tmp.y;
				continue;
			}else if(map[tmp.x-1][tmp.y]==sol){
				pilha[tam].x=tmp.x-1;
				pilha[tam++].y=tmp.y;
				continue;
			}else if(map[tmp.x][tmp.y+1]==sol){
				pilha[tam].x=tmp.x;
				pilha[tam++].y=tmp.y+1;
				continue;
			}else if(map[tmp.x][tmp.y-1]==sol){
				pilha[tam].x=tmp.x;
				pilha[tam++].y=tmp.y-1;
				continue;
			}
			break;
		}
		while(tam!=0){
			int x,y;
			x=pilha[tam-1].x;
			y=pilha[--tam].y;
			map[x][y]=67;
			
		}
		
	}
}

int main(void) { // Função principal 
	int L[N][N]; 
	char r; 
	srand(time(NULL)); 
	do { 
		cria(L); 
		/* anota(L); */ // retire o comentario na versão final 
		/* extrai(L); */ // retire o comentario na versão final 
		anota(L);
		extrai(L);
		exibe(L); // retire esta chamada na versão final 
		printf("Continua? (s/n) "); 
		scanf("%c%*c",&r); 
	} while( toupper(r)!='N' ); 
	
	return 0; 
} /* fim-main */
