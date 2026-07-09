/* ============================================================
   EDA - Trabalho 6: Arvores Binarias de Pesquisa (ABP)
   ------------------------------------------------------------
   Implementa as funcoes basicas de uma ABP de numeros inteiros:
   criacao de no, insercao recursiva e busca. O main constroi a
   arvore a partir da sequencia de insercao da Questao 1 e
   imprime os tres percursos (Questao 2).
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------
   Questao 3.8: definicao da estrutura TNoBin
   ------------------------------------------------------------ */
typedef struct TNoBin {
    int chave;
    struct TNoBin *esquerda;
    struct TNoBin *direita;
} TNoBin;

/* ------------------------------------------------------------
   Questao 3.9: funcao para criar um novo no
   ------------------------------------------------------------ */
TNoBin *criarNo(int valor) {
    TNoBin *novo = (TNoBin *) malloc(sizeof(TNoBin));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para a chave %d.\n", valor);
        exit(1);
    }
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

/* ------------------------------------------------------------
   Questao 3.10: funcao recursiva de insercao.
   Recebe a raiz da (sub)arvore e devolve a raiz atualizada,
   ja com o novo valor inserido na posicao correta.
   ------------------------------------------------------------ */
TNoBin *inserir(TNoBin *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->chave) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    /* valores iguais sao ignorados (nao entram duas vezes na ABP) */

    return raiz;
}

/* ------------------------------------------------------------
   Questao 3.11: funcao de busca. Retorna o endereco do no que
   contem a chave procurada, ou NULL caso ela nao exista.
   ------------------------------------------------------------ */
TNoBin *buscar(TNoBin *raiz, int valor) {
    if (raiz == NULL || raiz->chave == valor) {
        return raiz;
    }

    if (valor < raiz->chave) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

/* ------------------------------------------------------------
   Percursos (usados na Questao 2)
   ------------------------------------------------------------ */
void preOrdem(TNoBin *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->chave);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void emOrdem(TNoBin *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->chave);
    emOrdem(raiz->direita);
}

void posOrdem(TNoBin *raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->chave);
}

/* ------------------------------------------------------------
   Calcula a altura da arvore (raiz no nivel 0, arvore vazia
   tem altura -1 por convencao)
   ------------------------------------------------------------ */
int altura(TNoBin *raiz) {
    if (raiz == NULL) return -1;

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    int maior = (alturaEsquerda > alturaDireita) ? alturaEsquerda : alturaDireita;
    return maior + 1;
}

/* ------------------------------------------------------------
   Libera toda a memoria da arvore (pos-ordem)
   ------------------------------------------------------------ */
void liberarArvore(TNoBin *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main(void) {
    TNoBin *raiz = NULL;

    /* Sequencia de insercao da Questao 1 */
    int valores[] = {45, 23, 67, 12, 34, 56, 89, 30, 40};
    int quantidade = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < quantidade; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Pre-ordem:  ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-ordem:   ");
    emOrdem(raiz);
    printf("\n");

    printf("Pos-ordem:  ");
    posOrdem(raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", altura(raiz));

    /* Teste da funcao de busca */
    int chaveProcurada = 56;
    TNoBin *encontrado = buscar(raiz, chaveProcurada);
    if (encontrado != NULL) {
        printf("Chave %d encontrada (endereco: %p)\n", chaveProcurada, (void *) encontrado);
    } else {
        printf("Chave %d nao encontrada.\n", chaveProcurada);
    }

    int chaveInexistente = 100;
    encontrado = buscar(raiz, chaveInexistente);
    if (encontrado != NULL) {
        printf("Chave %d encontrada.\n", chaveInexistente);
    } else {
        printf("Chave %d nao encontrada.\n", chaveInexistente);
    }

    liberarArvore(raiz);

    return 0;
}