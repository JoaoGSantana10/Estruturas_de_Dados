#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    if (n == 0  || n == 1){
        return 1; // fatorial de 0! = 1 e fatorial de 1! = 1  caso base
    }
    return n * fatorial(n - 1); //  caso recursivo
}

int main(){
    int n;
    printf("Digite o número para ser calculado o fatorial: ");
    scanf("%d", &n);
    printf("O fatorial de %d é: %d\n", n, fatorial(n));
    return 0;
}
