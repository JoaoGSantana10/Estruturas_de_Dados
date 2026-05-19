#include <stdio.h>
#include <stdlib.h>

/*
Passagem por valor 

Struct como parâmetro - recebe uma cópia
*/

typedef struct{
    int idade;
    float peso;
    float altura;
} Pessoa;

void ImprimePessoa(Pessoa P){ //recebe cópia
    printf("Idade: %d\n Peso: %.1f\n Altura: %.2f\n", P.idade, P.peso, P.altura);   
}

int main(){
    Pessoa Joao;
    Joao.idade = 20;
    Joao.peso = 70.0;
    Joao.altura = 1.75;
    ImprimePessoa(Joao); // passa cópia    
    return 0;

    // Passar por valor é seguro - a função não pode alterar o original. Mas copia todos os campos, o que pode ser custoso para structs grandes.
}