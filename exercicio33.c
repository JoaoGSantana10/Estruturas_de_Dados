#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Retorno de struct 
Uma função pode retornar uma struct completa:
*/

typedef struct{
    int idade;
    float peso;
    float altura;
    char nome[50];
} Pessoa;

void ImprimePessoa(Pessoa P){ //recebe cópia
    printf("Idade: %d\n Peso: %.1f\n Altura: %.2f\n Nome: %s\n", P.idade, P.peso, P.altura, P.nome);   
}

Pessoa SetPessoa(int idade, float peso, float altura, char nome[50]){
    Pessoa P;
    P.idade = idade;
    P.peso = peso;
    P.altura = altura;
    strcpy(P.nome, nome);
    return P; // retorna struct completa

};

int main(){
    Pessoa Joao;
    Joao = SetPessoa(20, 70.0, 1.75, "João"); // recebe struct
    ImprimePessoa(Joao);
    return 0;

    // Retornar struct é diferente de retornar vetor - struct pode ser retornada diretamente por valor.
    
}
