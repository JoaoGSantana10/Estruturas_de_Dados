#include <stdio.h>
#include <stdlib.h>

int main() {

    int matriz[3][4] = {{0}};
     matriz[2][1] = 15;
    int c, l;
    for( l = 0; l < 3; l++){
        for(c = 0; c < 4; c++){
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }
}