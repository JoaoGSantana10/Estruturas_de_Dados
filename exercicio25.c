#include <stdio.h>
#include <stdlib.h>


int main()
{   
    int vetor[10];
    int maiorN, menorN;

    
    for(int c = 0; c < 10; c++){
        printf("Informe o número v[%d]: ", c);
        scanf("%d", &vetor[c]);
    }
    
    maiorN = vetor[0];
    menorN = vetor[0];
    
    for (int c = 0; c < 10; c++){
        if(vetor[c] > maiorN){
            maiorN = vetor[c];
        } 
        else if( vetor[c] < menorN){
            menorN = vetor[c];
        }

    }
    
    printf("O maior Número é: %d\n", maiorN);
    printf("O menor Número é: %d\n", menorN);

    
    return 0;
}
