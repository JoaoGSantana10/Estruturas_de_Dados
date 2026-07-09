/* ============================================================
   EDA - Tarefa 5: Árvores Binárias (Parte 1)
   ------------------------------------------------------------
   Cria manualmente (no-a-no, sem função de inserção genérica)
   a árvore binária apresentada na Parte 1 do exercício:

                       15
                     /    \
                    8      22
                  /   \   /   \
                 4    11 18   27
               /  \   / \
              2    6 10  13

   Em seguida, percorre a árvore em pré-ordem, em-ordem e
   pós-ordem, e libera toda a memória alocada ao final.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------
   Estrutura do nó da árvore binária
   ------------------------------------------------------------ */
typedef struct No {
    int dado;
    struct No *esquerda;
    struct No *direita;
} No;

/* ------------------------------------------------------------
   Cria um nó novo, já inicializado com filhos NULL.
   (usada apenas para não repetir malloc + checagem em cada
   linha do main; a ligação entre os nós continua sendo feita
   manualmente, nó a nó, logo abaixo)
   ------------------------------------------------------------ */
No *criarNo(int valor) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para o valor %d.\n", valor);
        exit(1);
    }
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

/* ------------------------------------------------------------
   Percursos
   ------------------------------------------------------------ */
void preOrdem(No *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->dado);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->dado);
    emOrdem(raiz->direita);
}

void posOrdem(No *raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->dado);
}

/* ------------------------------------------------------------
   Libera toda a memória da árvore (pós-ordem: primeiro os
   filhos, depois o próprio nó), garantindo que não sobre
   nenhum bloco alocado ao final da execução.
   ------------------------------------------------------------ */
void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main(void) {
    /* --------------------------------------------------------
       Criação manual de cada nó da árvore da Parte 1
       -------------------------------------------------------- */
    No *n15 = criarNo(15);
    No *n8  = criarNo(8);
    No *n22 = criarNo(22);
    No *n4  = criarNo(4);
    No *n11 = criarNo(11);
    No *n18 = criarNo(18);
    No *n27 = criarNo(27);
    No *n2  = criarNo(2);
    No *n6  = criarNo(6);
    No *n10 = criarNo(10);
    No *n13 = criarNo(13);

    /* Ligação manual dos ponteiros (nó a nó, sem função de
       inserção automática) */
    n15->esquerda = n8;
    n15->direita  = n22;

    n8->esquerda  = n4;
    n8->direita   = n11;

    n22->esquerda = n18;
    n22->direita  = n27;

    n4->esquerda  = n2;
    n4->direita   = n6;

    n11->esquerda = n10;
    n11->direita  = n13;

    /* n18 e n27 permanecem como folhas (esquerda/direita = NULL) */

    /* --------------------------------------------------------
       Percursos
       -------------------------------------------------------- */
    printf("Pre-ordem:  ");
    preOrdem(n15);
    printf("\n");

    printf("Em-ordem:   ");
    emOrdem(n15);
    printf("\n");

    printf("Pos-ordem:  ");
    posOrdem(n15);
    printf("\n");

    /* --------------------------------------------------------
       Libera toda a memoria alocada
       -------------------------------------------------------- */
    liberarArvore(n15);

    return 0;
}