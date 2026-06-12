#include <stdio.h>
#include <stdlib.h>

int conta(char *str, char c){
    int contagem = 0;
    while(*str != '\0'){
        if (*str == c){
            contagem++;
        }
        str++;
    }
    return contagem;
}

int main(){
    char str[] = "programacao";
    int resultado = conta(str, 'a');
    printf("o total de letras com 'a': %d\n", resultado);

    return 0;
}
