

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 49

typedef struct Aluno{///////////FILA ESTÁTICA EM C (a alterar)
  int matricula;
  char nome[50];
  int idade;
}Aluno;

typedef struct Fila{
  int inicio;
  int fim;
  int qtd;//diz o tamanho da fila

  struct Aluno dados[MAX];
}Fila;

//declara funções
Fila *criaFila();
Aluno *alocaAluno(Aluno *aluno);
void adicionarNaFila(Fila *fila, Aluno *alunoNovo);


int main()
{
  //fila estática
  Fila *fila1;
  fila1 = criaFila(fila1);
  
  Aluno *aluno1;
  aluno1=alocaAluno(aluno1);

  adicionarNaFila(fila1, aluno1);

  printf("Nome: %s\n",aluno1->nome);
  printf("%i Anos \n", aluno1->idade);

  
    
  free(fila1);//"destroi" a fila, libera a memória que ela estava utilizando
  //usado na fila estática

  printf("\n");
  return 0;
}


void adicionarNaFila(Fila *fila, Aluno *alunoNovo){

  if (fila->qtd == MAX){//fila está cheia
    printf("Fila cheia");
    return;
  }else{
    fila->dados[fila->qtd] = *alunoNovo;
    fila->qtd += 1;
    alunoNovo->matricula = fila->qtd;//matricula começa do 1 
    //digitar nome, idade e notas do aluno;
    printf("Digite o nome completo do aluno %i\n", alunoNovo->matricula);
    fgets(alunoNovo->nome, 50, stdin); //stdin, le do teclado 
    printf("Digite a idade de %s\n", alunoNovo->nome);
  	scanf("%i", &alunoNovo->idade);
    
    
  }
  printf("\n");
}

void removerDaFila(Fila *fila, Aluno *alunoNovo){
    if(fila->qtd=0){
        printf("Fila vazia, nao tem o que retirar\n");
        return;
    }else{
        fila->inicio++;
    }
}


Fila *criaFila(Fila *fila){
  	//vou fazer em malloc só pq segundo o professor é mais rápido
    fila = (Fila*)malloc(sizeof(struct Fila));
    if (fila != NULL){
      fila->inicio=0;//fazer o papel do calloc
      fila->fim=0;
      fila->qtd=0;
    }
    //pode só usar calloc
    //fila = (Fila*) calloc(sizeof fila);
  return fila;
}

Aluno *alocaAluno(Aluno *aluno){
  aluno = (Aluno*)malloc(sizeof(struct Aluno));
    if (aluno != NULL){
      aluno->matricula=0;
      aluno->idade=0;
    }
  return aluno;
}