#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct vertice {
    int visitado;
    long long tamanho;
    struct lista *lista_adj;
} vertice;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

typedef struct lista {
    int qtd;
    struct registro *inicio;
} lista;

registro *aloca_registro() {
    registro *novo = (registro *)malloc(sizeof(registro));
    return novo;
}

lista *aloca_lista() {
    lista *novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

void push(vertice *v, int x) {
    if (v->lista_adj == NULL) {
        v->lista_adj = aloca_lista();
    }
    incluir_lista(v->lista_adj, x);
}

int incluir_lista(lista *l, int x) {
    if (l == NULL) {
        return 0;
    }

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        int inserido = 0;
        aux = l->inicio;
        while (aux != NULL && !inserido) {
            if (aux->valor == novo->valor) {
                return 0;
            }

            if (aux->valor < novo->valor) {
                ant = aux;
                aux = aux->prox;
            } else {
                if (ant == NULL) {
                    l->inicio = novo;
                } else {
                    ant->prox = novo;
                }

                novo->prox = aux;
                inserido = 1;
            }
        }
        if (!inserido) {
            ant->prox = novo;
            inserido = 1;
        }
    }
    l->qtd++;
    return 1;
}

void dfs(vertice *vertices, int raiz, long long *tamanho) {
    vertices[raiz].visitado = 1;
    (*tamanho)++;

    registro *aux;
    if (vertices[raiz].lista_adj == NULL) {
        return;
    }

    aux = vertices[raiz].lista_adj->inicio;

    while (aux != NULL) {
        if (vertices[aux->valor].visitado == 0) {
            dfs(vertices, aux->valor, tamanho);
        }
        aux = aux->prox;
    }
}

int main() {
    int casos_de_teste;
    scanf("%d", &casos_de_teste);

    while (casos_de_teste--) {
        int qtd_vertices, qtd_arestas;
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

        vertice *vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));
        long long componentes = 0;
        long long total_tamanho = 1;

        for (int i = 0; i < qtd_arestas; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            push(&vertices[a], b);
            push(&vertices[b], a);
        }

        for (int i = 1; i <= qtd_vertices; i++) {
            if (vertices[i].visitado == 0) {
                long long tamanho = 0;
                dfs(vertices, i, &tamanho);
                componentes++;
                total_tamanho = (total_tamanho * tamanho) % MOD;
            }
        }

        printf("%lld %lld\n", componentes, total_tamanho);
        free(vertices);
    }

    return 0;
}
