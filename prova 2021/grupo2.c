#include <stdio.h>
#include <string.h>
#define BUFFER 500

int PecaDomino(char str[]){

  if(strlen(str) != 2) 
    return 0; // false

  if( !(str[0]>='0' && str[0]<='6') )
    return 0; // false

  if( !(str[1]>='0' && str[1]<='6') )
    return 0; // false

  return 1; // true
}

int main()
{
 
  char str[BUFFER];
  scanf("%s", str);

  if (PecaDomino(str))
    printf("Peca valida.");
  else
    printf("Peca invalida.");
}