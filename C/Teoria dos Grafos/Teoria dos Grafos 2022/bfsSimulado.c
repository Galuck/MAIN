#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int in;
    int lower;

}vertice; 

int bfs(int V, int lista_adj[]){
    ndqueue = a fila vazia;
    while (s != NULL) {
        visit(s);
        insert(ndqueue,s);
        while (empty(ndqueue) == FALSE) {
            x = remove(ndqueue);
            /* visita todos os sucessores de x */
            firstsucc(x,yptr,nd);
            while (nd != NULL) {
                if (visited(nd) == FALSE) {
                    visit(nd);
                    insert(ndqueue,nd);
                } /* fim if */
                nextsucc(x,yptr,nd);
            } /* fim while */
        } /* fim while */
        s = select();
    } /* fim while */
    return bfs_traversal;
}

int main()
{
	int graph[V][V] = { { 0, 6, 9, 11,5, 9 },
						{ 6, 0, 3, 6, 5, 2 },
						{ 9, 3, 0, 0, 4, 4 },
						{ 11,6, 0, 0, 5, 6 },
						{ 5, 5, 4, 5, 0, 8 },
						{ 9, 2, 4, 6, 8, 0 },};

	dijkstra(graph, 0);

	return 0;
}