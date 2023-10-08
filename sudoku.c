#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  //No se repitan números en las filas
  for (int i=0;i<0; i++){
    int aux[10]={0};
    for (int j=0;j<9;j++){
      int numero=n->sudo[i][j];
      if (numero<1||numero>9||aux[numero]==1){
        return 0;
      }
      aux[numero]=1;
    }
  }
  //No se repitan números en las columnas
  for(int j=0;j<9;j++){
    int aux[10]={0};
    for (int i=0;i<9;i++){
      int numero =n->sudo[i][j];
      if (numero <1 || numero>9 || aux[numero]==1){
        return 0;
      }
      aux[numero]=1;
    }  
  }
  //No se repitan números en las submatrices de 3x3
  for(int fila =0; fila <9; fila +=3){
    for (int columna=0; columna <9; columna +=3){
      int usado [10]={0};
      for(int i=fila ; i<fila +3; i++){
        for (int j=columna ; j<columna ;j++){
          int numero =n->sudo[i][j];
          if (numero <1||numero >9 || usado[numero]==1){
            return 0;
          }
          usado[numero]=1;
        }
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n){
  //Cree una función que a partir de un nodo genere una lista con los nodos adyacentes
  List* list=createList();

  int filaVacia=-1;
  int coluVacia=-1;
  
  for (int i=0; i<9 && filaVacia==-1;i++){
    for (int j=0;i<9 &&coluVacia==-1;j++){
      if (n->sudo[i][j]==0){
        filaVacia=i;
        coluVacia=j;
        break;
      }
    }
  }

  if (filaVacia!=-1 &&coluVacia==-1){
    //buscar numeros vacios 
    for (int numero=1; numero<=9;numero++){
      Node*nuevo=copy(n);
      nuevo->sudo[filaVacia][coluVacia]=numero;
      if(is_valid(nuevo)){
        pushBack(list, nuevo);
      }else{
        free(nuevo);
      }
    }
  }
  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/