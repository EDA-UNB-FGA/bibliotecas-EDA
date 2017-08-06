## Alocação Dinâmica de Memória em C


___
**Observação: ** Esse conteúdo apenas vai explicar como fazer alocação dinâmica em C, procure as referências para aprender a parte mais "teórica" do conteúdo.
___

### Biblioteca Padrão
  Em C temos a bibloteca *stdlib* que da suporte para a alocação dinâmica de memória em C. Podemos importar a biblioteca com o código a seguir:

  ```
  #include <stdlib.h> //importação da biblioteca

  /*Resto do Código*/

  int main(){


    return 0;
  }

  ```

Existem algumas funções para alocação de memória nesta bibloteca:
  * malloc
  * calloc
  * realloc
  * free


#### malloc()

A função malloc apenas reserva uma área da memória sem se preocupar com o lixo de memória e retorna um ponteiro (do tipo void) para essa área de memória.

**Assinatura:**
  void* malloc(size_t tamanho);

```
#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
  char nome[31];
  int matricula;
}aluno;

int main(){
  aluno *elemento, *vetor_elemento;

  /*alocando apenas uma variável*/
  elemento=(aluno*) malloc(sizeof (elemento);

  /*alocando um vetor de 10 elementos *;
  vetor_elemento=(aluno*)malloc( sizeof(elemento) *10 );


  return 0;
}

```
#### calloc

Praticamente faz a mesma coisa que a função **malloc** no entanto a função calloc limpa o lixo da memória (seta os valores em 0) e depois retorna o ponteiro para aquela região.

**Assinatura:** void* calloc(size_t numero_membros, size_t tamanho_do_tipo;


```
#include <stdio.h>
#include <stdlib.h> //importa calloc


//Estrutura aluno
typedef Aluno{
  int matricula;
}aluno;

int main(){

  //cria um vetor de alunos do tamanho 6
  aluno* aluno1 = (aluno*) callor(6,sizeof(aluno));


  return 0;
}

```
#### realloc

Como o próprio nome já entrega, **realloc** realoca a memória, essa função é muito usada quando precisamos aumentar o tamanho de um vetor por exemplo. É altamente recomendado que domine ela no estudo de vetor pois irá facilitar muito o seu trabalho.

**Assinatura:** void *realloc(void *ponteiro_atual,size_t novo_tamanho);

```
#include <stdio.h>
#include <stdlib.h>

int main(){

  //aloca um vetor de inteiros com 10 posições
  int *vetor = (int*)malloc(sizeof(int)*10);

  //aumenta o tamano do vetor para 12
  vetor = (int*) realloc(vetor,sizeof(int)*12);

  return 0;
}

```
### free

A função **free()** apenas libera memória para que ela possa ser usada por outros processos na máquina.

**Assinatura:** void free(void* ponteiro);

```
///aproveitando o código da secção do realloc

//limpando o ponteiro 'vetor'
free(vetor);


```



__
#### Apêndice

  * **Operador sizeof() :** O operador sizeof é usado para mostrar quantos *bytes* determinado tipo ou estrutura ocupa.
___
