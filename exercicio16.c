#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int n){
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } return Fibonacci(n - 1) + Fibonacci(n - 2);

}


int main()
{
    int n;
    do
    {
        printf("Digite um número inteiro positivo: ");
        scanf("%d", &n);
        if (n < 0){
            printf("Número inválido. Por favor, digite um número inteiro positivo.\n");
        }
    } while (n < 0);
    
    printf("O %dº número da sequência de Fibonacci é: %d\n", n, Fibonacci(n));
    return 0;
}
