#include <stdio.h>
#include <stdlib.h>



int main(){
    FILE *arquivo;

    arquivo = fopen("Produtos.txt", "w"); // Abre o arquivo para escrita (modo "w")
    fprintf(arquivo, "Produto: Mouse\n  Preço: R$ 50,00\n Quantidade: 10\n"); // Escreve uma linha no arquivo
    fprintf(arquivo, "\n"); // Escreve uma linha em branco no arquivo
    fprintf(arquivo, "Produto: Teclado\n  Preço: R$ 100,00\n Quantidade: 5\n"); // Escreve outra linha no arquivo
    fclose(arquivo); // Fecha o arquivo
    
    arquivo = fopen("Produtos.txt", "r"); // Abre o arquivo para leitura (modo "r")
    char linha[100]; // Buffer para armazenar cada linha lida do arquivo
    printf("Conteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo)) { // Lê cada linha do arquivo até o final
        printf("%s", linha); // Imprime a linha lida
    }
    fclose(arquivo); // Fecha o arquivo
    return 0;
}
