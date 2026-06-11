#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cidade[20]; // nome da cidade
    float *temperatura; // ponteiro para o vetor de temperaturas
} TMedidas;

typedef struct {
    int qtde_dias; // capacidade máxima do vetor
    int qtde_medidas; // quantas medidas já foram inseridas
    TMedidas *medidas; // ponteiro para o vetor de medidas
}TTemperaturas;

#endif