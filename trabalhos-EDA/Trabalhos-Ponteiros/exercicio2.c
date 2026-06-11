#include <stdio.h>
#include <stdlib.h>

int main(){
    int A = 10;
    int B = 20;
    int *aux;
    int *pontA;
    int *pontB;
    
    pontA = &A;
    pontB = &B;

    printf("O valor do ponteiro 'pontA' na memória antes da troca é: %p\n", &pontA);
    printf("O valor do ponteiro 'pontB' na memória antes da troca é: %p\n", &pontB);
    printf("-----------------------------------------------------------------------\n");
    printf("Valores depois da troca\n");
    printf("-----------------------------------------------------------------------\n");
    aux = pontA;
    pontA = pontB;
    pontB = aux;
    printf("O valor do ponteiro 'pontA' trocado na memória é: %p\n", pontA);
    printf("O valor do ponteiro 'pontB' trocado na memória é: %p\n", pontB);


    return 0;
}
