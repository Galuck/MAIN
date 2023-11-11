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

registro *aloca_registro();
lista *aloca_lista();
int incluir_lista(lista *l, int x);
void push(vertice *v, int x);
int dfs(vertice * vertices , int raiz, int cor);
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
            //scanf("%d %d", &qtd_vertices, &qtd_arestas);
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
 