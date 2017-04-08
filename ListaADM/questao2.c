#include <stdio.h>
#include <stdlib.h>

typedef char* string;

int main()
{

    string *vetor;
    char c,s;
    int i,j;
    int conta_letras;
    int conta_nomes=0;

    vetor=NULL;
    do{
        printf("Informe nome completo (digite <Enter> para sair): ");
        vetor=(string*)realloc(vetor,(conta_nomes+1)*sizeof(string));
        if(vetor==NULL){
            printf("Espaco insuficiente no heap para alocacao.\n");
            exit(1);
        }

        vetor[conta_nomes]=NULL;
        conta_letras=0;
        do{

            s=fgetc(stdin);
            if(s=='\n') s='\0';
            if(conta_letras==0) c=s;

            vetor[conta_nomes]=(string)realloc(vetor[conta_nomes],(conta_letras+1)*sizeof(char));
            if(vetor[conta_nomes]==NULL){
                printf("Espaco insuficiente no heap para alocacao.\n");
                exit(1);
            }

            vetor[conta_nomes][conta_letras]=s;
            if(c!='\0')conta_letras++;

        } while(s!='\0');

        if(c!='\0') conta_nomes++;

    } while(c!='\0');

    if(conta_nomes<=0) printf("Nenhum nome registrado.\n");
    else{

        printf("\nLista de nomes:\n");
        for(i=0;i<conta_nomes;i++){

            printf("Nome: ");
            for(j=0;vetor[i][j]!='\0';j++) printf("%c",vetor[i][j]);
            printf("\n");

        }

        printf("\n");

    }

    free(vetor);
    return 0;

}
