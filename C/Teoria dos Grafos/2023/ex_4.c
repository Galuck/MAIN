//SAIDA DE INCENDIO

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

lista *inicia_lista(){

    lista *novo;
    novo=(lista*)calloc(1,sizeof(lista));
}

registro *inicia_registro(){

    registro *novo;
    novo=(registro*)calloc(1,sizeof(registro));
}

void add_lista(lista *lista_insere, int valor_inserido){

    registro * novoRegistro= inicia_registro();
    novoRegistro->valor= valor_inserido;
    novoRegistro->proximo= NULL;

    if(lista_insere->inicio == NULL){
        lista_insere->inicio= novoRegistro;
        lista_insere->tamanho++;
        return;
    }
    
    registro * aux= lista_insere->inicio;

    while(aux->proximo != NULL)
    {
        aux= aux->proximo;
    }

    aux->proximo= novoRegistro;
    lista_insere->tamanho++;
}

void push(lista *lista_adjascente, int valor){

    add_lista(lista_adjascente,valor);
}

void dfs(vertice *vertices, int inicio, int *qtd_elementos){

    if(vertices[inicio].visitado == 0){

        (*qtd_elementos)++;

        vertices[inicio].visitado=1;

        registro *aux= vertices[inicio].lista_adj->inicio;

        while(aux!= NULL){
            dfs(vertices, aux->valor, qtd_elementos);
            aux= aux->proximo;
        }
    }
}

int main(){

    int qtd_arestas, qtd_vertices;
    int a, b; 
    int qtd_casos=0;
    vertice *v;

    scanf("%d", &qtd_casos);

    while(qtd_casos--){

        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        v=(vertice*)calloc(qtd_vertices+1, sizeof(vertice));

        for(int i=1; i<=qtd_vertices; i++){

            v[i].lista_adj= inicia_lista();
            v[i].visitado=0;
        }

        for( int i=0; i<qtd_arestas; i++){

            scanf("%d %d", &a, &b);
            push(v[a].lista_adj,b);
            push(v[b].lista_adj,a);
        }

        int saidas=0;
        int qtd_elementos=0;
        int capitao=1;

        for(int i=1; i<=qtd_vertices;i++ ){

            if(v[i].visitado == 0){

                dfs(v,i,&qtd_elementos);
                capitao *=qtd_elementos;
                saidas++;
            }
            qtd_elementos=0;
        }
        printf("saidas: %d capitaes: %d \n", saidas, capitao);
    }
    return 0;
}