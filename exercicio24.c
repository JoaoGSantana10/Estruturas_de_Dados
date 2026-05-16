#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Notas de 5 turmas;

int main()
{
    int m[5][80][3];
    int t, a, n;
    float soma = 0.0;
    srand(time(NULL));
    for(t = 0; t < 5; t ++){
        for (a = 0; a < 80; a++){
            for (n = 0; n < 3; n++){
                m[t][a][n] = rand() % 19;
            }
            printf("\n");
        }
        printf("\n");
    }
    
    for(t = 0; t < 5; t++){
        soma = 0.0;
        for (a = 0; a < 80; a++){
            for (n = 0; n < 3; n++){
                soma = soma + m[t][a][n];
                printf("%d", m[t][a][n]);
                printf("\nA média das turmas é : %.2f\n",soma / 240.0);
            }
            printf("\n");
        }
        printf("\n");
    }





    return 0;
}
