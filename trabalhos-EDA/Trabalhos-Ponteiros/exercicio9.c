#include <stdio.h>

void inverte(int *v, int tamanho) {
    int *esq = v;
    int *dir = v + tamanho - 1;

    while (esq < dir) {
        // Troca sem variável auxiliar tradicional (usa XOR)
        *esq ^= *dir;
        *dir ^= *esq;
        *esq ^= *dir;

        esq++;
        dir--;
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    int n = 5;

    inverte(v, n);

    int *p = v;
    while (p < v + n) {
        printf("%d ", *p);
        p++;
    }
    printf("\n"); // saída: 5 4 3 2 1

    return 0;
}