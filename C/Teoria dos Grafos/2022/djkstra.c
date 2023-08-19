/*                   Questao 5: Relatório da implementação                 */

/* Implementado por: Glauber Cintra - 14set1998                            */

/* Este programa implementa o algoritmo de Dijkstra para o problema do     */
/* caminho de custo mínimo em grafos dirigidos com custos positivos nas    */
/* arestas.                                                                */

/* O grafo é representado usando-se a variável "vertices" que indica       */
/* o número de vértices do grafo e uma matriz de incidência onde o         */
/* elemento na linha i e coluna j desta matriz contêm o custo do arco      */
/* que sai de i e incide em j, ou -1 sem não existe arco de i para j.      */

/* O programa possui um menu principal com 3 opções. Selecionando a        */
/* primeira opção, é requerido do usuário digitar as informações relativas */
/* a um novo grafo, começando por especificar o número de vértices e       */
/* depois digitando, em qualquer ordem, os arcos do grafo, especificando   */
/* os vértices adjacentes ao arco e seu custo.                             */

/* Através da segunda opção o usuário informa quais os vértices origem     */
/* e destino. A função dijkstra é então chamada com os parâmetros          */
/* "vertices", "origem", "destino" e a matriz de incidência "custos".      */
/* A função calcula um caminho dirigido de custo mínimo entre "origem" e   */
/* "destino", e devolve este caminho (na ordem reversa) e seu custo,       */
/* se ele existir, ou a mensagem "No digrafo dado não existe caminho       */
/* entre os vértices origem e destino !!", caso contrário.                 */

/* A terceira opção do menu principal serve para sair do programa.         */

/* Na função dijkstra "ant[i]" guarda o antecessor do vértice i no         */
/* caminho de custo mínimo entre "origem" e "destino". O valor "dist[i]"   */
/* indica o custo do menor caminho da "origem" ao vértice i. O vetor      */
/* "z" indica o conjunto de vértices para os quais já se conhece um        */
/* caminho de custo mínimo partindo da "origem".                           */

/* Determinamos o vértice que deve entrar em z olhando sequencialmente     */
/* o vetor "dist", o que leva tempo O(V). Atualizamos os custos            */
/* dos vizinhos do novo vértice de z também em tempo O(V). Nossa           */
/* implementação portanto requer tempo O(V^2).                             */

/* Executamos diversos testes e em todos eles verificamos que o            */
/* programa encontrou a solução correta.                                   */


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
    printf("\nO caminho de custo mínimo entre os vértices %d e %d  é (na ordem reversa):\n",
           origem,destino);
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


main(int argc, char **argv) {

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

}