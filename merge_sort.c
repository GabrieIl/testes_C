#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


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


int main(void){
    long int *vetor, tam, i;

    printf("\n > Tamanho do vetor: ");
    scanf("%ld", &tam);

    clock_t start1 = clock();
    vetor = gerar_vetor(tam, 1);
    clock_t stop1 = clock();
    printf("\n Tempo para gerar o vetor: %.5f\n", ((double)(stop1-start1))/CLOCKS_PER_SEC);

    clock_t start2 = clock();
    merge_sort(vetor, 0, tam-1);
    clock_t stop2 = clock();
    printf("\n Tempo para ordenar o vetor: %.5f\n", ((double)(stop2-start2))/CLOCKS_PER_SEC);
    
    /*for(i=0;i<tam;i++){
        printf("\n %d", vetor[i]);
    }*/

    return 0;
}
