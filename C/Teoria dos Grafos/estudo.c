#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define INFINITY 9999
#define MAX 10

void djkstra(int Grafo[MAX][MAX],int qtd_vertices,int raiz);

int main(){
    int Grafo[MAX][MAX];
    int qtd_vertices;
    printf("\nDigite a quantidade de vertices do grafo:\n");
    scanf("%i",&qtd_vertices);
    printf("\nDigite agora a matriz de adjancencias:\n");
    for(int i=0;i<qtd_vertices;i++)
    for(int j=0;i<qtd_vertices;j++)
    scanf("%i",&Grafo[i][j]);

    printf("\nDigite a raiz do grafo:\n");
    int raiz;
    scanf("%i",&raiz);

    djkstra(Grafo,qtd_vertices,raiz);

    return 0;
}

void djkstra(int Grafo[MAX][MAX], int qtd_vertices,int raiz){

    int custo[MAX][MAX],distancia[MAX],pai[MAX];
    int visitado[MAX],mindistance,count;
    int filho;
    int i,j;

    for(int i=0;i<qtd_vertices;i++)
    for(int j=0;i<qtd_vertices;j++)
    if(Grafo[i][j]==0)
    custo[i][j]=INFINITY;
    else
    custo[i][j]=Grafo[i][j];

    for(i=0;i<qtd_vertices;i++){
        distancia[i]=custo[raiz][i];
        pai[i]=raiz;
        visitado[i]=0;
    }
    distancia[raiz]=0;
    visitado[raiz]=1;
    count=1;
    while(count<qtd_vertices-1){
        mindistance=INFINITY;
        for(i=0;i<qtd_vertices;i++)
        if(distancia[i]<mindistance&&!visitado){
            mindistance=distancia[i];
            filho=i;
        }
        visitado[filho]=1;
        for(i=0;i<qtd_vertices;i++)
        if(!visitado[i])
        if(mindistance+custo[filho][i]<distancia[i]){
            distancia[i]=mindistance+custo[filho][i];
            pai[i]=filho;
        }
        count++;
    }
    for(int i=0;i<qtd_vertices;i++)
    if(i!=raiz){
        printf("\nMenor distancia ate o vertice %i= %i",i,distancia[i]);
        printf("\nCaminho:%i",i);
        j=i;
        do{
            j=pai[j];
            printf("<-%i",j);
        }while(j!=raiz);
    }
}