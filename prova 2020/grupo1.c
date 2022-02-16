#include <stdio.h>

int main()
{
  int divisor, n;

  printf("Funcao que verifica se um numero N e' primo:\nIndique N:");
  scanf(" %d", &n);
  
  if(n<=0)
    printf("Erro: o numero tem de ser maior que zero.\n");
  else {
    divisor=2;
    while(divisor*divisor<=n) {
      if(n%divisor == 0) {
        printf("\nNumero %d divisivel por %d\n", n, divisor);
        return 0;
      }
      /* mostrar iteração */
      printf("%d ",divisor);
      divisor++;
    }

    printf("\nNumero %d primo!\n",n);
  }

}