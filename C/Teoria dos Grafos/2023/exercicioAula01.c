#include <stdio.h>
#include <stdlib.h>


//
typedef struct vertice
{
    int visitado;
    struct lista *lista_adj;
} vertice;
//



typedef struct Registro
{
    int valor;
    struct Registro * proximo;
}Registro;//valores dentro da lista

typedef struct Lista{
    int qtd;
    
    struct Lista *inicio;

}Lista;//alocacao dinamica


Lista * aloca_lista();
Registro * aloca_registro();


int main() {
    
    int vetor[10000];
    int matriz[1000][1000];

//
    vertice * vertices;
//



    //TESTE//
    Registro l1, l2, l3;
    Registro *gancho = &l1;//gancho vai apontar para o endereço de memoria de l1

    l1.valor = 10;
    l2.valor = 20;
    l3.valor = 30;   

    l1.proximo = &l2;//proximo da l1 vai apontar para o endereço de memoria de l2
    l2.proximo = &l3;//proximo da l2 vai apontar para o endereço de memoria de l3
    l3.proximo = NULL;//proximo da l3 vai apontar para NULL, porque é o ultimo elemento da lista
    //ou
    l3.proximo = (Lista *)0;

    while(gancho != (Lista *)0){//mostrar os valores da lista ligada
        printf("%d\n", gancho->valor);
        gancho = gancho->proximo;//vai passar pro próximo valor
    }

    //agora tem que descobrir como fazer isso dinamicamente sem ter que ficar declarando l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12...

    //alocar lista dinamicamente
    //alocar Registro dinamicamente
    
//     Alocar Memória para um Novo Nó:
// Para adicionar um novo elemento à lista, você precisará alocar memória para um novo nó usando a função malloc.

    // Lista *novaLista = (struct Lista*)malloc(sizeof(Lista));

    // if (novaLista == NULL) {
    //     // Tratar erro de alocação

    // }else{
    //     // Inicializar o novo nó
    //     novaLista->valor = 10;// Atribuir o valor ao campo data
    //     novaLista->proximo = NULL;// O próximo nó é inicializado como NULL
    // }

    

    // Agora você precisa ajustar os ponteiros para inserir o nó na lista


    //TESTE//


    int numeroVertices=0;
    int numeroArestas=0;

    //fazer um menuzinho, ler numero de vertices pelo input ou deseja falar numero de vertices.
    //fazer loop de um switch case do menu até o usuário usar a opção de sair do app

    while(1){
        printf("Opcoes: \n");
        printf("1 - Ler/Adicionar vertices\n");
        printf("2 - Ler/Adicionar arestas\n");
        printf("3 - Mostrar matriz de adjacencia\n");
        printf("4 - Mostrar lista de adjacencia\n");
        printf("5 - Sair\n");
        
        //ler numero de vertices
        //tamanho da minha matriz é a quantidade de vertices ao quadrado
        //ler vertice por vértice, não pode repetir, para descobrir a quantidade de vértices
        //declarar vetor grande
        //A tá no vetor? não, coloca ele
        //percorre todo o input um por um e checar se esse input já está no vetor (fazer isso dentro de um for)
        //declara a matriz com o tamanho do vetor resultante? ou com um tipo de count.


        int opcao;
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                //adicionar vertices
                printf("Escolha o modo: \n");
                printf("1 - Input numero de vertices\n");
                printf("2 - Input dos vertices\n");
                
                int opcaoLeitura;
                scanf("%d", &opcaoLeitura);
                switch (opcaoLeitura)
                {
                case 1:
                    //input qtd vertices
                    printf("Digite o numero de vertices: \n");
                    scanf("%d", &numeroVertices);
                    break;
                
                case 2:
                    //input dos vertices (desnecessário?) (ler qtd de vértices pelas conexões de arestas?)
                    printf("Digite o numero de conexoes (arestas): \n");
                    int numeroArestas;
                    scanf("%d", &numeroArestas);

                    printf("Digite as conexoes: \n");
                    for (int i = 0; i < numeroVertices; i++)
                    {
                        scanf("%d", &vetor[i]);
                    }
                    break;

                default:
                    break;
                }


                break;
            
            case 2:
                //adicionar arestas

                printf("Escolha o modo: \n");
                printf("1 - Input numero de arestas\n");
                printf("2 - Input das conexoes(arestas)\n");
                
                int opcaoLeitura;
                scanf("%d", &opcaoLeitura);
                switch (opcaoLeitura)
                {
                case 1:
                    //input qtd arestas
                    printf("Digite o numero de arestas: \n");
                    scanf("%d", &numeroArestas);
                    break;
                case 2:
                    //input das conexoes
                    printf("Digite o numero de conexoes (arestas): \n");
                    int numeroArestas;
                    scanf("%d", &numeroArestas);

                    printf("O input a seguir deve ser feito com um par de vertices separado por um espaco: \n");
                    printf("Digite as conexoes: \n");
                    int a,b;
                    for (int i = 0; i < numeroArestas; i++)
                    {
                        //scanf("%d %d", &vetor[i], &vetor[i+1]); 

                        scanf("%d %d",&a,&b);
                        push(&vertices[a],b);
                        push(&vertices[b],a);
                        i++;

                        //aloca_lista_ligada();
                    }
                    break;

                default:
                    break;
                }
                
                break;
            
            case 3:
                //mostrar matriz de adjacencia

                break;
            
            case 4:
                //mostrar lista de adjacencia


                break;
            
            case 5:
                //sai do programa
                exit(0);
                break;
            
            default:
                break;
        }
            

 
    }

    return 0;
}


Lista * aloca_lista()
{
    Lista * novo;
    novo = (Lista*)calloc(1,sizeof(Lista));
    novo->inicio=NULL;

    return novo;
}

Registro * aloca_registro()
{
    Registro * novo;
    novo = (Registro*)calloc(1,sizeof(Registro));
    return novo;
}


//////////////////////////////////////////
void push(vertice *v, int x)
{
    if (v->lista_adj == NULL)
        v->lista_adj = aloca_lista();
    incluir_ordenado_lista(v->lista_adj, x);
}


int incluir_ordenado_lista(lista *l, int x)
{
    if (l == NULL)
        return 0;

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        int inserido = 0;
        aux = l->inicio;
        while (aux != NULL && !inserido)
        {

            if (aux->valor == novo->valor)
            {
                return 0;
            }

            if (aux->valor < novo->valor)
            {
                ant = aux;
                aux = aux->prox;
            }
            else
            {
                if (ant == NULL)
                    l->inicio = novo;
                else
                    ant->prox = novo;

                novo->prox = aux;
                inserido = 1;
            }
        }
        if (!inserido)
        {
            ant->prox = novo;
            inserido = 1;
        }
    }
    l->qtd++;
    return 1;
}
