# Resumo da aula

## Argumentos da função `main`

**1. `argc`**

Diz a quantidade de parametros passadas para o terminal.

code:
```c
int main(int argc, char **argv)
{
  printf("%d", argc);
}
```

compiling and running:
```bash
./test 2 3 4 5
```

output:
```
5
```

**2. `argv`**

é o vetor que guarda os parametros passados pelo terminal.

## Casting

Avisa que uma variável será representada em outro tipo.

```c
  int c = (int)'2';
  // c = 50
```

```c
  int val = (int)(92012.2)
  // val = 92012
```

