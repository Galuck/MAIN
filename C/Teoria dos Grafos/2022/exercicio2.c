#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    int valor;
    struct registro *proximo;
} registro;

typedef struct lista{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct vertice{
    int visitado;
    struct lista *lista_adj;
} vertice;

int qtd=0;

registro *aloca_registro();
lista *aloca_lista();

int lista_ordenada(int x, lista *lista);

void push(int x,vertice *vertice);
void dfs(int x, vertice * vertices);

///////MAIN///////MAIN/////////MAIN/////////MAIN///////////MAIN///////////MAIN////////////MAIN///////////
int main(){

    int contador=0;
    int i=0;
    int aux=1;


    int x=0;
    int y=0;
    int n=0;//'n' é a quantidade de vertices (node)
    int e=0;//'e' é a quantidade de arestas  (edge)
    vertice * vertices;

    //node and edge
    printf("\n  Digite x qtd de Vertices e a qtd de Arestas: \n");
    scanf("%i %i",&n,&e);
    vertices = (vertice*)calloc(n+1,sizeof(vertice));
    while(i<e){
        scanf("%i %i",&x,&y);
        push(y, &vertices[x]);
        push(x, &vertices[y]);
        i++;
    }
    for(i=1;i<=n;i++){
        if (vertices[i].visitado==0){
            dfs(i, vertices);
            contador++;
            aux = aux * qtd;
            qtd=0;
        } 
    }
    printf("\n  Conectados: %i\n",contador);
    return 0;
}
////////////////////////////////////////////////////////////

lista *aloca_lista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro(){
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

int lista_ordenada(int x, lista *lista){
    if (lista == NULL){
        return 0;
    }

    registro *novo = aloca_registro();
    novo->valor = x;

    registro *aux = NULL;
    registro *anterior = NULL;
    
    

    if (lista->inicio == NULL){
        lista->inicio = novo;
    }
    else{
        int inserido = 0;
        aux = lista->inicio;
        while (aux!=NULL && !inserido){
            if (aux->valor==novo->valor){
                return 0;
            }

            if (aux->valor < novo->valor){
                anterior = aux;
                aux = aux->proximo;
            }

            else{
                if (anterior==NULL){
                    lista->inicio = novo;
                }
                    
                else{
                    anterior->proximo=novo;
                }
                    
                novo->proximo=aux;
                inserido=1;
            }
        }
        if (!inserido){
            anterior->proximo=novo;
            inserido=1;
        }
    }
    lista->qtd++;
    return 1;
}


void push(int x, vertice *vertice){
    if (vertice->lista_adj == NULL){
        vertice->lista_adj = aloca_lista();
    }
    lista_ordenada(x, vertice->lista_adj);
}

void dfs(int x, vertice * vertices){
    registro * aux;
    vertices[x].visitado=1;
    qtd++;

    if (vertices[x].lista_adj==NULL){
        return;
    }
    aux = vertices[x].lista_adj->inicio;

    while(aux!=NULL){
        if (vertices[aux->valor].visitado==0){
            dfs(aux->valor, vertices); 
        }
        aux = aux->proximo;
    }
}