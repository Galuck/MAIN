#include <stdio.h>
#include <stdlib.h>

int count=1;
typedef struct elemento
{
  int vertice;
  int distancia;
} elemento;

int qtd_global[10001];
int count_min_heap = 0;
elemento heap[1000];

typedef struct vertice
{
  int visitado;
  int distancia;
  //struct lista *lista_adj;
  int lista_adj[1000];
  int tam_lista_adj;
  int in;
  int lower;
}vertice;

typedef struct lista
{
  int qtd;
  struct registro *inicio;
} lista;

typedef struct registro
{
  int valor;
  int peso;
  struct registro *prox;
} registro;

int main()
{
  vertice *vertices;
  int qtd_vertices;
  int qtd_arestas;
  int a;
  int b;

  vertices = (vertice *)calloc(10001, sizeof(vertice));

  //ler o grafo aqui (antes tava uma porra de ler arquivo)
  printf("\nDigite a quantidade de vertices e arestas:\n");
  scanf("%i %i", &qtd_vertices, &qtd_arestas);


  vertice* vertices= (vertice*)calloc(qtd_vertices+1, sizeof(vertice));
  
  printf("\nDigite as conexoes das arestas:\n");
  for(int i=0;i<qtd_arestas;i++){
    scanf("%i %i", &a, &b);
    vertices[a].lista_adj[vertices[a].tam_lista_adj]=b;
    vertices[a].tam_lista_adj++;
    vertices[b].lista_adj[vertices[b].tam_lista_adj]=a;
    vertices[b].tam_lista_adj++;
  }

  djikstra(vertices,5);

  for(int i=1;i<=qtd_vertices;i++)
  {
      printf("\n Distancia do no Raiz até %d = %d",i,vertices[i].distancia);
  }

  printf("\n");
  return 0;
}

void djikstra(vertice * vertices, int raiz){

  int corrente, distancia_atual;
  elemento elemento_aux;
  registro * aux;
  
  for(int i=0;i<10001;i++){
    vertices[i].distancia = 9999;//inicializar distancias como um número enorme(de preferencia infinito)
  }

  vertices[raiz].distancia =0;
  elemento_aux.distancia = 0;
  elemento_aux.vertice = raiz;
  push_fila(elemento_aux);

  while(!vazio()){
    elemento_aux = pop();
    corrente = elemento_aux.vertice;
    distancia_atual = elemento_aux.distancia;

    if (vertices[corrente].lista_adj== NULL){
      printf("\n Vertice em componente desconetado");
      return;         
    }

    //aux = vertices[corrente].lista_adj->inicio;
    while(aux!=NULL){
      if (distancia_atual + aux->peso < vertices[aux->valor].distancia){

        vertices[aux->valor].distancia = distancia_atual + aux->peso;
        elemento_aux.distancia = vertices[aux->valor].distancia;
        elemento_aux.vertice = aux->valor;
        push_fila(elemento_aux);
      }
      aux = aux->prox;
    }
  }
}

void subir_minimo(int indice)
{

  elemento aux;

  if (indice <= 1){
    return;
  }

  int pai = indice/2;

  if (heap[indice].distancia < heap[pai].distancia)
  {
    aux = heap[indice];
    heap[indice] = heap[pai];
    heap[pai] = aux;
    subir_minimo(pai);
  }
}

void desce_minimo(int indice)
{
  if (indice * 2 > count_min_heap){
    return;
  }

  int esquerda = indice*2;
  int direita = (indice*2)+1;

  int menor = indice;

  if (esquerda <= count_min_heap && heap[esquerda].distancia < heap[menor].distancia){
    menor = esquerda;
  }

  if (direita <= count_min_heap && heap[direita].distancia < heap[menor].distancia){
    menor = direita;
  }

  if (menor == indice){
    return;
  }

  elemento aux;

  aux = heap[indice];
  heap[indice] = heap[menor];
  heap[menor] = aux;
  desce_minimo(menor);
}

int push_fila(elemento x){
  count_min_heap++;
  heap[count_min_heap] = x;
  subir_minimo(count_min_heap);
}

elemento pop(){
  elemento retorno;
  if (count_min_heap == 0){
    retorno.distancia = -1;
    retorno.vertice = -1;
    return retorno;
  }

  retorno = heap[1];
  // printf("\n %d",heap[1]);
  heap[1] = heap[count_min_heap];
  count_min_heap--;
  desce_minimo(1);
  return retorno;
}

int vazio(){
  if (count_min_heap==0){
    return 1;
  }
  else{
    return 0;
  }    
}
int menor(int a, int b){return a<b? a:b;}