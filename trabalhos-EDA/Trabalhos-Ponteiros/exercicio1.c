#include <stdio.h>
#include <stdlib.h>

int main(){

    int t = 10;
    float p = 20;
    int *pt;
    float *pf;
    pf = &p;
    pt = &t;

    printf("O valor que está armazenado no ponteiro  p é: %f\n", *pf);
    printf("O endereço do ponteiro pf na memória é: %p\n", &pf);
    printf("O valor que está armazenado no ponteiro t é: %d\n", *pt);
    printf("O endereço do ponteiro pt na memória é: %p\n", &pt);
    
    return 0;
}
