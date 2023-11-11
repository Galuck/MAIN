//exercicio besouro gay

#include <stdio.h>
#include <stdlib.h>

//cor só é necessário em grafo bipartido
typedef struct vertice{
int visitado;
int cor;
struct lista *lista_adj;
}vertice;

typedef struct lista{
int tamanho;
struct registro *inicio;
}lista;

typedef struct registro{
int valor;
struct registro *proximo;
}registro;

lista *inicializa_lista(){
  lista *nova_lista=(lista *)calloc(1,sizeof(lista));
  nova_lista->tamanho=0;
  return nova_lista;
}

registro *inicializa_registro(){
  registro *novo_registro=(registro *)calloc(1,sizeof(registro));
  return novo_registro;
}

void inserir_lista(lista *minha_lista,int valor){

  registro *novo_registro= inicializa_registro();

  novo_registro->valor=valor;
  novo_registro->proximo=NULL;

  if(minha_lista->inicio==NULL)
  {
    minha_lista->inicio=novo_registro;
    minha_lista->tamanho++;
    return;
  }
  
  registro *aux=minha_lista->inicio;

  while(aux->proximo!=NULL){
    aux= aux->proximo;
  }
  aux->proximo=novo_registro;
  minha_lista->tamanho++;
}

void mostra(vertice *vertice){
registro *aux;
aux=vertice->lista_adj->inicio;

while(aux!=NULL){

    printf("%d",aux->valor);
    aux= aux->proximo;
}
printf("\n");
}

void add_lista(vertice *vertice,int valor){
    if(vertice->lista_adj==NULL){
        vertice->lista_adj=inicializa_lista();
    }
    inserir_lista(vertice->lista_adj,valor);
}

int dfs(vertice *lista_vertices, int raiz, int cor){

    registro *aux;
    aux=lista_vertices[raiz].lista_adj->inicio;
    lista_vertices[raiz].cor=cor;
    lista_vertices[raiz].visitado=1;

    while (aux != NULL){
        if(lista_vertices[aux->valor].visitado==0)
        {
            if(!dfs(lista_vertices,aux->valor,lista_vertices[raiz].cor * -1))
            {
                return 0;
            }
        }
        else
        {
            if(lista_vertices[aux->valor].cor==lista_vertices[raiz].cor){
                return 0;
            }
        }
        aux=aux->proximo;
    }
    return 1;
}

int main() {
  int qtd_casos;
  scanf("%d", &qtd_casos);

  while(qtd_casos--){

    int qtd_vertices;
    int qtd_arestas;
    int a, b;
    int flag= 0;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    vertice *vertices= (vertice *)calloc(qtd_vertices+1, sizeof(vertice));

    for(int i=0; i<qtd_arestas;i++){
        scanf("%d %d", &a, &b);
        add_lista(&vertices[a], b);
        add_lista(&vertices[b], a);
    }

    for(int i=1;i<=qtd_vertices;i++)
    {

        if(vertices[i].visitado==0)
        {
            if(!dfs(vertices,i,1))
            {
                flag=1;
            }
        }
     }

  //printf("%d",flag);
  if(flag)
        printf("inseto gay\n");
  else
        printf("apenas insetos heteronormativos\n");
    }
return 0;
}