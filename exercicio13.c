#include <stdio.h>
#include <stdlib.h>
/*
Leia um número positivo do usuário. Se ele digitar um número negativo ou zero, peça novamente (use while para a validação). 
Depois, faça a contagem regressiva até 1 usando outro while.
*/
int main()
{
    int n;
    printf("Informe um número: ");
    scanf("%d", &n);
    while (n < 0)
    {
        printf("Inválido! Digite um número positivo: ");
        scanf("%d", &n);
    }

    while (n >= 1)
    {
        printf("%d\n", n);
        n--;
    }
    printf("FIM!\n");

    return 0;
}
