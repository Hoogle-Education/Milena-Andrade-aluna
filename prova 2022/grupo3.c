#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

unsigned int randaux() {
  static long seed = 1;
  return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}

void GerarMundo(int mundo[MAX_SIZE][MAX_SIZE], int L, int C) {
  int i, j;
  for (i = 0; i<=L+1; i++){
    for (j = 0; j<=C+1; j++){
      if( i==0 || j == 0 ) mundo[i][j] = 7; // caso de borda a ser ignorado
      else if( i==L+1 || j==C+1) mundo[i][j] = 7; // caso de borda a ser ignorado
      else mundo[i][j] = randaux() % 5 - 2;
    }
  }
}

void MostraMundo(int mundo[MAX_SIZE][MAX_SIZE], int L, int C){

  int i, j;

  for(i=1; i<=L; i++){
    printf("Linha %d:", i+1);
    for(j=1; j<=C; j++){
      printf(" %d", mundo[i][j]);
    }
    printf("\n");
  }
}

int ComCovid(int mundo[MAX_SIZE][MAX_SIZE], int L, int C, int linha, int coluna){

  int count = 0;

  if(mundo[linha][coluna+1]!=7 && mundo[linha][coluna+1]<0) count++;

  if(mundo[linha][coluna-1]!=7 && mundo[linha][coluna-1]<0) count++;

  if(mundo[linha+1][coluna-1]!=7 && mundo[linha+1][coluna-1]<0) count++;

  if(mundo[linha+1][coluna]!=7 && mundo[linha+1][coluna]<0) count++;

  if(mundo[linha+1][coluna+1]!=7 && mundo[linha+1][coluna+1]<0) count++;

  if(mundo[linha-1][coluna-1]!=7 && mundo[linha-1][coluna-1]<0) count++;

  if(mundo[linha-1][coluna]!=7 && mundo[linha-1][coluna]<0) count++;

  if(mundo[linha-1][coluna+1]!=7 && mundo[linha-1][coluna+1]<0) count++;

  return count;
}

int SemCovid(int mundo[MAX_SIZE][MAX_SIZE], int L, int C, int linha, int coluna){
  int count = 0;

  if(mundo[linha][coluna+1]!=7 && mundo[linha][coluna+1]>0) count++;

  if(mundo[linha][coluna-1]!=7 && mundo[linha][coluna-1]>0) count++;

  if(mundo[linha+1][coluna-1]!=7 && mundo[linha+1][coluna-1]>0) count++;

  if(mundo[linha+1][coluna]!=7 && mundo[linha+1][coluna]>0) count++;

  if(mundo[linha+1][coluna+1]!=7 && mundo[linha+1][coluna+1]>0) count++;

  if(mundo[linha-1][coluna+1]!=7 && mundo[linha-1][coluna+1]>0) count++;

  if(mundo[linha-1][coluna]!=7 && mundo[linha-1][coluna]>0) count++;

  if(mundo[linha-1][coluna-1]!=7 && mundo[linha-1][coluna-1]>0) count++;

  return count;
}

int Saude(int mundo[MAX_SIZE][MAX_SIZE], int L, int C, int linha, int coluna){

  linha++;
  coluna++;

  int sem = SemCovid(mundo, L, C, linha, coluna);
  int com = ComCovid(mundo, L, C, linha, coluna);

  // printf("com = %d|| sem = %d\n", com, sem);
  // printf("linha = %d|| coluna = %d\n", L, C);

  if(mundo[linha][coluna] == 0){
    if( sem >= 2 ) mundo[linha][coluna] = 1;
  }else if( mundo[linha][coluna] > 0 ){
    if( sem <= 1 ) mundo[linha][coluna]--;
    else if( sem >= 5 || com >= 3) mundo[linha][coluna]*=(-1);
    else{
      mundo[linha][coluna]++;
      if(mundo[linha][coluna] > 2) mundo[linha][coluna] = 2;
    }
  }else{
    if(com <= 2) mundo[linha][coluna]*=(-1);
    else {
      mundo[linha][coluna]--;
      if(mundo[linha][coluna] < -2) mundo[linha][coluna] = -2;
    }
  }

  return mundo[linha][coluna];
}

void main() {
  int i, j, L, C, linha, coluna;
  int mundo[MAX_SIZE][MAX_SIZE];
  scanf("%d %d %d %d", &L, &C, &linha, &coluna);

  GerarMundo(mundo, L, C);
  // MostraMundo(mundo, L, C);
  printf("Saude = %d\n", Saude(mundo, L, C, linha, coluna) );
}