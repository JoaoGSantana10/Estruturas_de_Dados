/* ============================================================
   EDA - Trabalho 6: Questao 4 - Sistema de Inventario de Laboratorio
   ------------------------------------------------------------
   Cada equipamento e armazenado em uma ABP indexada pelo
   Codigo de Patrimonio. A busca retorna o nome do equipamento
   encontrado ou uma mensagem de "Nao encontrado".
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

/* ------------------------------------------------------------
   Estrutura do no: cada equipamento guarda seu codigo de
   patrimonio (chave da ABP) e o nome do equipamento.
   ------------------------------------------------------------ */
typedef struct NoEquipamento {
    int  codigoPatrimonio;
    char nome[TAM_NOME];
    struct NoEquipamento *esquerda;
    struct NoEquipamento *direita;
} NoEquipamento;

NoEquipamento *criarNoEquipamento(int codigo, const char *nome) {
    NoEquipamento *novo = (NoEquipamento *) malloc(sizeof(NoEquipamento));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para o codigo %d.\n", codigo);
        exit(1);
    }
    novo->codigoPatrimonio = codigo;
    strncpy(novo->nome, nome, TAM_NOME - 1);
    novo->nome[TAM_NOME - 1] = '\0';
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

NoEquipamento *inserirEquipamento(NoEquipamento *raiz, int codigo, const char *nome) {
    if (raiz == NULL) {
        return criarNoEquipamento(codigo, nome);
    }

    if (codigo < raiz->codigoPatrimonio) {
        raiz->esquerda = inserirEquipamento(raiz->esquerda, codigo, nome);
    } else if (codigo > raiz->codigoPatrimonio) {
        raiz->direita = inserirEquipamento(raiz->direita, codigo, nome);
    }

    return raiz;
}

/* ------------------------------------------------------------
   Funcao pedida na Questao 4: recebe a raiz da arvore e um
   codigo de patrimonio, e retorna o nome do equipamento (caso
   exista) ou a mensagem "Nao encontrado".
   ------------------------------------------------------------ */
const char *buscarEquipamento(NoEquipamento *raiz, int codigo) {
    if (raiz == NULL) {
        return "Nao encontrado";
    }

    if (codigo == raiz->codigoPatrimonio) {
        return raiz->nome;
    } else if (codigo < raiz->codigoPatrimonio) {
        return buscarEquipamento(raiz->esquerda, codigo);
    } else {
        return buscarEquipamento(raiz->direita, codigo);
    }
}

void liberarEquipamentos(NoEquipamento *raiz) {
    if (raiz == NULL) return;
    liberarEquipamentos(raiz->esquerda);
    liberarEquipamentos(raiz->direita);
    free(raiz);
}

int main(void) {
    NoEquipamento *raiz = NULL;

    raiz = inserirEquipamento(raiz, 1050, "Microscopio Digital");
    raiz = inserirEquipamento(raiz, 1020, "Osciloscopio");
    raiz = inserirEquipamento(raiz, 1080, "Fonte de Alimentacao");
    raiz = inserirEquipamento(raiz, 1010, "Multimetro");
    raiz = inserirEquipamento(raiz, 1035, "Gerador de Sinais");

    printf("Codigo 1035 -> %s\n", buscarEquipamento(raiz, 1035));
    printf("Codigo 1080 -> %s\n", buscarEquipamento(raiz, 1080));
    printf("Codigo 9999 -> %s\n", buscarEquipamento(raiz, 9999));

    liberarEquipamentos(raiz);

    return 0;
}