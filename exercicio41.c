#include <stdio.h>
#include <stdlib.h>

int smallerIndex(int vet[], int tam, int ini){
    int menor = ini, j;
    for (j = ini + 1; j < tam; j++){
        if (vet[menor] > vet[j]){
            menor = j;
        }
    }
    return menor;
}

void selectionSort(int vet[], int tam){
    int i, menor, aux;
    for(i = 0; i < tam; i++){
        menor = smallerIndex(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

/*
 Inserção(Insertion Sort)

 [60, 43, 37, 3, 51, 92]

 i = 0 [43, 60, 37, 3, 51, 92]
 i = 1 [37, 43, 60, 3, 51, 92]
 i = 2 [3, 37, 43, 60, 51, 92]
 i = 3 [3, 37, 43, 51, 60, 92]
 i = 4 [3, 37, 43, 51, 60, 92]
 i = 5 [3, 37, 43, 51, 60, 92]
 
  [8, 4, 6, 2]

  i = 0 [4, 8, 6, 2]
  i = 1 [4, 6, 8, 2]
  i = 2 [4, 6, 2, 8]
----------------------------------

  Bolha (Bubble Sort)

  [3, 1, 4, 1, 5]

  i = 4 [1, 3, 1, 4, 5]
  i = 3 [1, 1, 3, 4, 5]
  i = 2 [1, 1, 3, 4, 5]
  i = 1 [1, 1, 3, 4, 5]

  Intercalação (Merge Sort)

  [3, 7, 1, 5] (3,7) e (1,5)
  i = 0 (v[0] = 3, v[2] = 1)
  3 <= 1 não -> w[0] = 1, j = 3
  3 <= 5 sim -> w[1] = 3, i = 1
  7 <= 5 não -> w[2] = 5, j = 4 

 */