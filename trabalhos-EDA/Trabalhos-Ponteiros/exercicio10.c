#include <stdio.h>

void intercala(int *v1, int *v2, int *v3, int n) {
    int *p1 = v1;
    int *p2 = v2;
    int *p3 = v3;

    while (p1 < v1 + n) {
        *p3 = *p1;       // copia elemento de v1
        *(p3 + 1) = *p2; // copia elemento de v2

        p1++;
        p2++;
        p3 += 2;         // avança dois no v3
    }
}

int main() {
    int v1[] = {1, 3, 5};
    int v2[] = {2, 4, 6};
    int v3[6];
    int n = 3;

    intercala(v1, v2, v3, n);

    int *p = v3;
    while (p < v3 + 2 * n) {
        printf("%d ", *p);
        p++;
    }
    printf("\n"); // saída: 1 2 3 4 5 6

    return 0;
}