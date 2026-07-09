/* ============================================================
   EDA - Trabalho 4: Algoritmo de Busca
   ------------------------------------------------------------
   Carrega um vetor de municipios (IBGE + Linha + demais campos)
   a partir de um arquivo CSV, e permite consultar um municipio
   pelo codigo IBGE usando Busca Binaria e Busca Sequencial,
   comparando o tempo de execucao de cada uma.

   Observacoes de implementacao:
   - O vetor eh alocado dinamicamente (malloc) e toda a memoria
     alocada eh devidamente liberada (free) antes de sair do
     programa, sem deixar lixo.
   - O CSV precisa estar ordenado por IBGE para a busca binaria
     funcionar corretamente (o arquivo fornecido ja esta ordenado).
   - Uso de \r foi tratado na leitura das linhas, para evitar o
     problema classico de "string corrompida" ao ler arquivos
     gerados/exportados no Windows.

     Para rodar o Código:
     gcc -Wall -o trabalho4 trabalho4.c
     ./trabalho4
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <linux/time.h>

#define NOME_ARQUIVO   "municipios.csv"
#define TAM_MUNICIPIO  100
#define TAM_UF         5
#define TAM_REGIAO     50
#define TAM_PORTE      20

/* ------------------------------------------------------------
   Estrutura que representa cada registro do vetor
   ------------------------------------------------------------ */
typedef struct {
    long ibge;
    int  linha;
    char municipio[TAM_MUNICIPIO];
    char uf[TAM_UF];
    char regiao[TAM_REGIAO];
    long populacao2010;
    char porte[TAM_PORTE];
} Municipio;

/* ------------------------------------------------------------
   Remove '\r' e '\n' do final de uma string (evita lixo vindo
   de arquivos com quebra de linha estilo Windows: \r\n)
   ------------------------------------------------------------ */
static void limparQuebraLinha(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[len - 1] = '\0';
        len--;
    }
}

/* ------------------------------------------------------------
   1. Carregar dados
   Le o arquivo CSV e monta o vetor dinamico de Municipio.
   Retorna o ponteiro do vetor alocado e, via parametro,
   a quantidade de registros lidos.
   ------------------------------------------------------------ */
Municipio *carregarDados(const char *nomeArquivo, int *quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", nomeArquivo);
        *quantidade = 0;
        return NULL;
    }

    char linha[512];

    /* Primeiro, conta quantas linhas de dados existem (descontando o cabecalho) */
    int totalLinhas = 0;
    /* pula o cabecalho */
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        *quantidade = 0;
        return NULL;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        /* ignora linhas vazias (evita "nos fantasmas") */
        limparQuebraLinha(linha);
        if (strlen(linha) > 0) {
            totalLinhas++;
        }
    }

    if (totalLinhas == 0) {
        fclose(arquivo);
        *quantidade = 0;
        return NULL;
    }

    /* Aloca o vetor dinamicamente com o tamanho exato necessario */
    Municipio *vetor = (Municipio *) malloc(totalLinhas * sizeof(Municipio));
    if (vetor == NULL) {
        printf("Erro: falha ao alocar memoria.\n");
        fclose(arquivo);
        *quantidade = 0;
        return NULL;
    }

    /* Volta ao inicio do arquivo para ler os dados de fato */
    rewind(arquivo);
    fgets(linha, sizeof(linha), arquivo); /* descarta o cabecalho de novo */

    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL && i < totalLinhas) {
        limparQuebraLinha(linha);
        if (strlen(linha) == 0) {
            continue; /* pula linha em branco */
        }

        char *token;

        token = strtok(linha, ",");
        if (token == NULL) continue;
        vetor[i].ibge = atol(token);

        token = strtok(NULL, ",");
        vetor[i].linha = (token != NULL) ? atoi(token) : 0;

        token = strtok(NULL, ",");
        strncpy(vetor[i].municipio, (token != NULL) ? token : "", TAM_MUNICIPIO - 1);
        vetor[i].municipio[TAM_MUNICIPIO - 1] = '\0';

        token = strtok(NULL, ",");
        strncpy(vetor[i].uf, (token != NULL) ? token : "", TAM_UF - 1);
        vetor[i].uf[TAM_UF - 1] = '\0';

        token = strtok(NULL, ",");
        strncpy(vetor[i].regiao, (token != NULL) ? token : "", TAM_REGIAO - 1);
        vetor[i].regiao[TAM_REGIAO - 1] = '\0';

        token = strtok(NULL, ",");
        vetor[i].populacao2010 = (token != NULL) ? atol(token) : 0;

        token = strtok(NULL, ",");
        strncpy(vetor[i].porte, (token != NULL) ? token : "", TAM_PORTE - 1);
        vetor[i].porte[TAM_PORTE - 1] = '\0';

        i++;
    }

    fclose(arquivo);
    *quantidade = i;
    return vetor;
}

/* ------------------------------------------------------------
   Busca Sequencial: percorre o vetor do inicio ao fim.
   Complexidade: O(n)
   ------------------------------------------------------------ */
int buscaSequencial(Municipio *vetor, int n, long ibgeProcurado) {
    for (int i = 0; i < n; i++) {
        if (vetor[i].ibge == ibgeProcurado) {
            return i;
        }
    }
    return -1;
}

/* ------------------------------------------------------------
   Busca Binaria: exige vetor ordenado por IBGE.
   Complexidade: O(log n)
   ------------------------------------------------------------ */
int buscaBinaria(Municipio *vetor, int n, long ibgeProcurado) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio].ibge == ibgeProcurado) {
            return meio;
        } else if (vetor[meio].ibge < ibgeProcurado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

/* ------------------------------------------------------------
   Exibe as informacoes de um municipio na tela
   ------------------------------------------------------------ */
void exibirMunicipio(Municipio m) {
    printf("\n----- Dados do Municipio -----\n");
    printf("Municipio:        %s\n", m.municipio);
    printf("UF:               %s\n", m.uf);
    printf("Regiao:           %s\n", m.regiao);
    printf("Populacao (2010): %ld\n", m.populacao2010);
    printf("Porte:            %s\n", m.porte);
    printf("-------------------------------\n");
}

/* ------------------------------------------------------------
   2. Consultar municipio
   Le o codigo IBGE, executa as duas buscas, mede o tempo de
   cada uma com clock_gettime (alta resolucao) e exibe o
   resultado.
   ------------------------------------------------------------ */
void consultarMunicipio(Municipio *vetor, int n) {
    if (vetor == NULL || n == 0) {
        printf("\nOs dados ainda nao foram carregados. Escolha a opcao 1 primeiro.\n");
        return;
    }

    long codigoIbge;
    printf("\nDigite o codigo IBGE do municipio: ");
    if (scanf("%ld", &codigoIbge) != 1) {
        printf("Entrada invalida.\n");
        /* limpa o buffer de entrada em caso de erro */
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    struct timespec inicio, fim;
    double tempoBinaria, tempoSequencial;

    /* ---------- Busca Binaria ---------- */
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    int posBin = buscaBinaria(vetor, n, codigoIbge);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempoBinaria = (fim.tv_sec - inicio.tv_sec) * 1e6
                 + (fim.tv_nsec - inicio.tv_nsec) / 1e3; /* microssegundos */

    /* ---------- Busca Sequencial ---------- */
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    int posSeq = buscaSequencial(vetor, n, codigoIbge);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempoSequencial = (fim.tv_sec - inicio.tv_sec) * 1e6
                     + (fim.tv_nsec - inicio.tv_nsec) / 1e3; /* microssegundos */
    (void) posSeq; /* usado apenas para garantir que a busca sequencial tambem execute */

    if (posBin != -1) {
        exibirMunicipio(vetor[posBin]);
    } else {
        printf("\nMunicipio com codigo IBGE %ld nao encontrado.\n", codigoIbge);
    }

    printf("\nTempo de execucao da busca:\n");
    printf("  Busca Binaria:    %.4f microssegundos\n", tempoBinaria);
    printf("  Busca Sequencial: %.4f microssegundos\n", tempoSequencial);
}

/* ------------------------------------------------------------
   Libera toda a memoria alocada dinamicamente
   ------------------------------------------------------------ */
void liberarMemoria(Municipio *vetor) {
    free(vetor);
}

/* ------------------------------------------------------------
   Programa principal - Menu
   ------------------------------------------------------------ */
int main(void) {
    Municipio *vetor = NULL;
    int n = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Carregar dados\n");
        printf("2. Consultar municipio\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (opcao) {
            case 1:
                if (vetor != NULL) {
                    /* evita vazamento de memoria caso os dados
                       ja tenham sido carregados anteriormente */
                    liberarMemoria(vetor);
                    vetor = NULL;
                }
                vetor = carregarDados(NOME_ARQUIVO, &n);
                if (vetor != NULL) {
                    printf("\n%d registros carregados com sucesso.\n", n);
                }
                break;

            case 2:
                consultarMunicipio(vetor, n);
                break;

            case 3:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 3);

    /* Libera a memoria alocada antes de encerrar, garantindo
       que nao fique lixo em memoria */
    if (vetor != NULL) {
        liberarMemoria(vetor);
        vetor = NULL;
    }

    return 0;
}