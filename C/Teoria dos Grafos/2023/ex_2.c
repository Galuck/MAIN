#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int distancia;
    struct lista *lista_adj;
}vertice;

typedef struct fila{
    int tam;
    struct registro *inicio;
    struct registro *fim;
}fila;

typedef struct lista{
    int qtd;
    struct registro *inicio;
}lista;

typedef struct registro{
    int valor;
    struct registro *proximo;
}registro;

int bfs(vertice *v, int raiz, int qtd_vertices);
fila *aloca_Fila();
lista *aloca_Lista();
registro *aloca_Registro();
int incluiLista(lista *l, int valor_inserido);
void push(vertice *v, int valor);
void colocaFila(fila *minhaFila, int elemento);
int tiraFila(fila *minhaFila);

int main(){
    int qtd_vertices, qtd_arestas;
    int i, a, b;
    int qtd_casos=0;
    vertice *vertices;

    scanf("%d", &qtd_casos);

    while(qtd_casos--){
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        vertices= (vertice *)calloc(10000, sizeof(vertice));

        for(i=0; i< qtd_arestas; i++){
            scanf("%d %d", &a, &b);
            push(&vertices[a], b);
            push(&vertices[b], a);
        }

        printf("%d \n" , bfs(vertices, 1, qtd_vertices));
    }
    return 0;
}

fila *aloca_Fila(){
    fila *novo;
    novo = (fila *)calloc(1, sizeof(fila));
    return novo;
}

lista *aloca_Lista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_Registro(){
    registro *novo;
    novo = (registro *)calloc(1,sizeof(registro));
    return novo;
}

int incluiLista(lista *l, int valor_inserido){
    registro *novo= aloca_Registro();
    novo->valor= valor_inserido;
    novo->proximo=NULL;

    if(l->inicio==NULL){
        l->inicio=novo;
        l->qtd++;
        return 0;
    }

    registro *aux= l->inicio;

    while(aux->proximo!= NULL){
        aux= aux->proximo;
    }

    aux->proximo=novo;
    l->qtd++;
    return 1;
}

void push(vertice *v, int valor){
    if(v->lista_adj==NULL){
        v->lista_adj= aloca_Lista();
    }
    incluiLista(v->lista_adj, valor);
}

void colocaFila(fila *minhaFila, int elemento){
    registro *novoRegistro= aloca_Registro();
    novoRegistro->valor= elemento;

    if(minhaFila->inicio==NULL){
        minhaFila->inicio=novoRegistro;
        minhaFila->fim=novoRegistro;
        minhaFila->tam++;
        return;
    }

    minhaFila->fim->proximo= novoRegistro;
    minhaFila->fim= novoRegistro;
    minhaFila->tam++;
}

int tiraFila(fila *minhaFila){
    int retorno;
    retorno= minhaFila->inicio->valor;
    minhaFila->inicio=minhaFila->inicio->proximo;
    minhaFila->tam--;

    return retorno;
}

int bfs(vertice *v, int raiz, int qtd_vertices){
    fila *minhaFila= aloca_Fila();
    int current;
    registro *aux;

    for(int i=0; i<qtd_vertices; i++){
        v[i].visitado =0;
        v[i].distancia=-1;
    }

    colocaFila(minhaFila, raiz);
    v[raiz].visitado=1;
    v[raiz].distancia=0;

    while(minhaFila->tam>0){
        current= tiraFila(minhaFila);
        aux= v[current].lista_adj->inicio;

        while(aux!= NULL){
            if(v[aux->valor].visitado==0){
                v[aux->valor].visitado=1;
                colocaFila(minhaFila,aux->valor);
                v[aux->valor].distancia= v[current].distancia + 1;
            }
            aux=aux->proximo;
        }
    }
    return v[qtd_vertices].distancia;
}
