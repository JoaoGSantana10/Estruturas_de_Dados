#include<stdio.h>
#include<stdlib.h>

// sem funcao ficaria assim:
/*
int main(){
    float a1= 10, b1 = 20, c1 = 30;
    float a2= 40, b2 = 50, c2 = 60;
    float a3= 70, b3 = 80, c3 = 90;
    float soma1, media1, soma2, media2, soma3, media3;
    soma1 = a1+b1+c1; media1 = soma1/3;
    soma2 = a2+b2+c2; media2 = soma2/3;
    soma3 = a3+b3+c3; media3 = soma3/3;
    printf("Media 1: %.2f\n", media1);
    printf("Media 2: %.2f\n", media2);
    printf("Media 3: %.2f\n", media3);
    return 0;
}
*/

// Em vez de fazer a média de três números diretamente no main, vamos criar uma função para isso.
float media(float a, float b, float c){ 
    return (a + b + c) / 3.0; 
}

int main(){
    float a1= 10, b1 = 20, c1 = 30;
    float a2= 40, b2 = 50, c2 = 60;
    float a3= 70, b3 = 80, c3 = 90;
    float m1 = media(a1, b1, c1);
    float m2 = media(a2, b2, c2);
    float m3 = media(a3, b3, c3);
    printf("Media 1: %.2f\n", m1);
    printf("Media 2: %.2f\n", m2);
    printf("Media 3: %.2f\n", m3);
    return 0;
}
