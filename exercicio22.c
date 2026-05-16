#include <stdio.h>
#include <stdlib.h>

// Imprimir a nota de 80 alunos em 3 provas.

int main()
{
    int notas[80][3];
    int i, j;
    float soma = 0.0;

    srand(time(NULL));
    // Leitura de notas - para cada aluno, ler as 3 notas. O primeiro índice é o aluno, o segundo é a prova.
    for(i = 0; i < 80; i++){
        for(j = 0; j < 3; j++){
           notas[i][j] = rand() % 28;
           soma = soma + notas[i][j]; 
        }
        printf("\n");
    }
    
    for(i = 0; i < 80; i++){
        for(j = 0; j < 3; j++){
            printf("%d", notas[i][j]); 
        }
        printf("\n");
    }
    printf("A média das notas é: %.2f", soma / 240.0);


    return 0;
}
