#include <stdio.h>
#include <stdlib.h>

int maior(int *v, int tamanho){
       
    int max = *v;
    for (int *p = v + 1; p < v + tamanho; p++){
        if (*p > max){
        max = *p;
        }
    }
    return max;
}

int main(){
    
    int v[5] = {10, 20, 30, 40, 50};
    int resultado = maior(v, 5);
    printf("O maior elemento é: %d",resultado);    

    return 0;
}
