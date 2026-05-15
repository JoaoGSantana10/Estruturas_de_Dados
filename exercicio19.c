#include <stdio.h>
#include <stdlib.h>

// target: char a ser buscada

int BuscarLetras(char vetor[], int tam, char target){
    for(int i = 0; i < tam; i++){
        if(vetor[i] == target){
            return i; // retorna a posição do target
        }
    }
    return -1; // retorna -1 se o target não for encontrado
}

int main()
{
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char target;
    printf("Informe a letra que deseja buscar de A a J: ");
    scanf("%c", &target);
    int pos = BuscarLetras(letras, 10, target); // busca a letra 'E' no vetor de letras
    if (pos != -1){
        printf("A letra foi encontrada na posição: %d\n", pos);
    } else {
        printf("Não foi possível encontrar a letra.\n");
    }
    
    return 0;
}
