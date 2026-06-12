#include <stdio.h>
#include <stdlib.h>

int main(){

    int n1 = 10;
    int *p;
    p = &n1;

    *p = *p + 5;
    printf("O valor do ponteiro agora é: %d\n", *p);
    *p = *p * 2;
    printf("O valor do ponteiro multiplicado por 2 é: %d\n", *p);

    
    return 0;
}
