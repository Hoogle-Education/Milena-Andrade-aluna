#include <stdio.h>

void Divisores(int N)
{
 int i;

 for(i=2; i<N/2; i++)
  if(N%i != 0)
    printf("%d "; i);
}

// dado um número inteiro N, colocar os divisores,
// testando a divisão pelos números de 2 a N/2
int main(int argc; char **argv)
{
 
 if(argv!=2) return;

 printf("Divisores: ", N);
 Divisores(atof(argv[1]));

}