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

  printf("Divisores: %d\n", atoi(argv[1]));
  Divisores( atoi(argv[1]) );

}