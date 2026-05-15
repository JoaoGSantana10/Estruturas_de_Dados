#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaração e inicialização de um Vetor.

    int vetor[10] = {0}; // Inicializa todos os elementos com zero.
    int vetor[5] = {1, 2, 3, 4, 5}; // Inicializa todos os elementos com valores definidos.
    /* 
        O tamanho do vetor é inferido a partir do número de elementos fornecidos. Tamanho inferido = 3.
        O compilador conta os elementos automaticamente quando você omite o tamanho e inicializa com valores.
    */
    int vetor[] = {10, 20, 30}; 

    /*
    Isso para um int vetor[10]:
    vetor [0] = 42; Atribuindo a primeira posição do vetor o valor 42.
    vetor [9] = 99; décimo último elemento do vetor recebe o valor 99.
    vetor [5] = 15; sexto elemento.
    
    para percorrer todos os elementos do vetor, use o loop for:
    for (int i = 0; i < 10; i++){
     printf("%d\n", vetor[i]);
     }
    */
    
    return 0;
}
