// You are given an unweighted, undirected graph. Write a program to check if
// it's a tree topology.

// Input
// The first line of the input file contains two integers N and M --- number of
// nodes and number of edges in the graph (0 < N <= 10000, 0 <= M <= 20000).
// Next M lines contain M edges of that graph --- Each line contains a pair (u,
// v) means there is an edge between node u and node v (1 <= u, v <= N).

// Output
// Print YES if the given graph is a tree, otherwise print NO.

// Example
// Input:
// 3 2
// 1 2
// 2 3

// Output:
// YES
                                                                                                                                                                                                                                         
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
  int visitado;
  int cor;
  struct lista *lista_adj;

} vertice;

typedef struct lista {
  int qtd;
  struct registro *inicio;

} lista;

typedef struct registro {
  int valor;
  struct registro *prox;

} registro;

registro *aloca_registro();
lista *aloca_lista();
int incluir_lista(lista *l, int x);
void push(vertice *v, int x);
int dfs(vertice *vertices, int raiz, int pai);

int main() /////////////GABRIEL MAY PROCHNOW//2122082032
{
  // arestas=vertices-1 (só assim é uma arvore)
  // N e M, Nodes e Edges
  vertice *vertices;
  int qtd_vertices;
  int qtd_arestas;
  vertices = (vertice *)calloc(10001, sizeof(vertice));

  // printf("\nDigite a quantidade de Vertices e Arestas:\n");
  scanf("%d %d", &qtd_vertices, &qtd_arestas);

  for (int i = 1; i <= qtd_arestas; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    push(&vertices[a], b);
    push(&vertices[b], a);
  }

  // for(int i=1;i<=qtd_vertices;i++){//percorrer o vetor de vertices mudando a
  // raiz toda vez para ter certeza que não falta nenhum vértice
  //     dfs(vertices,i,0)
  // }

  int arvore = dfs(vertices, 1, 0);

  if (arvore == 1) {
    printf("\nNao eh uma arvore");
  } else {
    if (qtd_arestas == qtd_vertices - 1) {
      printf("\nYES");
    } else {
      printf("\nNO");
    }
  }

  printf("\n");
  return 0;
}

void push(vertice *v, int x) {
  if (v->lista_adj == NULL) {
    v->lista_adj = aloca_lista();
  }
  incluir_lista(v->lista_adj, x);
}

lista *aloca_lista() {
  lista *novo;
  novo = (lista *)calloc(1, sizeof(lista));
  return novo;
}

registro *aloca_registro() {
  registro *novo;
  novo = (registro *)calloc(1, sizeof(registro));
  return novo;
}

int dfs(vertice *vertices, int raiz, int pai) {
  registro *aux;
  vertices[raiz].visitado = 1; // marca como visitado

  if (vertices[raiz].lista_adj == NULL) { // lista vazia
    return 0;
  }
  aux = vertices[raiz].lista_adj->inicio; // inicio da lista de adjacência do
//                                           vértice sendo visitado

  while (aux != NULL) // percorrendo a lista de adjacência
  {
    if (vertices[aux->valor].visitado == 0) // se o vértice ainda não foi visitado, vai pra lista de adjacência
           // dele numa pilha de recursividade
    {
      dfs(vertices, aux->valor, raiz);
      // isso aqui vai criar uma pilha de recursividadde, e vai voltar a
      // recursividade um por um

    } else if (aux->valor != pai && pai != 0) {
      // printf("Existe ciclo!");
      // printf("\n Back Edge %d -> %d", x, aux->valor);
      return 1;
    }

    //

    aux = aux->prox; // vai para o próximo vértice da lista de adjacência
  }

  return 0;
}

int incluir_lista(lista *l, int x) {
  if (l == NULL) { // lista vazia
    return 0;
  }

  registro *novo, *aux = NULL, *ant = NULL;
  novo = aloca_registro(); // calloc neles
  novo->valor = x;

  if (l->inicio == NULL) {
    l->inicio = novo;
  } else {
    int inserido = 0;
    aux = l->inicio;
    while (aux != NULL && !inserido) {
      if (aux->valor == novo->valor) {
        return 0;
      }

      if (aux->valor < novo->valor) {
        ant = aux;
        aux = aux->prox;
      } else {
        if (ant == NULL) {
          l->inicio = novo;
        }

        else {
          ant->prox = novo;
        }

        novo->prox = aux;
        inserido = 1;
      }
    }
    if (!inserido) {
      ant->prox = novo;
      inserido = 1;
    }
  }
  l->qtd++;
  return 1;
}
