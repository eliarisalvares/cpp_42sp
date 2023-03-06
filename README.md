# CPP PISCINE 42 SP

## 42 São Paulo

A 42 é uma escola de programação que tem como objetivo formar programadores de
alto nível. É uma escola sem professores, onde o aluno aprende através de
projetos e de uma metodologia de auto-estudo e cooperação entre pares.

## CPP Piscine

Esse projeto é uma piscina de programação em C++ que tem como objetivo
apresentar os conceitos básicos da linguagem C++ e da orientação a objetos
através de 9 listas de exercícios (módulos).

### Conceitos Importantes de C++ (por ordem de aparição nas listas (módulos))

### Módulo 02

#### RawBits: Bits brutos.

RawBits são bits brutos, ou seja, bits que não foram interpretados e,
enquanto não forem interpretados, não possuem um significado específico, mas
são apenas uma sequência de bits (0s e 1s) que não tem um significado
específico.

#### Fixed Point: Ponto fixo.

São uma representação númerica de um número real, onde o número é representado
por uma parte inteira e uma parte fracionária. Por exemplo, um número de ponto
fixo pode ser representado como um inteiro dividido por 2^N, onde N é o número
de bits usados para representar a parte fracionária.

Fixed points permitem a representação de números fracionários com uma precisão
fixa e diferem de números inteiros na posição do ponto binário. Um número
inteiro pode ser interpretado como um número de ponto fixo em que o ponto
binário está na posição 0, por exemplo.

A vantagem de usar números de ponto fixo, então, é que fazer operações com
eles é mais simples e mais rápido do que fazer operações com números de ponto
flutuante. Tão simples quanto usar números inteiros, na verdade. E assim, é
possível utilizar as mesmas operações que são usadas com números inteiros para
fazer operações com números de ponto fixo.

A desvantagem é que, como os números de ponto fixo são representados por
inteiros, eles não podem representar números fracionários com tanta precisão
quanto os números de ponto flutuante.

##### Relação entre números de ponto fixo e binários

Em um octeto (8 bits), podemos representar números de ponto fixo com 4 bits
para a parte inteira e 4 bits para a parte fracionária. Isso significa que
podemos representar números de ponto fixo com precisão de 1/16. Por exemplo:

```
7.5 = 0111.1000

2.1 = 0010.0010
````

*A posição do ponto fixo em um número de ponto fixo depende do número de bits
usados para representar a parte inteira e a parte fracionária, assim como a
faixa de valores que o número pode assumir.*

#### Overload: Sobrecarga de operadores e funções.

"Overload" em C++ se refere ao recurso de definir múltiplas funções com o mesmo
nome, mas com diferentes parâmetros.

Isso significa que em C++, é possível ter várias funções com o mesmo nome, mas
com diferentes tipos de parâmetros. Por exemplo, uma função chamada "soma" que
 aceita dois números inteiros e retorna a soma desses números, e uma outra
 função "soma" que aceita duas strings e retorna a concatenação dessas strings.

Isso é possível porque o compilador C++ é capaz de diferenciar as diferentes
funções com base na lista de argumentos passada a elas. Quando uma função é
chamada, o compilador determina qual das funções sobrecarregadas deve ser
executada com base no número, tipos e ordem dos argumentos passados.

A sobrecarga de funções é uma técnica poderosa em C++ que permite escrever
código mais legível e fácil de usar, tornando a linguagem mais expressiva e
flexível.

### Assignment Operator: Operador de atribuição.

O operador de atribuição (=) é usado para atribuir um valor a uma variável.

```cpp
variavel = valor;
```

Onde "variavel" é o nome da variável a que se deseja atribuir um valor e "valor"
 é o valor a ser atribuído à variável. É usado para atualizar o valor de uma
 variável em tempo de execução (ou seja, durante a execução do programa) ou para
  inicializar uma variável com um valor depois de declará-la.

Além disso, esse operador pode ser sobrecarregado em C++, permitindo que um
comportamento específico seja definido para o operador de atribuição quando
usado com objetos de uma classe personalizada. Isso é útil para personalizar a
forma como as classes são usadas em um programa e para tornar o código mais
legível.
