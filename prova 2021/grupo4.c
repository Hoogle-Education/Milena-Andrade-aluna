// 313440226100
// 31 34 40 22 61 00
// mesa: 31
// mesa: 4331
// mesa: 044331
// peca: 22
// sequencia: 6100

#include <stdio.h>
#include <string.h>
#define BUFFER 500

int Juntar(char* sequencia, char peca[]){

  int tamanhoSequencia = strlen(sequencia);

  if(tamanhoSequencia == 0){
    strcat(sequencia, peca);
    return 1;
  }

  if(sequencia[0] == peca[0]){
    char temp = peca[0];
    peca[0] = peca[1];
    peca[1] = temp;
    
    char aux[BUFFER] = "";
    strcat(aux, peca);
    strcat(aux, sequencia);
    strcpy(sequencia, aux);
    return 1;
  }

  if(sequencia[tamanhoSequencia - 1] == peca[0]){
    strcat(sequencia, peca);
    return 1;
  }
  
  if(sequencia[0] == peca[1]){
    char aux[BUFFER] = "";
    strcat(aux, peca);
    strcat(aux, sequencia);
    strcpy(sequencia, aux);
    return 1;
  }

  if(sequencia[tamanhoSequencia - 1] == peca[1]){
    
    char temp = peca[0];
    peca[0] = peca[1];
    peca[1] = temp;
    
    char aux[BUFFER] = "";
    strcat(aux, sequencia);
    strcat(aux, peca);
    strcat(sequencia, aux);
    return 1;
  }

  return 0;
}

int main()
{

  char sequencia[BUFFER];
  char mesa[BUFFER] = "";
  scanf(" %s", sequencia);
  int itWorks = 1, tam = strlen(sequencia);

  for(int i=0; i<tam; i+=2){

    char peca[BUFFER] = "aa";
    peca[0] = sequencia[i];
    peca[1] = sequencia[i+1];

    if( itWorks == 0 ){
      printf("%s", peca);
      continue;
    }

    if( !(Juntar(mesa, peca)) ){
      printf("Mesa: %s\n", mesa);
      printf("Peca: %s\n", peca);
      printf("Sequencia: ");
      itWorks = 0;
    }
  }

  if(strlen(mesa) == tam){
      printf("Mesa: %s\n", mesa);
      printf("Peca: \n");
      printf("Sequencia: \n");
  }else printf("\n");
  
  return 0;
}