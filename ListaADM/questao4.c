#include <stdio.h>
#include <stdlib.h>

int** gera_matriz(int numero_linhas, int numero_colunas){

  int i,j;
  int **pp_Matriz;

  pp_Matriz=(int**)malloc(numero_linhas*sizeof(int*));
  if(pp_Matriz==NULL) return NULL;

  for(i=0;i<numero_linhas;i++){

    pp_Matriz[i]=(int*)malloc(numero_colunas*sizeof(int));
    if(pp_Matriz[i]==NULL){
      free(pp_Matriz);
      return NULL;
    }

    for(j=0;j<numero_colunas;j++) pp_Matriz[i][j]=i; /* Ou i+1? */

  }

  return pp_Matriz;

}

void imprime_matriz(int **pp_Matriz, int numero_linhas, int numero_colunas){

  int i,j;

  printf("Matriz:\n");
  for(i=0;i<numero_linhas;i++){
    for(j=0;j<numero_colunas;j++) printf(" %2d",pp_Matriz[i][j]);
    printf("\n");
  }
  printf("\n");

  return;

}

int main(){

  int **Nova_Matriz;
  int i, j, numero_linhas, numero_colunas, saida=0;

  printf("Informe numero de linhas da matriz: ");
  scanf(" %d",&numero_linhas);
  printf("Informe numero de colunas da matriz: ");
  scanf(" %d",&numero_colunas);

  if(numero_linhas<=0||numero_colunas<=0){
    saida=1;
    printf("Valor(es) informado(s) invalido(s).\n");
  }

  else{

    Nova_Matriz=gera_matriz(numero_linhas,numero_colunas);
    if(Nova_Matriz==NULL){
      saida=1;
      printf("Memoria insuficiente no heap para alocacao.\n");
    }

    else{
      imprime_matriz(Nova_Matriz,numero_linhas,numero_colunas);
      free(Nova_Matriz);
    }

  }

  return saida;

}
