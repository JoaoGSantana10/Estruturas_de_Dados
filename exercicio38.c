#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float preco;
    int quantidade;

} Produto;

int main(){
    int n, i;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    // Alocação dinâmica de produtos. 
    Produto *produto = malloc(sizeof(Produto) *n);

    for(i = 0; i < n; i++){
        printf("digite o nome do produto: ");
        scanf("%s", &produto[i].nome);
        printf("Digite o preço do produto: ");
        scanf("%f", &produto[i].preco);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &produto[i].quantidade);  
    }

    printf("\nProdutos cadastrados:\n");
    for(i = 0; i < n; i++){
        printf("Produto %d:\n", i);
        printf("Nome: %s\n", produto[i].nome);
        printf("Preço: %.2f\n", produto[i].preco);
        printf("Quantidade : %d\n", produto[i].quantidade);        
    }
    free(produto); // liberar a memória alocada
       
    return 0;
}