#include <stdio.h>
#include <stdlib.h>

// Alocação dinâmica com malloc

typedef struct{
    char nome[50];
    int idade;
} Pessoa;



int main(){
    Pessoa *P = (Pessoa*) malloc(sizeof(Pessoa)); // aloca dinamicamente
    
    if(P){ // sempre verificar se malloc funcionou
        P->idade = 3;
        printf("Idade: %d\n", P->idade);
        free(P); // sempre liberar a memória 
        /*
        Sempre verificar se malloc retornou NULL e sempre chamar free() no final. Memória alocada com malloc não é liberada automaticamente.
        */
    }
    return 0;
}
