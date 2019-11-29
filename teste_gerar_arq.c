#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int main(void){
    int num;

    printf(" > Quantidade de números no arquivo: ");
    scanf("%d", &num);
    gerar_arquivo_numeros(num, 1);
    printf(" > O arquivo foi gerado!\n");

    return 0;
}
