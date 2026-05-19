#include <stdio.h>
#include <stdlib.h>



int main(){
    FILE *arquivo;

    arquivo = fopen("exemplo.txt", "w"); // Abre o arquivo para escrita (modo "w")
    fprintf(arquivo, "Olá, este é um exemplo de escrita em arquivo.\n"); // Escreve uma linha no arquivo
    fprintf(arquivo, "Esta é a segunda linha do arquivo.\n"); // Escreve outra linha no arquivo
    fclose(arquivo); // Fecha o arquivo
    
    arquivo = fopen("exemplo.txt", "r"); // Abre o arquivo para leitura (modo "r")
    char linha[100]; // Buffer para armazenar cada linha lida do arquivo
    printf("Conteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo)) { // Lê cada linha do arquivo até o final
        printf("%s", linha); // Imprime a linha lida
    }
    fclose(arquivo); // Fecha o arquivo
    return 0;
}
