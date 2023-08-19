#include<stdio.h>
#include<stdlib.h>

//Faça um programa que receba do usuário N pares de valores, onde cada par representa uma aresta bidirecional entre cada valor do par

//Mostre uma matriz de adjacencia que representa esse grafo
//Mostre uma lista de adjacencia que represente esse grafo


/*
ex
1 2 
1 4 
2 5 
3 6
*/


/////LISTA///////LISTA////////LISTA////////LISTA//////LISTA///////
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

void mostrar(lista *l, int tipo_mostrar, int i)
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
        printf("Nó %i ->", i);
        while (aux != NULL)
        {
            printf(" %i", aux->valor);
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
/////LISTA///////LISTA////////LISTA////////LISTA//////LISTA///////




////FUNÇÕES////FUNÇÕES////FUNÇÕES////FUNÇÕES////

void matrizAdjacente(int qtdPares);
// void listaAdjacente(int qtdPares);


////VAR////VAR////VAR////VAR////VAR////
int qtdPares = 0;
int valor[1000];
int matrix[30][30];



int choice = 0;

////MAIN////MAIN////MAIN////MAIN////
int main(){

    printf("Deseja mostrar como Matriz ou como Lista?\n");
    printf("1-Matriz\n");
    printf("2-Lista\n");
    scanf("%d", &choice);

    if(choice==1){
        printf("Digite a quantidade N de pares de valores:  \n");
        scanf("%i", &qtdPares);
        matrizAdjacente(qtdPares);
    }else{
        printf("Não consegui fazer a parte de Listas, mas o que eu tentei fazer está no código comentado \n");
        // scanf("%i", &qtdPares);
        // listaAdjacente(qtdPares);
    }

    return 0;
}
// void listaAdjacente(int qtdPares){
//     // lista *l1;
//     // l1 = aloca_lista_dupla();

//     lista listas[30];

//     int value=0;
//     int valorLista = 0;

//     for(int i=0; i<qtdPares; i++){
//         for(int j=0; j<2; j++){

//             if(j==0){
//                 scanf("%i", &valorLista);
//                 if(listas[valorLista]== NULL){
//                     listas[valorLista] = aloca_lista_dupla();
//                     incluir(listas[valorLista], valorLista, 2);
//                 }
                
//             }else if(j==1){
//                 scanf("%i", &value);
//                 incluir(listas[valorLista], value, 2);
//                 if(listas[value]== NULL){
//                     listas[value] = aloca_lista_dupla();
//                     incluir(listas[value], value, 2);
//                     incluir(listas[value], valorLista, 2);
//                 }else{
//                     // incluir(listas[value], value, 2);
//                     incluir(listas[value], valorLista, 2);
//                 }
//             }
            
//         } 
//     }


//     for(int i=0; i<30; i++){
//        if(listas[i]!=NULL){
//             mostrar(listas[i], 1, i);
//             printf("\n");
//        }
//     }

//     return;
// }

void matrizAdjacente(int qtdPares){

    for(int y=0; y>100; y++){
        for(int x=0; x>100; x++){
            matrix[x][y]=0;
        }
    }

    printf("Digite os %i pares de valores: \n", qtdPares);

    for(int i=0; i<qtdPares; i++){
        for(int j=0; j<2; j++){
            
            if(j==0){
                scanf("%i", &valor[i]);
            }else 
            
            if(j==1){
                scanf("%i", &valor[i+1]);
                matrix[valor[i]][valor[i+1]] = 1; //conectado
                matrix[valor[i+1]][valor[i]] = 1;
            }

        } 
    }
    
    for(int i=0; i<30; i++){
        printf("|");
        for(int j=0; j<30; j++){
            if(j==i){
                matrix[i][j] = 1;//conectado com ele mesmo
            }
            printf("%i ", matrix[j][i]);
        } 
        printf("| \n");
    }

    return;
}