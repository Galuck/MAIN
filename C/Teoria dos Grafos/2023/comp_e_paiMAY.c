#include <stdio.h>
#include <stdlib.h>

int qtd_global[10001];

typedef struct lista
{
    int qtd;//quantidade de elementos na lista
    struct registro *inicio;//ponteiro para o inicio da lista
} lista;

typedef struct registro
{
    int valor;//valor do elemento no vertice
    struct registro *prox;//ponteiro para o proximo elemento
} registro;

typedef struct vertice
{
    int visitado;//verificar se o vertice ja foi visitado
    struct lista *lista_adj;//lista de adjacencia desse vértice em questão. Aqui vai armazenar os outros vértices que ele está ligado
} vertice;

//Pelo o que eu entendi até agora, cada lista vai ser formada por vários registros, e cada registro vai conter um vértice e cada vértice vai ter sua própria lista de adjacências.





///Funções feitas pelo professor
void mostrar_lista(lista *l);
int incluir_ordenado_lista(lista *l, int x);
registro *aloca_registro();
lista *aloca_lista();
int carrega_grafo(vertice *vertices, char *nome_do_arquivo);
void push(vertice *v, int x);
void mostrar_lista_dos_vertices(vertice *v, int tam);
void dfs(vertice * vertices , int x);
//declaração das funções





int main (int *argc, char *argv[]){

    int cc=0;
    vertice *vertices;
    int qtd_vertices;    
    printf(" Parametro recebido: %s", argv[1]);








    
    return 0;
}
