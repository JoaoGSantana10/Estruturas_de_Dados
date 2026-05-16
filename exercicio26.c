#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p[10];
    int c, op, quantidade, indice;

    for(c = 0; c < 10; c++){
        printf("Digite o estoque o produto %d: ", c);
        scanf("%d", &p[c]);
    }
    
    for(c = 0; c < 10; c++){
        printf("Estoque produto [%d]: %d Unidades", c, p[c]);
    }

    do{
        printf("=========================\n");
        printf("SUPERMERCADO DO DEV\n");
        printf("=========================\n");
        printf("[0] - VSCODE PREMIUN\n");
        printf("[1] - INTELLIJ PREMIUN\n");
        printf("[2] - CLAUDE CODE\n");
        printf("[3] - GITHUB COPILOT\n");
        printf("[4] - MONSTER DO PCTHEONEE\n");
        printf("[5] - CI/CD PIPELINE\n");
        printf("[6] - ÓCULOS PARA O ESTILO DEV\n");
        printf("[7] - TERMINAL PLUS\n");
        printf("[8] - SPOTIFY COM AS PEDRADAS DO PCTHEONEE\n");
        printf("[9] - .ENV ORGANIZADO\n");
        printf("-------------------------------\n");
        printf("1 - COMPRAR PRODUTO\n");
        printf("2 - ADICIONAR PRODUTO\n");
        printf("3 - VER ESTOQUE\n");
        printf("0 - SAIR\n");
        printf("ESCOLHA: ");
        scanf("%d", &op);
        

        switch (op)
        {
        case 1 :
            printf("Qual produto você deseja comprar de 0 a 9:");
            scanf("%d", &indice);
            printf("Quantas quantidade você deseja comprar: ");
            scanf("%d", &quantidade);
            if (p[indice] >= quantidade){
                p[indice] = p[indice] - quantidade;
            } else{
                printf("PRODUTO SEM ESTOQUE!\n");
            }

            for ( c = 0; c < 10; c++){
                printf("Estoque %d: %d Unidade\n", c, p[c]);    
            }
        break;
            
        case 2:
            printf("Digite o indice do produto que você deseja adicionar: ");
            scanf("%d", &indice);
            printf("Deseja adicionar quantas quantidades: ");
            scanf("%d", &quantidade);
            p[indice] = p[indice] + quantidade;

            for(c = 0; c < 10; c++){
                printf("Estoque do produto %d: %d\n",c, p[c]);
            }

            break;
        case 3:
            printf("Estoque: ");
            for (c = 0; c < 10; c++){
                printf("Estoque dos produtos %d: %d\n", c, p[c]);
            }
        break;
        
        case 0: 
            printf("Saindo...\n");
        break;

        default:
            break;
        }
        
    } while (op != 4);
    
    return 0;
}
