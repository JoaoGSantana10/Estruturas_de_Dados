#include <stdio.h>
#include <stdlib.h>

/*
Forma Recomendada 

Definir a struct, depois declarar variáveis separadas.

struct Livros{
    char titulo[50]
    char autor[50];
    char assunto[50];
    int id_livro;
};

*/

/* declarando depois - forma recomendada

struct Livros livro1, livro2;

Separar definição é a prática mais limpa -  a struct fica no topo do arquivo e as varíaveis onde forem necessárias */

/*
Forma não recomendada

struct Livros {
    char titulo[50];
    char autor[50];
    } livro1, livro2; // Declarar aqui mistura definição com uso.
Declarar variáveis junto com a definição dificulta reutilizar a struct em outros lugares do código.
*/


/*
Inicialização - duas formas

struct Livros L1 = {"C Como Programar", "Deitel", "Programação", 12345};

com strcpy(campo a campo)

strcpy(L1.titulo, "C Como Programar");
strcpy(L1.autor, "Deitel");
L1.id_livro = 12345;

Use strcpy para strings dentro de struct - não é possível fazer L1.titulo = "texto" depois da declaração.


Acesso com ponto

printf("%s\n", livro1.titulo);
livro1.id_livro = 1011;

copiar toda struct de uma vez

livro2 = livro1;  

copia todos os campos

Diferentes de vetores, structs podem ser copiadas com um único =. Todos os campos são copiados automaticamente.

*/

int main(){
    
    return 0;
}
