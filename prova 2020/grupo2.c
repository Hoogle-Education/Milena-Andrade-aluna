#include <stdio.h>
#define MAXTAM 10010
#define BUFFER 200

void MostrarDamas(int linhaDamas[], int tam){

  char tabuleiro[BUFFER][BUFFER];

  for(int i=tam-1; i>=0; i--){
    for(int j=0; j<tam; j++){
      int posDama = linhaDamas[i];

      if(j == posDama) tabuleiro[j][i] = '#';
      else tabuleiro[j][i] = '.';
    }
  }

  for(int i=0; i<tam; i++){
   for(int j=tam-1; j>=0; j--) printf("%c", tabuleiro[i][j]);

   printf("\n");
  }

}

int main(int argc, char const *argv[])
{
  
  int tam, linhaDamas[MAXTAM];
  printf("Insira o tamanho do tabuleir: ");
  scanf(" %d", &tam);

  printf("Insira a posição das das damas, em cada coluna, da direita para esquerda no tabuleiro:\n");

  for(int i=0; i<tam; i++) scanf(" %d", &linhaDamas[i]);

  MostrarDamas(linhaDamas, tam);

  return 0;
}