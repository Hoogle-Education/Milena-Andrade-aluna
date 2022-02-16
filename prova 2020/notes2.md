# File manipulation

```c
  #include <stdlib.h>
```

## as mais complicadas de associar

### 1. `fgets`

puxa do arquivo linha por linha até encontrar o `EOF`, *end of file*.

parametros:

```
  fgets(<buffer>, <MAXCHAR>, <file>)
```

`buffer` - uma string que recebe a entrada da linha que foi puxada do arquivo
`file` - arquivo aberto através da `fopen`

### 2. `strtok()`

serve para *splitar* os dados de uma string, muito usada junto com a fgets.

**primeiro uso:**

```c
  char *splitedData;
  splitedData = strtok(<buffer>, <regex>);
```

`regex` - é a regra que iremos usar para splitar os dados

exemplo: 1;2;3;4;5;6 

regex = ";"

**segundo uso:**
caso nosso objetivo seja continuar splitando os dados de uma mesma string, teremos um segundo uso diferente.

```c
  splitedData = strtok(NULL, ";");
```

isto irá manter a string `splitedData` na posição após o regex e pegará o dado subsequente antes do próximo `regex`, caso contrário:

```c
  splitedData = strtok(<buffer>, <regex>);
```

meu `splitedData` apenas iria repetir os dados, pois seria passado novamente o ponteiro para o início do buffer.

