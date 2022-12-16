#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{

    int visitado;
    int lista_adj[1000];
    int tamanho_lista_adj;

    int in; 
    int lower;

}vertice;

int count=0;
int qtd_pontes=0;

int main(){

    
    int a=0;
    int b=0;
    int qtd_vertices;
    int qtd_arestas;

    printf("\nDigite a qtd de vertices e arestas do grafo:\n");
    scanf("%i %i", &qtd_vertices,&qtd_arestas);

    // um array de vertices
    vertice * vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));//decorar isso aqui

    printf("\nDigite as conexoes das %i arestas do grafo:\n", qtd_arestas);
    for(int i=0; i<qtd_arestas; i++){

        scanf("%i %i", &a, &b);
        vertices[a].lista_adj[vertices[a].tamanho_lista_adj]= b; //adicionando b na lista de adjacencia de A
        vertices[a].tamanho_lista_adj++;
        vertices[b].lista_adj[vertices[b].tamanho_lista_adj]= a; //como é bidirecional, vai para os dois lados
        vertices[b].tamanho_lista_adj++;////NAO ESQUECER
    }


    dfs2(vertices,qtd_vertices,0,0);//raiz 0 e pai 0, testando o resultado do primeiro exercício
    //dfs2(vertices,qtd_vertices,1,1);
    //esses dois deram certo

    return 0;
}   

void dfs2(vertice * vertices, int qtd_vertices, int raiz, int pai){

    int filho;

    vertices[raiz].visitado=1;
    count++;
    vertices[raiz].in=count;
    vertices[raiz].lower=count;

    for(int i=0; i<vertices[raiz].tamanho_lista_adj; i++){//vai percorrer até todo o tamanho da lista de adjacencia do vertice

        filho=vertices[raiz].lista_adj[i];
        
        if(filho==pai){//tá comparando o número em si
            continue;
        }
        else{

            if(vertices[filho].visitado==1){// aqui tá comparado o vértice no index do numero
                vertices[raiz].lower = menor(vertices[raiz].lower, vertices[filho].in);
            }

            else{

                //recurssiva
                dfs2(vertices, qtd_vertices, filho, raiz);
                
                if(vertices[filho].lower>vertices[raiz].in){
                    qtd_pontes++;
                    printf("\nPonte entre: %i e %i\n", raiz, filho);//RAIZ e FILHO, nessa ordem porra
                }


                vertices[raiz].lower= menor(vertices[raiz].lower, vertices[filho].lower);
            }
        }
    }
}


int menor(int a, int b){return a<b? a:b;}