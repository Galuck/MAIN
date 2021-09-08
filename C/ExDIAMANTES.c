

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>


int main()//ignore a pilha pls
{
  int diamante=0;
  char mina[1000];
  printf("Digite a ENTRADA para a MINA: \n");
  scanf("%s", mina);
  for (int i = 0; i < strlen(mina); i++){
    if (mina[i] == '\0'){
      break;
    }
    if (mina[i] == '<'){
      for (int j = i; j< strlen(mina); j++){
        if (mina[j] == '>'){
          diamante++;
          break;
        }
      }
    }
  }
  printf("%d DIAMANTES!!\n", diamante);
  
    
  printf("\n");
  return 0;
}

