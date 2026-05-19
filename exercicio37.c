#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

//void SetProduto(Produto P*, char nome[50], float preco, int quantidade){
  //  strcpy(p1.nome->nome);
    //p1.preco->preco;
    //p1.quantidade->quantidade;

//}

int main(){

    Produto p1;
    
    strcpy(p1.nome,"Arroz");
    p1.preco = 20.0;
    p1.quantidade = 10;

    printf("Nome: %s \n Preço: %.1f \n Quantidade: %d\n", p1.nome, p1.preco, p1.quantidade);
    printf("\n");
    
    Produto *ptr;

    ptr = &p1;
    printf("Nome: %s\n Preço: %.1f\n Quantidade: %d\n", ptr->nome, ptr->preco, ptr->quantidade);

    return 0;
}
