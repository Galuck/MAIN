#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// receba 10 números do usuário 
// Esses 10 números devem ser incluídos em uma lista de nome lista_do_felippe 
// e após incluído todos os números, solicite ao usuário um número X 
// e diga se o número X está na lista ou não.

//structs//
typedef struct lista_do_felippe
{                   
    struct registro *inicio;                //ponteiro inicial para poder percorrer a lista
}lista_do_felippe;

typedef struct registro
{   
    int valor;
    struct registro *proximo;               //armazena o endereço de uma struct tipo 'registro' 
}registro;

//declarando as funcoes
lista_do_felippe *aloca_lista(); 
registro *aloca_registro();
void incluir_na_lista(lista_do_felippe *lista, int x);
void Ler_e_consultar_numeros(lista_do_felippe *l1);


////MAIN////MAIN////MAIN////MAIN////
int main(){

    lista_do_felippe *l1;              
    l1=aloca_lista();                       //aloca_lista retorna os endereços disponíveis para atribuir os dados

    printf("Digite os 10 valores na lista 1:\n");
    Ler_e_consultar_numeros(l1);
    

    return 0;
}



/////////funções///////////

lista_do_felippe *aloca_lista()             //função para poder alocar uma nova lista sempre que chamar
{
    lista_do_felippe *novo;         
    novo = (lista_do_felippe*)malloc(sizeof(lista_do_felippe));
    return novo;                            //retorna os endereços liberados pelo calloc
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro*)malloc(sizeof(registro));
    return novo;
}

//

void incluir_na_lista(lista_do_felippe *lista, int x) 
{
    registro *novo;                         //ponteiro pq vai receber os endereços do aloca registro?
    registro *aux;                          //ponteiro pq recebe o endereço do inicio da lista e do proximo
    novo = aloca_registro();
    novo->valor = x;                        //add o valor que o usuário queria no registro 'novo'

    if (lista->inicio==NULL)                //se estiver vazia
    {
        lista->inicio = novo;               //fazer o registro 'novo' ser o primeiro da lista
    }
    else
    {
        aux = lista->inicio;                //aux, oq se for a lista normal vai dar merda
        while(aux->proximo!=NULL)           //percorre a lista até achar o fim para incluir o novo valor
        {
            aux = aux->proximo;             //lista->inicio->proximo
        }

        aux->proximo = novo;                //aux é o atual fim lista, faz o registro 'novo' ser o novo fim.
    }
}


void Ler_e_consultar_numeros(lista_do_felippe *l1){
    registro *aux = l1->inicio;

    for(int i = 0;i<10;i++){
        int x=0;
        scanf("%i", &x);
        incluir_na_lista(l1,x);
    }

    aux = l1->inicio;                //aux, oq se for a lista normal vai dar merda
    while(aux->proximo!=NULL)           //percorre a lista até achar o fim para incluir o novo valor
    {
        aux = aux->proximo;             //lista->inicio->proximo
    }

    printf("Deseja consultar qual numero?");
    int i;
    scanf("%i", &i);
    aux = l1->inicio;    
    int verifier=0;            
    while(aux->proximo!=NULL)           
    {
        if(i==aux->valor){
            verifier++;
        }
        aux = aux->proximo;            
    }
    if(verifier>0){
        printf("O valor aparece %i vez(es) na lista!\n", verifier);
    }else{
        printf("O valor nao esta na lista...\n");
    }

}