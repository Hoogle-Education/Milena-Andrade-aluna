#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Divisores(int N)
{
 int i;

  printf("%d\n", N);

 for(i=1; i<=N ; i++)
  if(N%i == 0)
    printf("%d ", i);
}

// dado um número inteiro N, colocar os divisores,
// testando a divisão pelos números de 2 a N/2
int main(int argc, char **argv)
{

  if(argc != 2) return 0;

  // strlen -> 1 -> caracter -> printf(caracter)
  // strlen > 1 -> string -> ...

  // printf("Divisores: %c\n", *argv[1]);
  Divisores( (int)atof(argv[1]) );

}