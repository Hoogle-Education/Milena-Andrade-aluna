#include <stdio.h>
#include<stdlib.h>
#define BUFFER 200

typedef struct imovel{
  char morada[BUFFER];
  int assoalhadas;
  float aluguel;
  char cidade[BUFFER];
  char zona[BUFFER];
} imovel;

void menu(int mode){
  if(mode == 1){
    puts("1 - Adicionar um novo immovel");
    puts("0 - Sair do programa");
  }else if(mode == 2){
    printf("Insira a morada: ");
  }else if(mode == 3){
    printf("Insira o numero de assoalhas: ");
  }else if(mode == 4){
    printf("Insira o valor do aluguel: ");
  }else if(mode == 5){
    printf("Insira a cidade: ");
  }else if(mode == 6){    
    printf("Insira a zona: ");
  }

}

int main(){

  FILE *txtFile;
  const char *filename = "BDimobiliario.txt";

  txtFile = fopen(filename, "a");

  // fprintf || fscanf

  int option;
  menu(1);
  while( scanf(" %d", &option) ){

    if(option == 0) break;

    imovel input;
    menu(2);
    scanf("%s", input.morada);

    menu(3);
    scanf("%d", &input.assoalhadas);

    menu(4);
    scanf("%f", &input.aluguel);

    menu(5);
    scanf("%s", input.cidade);

    menu(6);
    scanf("%s", input.zona);

    fprintf(txtFile, "Morada: %s\n", input.morada);
    menu(1);
  }

  fclose(txtFile);
  return 0;
}