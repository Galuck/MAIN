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

typedef struct vertice
{
    int visitado;
    int cor;
    struct lista *lista_adj;
} vertice;

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

int incluir_ordenado_lista(lista *l, int x);
registro *aloca_registro();
lista *aloca_lista();
void push(vertice *v, int x);

int dfs(vertice * vertices , int raiz, int cor);

void reset_dfs(vertice * vertices , int x);


int main()
{

    vertice *vertices;
    int qtd_vertices, qtd_arestas;
    int casos_de_teste=0;

    vertices = (vertice *)calloc(2001, sizeof(vertice));


    //printf("\nDigite a quantidade de Casos de Teste:\n");
    scanf("%d", &casos_de_teste);

    //printf("\nDigite a quantidade de Vertices e Arestas:\n");
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    while(casos_de_teste!=0){

        for(int i=1;i<=qtd_arestas;i++)
        {
            int a, b;
            // printf("\n A: %d B: %d", a, b);
            push(&vertices[a], b);
            push(&vertices[b], a);
            
        }
        
        for(int i=1;i<=qtd_vertices;i++){//percorrer o vetor de vertices mudando a raiz toda vez para ter certeza que não falta nenhum vértice
            if(dfs(vertices,i,1)){
                printf("Suspicious bugs found!");
                break;
            }else{
                printf("No suspicious bugs found!");
                break;
            }
            //ex: Vermelho: 1
            //    Azul: -1
        }

        for(int i=1;i<=qtd_vertices;i++){//percorrer o vetor de vertices mudando a raiz toda vez para ter certeza que não falta nenhum vértice

            reset_dfs(vertices,i);//resetar os valores para fazer outro caso de testes
        }

        printf("\nScenario #%d:\n",casos_de_teste);


        casos_de_teste--;

    }

    printf("\n");
    return 0;
}

void push(vertice *v, int x)
{
    if (v->lista_adj == NULL){
        v->lista_adj = aloca_lista();
    }
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


/////limpar os valores de visitado
void reset_dfs(vertice * vertices , int raiz)
{
    registro * aux;
    vertices[raiz].visitado=0;
    vertices[raiz].cor=0;

    if (vertices[raiz].lista_adj==NULL){
        return;
    }
        
    aux = vertices[raiz].lista_adj->inicio;

    while(aux!=NULL)
    {
        if (vertices[aux->valor].visitado==1)
        {
            reset_dfs(vertices,aux->valor); 
        }
        aux = aux->prox;
    }
}

/////

///bipartido (dfs vai ser do tipo int para poder retornar 0 ou 1)
int dfs(vertice * vertices , int raiz, int cor)
{
    registro * aux;
    vertices[raiz].visitado=1;
    vertices[raiz].cor=cor;

    if (vertices[raiz].lista_adj==NULL){//lista vazia
        return 0;
    } 
    aux = vertices[raiz].lista_adj->inicio;//inicio da lista de adjacência do vértice sendo visitado

    while(aux!=NULL)//percorrendo a lista de adjacência
    {
        if (vertices[aux->valor].visitado==0)
        {
            dfs(vertices,aux->valor,cor*-1);//multiplicar por -1 para mudar a cor
            //isso aqui vai criar uma pilha de recursividadde, e vai voltar a recursividade um por um

        }else if(vertices[aux->valor].visitado==1 && vertices[aux->valor].cor==vertices[raiz].cor){//se o vértice já foi visitado e a cor dele é igual a cor do vértice pai, o grafo n é bipartido
            //printf("Suspicious bugs found!");
            return 1;
        }
        aux = aux->prox;//vai para o próximo vértice da lista de adjacência
    }

    //printf("No suspicious bugs found!");
    return 0;
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
