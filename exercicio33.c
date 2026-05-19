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

/*
Passagem por referência 

Usar ponteiro para modificar o original

Quando você precisa que a função modifique a struct original, passa um ponteiro com &:
*/

void SetPessoa(Pessoa *P, int idade, float peso, float altura, char nome[50]){
    
    (*P).idade = idade; // forma 1: deresferênciar
    P->peso = peso; // forma 2: operador seta (mais usada)
    P->altura = altura;
    strcpy(P->nome, nome);

    /*
    Notação com asterisco

    (*P).idade = 15;
    deresferencia o P, depois acessa o campo Idade

    Notação com seta(preferida)

    P->idade = 15;

    atalho para (*P).idade
    muito mais legível

    P->campo e (*P).campo são exatamente equivalentes. Use sempre a seta - é o padrão do mercado.
    
    */

}


int main(){
    //Pessoa Joao;
    //Joao = SetPessoa(20, 70.0, 1.75, "João"); // recebe struct
    //ImprimePessoa(Joao);

    Pessoa Joao;
    SetPessoa(&Joao, 20, 70.0, 1.75, "João"); // passa endereço
    ImprimePessoa(Joao);
    return 0;

    // Retornar struct é diferente de retornar vetor - struct pode ser retornada diretamente por valor.
    
}
