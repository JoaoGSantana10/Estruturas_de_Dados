#include <stdio.h>
#include <stdlib.h>

// Uma Matriz é como uma tabela, matriz[i][j] = linha i e coluna j.

int main()
{
    int matriz[3][4]; // 3 linhas e 4 colunas = 12 elementos.
    /*
    matriz[0][0] linha 0, coluna 0 - canto superior esquerdo
    matriz[2][3] linha 2, coluna 3 - canto inferior direito
    matriz[2][1] = 15 - terceira linha, segunda coluna recebe o valor 15
    O primeiro índice é sempre a linha, o segundo é a coluna. [linha][coluna]
    */

    // Para percorrer todos os elementos de uma matriz, você precisa de dois for - um para linhas e outro para colunas:
    
    for(int i = 0; i < 3; i++){ // percorre as linhas
        for (int j = 0; j < 4; j++){ // percorre as colunas
            printf("%d", matriz[i][j]);

        }   
        printf("\n"); // pula linha após cada fileira
    }
    
    return 0;
}
