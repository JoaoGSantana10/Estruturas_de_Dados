#include<stdio.h>
#include<stdlib.h>

/* 
while(condição){
 Executa enquanto a condição for verdadeira
}
*/

int main(){
    int i = 0;
    while (i < 5){
        printf("%d\n", i);
        i++;
        // Esqueceu o i++ loop infinito
    }
    return 0;
}
