#include <stdio.h>
#include <stdlib.h>
#include <string.h>


  typedef struct node{
    int value;
    struct node *next;
    struct node *anterior;
  
  }node;


  void print_List(node *head){
    node *aux= head;
    printf("\n Mostrando lista em ordem de criação: \n");
    while(aux!= NULL){
      printf("-(%i)- \n", aux->value); //aux é o inicio, e o inicio é n1, printa valor de n1
      aux= aux->next; //anda para frente a lista (vai para o proximo)
    }
  }

  void print_List_Backwards(node *tail){
    node *aux= tail;
    printf("\n Mostrando lista em ordem invertida de criação: \n");
    while(aux!= NULL){
      printf("-(%i)- \n", aux->value); //aux é o fim, e o fim é n3, printa valor de n3
      aux= aux->anterior; //anda para frente a lista (vai para o anterior)
    }
  }

  node *criarNode(int value){

    node *newNode = malloc(sizeof(node));
    newNode->value =value;
    newNode->next=NULL;
    newNode->anterior=NULL;
  
    return newNode;
  }

  node *addNode_to_Head(node *head, node *addedNode){
    addedNode->next=head;
    addedNode->anterior=NULL;
    return addedNode;//vira a nova cabeça
  }

  void addNode_after_otherNode(node *nodeToInsertAfter, node *newNode){
    newNode->next=nodeToInsertAfter->next;
    nodeToInsertAfter->next=newNode;
  }
  
  node *find_Node(node *head, int value){
    node *aux=head;
    while(aux!=NULL){
      if(aux->value==value){
        printf("\nEncontrado\n");
        return aux;
      }
      aux=aux->next;
    }
    printf("\nNao encontrado\n");
    return NULL;
  }

  

int main(void) {

  node *head= NULL; //inicio
  node *tail=NULL; //fim

  node *temp;

  for(int i=0; i<110; i+=10){
    temp = criarNode(i);
    head = addNode_to_Head(head, temp);
  }
  
  temp = find_Node(head, 50); //variavel vai receber valor do 
  printf("\nValor encontrado: %d\n",temp->value);

  addNode_after_otherNode(temp, criarNode(69));// vai add após o node temp (que agora é 50)

  /////////////////////////

  print_List(head);



  return 0;
}