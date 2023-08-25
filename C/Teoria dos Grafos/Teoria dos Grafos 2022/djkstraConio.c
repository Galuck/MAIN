#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
 
void dijkstra(int Grafo[MAX][MAX],int n,int raiz);
 
int main()
{
    int Grafo[MAX][MAX];
    int qtd_vertices;
    printf("\nDigite o numero de vertices:");
    scanf("%d",&qtd_vertices);
    printf("\nDigite a matriz de adjacencia:\n");
    for(int i=0;i<qtd_vertices;i++)
    for(int j=0;j<qtd_vertices;j++)
    scanf("%d",&Grafo[i][j]);
    printf("\nDigite a raiz:");
    int raiz;
    scanf("%d",&raiz);
    dijkstra(Grafo,qtd_vertices,raiz);
    return 0;
}
 
void dijkstra(int Grafo[MAX][MAX],int n,int raiz)
{
    int custo[MAX][MAX],distance[MAX],pai[MAX];
    int visited[MAX],count,mindistance,filho,i,j;
    
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(Grafo[i][j]==0)
    custo[i][j]=INFINITY;//deixa tudo como infinito
    else
    custo[i][j]=Grafo[i][j];
    //initialize pai[],distance[] and visited[]
    for(int i=0;i<n;i++)
    {
        distance[i]=custo[raiz][i];
        pai[i]=raiz;
        visited[i]=0;
    }
    distance[raiz]=0;
    visited[raiz]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
        //filho gives the node at minimum distance
        for(int i=0;i<n;i++)
        if(distance[i]<mindistance&&!visited[i])
        {
            mindistance=distance[i];
            filho=i;
        }
        //check if a better path exists through filho
        visited[filho]=1;
        for(int i=0;i<n;i++)
        if(!visited[i])
        if(mindistance+custo[filho][i]<distance[i])
        {
            distance[i]=mindistance+custo[filho][i];
            pai[i]=filho;
        }
        count++;
    }
    
    //print the path and distance of each node 
    for(int i=0;i<n;i++)
    if(i!=raiz)
    {
        printf("\nDistancia do vertice %d=%d",i,distance[i]);
        printf("\nCaminho=%d",i);
        j=i;
        do
        {
            j=pai[j];
            printf("<-%d",j);
        }while(j!=raiz);
    }
}