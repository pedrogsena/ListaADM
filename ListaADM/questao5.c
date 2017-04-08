#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *vetor;
    int number,index;
    int tamanho=0;
    int qte_dezenas=0;
    char c;
    vetor=NULL;

    do{

        vetor=(int*)realloc(vetor,10*(qte_dezenas+1)*sizeof(int));
        if(vetor==NULL){
            printf("Espaco insuficiente no heap para alocacao de memoria.\n");
            exit(1);
        }

        for(index=0;index<10;index++){

            do{
                c=fgetc(stdin);
            } while(c=='\n');

            if(c<'0'||c>'9'){
                printf("\nDigito invalido.\n");
                exit(1);
            }

            number=atoi(&c);
            if(number==0) break;

            vetor[index+10*qte_dezenas]=number;
            tamanho++;

        }

        if(number!=0) qte_dezenas++;

    } while(number!=0);

    printf("Vetor: ");
    for(index=0;index<tamanho;index++) printf(" %d",vetor[index]);
    printf("\n\n");

    free(vetor);
    return 0;

}
