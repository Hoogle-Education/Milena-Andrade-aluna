#include <stdio.h>
#include <string.h>
#define BUFFER 500

int Juntar(char* sequencia, char peca[]){

  int tamanhoSequencia = strlen(sequencia);

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
  char peca[BUFFER];
  scanf(" %s", sequencia);
  scanf(" %s", peca);

  if(Juntar(sequencia, peca))
    printf("%s\n", sequencia);
  else
    printf("Peca %s nao pode ser adicionada a %s.", peca, sequencia);

}