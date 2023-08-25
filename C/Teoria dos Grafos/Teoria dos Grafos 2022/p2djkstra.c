#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVERTICES 100

void dijkstra(int vertices,int origem,int destino,int *custos)
{ int i,v,    /* variáveis auxiliares */
      ant[MAXVERTICES],   /* vetor dos antecessores */
      z[MAXVERTICES];     /* vértices para os quais se conhece o caminho mínimo */
  double min, /* variável auxiliar */
       dist[MAXVERTICES]; /* vetor com os custos dos caminhos */

/* OBS: O usuário enxerga os vértices como rotulados de 1 a "vértices",  */
/* mas o programa armazena as informações usando os elementos 0 dos */
/* dos vetores. Dessa formar é preciso subtrair 1 de "origem" e "destino" */
/* ao mapeá-los nos vetores. */

  /* Inicialização */

  for (i=0;i<vertices;i++) {
    if (custos[(origem-1)*vertices+i]!=-1) {
      ant[i]=origem-1; 
      dist[i]=custos[(origem-1)*vertices+i];
    }
    else {
      ant[i]=-1;
      dist[i]=HUGE_VAL;
    }
    z[i]=0;
  }
  z[origem-1]=1;
  dist[origem-1]=0;

  /* Laço principal */

  do {

    /* Encontrando o vértice que deve entrar em z */

    min=HUGE_VAL;
    for (i=0;i<vertices;i++)
      if (!z[i])
        if (dist[i]>=0 && dist[i]<min) {min=dist[i];v=i;}

    /* Calculando as distâncias dos novos vizinhos de z */

    if (min!=HUGE_VAL && v!=destino-1) {
      z[v]=1;
      for (i=0;i<vertices;i++)
        if (!z[i]) {
          if (custos[v*vertices+i]!=-1 && dist[v]+custos[v*vertices+i]<dist[i])
            { dist[i]=dist[v]+custos[v*vertices+i];ant[i]=v; }
        }
    }
  } while (v!=destino-1 && min!=HUGE_VAL);

  /* Imprimindo o resultado  */

  if (min==HUGE_VAL)
    printf("\nNo digrafo dado não existe caminho entre os vértices %d e %d !!\n",origem,destino);
  else {
    printf("\nO caminho de custo mínimo entre os vértices %d e %d  é (na ordem reversa):\n",origem,destino);
    i=destino;
    printf("%d",i);
    i=ant[i-1];
    while (i!=-1) {
      printf("<-%d",i+1);
      i=ant[i];
    }
    printf("\nO custo deste caminho é: %d\n",(int) dist[destino-1]);
  }
  
} /* dijsktra */


int main() {

    char opcao,lixo[50];   /* variáveis auxiliares */
    int i,custo,           /* variáveis auxiliares */
        vertices=0,        /* número de vértices do grafo */
        origem,            /* vértice origem */
        destino,           /* vértice destino */
        *custos=NULL;      /* matriz de incidência */

    do {

    /* Menu principal */

    printf("\n      Solucionador para o problema do caminho de custo mínimo em digrafos\n");
    printf("(Algoritmo proposto por Dijkstra e implementado por Glauber Cintra em 11set1998)\n\n");
    printf("Escolha sua opção:\n");
    printf("     1. Digitar um digrafo\n");
    printf("     2. Resolver uma instância\n");
    printf("     3. Sair do programa\n\n");
    printf("Opção: ");
    gets(&opcao);

    /* Digitar novo grafo */

    if (opcao==49) {
        do {
        printf("\nNúmero de vértices (entre 2 e %d): ",MAXVERTICES);
        scanf("%d",&vertices);
        } while (vertices<2 || vertices>MAXVERTICES);

        if (!custos)
        free(custos);
        custos=(int *) malloc(sizeof(int)*vertices*vertices);
        for (i=0;i<=vertices*vertices;i++) custos[i]=-1;
        printf("Digite agora as arestas\n");
        do {

        do {
            printf("Origem da aresta (entre 1 e %d ou 0 para sair): ",vertices);
            scanf("%d",&origem);
        } while (origem<0 || origem>vertices);

        if (origem) {

            do {
            printf("Destino da aresta (entre 1 e %d, menos %d): ",vertices,origem);
            scanf("%d",&destino);
            } while (destino<1 || destino>vertices || destino==origem);

            do {
            printf("Custo (positivo) da aresta do vértice %d para o vértice %d: ",origem,destino);
            scanf("%d",&custo);
            } while (custo<0);
            custos[(origem-1)*vertices+destino-1]=custo;
        }

        } while (origem);
        gets(lixo);
    }

    /* Achar caminho mínimo entre 2 vértices */
    if (opcao==50 && vertices>0) {
        printf("\nDigite os vértices origem e destino do caminho\n");
        do {
            printf("Vértice origem (entre 1 e %d): ",vertices);
            scanf("%d",&origem);
        } while (origem<1 || origem>vertices);
    
        do {
            printf("Vértice destino (entre 1 e %d, menos %d): ",vertices,origem);
            scanf("%d",&destino);
        } while (destino<1 || destino>vertices || destino==origem);

        dijkstra(vertices,origem,destino,custos);
        gets(lixo);
    }

    } while (opcao!=51);

    printf("\nAté a próxima...\n\n");

} /* Fim do programa */