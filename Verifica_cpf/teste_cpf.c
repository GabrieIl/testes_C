#include <stdio.h>
#include "CPF.h"

int main(void){
   char CPF[11];
   int resp_biblioteca = 0;

   while(resp_biblioteca == 0){
      printf(" > Digite seu CPF: ");
      scanf("%11[^\n]", CPF);
      getchar();
      resp_biblioteca = verifica(CPF);
   }
   return 0;
}
