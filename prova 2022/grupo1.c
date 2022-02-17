#include <stdio.h>
#include <string.h>
#define BUFFER 200

/* ArabeParaRomana: recebe um número em árabe, e retorna a sua string em
numeração romana */
void ArabeParaRomana(int arabe, char *romana)
{
 /* valores e respetivas designações em numeração romana, por ordem */
 static int valor[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 0 };

 static char *texto[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I", ""};

 int i;
 /* inicializar a numeração romana com a string vazia */
 strcpy(romana, "vazia");
 /* processar todos os valores, do maior para o menor */
 for(i = 0; i < 14 && arabe != 0; i++){

    // printf("i = %d || arabe = %d\n", i, arabe);
    while(arabe >= valor[i]) {

      if( strcmp(romana, "vazia") == 0 ) strcpy(romana, texto[i]);
      else strcat(romana, texto[i]);

      arabe -= valor[i];
    }

 }

}

int main(void){

  char rtn[200] = "";

  int n;

  scanf(" %d", &n);

  ArabeParaRomana(n, rtn);

  printf("%s\n", rtn);

  return 0;
}