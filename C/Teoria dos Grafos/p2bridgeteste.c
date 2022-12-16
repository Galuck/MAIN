#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int in;
    int lower;
}vertice;

int count=0;
int qtd_pontes=0;

int main(){

    int qtd_vertices;
    int qtd_arestas;
    int a;
    int b;
     
    printf("\nDigite a quantidade de vertices e arestas:\n");
    scanf("%i %i", &qtd_vertices, &qtd_arestas);

    vertice *vertices= (vertice*)calloc(qtd_vertices+1, sizeof(vertice));

    printf("\nAgora digite as conexoes da arestas:\n");
    for(int i=0; i<qtd_arestas;i++){
        scanf("%i %i", &a, &b);
        vertices[a].lista_adj[vertices[a].tam_lista_adj]=b;
        vertices[a].tam_lista_adj++;
        vertices[b].lista_adj[vertices[b].tam_lista_adj]=a;
        vertices[b].tam_lista_adj++;
    }

    //bridge(vertices, qtd_vertices, 0,0);//nesse mesmo caso

    bridge(vertices, qtd_vertices, 1,1);// tem que colocar a raiz e o pai como a raiz do problema

    printf("\nQtd de pontes: %i", qtd_pontes);

}

void bridge(vertice * vertices, int qtd_vertices, int raiz, int pai){

    int filho;

    count++;
    vertices[raiz].visitado=1;
    vertices[raiz].in=count;
    vertices[raiz].lower=count;

    for(int i=0;i<vertices[raiz].tam_lista_adj;i++){
        filho=vertices[raiz].lista_adj[i];
        if(filho==pai){
            continue;
        }
        else{
            if(vertices[filho].visitado==1){
                vertices[raiz].lower=menor(vertices[raiz].lower, vertices[filho].in);
            }
            else{
                bridge(vertices,qtd_vertices,filho, raiz);

                if(vertices[filho].lower>vertices[raiz].in){
                    qtd_pontes++;
                    printf("\nPonte entre %i e %i", raiz, filho);
                }
                vertices[raiz].lower=menor(vertices[raiz].lower, vertices[filho].lower);
            }
        }
    }

}

int menor(int a, int b){return a<b? a:b;}