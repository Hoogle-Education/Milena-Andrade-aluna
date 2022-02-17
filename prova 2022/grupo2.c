#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

unsigned int randaux() {
  static long seed = 1;
  return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}

void GerarMundo(int mundo[MAX_SIZE][MAX_SIZE], int L, int C) {
  int i, j;
  for (i = 0; i<L; i++)
  for (j = 0; j<C; j++)
  mundo[i][j] = randaux() % 5 - 2;
}

void MostraMundo(int mundo[MAX_SIZE][MAX_SIZE], int L, int C){

  int i, j;

  for(i=0; i<L; i++){
    printf("Linha %d:", i+1);
    for(j=0; j<C; j++){
      printf(" %d", mundo[i][j]);
    }
    printf("\n");
  }

}

void main() {
  int i, j, L, C;
  int mundo[MAX_SIZE][MAX_SIZE];
  scanf("%d %d", &L, &C);

  GerarMundo(mundo, L, C);
  MostraMundo(mundo, L, C);
}