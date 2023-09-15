#include <stdio.h>
#include <stdlib.h>


//
int qtd_global[10001];
int qtd_arestas;

typedef struct lista
{
    int qtd;//quantidade de elementos na lista
    struct registro *inicio;//ponteiro para o inicio da lista
} lista;


typedef struct registro//estrutura pra usar nos Index
{
    int valor;//valor do elemento no vertice
    struct registro *prox;//ponteiro para o proximo elemento
} registro;


typedef struct vertice
{
    int visitado;//verificar se o vertice ja foi visitado
    struct lista *lista_adj;//lista de adjacencia desse vértice em questão. Aqui vai armazenar os outros vértices que ele está ligado
} vertice;






///Funções feitas pelo professor
void mostrar_lista(lista *l);
int incluir_ordenado_lista(lista *l, int x);
registro *aloca_registro();
lista *aloca_lista();
int carrega_grafo(vertice *vertices);
void push(vertice *v, int x);
void mostrar_lista_dos_vertices(vertice *v, int tam);




void dfs(vertice * vertices , int x);

//declaração das funções




int main (int *argc, char *argv[]){

    int cc=0;

    printf("\n Digite a quantidade de arestas/conexoes: ");
    scanf("%i", &qtd_arestas);

    vertice *vertices;
    vertices = (vertice *)calloc(10000, sizeof(vertice));

    int qtd_vertices; 
    qtd_vertices = carrega_grafo(vertices);

    int x, y;

    for(int i=1;i<=qtd_vertices;i++)
    {
        if (vertices[i].visitado ==0)
        {
            cc++;
            
            dfs(vertices,i);
        }
    }

    printf("\n Quantidade de Componentes Conectados: %d",cc);

    mostrar_lista_dos_vertices(vertices, qtd_arestas);

    // printf("\n Digite as %i conexoes de vertices: ");
    // for(int i=0; i<qtd_arestas; i++){
    //     scanf("%i %i", &x, &y);
        
    //     //add vertice
    //     add_vertice(vertices, x);
    //     qtd_vertices++;


    //     //add vertice
    //     add_vertice(vertices, y);
    //     qtd_vertices++;

    // }

    
    return 0;
}

add_vertice(vertice *vertices, int x){
    //add vertice1
    
    if(vertices->lista_adj == NULL){
        vertices->lista_adj = (lista*)malloc(sizeof(lista));
    }




}


//funções feitas pelo professor
int carrega_grafo(vertice *vertices)
{
    FILE *arq;
    arq = fopen("D:/DOCUMENTOS/FACULDADE/Git/MAIN/C/Teoria dos Grafos/2023/input_grafo.txt", "r");
    int a, b;
    int qtd_vertices=0;

    int i;

    for(i=0;i<10001;i++)
    {
        qtd_global[i] =0;
    }

    if (arq == NULL)
    {
        printf("\n Arquivo nao localizado");
        return 0;
    }

    while (fscanf(arq, "%d;%d\n", &a, &b) != EOF)
    {
        printf("\n A: %d B: %d", a, b);
        qtd_arestas++;

        if (qtd_global[a]==0)
            qtd_vertices++;
            qtd_global[a] = 1;

        if (qtd_global[b]==0)
            qtd_vertices++;
            qtd_global[b] = 1;

        push(&vertices[a], b);
        push(&vertices[b], a);
    }

    return qtd_vertices;
}

void push(vertice *v, int x)
{
    if (v->lista_adj == NULL)
        v->lista_adj = aloca_lista();
    incluir_ordenado_lista(v->lista_adj, x);
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

int incluir_ordenado_lista(lista *l, int x)
{
    if (l == NULL)
        return 0;

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        int inserido = 0;
        aux = l->inicio;
        while (aux != NULL && !inserido)
        {

            if (aux->valor == novo->valor)
            {
                return 0;
            }

            if (aux->valor < novo->valor)
            {
                ant = aux;
                aux = aux->prox;    
            }
            else
            {
                if (ant == NULL)
                    l->inicio = novo;
                else
                    ant->prox = novo;

                novo->prox = aux;
                inserido = 1;
            }
        }
        if (!inserido)
        {
            ant->prox = novo;
            inserido = 1;
        }
    }
    l->qtd++;
    return 1;
}

void mostrar_lista_dos_vertices(vertice *v, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (v[i].lista_adj != NULL)
        {
            printf("\n Lista de Adjacencias do no : %d", i);
            mostrar_lista(v[i].lista_adj);
        }
    }
}

void mostrar_lista(lista *l)
{
    registro *aux;

    if (l == NULL)
    {
        printf("\n Lista nula");
        return;
    }

    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    aux = l->inicio;
    while (aux != NULL)
    {
        printf("\n -> %d", aux->valor);
        aux = aux->prox;
    }
}

//




//MEU dfs padrão
void dfs(vertice * vertices , int x){

    registro *aux;//ponteiro auxiliar para percorrer a lista de adjacencia do vertice x

    vertices[x].visitado = 1;//visitou o vértice

    printf("\nVisitando vertice %i ", x);

    aux = vertices[x].lista_adj->inicio;//aux vira o inicio da lista de adjacencia do vertice x

    if(aux == NULL){//se o inicio da fila for null, a lista está vazia
        printf("\nLista esta vazia");
    }

    while (aux != NULL)//enquanto o valor da lista não for nulo, ou seja, enquanto tiver elementos na lista, vai continuar em loop
    {
        if (vertices[aux->valor].visitado == 0)//se o vértice não foi visitado, vai chamar a função dfs novamente, para visitar ele
        {
            dfs(vertices, aux->valor);//chamando função recursivamente
        }
        aux = aux->prox;//valor de aux recebe o próximo elemento da lista, avançando a lista de adjacencia daquele vértice em questão
    }
}

