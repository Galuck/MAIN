// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

// Input:
// First line contains T. T testcases follow.
// First line of each test case contains two space-separated integers N, M.
// Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

// Output:
// Print the answer to each test case in a new line.

// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 104
// 1 ≤ M ≤ 105
// 1 ≤ X, Y ≤ N

#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int distancia;
    struct lista *lista_adj;

} vertice;

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *ultimo;

} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;

} registro;

registro *aloca_registro();
lista *aloca_lista();
int incluir_lista(lista *l, int x);
void push(vertice *v, int x);
int dfs(vertice * vertices , int raiz, int );
void liberarGrafo(vertice *vertices, int numVertices);

int main()/////////////GABRIEL MAY PROCHNOW//2122082032
{

    vertice *vertices;
    int qtd_vertices;
    int qtd_arestas;
    int casos_de_teste=0;
    int counter=0;

    vertices = (vertice *)calloc(2001, sizeof(vertice));


    //printf("\nDigite a quantidade de Casos de Teste:\n");
    scanf("%d", &casos_de_teste);

    //printf("\nDigite a quantidade de Vertices e Arestas:\n");
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    while(casos_de_teste!=0){

        for(int i=1;i<=qtd_arestas;i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            push(&vertices[a], b);
            push(&vertices[b], a);
            
        }

        counter++;

        printf("Scenario #%d:\n",counter);
        
        for(int i=1;i<=qtd_vertices;i++){//percorrer o vetor de vertices mudando a raiz toda vez para ter certeza que não falta nenhum vértice
            if(dfs(vertices,i,1)==1){
                printf("Suspicious bugs found!\n");
                break;
            }else{
                printf("No suspicious bugs found!\n");
                break;
            }
            //ex: Vermelho: 1
            //    Azul: -1
        }

        casos_de_teste--;

        // Libere a memória alocada para o grafo antes de alocar novamente para o próximo caso de teste
        liberarGrafo(vertices, qtd_vertices);

        if (casos_de_teste > 0) {
            // Alocar memória novamente para o próximo caso de teste
            vertices = (vertice *)calloc(2001, sizeof(vertice));
            scanf("%d %d", &qtd_vertices, &qtd_arestas);
        }


        bfs(vertices, 6);

    for(i=1;i<=qtd_vertices;i++)
    {
        printf("\n Distancia do vertice %d para a raiz %d = %d",i,raiz,vertices[i].distancia);
    }

    }

    printf("\n");
    return 0;
}

void push(vertice *v, int x)
{
    if (v->lista_adj == NULL){
        v->lista_adj = aloca_lista();
    }
    incluir_lista(v->lista_adj, x);
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

///bipartido (dfs vai ser do tipo int para poder retornar 0 ou 1, poderia ser bool tbm, mas fodase)
int dfs(vertice * vertices , int raiz, int cor)
{
    registro * aux;
    vertices[raiz].visitado=1;//marca como visitado
    vertices[raiz].cor=cor;//a cor q eu muitipliquei por -1 na chamada da função vai ser a noca cor do vértice, tipo:
    //ex: Vermelho: 1
    //    Azul: -1

    if (vertices[raiz].lista_adj==NULL){//lista vazia
        return 0;
    } 
    aux = vertices[raiz].lista_adj->inicio;//inicio da lista de adjacência do vértice sendo visitado

    while(aux!=NULL)//percorrendo a lista de adjacência
    {
        if (vertices[aux->valor].visitado==0)//se o vértice ainda não foi visitado, vai pra lista de adjacência dele numa pilha de recursividade
        {
            dfs(vertices,aux->valor,cor*-1);//multiplicar por -1 para mudar a cor
            //isso aqui vai criar uma pilha de recursividadde, e vai voltar a recursividade um por um

        }else if(vertices[aux->valor].visitado==1 && vertices[aux->valor].cor==vertices[raiz].cor){//se o vértice já foi visitado e a cor dele é igual a cor do vértice pai, o grafo n é bipartido
            //printf("Suspicious bugs found!");
            return 1;
        }
        aux = aux->prox;//vai para o próximo vértice da lista de adjacência
    }

    return 0;
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


///s, essa função é tua, ainda tenho q estudar melhor ela kkkk
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

//

void insert_queue(lista *f, int x)
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    novo->valor = x;

    if (f->tam == 0)
    {
        f->inicio = novo;
        f->ultimo = novo;
    }
    else
    {
        f->ultimo->prox = novo;
        f->ultimo = novo;
    }
    f->tam++;
}

int pop_queue(lista *f)
{
    if (is_empty(f))
    {
        return -1;
    }
    else
    {
        int retorno;
        retorno = f->inicio->valor;
        f->inicio = f->inicio->prox;
        f->tam--;
        return retorno;
    }
}

int is_empty(lista *f)
{
    if (f->tam == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void bfs(vertice *vertices, int raiz)
{
    lista *f;
    f = calloc(1, sizeof(lista));
    int current;
    int i, filho;

    insert_queue(f, raiz);

    while (!is_empty(f))
    {
        current = pop_queue(f);
        if (vertices[current].visitado == 0)
        {
            printf(" %d", current);
        }
        vertices[current].visitado = 1;
        for (i = 0; i < vertices[current].tam_lista_adj; i++)
        {
            filho = vertices[current].lista_adj[i];
            if (vertices[filho].visitado == 0)
            {
                vertices[filho].distancia = vertices[current].distancia + 1;
                insert_queue(f, filho);
            }
        }
    }
}