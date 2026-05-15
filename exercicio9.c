#include <stdio.h>
#include <stdlib.h>

/* for (inicialização; condicação; incremento){
    Bloco executado enquanto a condição é verdadeira
}
*/
int main(){

    for (int i = 0; i < 4; i++){
       printf("%d\n", i);
       /*  
        Passo 1: i=1 → condição 1 < 4? SIM → imprime 1 → i++
        Passo 2: i=2 → condição 2 < 4? SIM → imprime 2 → i++
        Passo 3: i=3 → condição 3 < 4? SIM → imprime 3 → i++
        Passo 4: i=4 → condição 4 < 4? NÃO → sai 
        */  
    }
    
    return 0;
}
