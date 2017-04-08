#include <stdio.h>
#include <stdlib.h>

int main(){

  int index, numero, saida=0, *sequencia;

  printf("Informe numero inteiro N: ");
  scanf(" %d",&numero);

  if(numero<=0){
    saida=1;
    printf("Numero informado invalido.\n");
  }

  else{

    sequencia=(int*)malloc(sizeof(int)*numero);

    if(sequencia==NULL){
      saida=1;
      printf("Memoria insuficiente no heap para alocacao.\n");
    }

    else{

      printf("Numero valido, informe sequencia a seguir:\n");
      for(index=0;index<numero;index++){
        printf("Informe %d-esimo termo: ",index+1);
        scanf(" %d",sequencia+index);
      }

      printf("N = %d\nSequencia:",numero);
      for(index=0;index<numero;index++) printf(" %d",sequencia[index]);
      printf("\n");

      free(sequencia);

    }

  }

  return saida;
}
