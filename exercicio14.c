#include<stdio.h>
#include<stdlib.h>
/*
Crie um menu que mostre as opções: 1-Somar, 2-Subtrair, 0-Sair. Para cada opção (exceto 0), leia dois números e mostre o resultado. 
Continue mostrando o menu até o usuário digitar 0. Use do-while.
*/
int main()
{
    int n1, n2,op, soma, subtrair;
    printf("Informe o primeiro valor: ");
    scanf("%d", &n1);
    printf("Informe o segundo valor: ");
    scanf("%d", &n2);
    do
    {
        printf("[1] - Somar \n [2] - Subtrair \n [0] - Sair \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            //soma = n1 + n2;
            printf("A soma entre %d + %d = %d\n", n1, n2, soma = n1 + n2);
            break;
        case 2:
            //subtrair = n1 - n2;
            printf("A subtração entre %d - %d = %d\n", n1, n2, subtrair = n1 - n2);
        break;
        
        default:
            break;
        }
        
    } while (op != 0);
    

    return 0;
}
