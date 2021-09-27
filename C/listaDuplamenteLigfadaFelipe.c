#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro
{
    int valor;
    struct registro *ant;
    struct registro *prox;
} registro;

lista *aloca_lista_dupla()
{
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}


// tipo_inclusao 1 : do inicio pro fim
// tipo_inclusao 2 : do fim para o inicio
void incluir(lista *l, int x, int tipo_inclusao)//lista, valor e tipo de inclusão
{
    if (l == NULL){
        return;
    }

    if (tipo_inclusao != 1 && tipo_inclusao != 2)
    {
        printf("\n Tipo de inclusao informado incorreto");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)//lista vazia
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        switch (tipo_inclusao)
        {
            // tipo_inclusao 1 : do inicio pro fim
        case 1:
            novo->prox = l->inicio;//'novo' vira o novo inicio
            l->inicio->ant = novo;//bota o novo na frente do inicio atual
            l->inicio = novo;//inicio atual muda para o novo inicio
            break;
        // tipo_inclusao 2 : do fim para o inicio
        case 2:
            l->fim->prox = novo;//'novo' vira o próximo do fim
            novo->ant = l->fim;// faz o ponteiro ant de novo apontar para o fim(que esta atrás)
            l->fim = novo; //'novo' agora é o novo fim da lista(inclui no fim)
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }
}



void mostrar(lista *l, int tipo_mostrar)
{
    if (l == NULL)
    {
        printf("\n Lista nao alocada");
        return;
    }

    if (tipo_mostrar != 1 && tipo_mostrar != 2)
    {
        printf("\n Tipo mostrar invalido");
        return;
    }

    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux;

    switch (tipo_mostrar)
    {
    case 1:
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n -> %d", aux->valor);
            aux = aux->prox;
        }
        break;
    case 2:
        aux = l->fim;
        while (aux != NULL)
        {
            printf("\n -> %d", aux->valor);
            aux = aux->ant;
        }
        break;
    default:
        printf("\n opcao invalida");
        break;
    }
}

// 1 - removeu
// 0 - não removeu
int remover(lista *l, int x)
{
    if (l == NULL){
        return 0;
    }
    if (l->inicio == NULL){
        return 0;
    }

    registro *aux;

    aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (aux->ant == NULL)
                l->inicio = aux->prox;
            else
                aux->ant->prox = aux->prox;

            if (aux->prox == NULL)
                l->fim = aux->ant;
            else
                aux->prox->ant = aux->ant;
            return 1;
        }
        else
        {
            aux=aux->prox;
        }
    }
    return 0;
}

int main()
{

    lista *l1, *l2;

    l1 = aloca_lista_dupla();

    incluir(l1, 10, 2);
    incluir(l1, 20, 2);
    incluir(l1, 30, 2);
    incluir(l1, 40, 2);
    incluir(l1, 50, 2);
    incluir(l1, 60, 2);

    printf("\n Mostrando do inicio pro fim");
    mostrar(l1, 1);

    printf("\n Mostrando do fim pro inicio");
    mostrar(l1, 2);

    incluir(l1, 9, 1);
    incluir(l1, 8, 1);
    incluir(l1, 7, 1);
    incluir(l1, 6, 1);
    incluir(l1, 5, 1);

    printf("\n Mostrando do inicio pro fim");
    mostrar(l1, 1);

    printf("\n Mostrando do fim pro inicio");
    mostrar(l1, 2);


    remover(l1,10);
    remover(l1,5);
    printf("\n Mostrando do inicio pro fim");
    mostrar(l1, 1);

    printf("\n");
    return 0;
}