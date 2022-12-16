// Utilizando como base a matriz de adjacências abaixo, onde cada posição [i,j] representa o peso entre i e j, 
// implemente o algoritmo de Dijkstra e mostre na  tela qual a menor distância entre F e todos os outros vértices do grafo.
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int menorDistancia(int distancia[], bool sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int vertices = 0; vertices < 6; vertices++){
        if (sptSet[vertices] == false && distancia[vertices] <= min){
            min = distancia[vertices], min_index = vertices;
        }
    }
    return min_index;
}
 
void resultado(int distancia[])
{
    for (int i = 0; i < 6; i++){
        printf("Vertice: %d \n Distancia: %d\n", i, distancia[i]);
    }
}

void dijkstra(int grafo[6][6], int raiz)
{
    int distancia[6]; 
    bool sptSet[6]; 
    for (int i = 0; i < 6; i++){
        distancia[i] = INT_MAX, sptSet[i] = false;
    }

    distancia[raiz] = 0;
    
    for (int count = 0; count < 6 - 1; count++) {

        int u = menorDistancia(distancia, sptSet);
        sptSet[u] = true;
        for (int vertices = 0; vertices < 6; vertices++){
            if (!sptSet[vertices] && grafo[u][vertices] && distancia[u] != INT_MAX && distancia[u] + grafo[u][vertices] < distancia[vertices]){
                distancia[vertices] = distancia[u] + grafo[u][vertices];
            }
        }
    }

    resultado(distancia);
}

int main()
{
    //                    a  b  c  d  e  f
	int grafo[6][6] = { 
                        { 0, 6, 9, 11,5, 9 },
						{ 6, 0, 3, 6, 5, 2 },
						{ 9, 3, 0, 0, 4, 4 },
						{ 11,6, 0, 0, 5, 6 },
						{ 5, 5, 4, 5, 0, 8 },
						{ 9, 2, 4, 6, 8, 0 },};
    //vertice 5 = F
	dijkstra(grafo, 5);

	return 0;
}


