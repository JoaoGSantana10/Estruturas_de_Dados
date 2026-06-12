#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int A = 10, B = 20;
    int *p1, *p2;
    
    p1 = &A;
    p2 = &B;

    
    printf("O valor de 'A' antes da troca é: %d\n", *p1);
    printf("O valor de 'B' antes da troca é: %d\n", *p2);
    printf("------------------------------------------\n");
    printf("Os valores trocados são:\n");
    printf("------------------------------------------\n");
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
    printf("O valor de 'A' depois da troca é: %d\n", *p1);
    printf("O valor de 'B' depois da troca é: %d\n", *p2);


    return 0;
}
