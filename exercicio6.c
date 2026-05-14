#include <stdio.h>
#include <stdlib.h>

// sistema de supermercado, que mantem a contagem de produtos diferentes em um vetor, e o valor do índice indica a quantidade no estoque. 

int main(){
    int v[10];
    int c;
    int opcao, indice, quantidade;

    srand(time(NULL));

    for(c = 0; c < 10; c++){
     v[c] = rand() % 50 + 1; 
    }

    for(c = 0; c < 10; c++){
        printf("Produto %d: %d unidades\n", c, v[c]);
    }

    do {
        printf("-------------------------\n");
        printf("ESTOQUE SUPERMERCADO\n");
        printf("-------------------------\n");
        printf(" 0 = Arroz\n");
        printf(" 1 = Macarrão\n");
        printf(" 2 = Açúcar\n");
        printf(" 3 = Feijão\n");
        printf(" 4 = Água\n");
        printf(" 5 = Laranja\n");
        printf(" 6 = Suco\n");
        printf(" 7 = Refrigerante\n");
        printf(" 8 = Uva\n");
        printf(" 9 = Maçã\n");


                        
        printf("[0] - Sair\n");
        printf("[1] - Comprar Produto\n");
        printf("[2] - Adicionar Estoque\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch (opcao){

        case 1:
            printf("Qual produto de 0 a 9 você quer comprar?");
            scanf("%d", &indice);
            printf("Quantas unidades você deseja comprar?");
            scanf("%d", &quantidade);
            if (quantidade <= v[indice]){
                v[indice] = v[indice] - quantidade;
            } else {
                printf("Estoque insuficiente");
            }
            for(c = 0; c < 10; c++){
                printf("Produto %d: %d unidades\n", c, v[c]);
            }        
            break;
        case 2 :
            printf("Qual o produto que deseja adicionar\n?");
            scanf("%d", &indice);
            printf("Quantas unidades deseja adicionar");
            scanf("%d", &quantidade);
            v[indice] = v[indice] + quantidade;
            for(c = 0; c < 10; c++){
                printf("Produto %d: %d unidades\n", c, v[c]);
            }        
            break;

        default:
            break;
        }
    } while(opcao != 0 );







}