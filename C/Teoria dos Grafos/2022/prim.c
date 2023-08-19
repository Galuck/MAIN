#include <stdio.h>
#include <stdlib.h>

// (MST): Minimum Spanning Tree 
// tambem conhecido como ~Movimento dos Sem Terra~

void GRAPHmstP1( Graph G, Vertex parent[]) 
{ 
  Vertex v0, w, frj[maxV]; link a; 
  double price[maxV], c;
  for (w = 0; w < G->V; w++) 
  parent[w] = -1, price[w] = INFINITO; 
  v0 = 0;
  parent[v0] = v0;
    for (a = G->adj[v0]; a != NULL; a = a->next) {
      price[a->w] = a->cost; 
      frj[a->w] = v0; 
     } 

    while (1) { 
      double minprice = INFINITO; 
        for (w = 0; w < G->V; w++) 
           if (parent[w] == -1 && minprice > price[w]) 
              minprice = price[v0=w]; 
           if (minprice == INFINITO) break;
              parent[v0] = frj[v0]; 
          for (a = G->adj[v0]; a != NULL; a = a->next) {
              w = a->w, c = a->cost;
          if (parent[w] == -1 && price[w] > c) {
            price[w] = c; 
            frj[w] = v0; 
          }
       }
    }
}