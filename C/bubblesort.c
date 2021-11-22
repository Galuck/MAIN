#include <stdio.h>
#include <stdlib.h>

//Faça um programa que receba do usuário N valores até que seja digitado o valor 0,
//inclua os N valores em uma lista ligada e utilizando o algoritmo bubblesort ordene todos os valores dentro da lista ligada.

//structs//
typedef struct lista
{                   
    struct registro *inicio;           
}lista;

typedef struct registro
{   
    int valor;
    struct registro *proximo;              
}registro;

//declarando as funcoes
lista *aloca_lista(); 
registro *aloca_registro();
void incluir_na_lista(lista *lista, int x);
int Ler_numeros(lista *l1);
void bubblesort(lista *lista, int count);


////MAIN////MAIN//
int main(){

    lista *l1;              
    l1=aloca_lista();                  

    printf("Digite os 10 valores na lista 1:\n");
    int count;
    count = Ler_numeros(l1);

    bubblesort(l1, count);
    

    return 0;
}



/////////funções///////////

lista *aloca_lista()           
{
    lista *novo;         
    novo = (lista*)malloc(sizeof(lista));
    return novo;                           
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro*)malloc(sizeof(registro));
    return novo;
}

//

void incluir_na_lista(lista *lista, int x) 
{
    registro *novo;                      
    registro *aux;                       
    novo = aloca_registro();
    novo->valor = x;                      

 
    if (lista->inicio==NULL)              
    {
        lista->inicio = novo;           
    }
    else
    {
        aux = lista->inicio;              
        while(aux->proximo!=NULL)           
        {
            aux = aux->proximo;            
        }

        aux->proximo = novo;   
        printf("\n Valor adicionado: \n%i", novo->valor);  
        printf("\n");
    }
}


void bubblesort(lista *lista, int count)
{
    int j, i;
    int trocado = 1;
    registro *aux;
    aux= lista->inicio;

    int temp;

  
    for (i = 0; i <= count; i++)
    {
  
        aux= lista->inicio;
        trocado = 0;
  
        for (j = 0; j < count - i - 1; j++) 
        {
  
            if (aux->valor > aux->proximo->valor)
            {
  
                temp = aux->valor;
                aux->valor = aux->proximo->valor;
                aux->proximo->valor= temp;
                trocado = 1;
            }
  
            aux = aux->proximo;
        }
  
  
        if (trocado == 0)
            break;
    }

    printf("\n Lista ordenada: ");
    aux= lista->inicio;
    while(aux != NULL)           //percorre a lista até achar o fim para incluir o novo valor
        {
            printf(" %i,", aux->valor);  
            aux = aux->proximo;             //lista->inicio->proximo
        }

}

int Ler_numeros(lista *l1){
    int count;
    count=0;
    for(int i = 0; ;i++){
        int x=0;
        scanf("%i", &x);
        if(x == 0){
    
            break;
        }

        incluir_na_lista(l1,x);
        count++;
    }
    registro *aux;
    aux= l1->inicio;
    printf("\nLista Desordenada: ");
    while(aux != NULL)           
        {
            printf(" %i,", aux->valor);  
            aux = aux->proximo;             
        }
    printf("\n");
    return count;
}

