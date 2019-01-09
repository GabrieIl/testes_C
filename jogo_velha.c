#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void limpa_buffer(void){
   char c;
   while((c = getchar()) != '\n' && c != EOF);
}


void tabuleiro(char jogo[4][4], char mensagem, int vez){
   int i, j;
	
   system("clear");
   printf("________________________________\n");
	printf("     J O G O  D A  V E L H A    \n");
   for(i = 0; i < 4; i++){
		printf("\n");
		for(j = 0; j < 4 ; j++){
			if((i==0)||(j==0)){
            if(j == 0){
               printf("\t   %c ", jogo[i][j]);
            }else{
               printf(" %c ", jogo[i][j]);
            }
			}else{
		    	printf("[%c]", jogo[i][j]);
	      }
		}
	}
   printf("\n\n");
   printf(" ______________________________ \n");
   printf("|             AVISOS           |\n");
   printf("|------------------------------|\n");
   if(mensagem == 'a'){
      if(vez == 0){
         printf("|  Digite a linha e a coluna.  |\n");
      }else if(vez % 2 == 0){
         printf("|        É a vez do [x]        |\n");
         printf("|  Digite a linha e a coluna.  |\n");
      }else{
         printf("|        É a vez da [O]        |\n");
         printf("|  Digite a linha e a coluna.  |\n"); 
      }
   }else if(mensagem == 'b'){
      printf("|   Essa posição não existe.   |\n");
   }else if(mensagem == 'c'){
      printf("| Essa posição já está ocupada.|\n");
   }else if(mensagem == 'x'){
      printf("|          Fim de jogo!        |\n");
      printf("|      O vencedor foi [x].     |\n");
   }else if (mensagem == 'O'){
      printf("|          Fim de jogo!        |\n");
      printf("|      O vencedor foi [O].     |\n");
   }else{
      printf("|          Fim de jogo!        |\n");
      printf("|            Empate.           |\n");
   }
   printf("|______________________________|\n");
}


char verifica(char jogo[4][4]){

   //Verifica linhas iguais;
   if(jogo[1][1] == jogo[1][2] && jogo[1][1] == jogo[1][3]){
      return jogo[1][1];
   }else if(jogo[2][1] == jogo[2][2] && jogo[2][1] == jogo[2][3]){
      return jogo[2][1];
   }else if(jogo[3][1] == jogo[3][2] && jogo[3][1] == jogo[3][3]){
      return jogo[3][1];

   //Verifica colunas iguais;
   }else if(jogo[1][1] == jogo[2][1] && jogo[1][1] == jogo[3][1]){
      return jogo[1][1];
   }else if(jogo[1][2] == jogo[2][2] && jogo[1][2] == jogo[3][2]){
      return jogo[1][2];
   }else if(jogo[1][3] == jogo[2][3] && jogo[1][3] == jogo[3][3]){
      return jogo[1][3];
   
   //Verifica diagonais iguais;
   }else if(jogo[1][1] == jogo[2][2] && jogo[1][1] == jogo[3][3]){
      return jogo[1][1];
   }else if(jogo[3][1] == jogo[2][2] && jogo[3][1] == jogo[1][3]){
      return jogo[3][1];
   }else{
      return ' ';
   }
}


int main(){  
   
      /* MENSAGENS
       * a - Digite a linha e a coluna.
       * b - Essa posição não existe.
       * c - Essa posição já está ocupada.
       * x/O - Fim de jogo!*/
   
   int vez = 0;
   char linha, coluna, mensagem = 'a';
   char jogo[4][4] = {{' ','1','2','3'},
                       {'A',' ',' ',' '},
                       {'B',' ',' ',' '},
                       {'C',' ',' ',' '}};
    
   while(1){
  		if(vez == 9 || verifica(jogo) != ' '){
         tabuleiro(jogo, verifica(jogo), vez);
         break;
      }

      tabuleiro(jogo, mensagem, vez);
		printf("\n");
		printf("> ");
	   linha = getchar();
      linha = toupper(linha);
      coluna = getchar();
      limpa_buffer();

      if((linha-64) > 3 || (coluna-48) > 3){
         mensagem = 'b';

      }else if((jogo[linha-64][coluna-48]) == ' '){
         if(vez % 2 == 0){
            jogo[linha-64][coluna-48] = 'x';
            mensagem = 'a';
         }else{
            jogo[linha-64][coluna-48] = 'O';
            mensagem = 'a';
         }
         vez++;
      }else if(linha == '0' && coluna == '0'){
         //Saída do jogo, para o programador
         break;
      }else{
         mensagem = 'c';

      }
   }

	return 0;
}
