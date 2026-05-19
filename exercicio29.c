#include <stdio.h>
#include <stdlib.h>    

/*
Imagine guardar dados de uma pessoa: nome, idade e altura. Sem struct você precisaria de variáveis soltas sem conexão entre si:

char nome1[50]; nome2[50];
int idade1, idade2;
float altura1, altura2;

confuso e muito ruim de escalar.

com struct, tudo fica agrupado num único tipo
*/

typedef struct {
    char nome[50];
    int idade;
    float altura;

} Pessoa;

Pessoa Joao, Maria; // cada um tem nome, idade e altura.

/*
Struct é uma estrutura composta heterogênea - campos de tipos diferentes agrupados sob um mesmo nome em um bloco contínuo de memória.
*/


/*
Comparação entre struct e array:

Homogênea vs. Heterogêna 

Vetor/Matriz(Homogênea)

Todos os elementos do mesmo tipo. Acesso por índice numérico.

int notas[5]; // 5 notas, todas do tipo int

Struct(Heterogênea)

Campos de tipos diferentes. Acesso por nome do campo com ponto.

joao.nome
joao.idade
joao.altura

*/

int main()
{
    
    return 0;
}
