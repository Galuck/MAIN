// Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. 
//In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs.

// Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.

// Input
// The first line of the input contains the number of scenarios. 
//Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. 
//In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.

// Output
// The output for every scenario is a line containing “Scenario #i:”, where i is the number of the scenario starting at 1, followed by one line saying either “No suspicious bugs found!” 
//if the experiment is consistent with his assumption about the bugs’ sexual behavior, or “Suspicious bugs found!” if Professor Hopper’s assumption is definitely wrong.

// Example
// Input:
// 2
// 3 3
// 1 2
// 2 3
// 1 3
// 4 2
// 1 2
// 3 4

// Output:
// Scenario #1:
// Suspicious bugs found!
// Scenario #2:
// No suspicious bugs found!

#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int cor;
    lista *lista_adj;
}vertice;

typedef struct lista{
    int qtd;
    registro *inicio;
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;


//dfs
//incluir na lista
incluir_lista(lista *l, int x);
//'push'
push(vertice *v, int x);
//aloca registro
registro *aloca_registro();
//aloca lista
lista *aloca_lista();  
//liberar grafo


int main(){

    int qtd_vertices, qtd_arestas;
    vertice *vertices = (vertice*)calloc(2001, sizeof(vertice));
    int casos_de_teste=0;
    int counter=0;

    printf("\nDigite a quantidade de casos de teste\n");
    scanf("%d", &casos_de_teste);

    printf("\nDigite a quantidade de vertices e arestas\n");
    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    
    for(int i=1;i<=qtd_arestas;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        push(&vertices[a], b);//adicionar na lista de adjacência do a, o valor b
        push(&vertices[b], a);//adicionar na lista de adjacência do b, o valor a
    }




    return 0;
}

lista *aloca_lista(){
    lista *novo = (lista*)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro(){
    registro *novo = (registro*)calloc(1, sizeof(registro));
    return novo;
}

push(vertice *v, int x){
    if(v->lista_adj == NULL){
        v->lista_adj = aloca_lista();
    }
    incluir_lista(v->lista_adj, x);
}

int incluir_lista(lista *l, int x){
    registro *novo = aloca_registro();
    novo->valor = x;
    novo->prox = NULL;

    if(l->qtd == 0){
        l->inicio = novo;
    }else{
        registro *aux = l->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;

    return 1;
}