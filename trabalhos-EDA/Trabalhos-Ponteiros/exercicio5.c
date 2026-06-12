#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int v[5] = {10, 20, 30, 40, 50}, soma;
    int *p;
    p = v;
    int i = 0;
    soma = 0;
    for (p = v; p < v + 5; p++){
        printf("Elemento %d : %d \n",i, *p);
        i += 1;
        soma = soma + *p;
    }
    printf("A soma é: %d\n", soma);
    

    return 0;
}
