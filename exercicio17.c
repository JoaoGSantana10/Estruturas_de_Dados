#include <stdio.h>
#include <stdlib.h>

// Estruturas Homogêneas = todos elementos do mesmo tipo, armazenados em sequência contínua na memória.

int main()
{
    //forma de declarar um vetor: tipo nome[tamanho]; 80 posições em sequência na memória.
    /* Muito importante: O índice do vetor sempre começa em 0, ou seja, o primeiro elemento do vetor de 10 posições é
        o v[0] e o último elemento é o v[9].
    */
    int v[80], i;
    /* inicializa o gerador de números aleatórios com base no tempo atual 
        para garantir que os números gerados sejam diferentes a cada execução.
    */
    srand(time(NULL));  
    for (i = 0; i < 80; i++){
        v[i] = rand() % 100;
        printf("%d\n", v[i]);
    }

    return 0;
}

/*
Formar de declara uma matriz
    int m[3][4]; // 3 linhas e 4 colunas, total de 12 elementos, armazenados em sequência na memória.

Forma de declarar uma matriz 3D
    int m[5][80][3]; // 5 turmas, 80 alunos e 3 notas, total de 1200 elementos, armazenados em sequência na memória.


*/
