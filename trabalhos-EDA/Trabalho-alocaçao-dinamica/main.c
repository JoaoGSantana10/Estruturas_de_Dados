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
            for(int i; i < temps.qtde_dias; i++){
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
          printf("Em construção\n");
          break;
      case 0:
          printf("Encerrando o programa");
          break;
      default:
          break;
      }
    } while (op != 0 );
    
    return 0;
}



