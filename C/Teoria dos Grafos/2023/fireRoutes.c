#include <stdlib.h>
#include <stdio.h>

// Tem 'N' funcionários no prédio, e cada um trabalha numa cabine separada (1 até N)


/////////////////////////////
typedef struct vertice{
    int visitado;
    struct lista *lista_adj;
}vertice;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

typedef struct lista{
    int qtd;
    struct registro *inicio;
}lista;
////////////////////////////Essa é a base de structs



///Declaração de funções 
registro *aloca_registro();
lista *aloca_lista();
int incluir_lista(lista *l, int x);
void push(vertice *v, int x);
void dfs(vertice * vertices , int raiz);
void liberarGrafo(vertice *vertices, int numVertices);
/////////////////////////////////////////////////



int main(){

    vertice *vertices;
    int qtd_vertices;
    int qtd_arestas;
    int casos_de_teste;

    vertices = (vertice *)calloc(2001, sizeof(vertice));///NAO ESQUECER DE ALOCAR OS VERTICES

    printf("\nDigite a quantidade de casos de teste\n");
    scanf("%d", &casos_de_teste);

    while(casos_de_teste!=0){
        printf("\nDigite a quantidade de Vertices e Arestas:\n");
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

        printf("\nDigite as arestas:\n");
        for(int i=1;i<=qtd_arestas;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            push(&vertices[a], b);
            push(&vertices[b], a);
        }

        int componentes_conectados=0;
        
        for(int i=1;i<=qtd_vertices;i++)
        {
            if (vertices[i].visitado ==0)
            {
                componentes_conectados++;
                
                dfs(vertices,i);
            }
        }

        printf("\nTem %d componentes conectados nesse grafo!", componentes_conectados);

        casos_de_teste--;

        // Libere a memória alocada para o grafo antes de alocar novamente para o próximo caso de teste
        liberarGrafo(vertices, qtd_vertices);

        if (casos_de_teste > 0) {
            // Alocar memória novamente para o próximo caso de teste
            vertices = (vertice *)calloc(2001, sizeof(vertice));
            scanf("%d %d", &qtd_vertices, &qtd_arestas);
        }

    }

    
    

    return 0;
}


/////////////////////////////
lista *aloca_lista(){
    lista *novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro(){
    registro *novo = (registro *)malloc(sizeof(registro));
    return novo;
}
///////////////////////////////////////Alocações




///Incluir no grafo
void push(vertice *v, int x)
{
    if (v->lista_adj == NULL){
        v->lista_adj = aloca_lista();
    }
    incluir_lista(v->lista_adj, x);
}

int incluir_lista(lista *l, int x)
{
    if (l == NULL){//lista vazia
        return 0;
    }

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();//calloc neles
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
                if (ant == NULL){
                    l->inicio = novo;
                }
                    
                else{
                    ant->prox = novo;
                }

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


void liberarGrafo(vertice *vertices, int numVertices) {

    for (int i = 1; i <= numVertices; i++) {//percorrer todos os vértices

        lista *listaAdj = vertices[i].lista_adj;//pegar a lista de adjacência do vértice i
        registro *atual = listaAdj->inicio;//pegar o primeiro registro dessa lista de adjacência

        while (atual != NULL) {//percorrer tudo até achar um NULL

            registro *proximo = atual->prox;//percorre
            free(atual);//dar free em todos os registros da lista de adjacência do vértice i
            atual = proximo;

        }
        free(listaAdj);//dar free na lista de adjacência desse vértice do for
    }
    free(vertices);//termina de liberar tudo
}


void dfs(vertice *vertice, int raiz){
    vertice[raiz].visitado = 1;
    //printf("\nVisitando o vertice %d", raiz);

    registro *aux;
    if(vertice[raiz].lista_adj==NULL){
        return;
    }

    aux = vertice[raiz].lista_adj->inicio;//(o inicio é um registro, por isso usamos aux->valor)   
    //aux vai virar o inicio da lista

    while(aux!=NULL){

        if(vertice[aux->valor].visitado==0){
            dfs(vertice,aux->valor);
        }

        aux=aux->prox;//aux vai ir passando de um por um dentro da lista de adjacência

    }
}
