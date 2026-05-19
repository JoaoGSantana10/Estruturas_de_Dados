#include <stdio.h>
#include <stdlib.h>

/*

Temperatura média por andar (exercício do slide) 
Declare float temp[3][4][2] (3 andares, 4 salas, 2 leituras). Inicialize com valores fixos (não precisa de scanf) e calcule a temperatura média de cada andar.
*/
int main(){
    int a, s, l,soma;
    float temp[3][4][2]= {
        // andar 1
        {{20.5, 20.0}, {22.0, 21.0}, {21.5, 20.5}, {19.0, 18.0}},
        // andar 2
        {{21.0, 20.5}, {23.0, 22.5}, {22.0, 21.5}, {20.0, 19.5}},
        // andar 3
        {{21.5, 21.0}, {22.5, 22.0}, {23.0, 22.5}, {20.5, 20.0}}
    };

    for( a = 0; a < 3; a++){
        soma = 0.0; // resetar a soma para cada andar
        for(s = 0; s < 4; s++){
            for(l = 0; l < 2; l++){
                printf("%.1f ", temp[a][s][l]);
                soma = soma + temp[a][s][l];
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("A temperatura média por andar é: %.4f\n", soma / 8.0); // 8 leituras por andar (4 salas x 2 leituras cada)


    return 0;
}
