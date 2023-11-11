// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

// Input:
// First line contains T. T testcases follow.
// First line of each test case contains two space-separated integers N, M.
// Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

// Output:
// Print the answer to each test case in a new line.

// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 104
// 1 ≤ M ≤ 105
// 1 ≤ X, Y ≤ N



#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int visitado;
    int distancia;
    int lista_adj[1000];
    int tam_lista_adj;
} vertice;

typedef struct lista {
    int tam;
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

void enfileirar(lista *f, int x) {
    registro *novo = (registro *)malloc(sizeof(registro));
    novo->valor = x;
    novo->prox = NULL;

    if (f->tam == 0) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->tam++;
}

int desenfileirar(lista *f) {
    if (f->tam == 0) {
        return -1;
    } else {
        int retorno = f->inicio->valor;
        registro *temp = f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
        f->tam--;
        return retorno;
    }
}

void bfs(vertice *vertices, int raiz) {
    lista *f = (lista *)malloc(sizeof(lista));
    f->tam = 0;
    f->inicio = NULL;
    f->fim = NULL;
    int atual;
    int i, filho;

    enfileirar(f, raiz);

    while (!(f->tam == 0)) {
        atual = desenfileirar(f);
        vertices[atual].visitado = 1;
        for (i = 0; i < vertices[atual].tam_lista_adj; i++) {
            filho = vertices[atual].lista_adj[i];
            if (vertices[filho].visitado == 0) {
                vertices[filho].distancia = vertices[atual].distancia + 1;
                enfileirar(f, filho);
            }
        }
    }
}

int main() {
    int qtd_vertices, qtd_arestas, i, a, b, qtd_cenarios, c;
    int qtd_cc = 0;
    vertice *vertices;

    scanf("%d", &qtd_cenarios);

    for (c = 1; c <= qtd_cenarios; c++) {

        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

        for (i = 0; i < qtd_arestas; i++) {
            scanf("%d %d", &a, &b);
            vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
            vertices[a].tam_lista_adj++;
            vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
            vertices[b].tam_lista_adj++;
        }

        int k, j;

        bfs(vertices, 1);
        printf("\n%d", vertices[qtd_vertices].distancia);
    }

    free(vertices);
    return 0;
}