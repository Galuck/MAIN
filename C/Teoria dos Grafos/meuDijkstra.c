#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define INFINITY 9999
#define MAX 10

void djkstra(int Grafo[MAX][MAX],int n,int raiz);

int main(){//códio feito por matriz de adjacencia
    int Grafo[MAX][MAX];
    int qtd_vertices;
    printf("\nDigite o numero de vertices:\n");
    scanf("%i",&qtd_vertices);

    printf("\nDigite a matriz de adjacencia:\n");
    for(int i=0;i<qtd_vertices;i++)//for duplo
    for(int j=0;i<qtd_vertices;j++)
    scanf("%i", &Grafo[i][j]);//aqui pega todos os valores do Grafo e seus custos

    printf("\nDigite a raiz do grafo:\n");
    int raiz;//a raiz vai ser por qual vértice a busca vai começar
    scanf("%i",&raiz);

    djkstra(Grafo,qtd_vertices,raiz);//vai printar a menor distancia da raiz até cada vértice

    return 0;
}

void djkstra(int Grafo[MAX][MAX],int n, int raiz){//  'n' é a quantidade de vértices

    int custo[MAX][MAX],distancia[MAX],pai[MAX];//distancia e pai estão como vetores porque cada vertice vai ter a sua
    
    int visitado[MAX],count,mindistance,filho;
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(Grafo[i][j]==0)
    custo[i][j]==INFINITY;//se no grafo estiver o valor 0, vai mudar o custo para Infinito
    else
    custo[i][j]==Grafo[i][j];//aqui só vai colocar os valores dos custos do grafo na nova matriz de custos (para cada valor)

    for(i=0;i<n;i++){
        distancia[i]=custo[raiz][i];
        pai[i]=raiz;
        visitado[i]=0;
    }
    distancia[raiz]=0;
    visitado[raiz]=1;
    count=1;
    while(count<n-1){
        mindistance=INFINITY;//deixa a menor distancia como infinito, para atualizar

        for(i=0;i<n;i++)
        if(distancia[i]<mindistance&&!visitado){
            mindistance=distancia[i];//atualiza a menor distancia de cada vertice
            filho=i;
        }
        visitado[filho]=1;
        for(i=0;i<n;i++)
        if(!visitado[i])//se não foi visitado
        if(mindistance+custo[filho][i]<distancia[i]){//verifica qual a menor distancia
            distancia[i]=mindistance+custo[filho][i];
            pai[i]=filho;
        }
        count++;
    }
    for(i=0;i<n;i++)
    if(i!=raiz){
        printf("\nMenor distancia até o vertice %i= %i",i,distancia[i]);
        printf("\nCaminho:%i",i);
        j=i;
        do{
            j=pai[j];//isso aqui vai pegar o caminho pegando todos os pais do vértice até chegar na raiz
            printf("<-%i",j);
        }while(j!=raiz);
    }
}   