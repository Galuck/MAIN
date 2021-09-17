//Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base.
//A seguinte operação é ralizada enquanto tiver 2 ou mais cartas na pilha.
//Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.
//Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.
//Cada linha de entrada (com exceção da última) contém um número n ≤ 50. 
//A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída.
// A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente.

//A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. 
//A última linha contém o valor 0.
//Para cada caso de teste, imprima duas linhas.
// A primeira linha apresenta a sequência de cartas descartadas, cada uma delas separadas por uma vírgula e um espaço.
// A segunda linha apresenta o número da carta que restou. Nenhuma linha tem espaços extras no início ou no final. 
//Veja exemplo para conferir o formato esperado.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

typedef struct fila{//*************FILA*******************
    Lista *inicio;
    Lista *fim;
}Fila;

int pop(Fila *p){
    int carta;
    Lista *l;

    l = p->inicio;
    carta = l->info;

    p->inicio = l->prox;
    if(p->inicio==NULL){
        p->fim = NULL;
    }
    free(l);

    return carta;
}

void *push(Fila *fila, int carta){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = carta;
    novo->prox = NULL;
    if(fila->inicio==NULL){
        fila->inicio = novo;
        fila->fim = novo;
    }else{
    fila->fim->prox = novo;
    fila->fim = novo;
    }
}

Fila *alocarFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int main(){

    int n;
    int carta;
    int contador = 0;
    Fila *fila;
    fila = alocarFila();

    do{
        scanf("%d", &n);
        if(n){
            contador = n;
        for(int i=1;i<=n;i++){
            push(fila, i);
        }

        printf("Discarded cards:");

        while(contador!=1){
    
            printf(" %d ", pop(fila));
            push(fila, pop(fila));
            if(contador==2){
                printf("\nRemaining Card: %d", pop(fila));
            }

        if(contador!=2){
            printf(",");
            contador--;
        }
        }
        printf("teste");
        
        }
    }while(n!=0);

    return 0;
}