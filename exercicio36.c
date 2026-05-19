#include <stdio.h>
#include <stdlib.h>

int main(){
    int m[3][3] = {0}; // Inicializa todos os elementos com 0
    int i, j;

// Declarar uma matriz 3x3 de inteiros e fazer uma matriz identidade
    for ( i = 0; i < 3; i++){
        for ( j = 0; j < 3; j++){
            if (i == j){
                m[i][j] = 1; // Atribui 1 para os elementos da diagonal principal
            } else {
                m[i][j] = 0; // Atribui 0 para os outros elementos
            }
            
        }
    }

    for ( i = 0; i < 3; i++){
        for ( j = 0; j < 3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
