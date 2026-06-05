#include "listas.h"

// gcc main.c listas.c -o programa
//./programa

int main(){
    TNoI *Industrias = NULL;
    TNoC *Comercio = NULL;
    TDescritorS DescritorS = {NULL, 0, NULL};
    TDescritorU DescritorU = {NULL, 0, NULL};

    int opcao;
    do{
        printf("1. Carregar Dados de Entrada\n");
        printf("2. Gerar Lista Unificada\n");
        printf("3. Relatório: Industrias\n");
        printf("4. Relatório: Comércio\n");
        printf("5. Relatório: Comércio Invertida\n");
        printf("6. Relatório: Serviços\n");
        printf("7. Relatório: Serviços Invertida\n");
        printf("8. Relatório: Lista Unificada\n");
        printf("9. Relatório: Lista Unificada Invertida\n");
        printf("10. Apagar Listas\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado após a leitura do número

        switch(opcao){
            case 1:
                Industrias = CarregarIndustrias(Industrias);
                Comercio = CarregarComercio(Comercio);
                CarregarServico(&DescritorS);
                break;
            case 2:
                GerarListaUnificada(Industrias, Comercio, &DescritorS, &DescritorU);
                break;
            case 3:
                RelatorioIndustrias(Industrias);
                break;
            case 4:
                RelatorioComercio(Comercio);
                break;
            case 5: {
                TNoC *fim = Comercio;
                while(fim != NULL && fim->Prox != NULL)
                    fim = fim->Prox;
                    RelatorioComercioInvertido(fim);
                    break;
                }
            case 6:
                RelatorioServico(&DescritorS);
                break;
            case 7:
                RelatorioServicoInvertido(&DescritorS);
                break;
            case 8:
                RelatorioListaUnificada(&DescritorU);
                break;
            case 9:
                RelatorioListaUnificadaInvertida(&DescritorU);
                break;

           case 10:
                ApagarListaUnificada(&DescritorU);
                if(Industrias != NULL) {
                    ApagarListaIndustrias(Industrias);
                    Industrias = NULL;
                }
                if(Comercio != NULL) {
                    ApagarListaComercio(Comercio);
                    Comercio = NULL;
                }   
                ApagarListaServico(&DescritorS);
                printf("Listas apagadas com sucesso!\n");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    }while(opcao != 0);
    return 0;
}