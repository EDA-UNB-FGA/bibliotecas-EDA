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

___
#### Apêndice

  * **Operador sizeof() : ** O operador sizeof é usado para mostrar quantos *bytes* determinado tipo ou estrutura ocupa.
___
