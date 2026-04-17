#include <stdio.h>
struct pessoa{
    char nomeP[50];
    int idade;
    float altura;
} pessoa;

int main () {
    struct pessoa pessoas1 = {"João", 25, 1.80};
    struct pessoa pessoaM = {"João", 26, 1.81};

    printf("Pessoa:  \n nomeP: %s\n idade %d\n altura %f\n", pessoa.nomeP,pessoa.idade, pessoa.altura);
    printf("PessoaM: \n nomeP: %s\n idade %d\n altura %f\n", pessoaM.nomeP, pessoaM.idade, pessoaM.altura);
    return 0;

}