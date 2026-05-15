#include <stdio.h>
#include <stdlib.h>

int soma(int n){
    if(n == 1){
        return 1;
    }
    return  n + soma(n - 1);
}
int main()
{
    int n;
    /*printf("Digite um número inteiro positivo:");
    scanf("%d", &n);
    while ( n <= 0){
        printf("Digite um número inteiro positivo:");
        scanf("%d", &n);
    }*/
    do{
        printf("Digite um número inteiro positivo:");
        scanf("%d", &n);
        if(n <= 0){
            printf("Número inválido. Por favor, digite um número inteiro positivo.\n");
        }
    } while (n <= 0);
    printf("%d\n", soma(n));
    return 0;
}
