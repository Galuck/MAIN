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


int qtdPares = 0;
int valor[1000];
int matrix[30][30];


////MAIN////MAIN////MAIN////MAIN////
int main(){

    for(int y=0; y>100; y++){
        for(int x=0; x>100; x++){
            matrix[x][y]=0;
        }
    }


    printf("Digite a quantidade N de pares de valores:  \n");
    scanf("%i", &qtdPares);
    
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

    return 0;
}


