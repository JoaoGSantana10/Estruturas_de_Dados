#include <stdio.h>
#include <stdlib.h>

void dobra(int *x){
    *x = *x * 2;
}

int main(){
     
    int n1 = 10;
    int *x;
    x = &n1;
    printf("O valor de n1 é: %d\n", *x);
    dobra(&n1);
    printf("Novo valor depois da função: %d\n", n1);

    return 0;
}
