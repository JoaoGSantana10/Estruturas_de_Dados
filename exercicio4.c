#include <stdio.h>
#include <stdlib.h>

int main() {

    int vetor[10] = {0};
    int i;
    vetor[5] = 10;

    for(i = 0; i < 10; i++){
        printf("O valor do vetor na posição %d é: %d\n", i, vetor[i]);
    }

}