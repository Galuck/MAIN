	#include <stdio.h>
    #include <conio.h>
    #include <stdlib.h>

    int i, j, k, a, b, u, v;
	int numVertices=6;
	int ne = 1;
    int min, mincost = 0, cost[9][9], parent[9];
    int find(int);
    int uni(int, int);

    void main() {

		int cost[6][6] = { 
			{ 0, 6, 9, 11,5, 9 },
			{ 6, 0, 3, 6, 5, 2 },
			{ 9, 3, 0, 0, 4, 4 },
			{ 11,6, 0, 0, 5, 6 },
			{ 5, 5, 4, 5, 0, 8 },
			{ 9, 2, 4, 6, 8, 0 },};

		for (i = 1; i <= numVertices; i++) {
			for (j = 1; j <= numVertices; j++) {
				if (cost[i][j] == 0){
					cost[i][j] = 999;
				}
			}
		}

		printf("As arestas MST são:\n");
		while (ne < numVertices) {
			for (i = 1, min = 999; i <= numVertices; i++) {
				for (j = 1; j <= numVertices; j++) {
					if (cost[i][j] < min) {
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}
				}
			}
			u = find(u);
			v = find(v);
			if (uni(u, v)) {
			printf("%d Aresta (%d,%d) =%d\n", ne++, a, b, min);
			mincost += min;
			}
			cost[a][b] = cost[b][a] = 999;
		}
		printf("\n\tCusto minimo = %d\n", mincost);
		getch();
    }

    int find(int i) {
      while (parent[i])
        i = parent[i];
      return i;
    }
    int uni(int i, int j) {
      if (i != j) {
        parent[j] = i;
        return 1;
      }
      return 0;
    }