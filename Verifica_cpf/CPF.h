//Retorna o tamanho de um vetor do tipo char;
int tamanho_vetor(char vetor[]){
   int i = 0;
  
   while(vetor[i] != 0){
      i++;
   }
   return i;
}


//Verifica se o vetor não possui todos os dígitos iguais;
int verifica_iguais(char vetor[]){
   int contador = 1, num_atual, num_anterior, i;
   
   for(i = 0; i <= 10; i++){
      num_atual = vetor[i] - '0';
      if(i == 0){
         num_anterior = num_atual;
      }else{
         if(num_anterior == num_atual){
            contador++;
         }
      }
   }
   return contador;
}


//Verifica se todos os dígitos do vetor são realmente números;
//Retorna 1 caso todos os dígitos forem inteiros;
int verifica_decimal(char vetor[]){
   int resultado = 1, i;

   for(i = 0; i <= 10; i++){
      if(0 > (vetor[i] - '0') > 9){
         resultado = 0;
         break;
      }
   }
   return resultado;
}


//A função principal retornará [1] caso o CPF seja válido e [0] caso seja inválido;
int verifica(char cpf[]){
   int dv1, dv2, resto1, resto2, soma1 = 0, soma2 = 0, temp, mult, i;

   //Verificação dos requisitos mínimos do CPF;
   if(tamanho_vetor(cpf) != 11 || verifica_decimal(cpf) != 1 || verifica_iguais(cpf) == 11){
      return 0;
   }else{
      //Separa os dígitos verificadores;
      dv1 = cpf[9] - '0';
      dv2 = cpf[10] - '0'; 
     
      //Calcula o dígito verificador 1;
      mult = 10;
      for(i = 0; i <= 8; i++){
         soma1 += (mult * (cpf[i] - '0'));
         mult--;
      }
      resto1 = soma1 % 11;
      if(resto1 < 2){
         resto1 == 0;
      }else{
         resto1 = 11 - resto1;
      }
      
      //Calcula o dígito verificador 2, caso o dv 1 seja autenticado;
      if(dv1 == resto1){
         mult = 11;
         for(i = 0; i <= 9; i++){
            soma2 = (mult * (cpf[i] - '0'));
            mult--;
         }  
         
         resto2 = soma2 % 11;
         if(resto2 < 2){
            resto2 == 0;
         }else{
            resto2 = 11 - resto2;
         }
         if(dv2 == resto2){
            //Valida o CPF retornando [1];
            return 1;
         }
     
      }else{
         return 0;
      }
   } 
}
