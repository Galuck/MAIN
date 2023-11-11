#include <stdlib.h>
#include <stdio.h>

//for every escape route, one of the employees using that route needs to be appointed as the fire drill captain (raiz)

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
void dfs(vertice * vertices , int raiz, int *size);
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
        long long capitaes=1;

        for(int i=1;i<=qtd_vertices;i++)
        {
            
            if (vertices[i].visitado ==0)
            {
                int size=0;
                dfs(vertices,i, &size);
                componentes_conectados++;
                capitaes = (capitaes * size) % 1000000007;
            }
            
        }

        printf("\n%d Rotas de incendio, %d Possibilidades de capitao", componentes_conectados, (int)capitaes);

        casos_de_teste--;

        // Libere a memória alocada para o grafo antes de alocar novamente para o próximo caso de teste
        liberarGrafo(vertices, qtd_vertices);

        if (casos_de_teste > 0) {
            // Alocar memória novamente para o próximo caso de teste
            vertices = (vertice *)calloc(10001, sizeof(vertice));
        }

    }

    printf("\n");
    return 0;
}

///////////////////////////////////////Alocações
lista *aloca_lista()
{
    lista *novo = (lista *)calloc(1, sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}
/////////////////////////////////////


///Incluir no grafo
void push(vertice *v, int x)
{
    if (v->lista_adj == NULL){
        v->lista_adj = aloca_lista();
    }
    incluir_lista(v->lista_adj, x);//incluir na lista de 
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
        l->inicio = novo;//se a lista estiver vazia, o inicio vai ser o novo
    }
    else
    {
        int inserido = 0;
        aux = l->inicio;//aux vai virar o inicio da lista para percorrer
        while (aux != NULL && !inserido)//enquanto aux nao for nulo e nao tiver inserido na lista, continua (para poder adicionar no final da lista)
        {
            if (aux->valor == novo->valor)//se o valor que eu quero inserir ja estiver na lista, retorna 0
            {
                return 0;
            }

            if (aux->valor < novo->valor)//se o valor que eu quero inserir for maior que o valor que eu estou olhando, eu vou andar na lista (para deixar em ordem crescente)
            {
                ant = aux;
                aux = aux->prox;
            }
            else
            {
                if (ant == NULL){//se o anterior for nulo, o inicio vai ser o novo valor
                    l->inicio = novo;
                }
                    
                else{//se nao, o anterior vai apontar para o novo valor
                    ant->prox = novo;
                }

                novo->prox = aux;//percorre a lista
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
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i].lista_adj != NULL) {
            registro *atual = vertices[i].lista_adj->inicio;
            while (atual != NULL) {
                registro *proximo = atual->prox;
                free(atual);
                atual = proximo;
            }
            free(vertices[i].lista_adj);
        }
    }
    free(vertices);
}



void dfs(vertice *vertice, int raiz, int *size){
    vertice[raiz].visitado = 1;
    (*size)++;
    //printf("\nVisitando o vertice %d", raiz);

    registro *aux;
    if(vertice[raiz].lista_adj==NULL){
        return;
    }

    aux = vertice[raiz].lista_adj->inicio;//(o inicio é um registro, por isso usamos aux->valor)   
    //aux vai virar o inicio da lista

    while(aux!=NULL){

        if(vertice[aux->valor].visitado==0){
            dfs(vertice,aux->valor,size);
        }

        aux=aux->prox;//aux vai ir passando de um por um dentro da lista de adjacência

    }
}
