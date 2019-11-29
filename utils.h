#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Função para gerar vetores dado o tamanho e flag;
//Retorna um ponteiro para o vetor gerado;
//Flag =0 ~ gera um vetor de elementos crescente;
//Flag!=0 ~ gera um vetor aleatório no range do tamanho;


long int *gerar_vetor(long int tam, int flag){
    long int *vetor, i, aux, random;

    vetor = (long int *)malloc(sizeof(long int)*tam);
    
    for(i=0; i<tam; i++){
        vetor[i]=i+1;
    }
     
    if(flag!=0){
        srand((unsigned int)time(NULL));
        for(i=0; i<tam; i++){
            random=rand()%tam;
            aux = vetor[i];
            vetor[i] = vetor[random];
            vetor[random] = aux;
        }
        return vetor;
    
    }else{
        return vetor;
    }
}


//Função para gerar um arquivo .txt com um número por linha;
//É necessário passar um n inteiro e positivo;
//É necessário passar uma flag: 
//  -  = 0: Números ordenados
//  - != 0: Números aleatórios
//O arquivo criado terá o nome de <numeros.txt>;
//Qualquer execução acresentará valores ao arquivo caso ele já tenha sido criado;
long int gerar_arquivo_numeros(long int tam, int flag){
    long int i, *vetor;
    FILE *arq;
 
    arq = fopen("numeros.txt", "a");
    vetor = gerar_vetor(tam, flag); 
    for(i=0; i<tam; i++){
        fprintf(arq, "%ld\n", vetor[i]);
    }

    fclose(arq);
}
