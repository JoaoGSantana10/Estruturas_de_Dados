#include <stdio.h>
#include <stdlib.h>

void ImprimirVetor(int vetor[], int tam){ // vetor[] = é o ponteiro para o vetor, tam = é o tamanho do vetor.
    for (int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}

int main()
{
    int numeros[5] = {10, 20, 30, 40, 50};
    printf("Vetor de numeros:\n");
    ImprimirVetor(numeros, 5); printf("\n"); // imprime o vetor e o tamanho do vetor.
    
    return 0;
}
