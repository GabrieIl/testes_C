#include <stdio.h>
#include <stdlib.h>


int main(void){
    int qtd, num, i;
    FILE *arq;

    arq = fopen("numeros.txt", "a");
    printf(" > Inserir quantos números: ");
    scanf("%d", &qtd);

    for(i=0; i<qtd; i++){
        printf(" - Número %d: ", i+1);
        scanf("%d", &num);
        fprintf(arq, "%d\n", num);
    }

    fclose(arq);
    return 0;
}
