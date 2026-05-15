#include<stdio.h>
#include<stdlib.h>

int global = 100; // Variável Global

void minhafuncao(){
    int local = 70;  // Variável Local
    printf("%d\n %d", local, global);
}


int main(){
    minhafuncao();
    printf("\n %d", global); // Variável Global pode ser acessada em qualquer parte do código
    //printf("\n %d", local); // Erro: Variável 'local' só é acessível dentro da função 'minhafuncao'
    return 0;


}