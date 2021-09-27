#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    struct Elemento *inicio;
    struct Elemento *fim;
}Lista;

typedef struct Elemento{
    int id;
    int valor;
    struct Elemento *proximo;
    struct Elemento *anterior;
    
}Elemento;

void inserir_noFim(Lista *lista, int valorNovo, int id){

    Elemento *novoElemento;
    novoElemento= malloc(sizeof(Elemento));
    novoElemento->valor=valorNovo;
    novoElemento->id=id;

    if(lista->inicio==NULL){
        lista->fim=novoElemento;
        lista->inicio=novoElemento;
    }else{
        novoElemento->anterior=lista->fim;
        lista->fim->proximo=novoElemento;
        lista->fim= novoElemento; //novoElemento vira o fim e o antigo fim se mantem
    }
    printf("\nValor (%i) adicionado no elemento de id (%i) [adicionado no fim]\n", valorNovo, id);
}

void inserir_noInicio(Lista *lista, int valorNovo, int id){

    Elemento *novoElemento;
    novoElemento= malloc(sizeof(Elemento));
    novoElemento->valor=valorNovo;
    novoElemento->id=id;

    if(lista->inicio==NULL){
        lista->fim=novoElemento;
        lista->inicio=novoElemento;
    }else{
        novoElemento->proximo=lista->inicio;//não precisa mexer no fim, pois a lista não moveu
        lista->inicio->anterior=novoElemento;
        lista->inicio= novoElemento;//novoElemento vira o inicio e o antigo inicio se mantem 
    }
    printf("\nValor (%i) adicionado na lista de id (%i) [adicionado no inicio]\n", valorNovo, id);
}

void printarLista_Inicio(Lista *lista){
    Elemento *aux;
    aux = lista->inicio;
    printf("\n");
    printf("\nPrintando a Lista pelo Inicio: \n");
    while(aux!=NULL){
        printf("id(%i) | valor(%i)\n", aux->id, aux->valor);
        aux= aux->proximo; //faz a lista andar
    }
    printf("\n");
}

void printarLista_Fim(Lista *lista){
    Elemento *aux;
    aux= lista->fim;
    printf("\n");
    printf("\nPrintando a Lista pelo Fim: \n");
    while(aux!=NULL){
        printf("id(%i) | valor(%i)\n", aux->id, aux->valor);
        aux= aux->anterior;
    }
    printf("\n");
}

//adicionar void remover

void remover(Lista *lista, int idParaRemover){
    Elemento *aux;
    aux=lista->inicio;
    while(aux!= NULL){
        if(aux->id==idParaRemover){

            if(aux->proximo==NULL){
                lista->fim=aux->anterior;
            }else{
                aux->proximo->anterior= aux->anterior;
            }
            if(aux->anterior==NULL){
                lista->inicio=aux->proximo;
            }else{
                aux->anterior->proximo=aux->proximo;
            }
            printf("\nElemento de id (%i) e valor (%i) removido com sucesso\n", aux->id, aux->valor);
            free(aux);
            break;//encontrou o valor

        }else{
            aux=aux->proximo;
        }
    }
    if(aux==NULL){
        printf("\nElemento náo encontrado na Lista...\n");
    }
}

int main(){

    Lista *l1;

    l1 =malloc(sizeof(Lista)); //depois alocar listas de outra forma
    //pra fazer o mesmo em outras listas é só declarar uma nova

    inserir_noFim(l1, 30, 1);

    inserir_noInicio(l1, 20, 2);

    inserir_noInicio(l1, 10, 3);

    printarLista_Inicio(l1);

    inserir_noFim(l1, 40, 4);
    inserir_noFim(l1, 50, 5);
    inserir_noFim(l1, 60, 6);
    inserir_noFim(l1, 70, 7);
    inserir_noFim(l1, 80, 8);
    inserir_noFim(l1, 90, 9);
    inserir_noFim(l1, 100, 10);
    
    printarLista_Inicio(l1);    

    printarLista_Fim(l1);


    remover(l1, 3);

    printarLista_Inicio(l1);//valor agora removido



    printf("\n");
    return 0;
}