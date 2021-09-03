#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Construa uma função que receba por parâmetro 2 listas ligadas e retorne uma lista ligada com a junção
// das duas listas. Na função principal, leia 5 números e inclua na primeira lista e + 5 números e inclua
// na segunda lista. Utilizando a função criada, mostre o conteúdo de uma terceira lista contendo os valores das 
// 2 listas iniciais.

//structs//
typedef struct lista_do_felippe
{                   
  struct registro *inicio;                //ponteiro inicial para poder percorrer a lista
}lista_do_felippe;

typedef struct registro
{   
  int valor;
  struct registro *proximo;               //armazena o endereço de uma struct tipo 'registro' 
}registro;

//declarando as funcoes
lista_do_felippe *aloca_lista(); 
registro *aloca_registro();
void incluir_na_lista(lista_do_felippe *lista, int x);
void Ler_e_consultar_numeros(lista_do_felippe *l1);
void soma_listas(lista_do_felippe *l1, lista_do_felippe *l2);


////MAIN////MAIN////MAIN////MAIN////
int main(){

  lista_do_felippe *l1, *l2;              
  l1=aloca_lista(); 
  l2=aloca_lista();                      //aloca_lista retorna os endereços disponíveis para atribuir os dados

  printf("Digite os 5 valores na lista 1: \n");
  for(int i = 0; i<5; i++){
    int x=0;
    scanf("%i", &x);
    incluir_na_lista(l1,x);
  }

  printf("Digite os 5 valores na lista 2: \n");
  for(int i = 0; i<5; i++){
    int x=0;
    scanf("%i", &x);
    incluir_na_lista(l1,x);
  }
  
  soma_listas(l1,l2);
  
  return 0;
}



/////////funções///////////

lista_do_felippe *aloca_lista()             //função para poder alocar uma nova lista sempre que chamar
{
  lista_do_felippe *novo;         
  novo = (lista_do_felippe*)malloc(sizeof(lista_do_felippe));
  return novo;                            //retorna os endereços liberados pelo calloc
}

registro *aloca_registro()
{
  registro *novo;
  novo = (registro*)malloc(sizeof(registro));
  return novo;
}

void soma_listas(lista_do_felippe *l1, lista_do_felippe *l2){

  lista_do_felippe *l3;
  l3=aloca_lista();

  int x;

  registro *aux;

  aux = l1->inicio;

  while (aux != NULL) //inclui os valores da lista 1
  {
    x=aux->valor;
    incluir_na_lista(l3, x);
    aux = aux->proximo;
  }

  aux = l2->inicio;

  while (aux != NULL) //inclui os valores da lista 1
  {
    x=aux->valor;
    incluir_na_lista(l3, x);
    aux = aux->proximo;
  }

  aux = l3->inicio;
  printf("Mostrando lista 3, a soma da lista 1 e 2: \n");
  while (aux != NULL)
  {
    printf(" (%i)", aux->valor);
    aux = aux->proximo;
  }


}

//

void incluir_na_lista(lista_do_felippe *lista, int x) 
{
  registro *novo;                         //ponteiro pq vai receber os endereços do aloca registro?
  registro *aux;                          //ponteiro pq recebe o endereço do inicio da lista e do proximo
  novo = aloca_registro();
  novo->valor = x;                        //add o valor que o usuário queria no registro 'novo'

  if (lista->inicio==NULL)                //se estiver vazia
  {
    lista->inicio = novo;               //fazer o registro 'novo' ser o primeiro da lista
  }
  else
  {
    aux = lista->inicio;                //aux, oq se for a lista normal vai dar merda
    while(aux->proximo!=NULL)           //percorre a lista até achar o fim para incluir o novo valor
    {
      aux = aux->proximo;             //lista->inicio->proximo
    }

    aux->proximo = novo;                //aux é o atual fim lista, faz o registro 'novo' ser o novo fim.
    }
}
