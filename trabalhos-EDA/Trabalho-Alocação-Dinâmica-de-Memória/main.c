#include "listas.h"

int main(){

    TTemperaturas temps;
    int op;

    temps.medidas = NULL;

    do{
      printf("1 -  Reset\n"); // ler qtde_dias e aloca o vetor
      printf("2 - Inserir Medida\n"); // ler cidade e temperatura e adicionar no vetor
      printf("3 - Estatística\n"); // Mostar média, menor e maior temperatura
      printf("0 - Sair\n"); // Sai do programa
      scanf("%d", &op);   
      switch (op){
      case 1:
            if (temps.medidas != NULL)
            {
                free(temps.medidas);
            }
            printf("Quantos dias você deseja armazenar de medidas: ");
            scanf("%d", &temps.qtde_dias);
            temps.medidas = (TMedidas*) malloc(temps.qtde_dias * sizeof(TMedidas));
            for(int i = 0; i < temps.qtde_dias; i++){
                temps.medidas[i].temperatura = (float*) malloc(sizeof(float));
            }
            temps.qtde_medidas= 0;
            break;
      case 2:
            if (temps.medidas == NULL || temps.qtde_medidas >= temps.qtde_dias)
            {
                printf("Erro!\n");
                
            } 
            else{
                printf("Informe o nome da cidade: ");
                scanf("%s", temps.medidas[temps.qtde_medidas].cidade);
                printf("Informe a temperatura: ");
                scanf("%f", temps.medidas[temps.qtde_medidas].temperatura);
                temps.qtde_medidas ++;
            }
          break;
      case 3:
            if (temps.medidas == NULL || temps.qtde_medidas == 0)
            {
                printf("Nenhuma medida registrada!");
            } else {
                float soma = 0;
                for (int i = 0; i < temps.qtde_medidas; i++)
                {
                    soma += *temps.medidas[i].temperatura;
                }
                float media = soma / temps.qtde_medidas;
                
                int IMaior = 0;
                int IMenor = 0;

                for (int i = 1; i < temps.qtde_medidas; i++)
                {
                    if (*temps.medidas[i].temperatura > *temps.medidas[IMaior].temperatura)
                    {
                        IMaior = i;
                    } else if (*temps.medidas[i].temperatura < *temps.medidas[IMenor].temperatura)
                    {
                        IMenor = i;
                    }
                }
                printf("A média da temperatura é: %f\n", media);
                printf("A maior temperatura foi: %s - %f\n", temps.medidas[IMaior].cidade, *temps.medidas[IMaior].temperatura);
                printf("A menor temperatura foi: %s - %f\n", temps.medidas[IMenor].cidade, *temps.medidas[IMenor].temperatura);
                
            }
          break;
      case 0:
            if (temps.medidas != NULL)
            {
                for (int i = 0; i < temps.qtde_dias; i++)
                {
                  free(temps.medidas[i].temperatura);
                }
            }
          free(temps.medidas);
          break;
      default:
          break;
      }
    } while (op != 0 );
    
    return 0;
}



