#include <stdio.h>
#include <stdlib.h>

// Matriz 3D  é um conjunto de matrizes 2D empilhadas, m[i][j][k] - camada i, -linha j, - coluna k

int main()
{
    int matriz[2][3][4]; // 2 camadas, 3 linhas, 4 colunas; total = 2 x 3 x 4 = 24 elementos.

    /* 
    matriz[1][2][3] = 15
    segunda camada, terceira linha, quarta coluna
    */

    //iteração com for

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 4; k++){
                printf("%d", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n"); // Separa as camadas
    }
    
    return 0;
}
