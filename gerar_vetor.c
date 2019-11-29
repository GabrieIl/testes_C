#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    int *vetor, num, i, aux, random;

    //Inicialização do gerador de números aleatórios de forma variável;
    srand((unsigned int)time(NULL));

    //Input dos dados;
    printf("\n > Tamanho do vetor: ");
    scanf("%d", &num);

    //Alocação do vetor;
    vetor = (int *)malloc(sizeof(int)*num);

    //Alimentação crescente do vetor;
    for(i=0; i<num; i++){
        vetor[i]=i+1;
    }
    
    //Imprimindo o vetor antes de embaralhado;
    printf("\n Vetor antes de embaralhado:");
    for(i=0; i<num; i++){
        printf("\n %d", vetor[i]);
    }
    printf("\n");
    
    //Embaralhando o vetor;
    for(i=0; i<num; i++){
        random=rand()%num;
        aux = vetor[i];
        vetor[i] = vetor[random];
        vetor[random] = aux;
    }
    
    //Imprimindo depois de embaralhado;
    printf("\n Vetor depois de embaralhado:");
    for(i=0; i<num; i++){
        printf("\n %d", vetor[i]);
    }
    printf("\n");
    

    return 0;
}
