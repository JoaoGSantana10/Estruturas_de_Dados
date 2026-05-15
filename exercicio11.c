#include <stdio.h>
#include <stdlib.h>

/*
do {
    Executa primeiro depois testa
} while( condição );
*/

int main(){
    int op;
    
    do{
        printf("[1] - Jogar\n [2] - Config\n [0] - Sair\n ");
        scanf("%d", &op);
    } while (op != 0);

    return 0;
}
