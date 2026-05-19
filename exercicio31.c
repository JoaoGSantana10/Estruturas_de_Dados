#include <stdio.h>
#include <stdlib.h>

/*

O que é typedef

Criar um apelido para um tipo

typedef cria um nome alternativo para qualquer tipo existente. Com struct, elimina a necissidade de escrever struct toda vez.

Sem typedef

struct Pessoa {
    char nome[50];
    int idade;
};

struct Pessoa João;
struct Pessoa povo[10];

Com typedef

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

Pessoa João;
Pessoa povo[10];

Com typedef, Pessoa vira um tipo como int ou float - você pode usar diretamente sem a palavra struct.

*/

// typedef com tipos simples

typedef unsigned char BYTE; 
// BYTE agora é um sinônimo para unsigned char

BYTE b1, b2; 
b1 = "c";

typedef struct {int x; int y;} Ponto;
// Ponto é um novo tipo

Ponto a, b;
a.x = 1; a.y = 2;
b.x = 3; b.y = 4;


// Vetor de structs

/*
Depois de criar o tipo com typedef, você pode criar vetores de structs exatamente como faz com tipos primitivos:

typedef struct {
    float peso;
    int idade;
    float altura;
} Pessoa;

Pessoa Joao, P1, P2; variáveis individuais
Pessoa povo[10]; vetor de 10 pessoas

povo[4].idade = 23; acesso: vetor + ponto
povo[4].peso = 75.3; 
P2 = povo[4]; copia todos os campos
P2.idade++; modifica só o P2

*/


int main(){
    
    return 0;
}
