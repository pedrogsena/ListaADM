#include <stdio.h>
#include <stdlib.h>

#define TamVetQ1 10

int main(){

  int index, saida=0, *vetor;
  vetor=(int*)malloc(sizeof(int)*TamVetQ1);

  if(vetor==NULL){
    saida=1;
    printf("Memoria insuficiente no heap para alocacao.\n");
  }

  else{

    for(index=0;index<TamVetQ1;index++) vetor[index]=index+1;
    printf("Vetor:");
    for(index=0;index<TamVetQ1;index++) printf(" %d",vetor[index]);
    printf("\n");
    free(vetor);

  }

  return saida;

}
