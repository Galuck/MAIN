//descubra se é arvore
/* CONDIÇÕES PARA SER ÁRVCORE
1: vertice= aresta +1
2: não podem existir ciclos (backedge)*/

#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
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

registro *inicializa_registro(){

    registro *novo;
    novo=(registro*)calloc(1,sizeof(registro));

    return novo;
}

lista *inicializa_lista(){

    lista *novo;
    novo=(lista*)calloc(1,sizeof(lista));
}

void insere_lista(lista *lista_inserir, int valor){

    registro * novoRegistro= inicializa_registro();
    novoRegistro->valor= valor;

    if(lista_inserir->inicio ==NULL){
        lista_inserir->inicio= novoRegistro;
        lista_inserir->tamanho++;
        return;
    }

    registro *aux= lista_inserir->inicio;

    while(aux->proximo!= NULL)
    {
        aux= aux->proximo;
    }

    aux->proximo= novoRegistro;
    lista_inserir->tamanho++;
}

void push(vertice *v, int valor){

    if(v->lista_adj==NULL){
        v->lista_adj= inicializa_lista();
    }
    insere_lista(v->lista_adj, valor);
}

void dfs(vertice *v, int x, int anterior, int*ciclo){

    registro *aux= v[x].lista_adj->inicio;
    v[x].visitado=1;

    if(v[x].lista_adj==NULL)
    {
        return;
    }

    while(aux!=NULL)
    {
        if(v[aux->valor].visitado == 0)
        {
            dfs(v, aux->valor,x, ciclo);
        }
        else if(aux->valor !=anterior){
            *ciclo =1;
        }
        aux= aux->proximo;
    }
}

int main(){
    int qtd_arestas; 
    int qtd_vertices;
    int a, b;
    int ciclo=0;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    if(qtd_vertices != qtd_arestas +1){
        printf("NAO E ARVORE\n");
    }

    vertice *v=(vertice*)calloc(qtd_vertices +1,sizeof(vertice));

    for(int i=0; i<qtd_arestas; i++){

        scanf("%d %d", &a, &b);
        v[a].visitado=0;
        v[b].visitado=0;
        push(&v[a],b);
        push(&v[b],a);
    }

    //-1= vertice anterior
    dfs(v, a, -1, &ciclo);

    for(int i=1; i<= qtd_vertices; i++){

        if(v[i].visitado==0){
            printf("NAO E ARVORE\n");
            return 0;
        }
    }

    if(ciclo){
        printf("NAO E ARVORE\n");
    }
    else{
        printf("E ARVORE\n");
    }
    return 0;
}