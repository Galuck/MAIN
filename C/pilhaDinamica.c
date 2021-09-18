#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 5
#define vazio -1

//pilha dinamica (com lista ligada)
int pilha [tamanho];
int topo= vazio;


int push(int valor){

    if(topo>=tamanho-1){
        return 0;  //cheio
    }
    topo++;
    pilha[topo]=valor;
    return 1;//incluido
}

int pop(int valor){
    if(topo==vazio){
        return 0;
    }

    int aux= pilha[topo];
    topo--;
    return 1;
}


int main(){
    push(69);
    push(420);
    push(666);
    push(45);
    push(55);
    
    printf("(%i)\n", pilha[4]);
    printf("(%i)\n", pilha[3]);
    printf("(%i)\n", pilha[2]);
    printf("(%i)\n", pilha[1]);
    printf("(%i)\n", pilha[0]);


    printf("\n");
    return 0;
}