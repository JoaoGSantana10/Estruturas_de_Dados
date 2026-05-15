#include <stdio.h>
#include <stdlib.h>

// Escreva um programa em C que leia um número inteiro do usuário e imprima a tabuada dele (de 1 a 10) usando for.
int main()
{
    int n;
    int tab;
    printf("Digite um número para se calculado a tabuada:");
    scanf("%d", &n);
    for(int i = 1; i <= 10; i++){
        tab = n * i;
        printf("%d x %d = %d\n", n, i, tab);
    }
    return 0;
}
