#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


/*void merge_sort(long int *vetor, long int inicio, long int meio, long int fim){
    long int *vetor_esq, *vetor_dir, i, j, k;

    //Aloca;
    vetor_esq = (long int *)malloc(sizeof(long int)*(meio-inicio+1));
    vetor_dir = (long int *)malloc(sizeof(long int)*(fim-meio));

    //Preenche;
    for(i=0; i<(meio-inicio+1); i++){
        vetor_esq[i] = vetor[inicio+i];
    }
    for(j=0; i<(fim-meio); j++){
        vetor_dir[j] = vetor[meio+1+j];
    }

    //Compara;
    i=0;
    j=0;
    k=inicio;
    while(i<meio-inicio+1 && j<fim-meio){
        if(vetor_esq[i]<vetor_dir[j]){
            vetor[k] = vetor_esq[i];
            i++;
        }else{
            vetor[k] = vetor_dir[j];
            j++;
        }
        k++;
    }

    while(i<meio-inicio+1){
        vetor[k] = vetor_esq[i];
        i++;
        k++;
    }
    
    while(j<fim-meio){
        vetor[k] = vetor_dir[j];
        j++;
        k++;
    }
    free(vetor_esq);
    free(vetor_dir);
}*/

void intercala(long int *vetor, long int inicio, long int meio, long int fim){
    long int *vetor_esq, *vetor_dir, i, j, k;

    vetor_esq = (long int *)malloc(sizeof(long int)*(meio-inicio+1));
    vetor_dir = (long int *)malloc(sizeof(long int)*(fim-meio));

    for(i=0;i<meio-inicio+1;i++){
        vetor_esq[i]=vetor[inicio+i];
    }
    for(j=0;j<fim-meio;j++){
        vetor_dir[j]=vetor[meio+1+j];
    }       
                
    i=0;
    j=0;
    k=inicio;
    while(i<meio-inicio+1 && j<fim-meio){
        if(vetor_esq[i]>vetor_dir[j]){
            vetor[k]=vetor_dir[j];
            j++;
        }else{
            vetor[k]=vetor_esq[i];
            i++;
        }
        k++;
    }

    while(i<meio-inicio+1){
        vetor[k]=vetor_esq[i];
        i++;
        k++;
    }

    while(j<fim-meio){
        vetor[k]=vetor_dir[j];
        j++;
        k++;
    }
    free(vetor_esq);
    free(vetor_dir);
}


void merge_sort(long int *vetor, long int inicio, long int fim){
    long int meio, i;

    if(inicio<fim){
        meio=(inicio+fim)/2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio+1, fim);
        intercala(vetor, inicio, meio, fim);
    }
    return;
}



/*void merge(long int *vetor, long int inicio, long int fim){
    long int meio;

    if(inicio<fim){
        meio=(inicio+fim)/2;
        merge(vetor, inicio, meio);
        merge(vetor, meio+1, fim);
        merge_sort(vetor, inicio, meio, fim);
    }
    return;
}*/


int main(void){
    char c, nome[15], linhas[10];
    long int i, k, *vetor=NULL;
    FILE *arq;

    printf(" > Nome do arquivo [com o formato]: ");
    scanf("%s", nome);
  
    arq = fopen(nome, "r");
    i=0;
    while(fgets(linhas, 10, arq)){
        vetor = (long int *)realloc(vetor, sizeof(long int));
        vetor[i] = atoi(linhas);
        i++;
    }

    fclose(arq);
    //for(k=0; k<i; k++){
    //    printf(" %ld\n", vetor[k]);
    //}
    merge_sort(vetor, 0, i-1);
    for(k=0; k<i; k++){
        printf(" %ld\n", vetor[k]);
    }

    return 0;
}
