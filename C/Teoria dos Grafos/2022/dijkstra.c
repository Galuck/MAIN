#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NumVertices 100

void djkstra(int vertices,int pai,int destino,int *custos){ 

    int i;
    int v;
    int teste[NumVertices];  
    int anterior[NumVertices];
    double distance[NumVertices]; 
    double minimo;
    
    for (i=0;i<vertices;i++) {
        if (custos[(pai-1)*vertices+i]!=-1) {
            anterior[i]=pai-1; 
            distance[i]=custos[(pai-1)*vertices+i];
        }
        else {
            anterior[i]=-1;
            distance[i]=valor;
        }
        teste[i]=0;
    }

    distance[pai-1]=0;

    teste[pai-1]=1;

  do {

    minimo=valor;
    for (i=0;i<vertices;i++){
        if (!teste[i]){
        if (distance[i]>=0 && distance[i]<minimo) {
            minimo=distance[i];v=i;
        }
      }
    }
      
    if (minimo!=valor && v!=destino-1) {
      teste[v]=1;
      for (i=0;i<vertices;i++)
        if (!teste[i]) {
          if (custos[v*vertices+i]!=-1 && distance[v]+custos[v*vertices+i]<distance[i])
            { distance[i]=distance[v]+custos[v*vertices+i];anterior[i]=v; }
        }
    }
  } while (v!=destino-1 && minimo!=valor);

  if (minimo==valor){
    printf("Não existe caminho entre %d e %d\n",pai,destino);
  }
    
  else {
    printf("Caminho de custo mínimo entre %d e %d  é:\n",pai,destino);
    i=destino;
    printf("%d",i);
    i=anterior[i-1];
    while (i!=-1) {
      printf("<-%d",i+1);
      i=anterior[i];
    }
    printf("\nCusto do caminho: %d\n",(int) distance[destino-1]);
  }
  
}

int main() {

    int menu=0;
    char f[50];
    int i;
    int custo, pai,vertices=0,destino;
    int *custos=NULL;      

    do {
        printf("\n1 Digitar grafo\n");
        printf("2 instância\n");
        printf("3 Exit\n\n");
        scanf("%d",&menu);
   
        if (menu==49) {
            do {
                printf("\nNúmero de vértices (entre 2 e %d): ",NumVertices);
                scanf("%d",&vertices);
            } while (vertices<2 || vertices>NumVertices);

            if (!custos){
                free(custos);
            }
            custos=(int *) malloc(sizeof(int)*vertices*vertices);
            for (i=0;i<=vertices*vertices;i++){
                custos[i]=-1;
            } 
            printf("Digite as arestas\n");
            do {

                do {
                    printf("Origem da aresta (entre 1 e %d ou 0 para sair): ",vertices);
                    scanf("%d",&pai);
                } while (pai<0 || pai>vertices);

                if (pai) {

                    do {
                        printf("Destino da aresta, entre 1 e %d menos %d): ",vertices,pai);
                        scanf("%d",&destino);
                    } while (destino<1 || destino>vertices || destino==pai);

                    do {
                        printf("Custo da aresta de %d para %d: ",pai,destino);
                        scanf("%d",&custo);
                    } while (custo<0);
                    custos[(pai-1)*vertices+destino-1]=custo;
                }

            } while (pai);
        gets(f);
    }

    if (menu==50 && vertices>0) {
        printf("\nDigite os vértices pai e destino do caminho\n");
        do {
            printf("Vértice pai, 1 a %d): ",vertices);
            scanf("%d",&pai);
        } while (pai<1 || pai>vertices);
    
        do {
            printf("Vértice destino, 1 a %d menos o %d): ",vertices,pai);
            scanf("%d",&destino);
        } while (destino<1 || destino>vertices || destino==pai);

        djkstra(vertices,pai,destino,custos);
        gets(f);
    }

    } while (menu!=51);
}