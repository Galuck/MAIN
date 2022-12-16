#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista;
    int in;
    int lower;
}vertice;

int count=0;
int qtd_pontes=0;

int main(){
    int qtd_vertices, qtd_arestas;
    int a,b;
    printf("\nDigite a qtd de vertices e arestas:\n");
    scanf("%i %i",&qtd_vertices,&qtd_arestas);
    vertice *vertices=(vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    printf("\nDigite as conexoes das %i arestas:\n",qtd_arestas);
    for(int i=0;i<qtd_arestas;i++){
        scanf("%i %i",&a,&b);
        vertices[a].lista_adj[vertices[a].tam_lista]=b;
        vertices[a].tam_lista++;
        vertices[b].lista_adj[vertices[b].tam_lista]=a;
        vertices[b].tam_lista++;
    }
    printf("\nDigite a raiz do grafo:\n");
    int raiz;
    scanf("%i",&raiz);
    bridge(vertices,qtd_vertices,raiz,raiz);
    printf("\nQtd de pontes: %i",qtd_pontes);

    return 0;
}

void bridge(vertice *vertices, int qtd_vertices, int raiz, int pai){
    int filho;
    vertices[raiz].visitado=1;
    count++;
    vertices[raiz].in=count;
    vertices[raiz].lower=count;
    for(int i=0;i<vertices[raiz].tam_lista;i++){
        filho=vertices[raiz].lista_adj[i];
        if(filho==pai){
            continue;
        }
        else{
            if(vertices[filho].visitado==1){
                vertices[raiz].lower=menor(vertices[raiz].lower,vertices[filho].in);
            }
            else{
                bridge(vertices,qtd_vertices,filho,raiz);
                if(vertices[filho].lower>vertices[raiz].in){
                    qtd_pontes++;
                    printf("\nPonte entre %i e %i",raiz,filho);
                }
                vertices[raiz].lower=menor(vertices[raiz].lower,vertices[filho].lower);
            }
        }
    }
}

int menor(int a,int b){a<b? a:b;}