#include "listas.h"

void removerNewline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n')
        str[len-1] = '\0';
    len = strlen(str);
    if (len > 0 && str[len-1] == '\r')
        str[len-1] = '\0';
}

TNoI *InserirIndustrias(TNoI *Inicio, TCadastro *Dados){
    TNoI *novoNo = (TNoI*)malloc(sizeof(TNoI));
    if(novoNo == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return Inicio; // Retorna a cabeça original se a alocação falhar
    }
    novoNo->Dados = Dados;
    novoNo->Prox = Inicio; // O novo nó aponta para o início da lista
    return novoNo; // O novo nó se torna a nova cabeça da lista
}
TNoI *CarregarIndustrias(TNoI *Inicio){
    FILE *Arquivo = fopen("Industrias.txt", "r");
    if(Arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return Inicio; // Retorna a cabeça original se o arquivo não puder ser aberto
    }
    TCadastro *novo = malloc(sizeof(TCadastro));
   while(fgets(novo->CNPJ, sizeof(novo->CNPJ), Arquivo)){
    removerNewline(novo->CNPJ);
    if(strlen(novo->CNPJ) == 0) continue; // pula linha vazia
    fgets(novo->RazaoSocial, sizeof(novo->RazaoSocial), Arquivo);
    removerNewline(novo->RazaoSocial);
    fgets(novo->Cidade, sizeof(novo->Cidade), Arquivo);
    removerNewline(novo->Cidade);
    fgets(novo->Fone, sizeof(novo->Fone), Arquivo);
    removerNewline(novo->Fone);
    Inicio = InserirIndustrias(Inicio, novo);
    novo = malloc(sizeof(TCadastro));
}
    free(novo); // Libera a última alocação que não foi usada
    fclose(Arquivo);
    return Inicio;
}

TNoC *InserirComercio(TNoC *Inicio, TCadastro *Dados){
    TNoC *novoNo = (TNoC*)malloc(sizeof(TNoC));
    if(novoNo == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return Inicio; // Retorna a cabeça original se a alocação falhar
    }
    novoNo->Dados = Dados;
    novoNo->Prox = Inicio; // O novo nó aponta para o início da lista
    if(Inicio != NULL){
        Inicio->Ant = novoNo; // O nó antigo agora tem o novo nó como anterior
    }
    novoNo->Ant = NULL; // O novo nó é o primeiro, então não tem anterior
    return novoNo; // O novo nó se torna a nova cabeça da lista
}

TNoC *CarregarComercio(TNoC *Inicio){
    FILE *Arquivo = fopen("Comercio.txt", "r"); // Abre o arquivo para leitura
    if(Arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return Inicio; // Retorna a cabeça original se o arquivo não puder ser aberto
    }
    TCadastro *novo = malloc(sizeof(TCadastro)); // Aloca memória para um novo cadastro
    while(fgets(novo->CNPJ, sizeof(novo->CNPJ), Arquivo)){
        removerNewline(novo->CNPJ); // Remove o \n do final da string
        if(strlen(novo->CNPJ) == 0) continue; // pula linha vazia
        fgets(novo->RazaoSocial, sizeof(novo->RazaoSocial), Arquivo);
        removerNewline(novo->RazaoSocial); // Remove o \n do final da string
        fgets(novo->Cidade, sizeof(novo->Cidade), Arquivo);
        removerNewline(novo->Cidade); // Remove o \n do final da string
        fgets(novo->Fone, sizeof(novo->Fone), Arquivo);
        removerNewline(novo->Fone); // Remove o \n do final da string
        Inicio = InserirComercio(Inicio, novo); // Insere o novo cadastro
        novo = malloc(sizeof(TCadastro)); // Aloca um novo cadastro para a próxima leitura
    }
    free(novo); // Libera a última alocação que não foi usada
    fclose(Arquivo);
    return Inicio;
}

void InserirServico(TDescritorS *DescritorS, TCadastro *Dados){
    TNoS *novoNo = (TNoS*)malloc(sizeof(TNoS));
    if(novoNo == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return; // Retorna sem fazer nada se a alocação falhar
    }
    novoNo->Dados = Dados;
    novoNo->Prox = DescritorS->Inicio; // O novo nó aponta para o início da lista
    if(DescritorS->Inicio != NULL){
        DescritorS->Inicio->Ant = novoNo; // O nó antigo agora tem o novo nó como anterior
    }
    novoNo->Ant = NULL; // O novo nó é o primeiro, então não tem anterior
    DescritorS->Inicio = novoNo; // O novo nó se torna a nova cabeça da lista
    DescritorS->Tamanho++; // Incrementa o tamanho do descritor
    if(DescritorS->Fim == NULL){
        DescritorS->Fim = novoNo; // Se a lista estava vazia, o novo nó também é o fim
    }
}

void CarregarServico(TDescritorS *DescritorS){
    FILE *Arquivo = fopen("Servico.txt", "r"); // Abre o arquivo para leitura
    if(Arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return; 
    }
    TCadastro *novo = malloc(sizeof(TCadastro)); // Aloca memória para um novo cadastro
    while(fgets(novo->CNPJ, sizeof(novo->CNPJ), Arquivo)){
        removerNewline(novo->CNPJ); // Remove o \n do final da string
        if(strlen(novo->CNPJ) == 0) continue; // pula linha vazia
        fgets(novo->RazaoSocial, sizeof(novo->RazaoSocial), Arquivo);
        removerNewline(novo->RazaoSocial); // Remove o \n do final da string
        fgets(novo->Cidade, sizeof(novo->Cidade), Arquivo);
        removerNewline(novo->Cidade); // Remove o \n do final da string
        fgets(novo->Fone, sizeof(novo->Fone), Arquivo);
        removerNewline(novo->Fone); // Remove o \n do final da string
        InserirServico(DescritorS, novo); // Insere o novo cadastro no descritor
        novo = malloc(sizeof(TCadastro)); // Aloca um novo cadastro para a próxima leitura
    }
    free(novo); // Libera a última alocação que não foi usada
    fclose(Arquivo);
}

void InserirListaUnificada(TDescritorU *Unificada, TCadastroU *Dados){
    TNoU *novoNo = (TNoU*)malloc(sizeof(TNoU));
    if(novoNo == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return; // Retorna sem fazer nada se a alocação falhar
    }
    novoNo->Dados = Dados;
    novoNo->Prox = Unificada->Inicio; // O novo nó aponta para o início da lista
    if(Unificada->Inicio != NULL){
        Unificada->Inicio->Ant = novoNo; // O nó antigo agora tem o novo nó como anterior
    }
    novoNo->Ant = NULL; // O novo nó é o primeiro, então não tem anterior
    Unificada->Inicio = novoNo; // O novo nó se torna a nova cabeça da lista
    Unificada->Tamanho++; // Incrementa o tamanho do descritor
    if(Unificada->Fim == NULL){
        Unificada->Fim = novoNo; // Se a lista estava vazia, o novo nó também é o fim
    }
}

void GerarListaUnificada(TNoI *Industrias, TNoC *Comercio, TDescritorS *Servico, TDescritorU *Unificada){
 
    TNoI *atualIndustrias = Industrias;
    TNoC *atualComercio = Comercio;
    TNoS *atualServico = Servico->Inicio;
    
    TCadastroU *novo = malloc(sizeof(TCadastroU));
    while(atualIndustrias != NULL){
        strcpy(novo->CNPJ, atualIndustrias->Dados->CNPJ);
        strcpy(novo->RazaoSocial, atualIndustrias->Dados->RazaoSocial);
        strcpy(novo->Cidade, atualIndustrias->Dados->Cidade);
        strcpy(novo->Fone, atualIndustrias->Dados->Fone);
        novo->Tipo = 'I';
        InserirListaUnificada(Unificada, novo);
        novo = malloc(sizeof(TCadastroU));
        atualIndustrias = atualIndustrias->Prox;
    } free(novo); // Libera a última alocação que não foi usada
    while( atualComercio != NULL){
        strcpy(novo->CNPJ, atualComercio->Dados->CNPJ);
        strcpy(novo->RazaoSocial, atualComercio->Dados->RazaoSocial);
        strcpy(novo->Cidade, atualComercio->Dados->Cidade);
        strcpy(novo->Fone, atualComercio->Dados->Fone);
        novo->Tipo = 'C';
        InserirListaUnificada(Unificada, novo);
        novo = malloc(sizeof(TCadastroU));
        atualComercio = atualComercio->Prox;
    } free(novo); // Libera a última alocação que não foi usada
    while(atualServico != NULL){
        strcpy(novo->CNPJ, atualServico->Dados->CNPJ);
        strcpy(novo->RazaoSocial, atualServico->Dados->RazaoSocial);
        strcpy(novo->Cidade, atualServico->Dados->Cidade);
        strcpy(novo->Fone, atualServico->Dados->Fone);
        novo->Tipo = 'S';
        InserirListaUnificada(Unificada, novo);
        novo = malloc(sizeof(TCadastroU));
        atualServico = atualServico->Prox;
    } free(novo); // Libera a última alocação que não foi usada
}

void RelatorioIndustrias(TNoI *Inicio){
    TNoI *atual = Inicio;
    while(atual != NULL){
        printf("CNPJ: %s\n", atual->Dados->CNPJ);
        printf("Razão Social: %s\n", atual->Dados->RazaoSocial);
        printf("Cidade: %s\n", atual->Dados->Cidade);
        printf("Fone: %s \n", atual->Dados->Fone);
        printf("---------------------\n");
        atual = atual->Prox;
    }
}

void RelatorioComercio(TNoC *Inicio){
    TNoC *atual = Inicio;
    while(atual != NULL){
        printf("CNPJ: %s\n", atual->Dados->CNPJ);
        printf("Razão Social: %s\n", atual->Dados->RazaoSocial);
        printf("Cidade: %s\n", atual->Dados->Cidade);
        printf("Fone: %s\n", atual->Dados->Fone);
        printf("---------------------\n");
        atual = atual->Prox;
    }
}

void RelatorioServico(TDescritorS *DescritorS){
    TNoS *atual = DescritorS->Inicio;
    while(atual != NULL){
        printf("CNPJ: %s\n", atual->Dados->CNPJ);
        printf("Razão Social: %s\n", atual->Dados->RazaoSocial);
        printf("Cidade: %s\n", atual->Dados->Cidade);
        printf("Fone: %s\n", atual->Dados->Fone);
        printf("---------------------\n");
        atual = atual->Prox;
    }
}


void RelatorioComercioInvertido(TNoC *Fim){
    TNoC *atual = Fim;
    while(atual != NULL){
        printf("CNPJ: %s\n", atual->Dados->CNPJ);
        printf("Razão Social: %s\n", atual->Dados->RazaoSocial);
        printf("Cidade: %s\n", atual->Dados->Cidade);
        printf("Fone: %s\n", atual->Dados->Fone);
        printf("---------------------\n");
        atual = atual->Ant;
    }
}

void RelatorioServicoInvertido(TDescritorS *DescritorS){
    TNoS *atual = DescritorS->Fim;
    while(atual != NULL){
        printf("CNPJ: %s\n", atual->Dados->CNPJ);
        printf("Razão Social: %s\n", atual->Dados->RazaoSocial);
        printf("Cidade: %s\n", atual->Dados->Cidade);
        printf("Fone: %s\n", atual->Dados->Fone);
        printf("---------------------\n");
        atual = atual->Ant;
    }
}

void RelatorioListaUnificada(TDescritorU *Unificada){
    TNoU *atual = Unificada->Inicio;
    while(atual != NULL){
        printf("CNPJ: %s\n", atual->Dados->CNPJ);
        printf("Razão Social: %s\n", atual->Dados->RazaoSocial);
        printf("Cidade: %s\n", atual->Dados->Cidade);
        printf("Fone: %s\n", atual->Dados->Fone);
        printf("Tipo: %c\n", atual->Dados->Tipo);
        printf("---------------------\n");
        atual = atual->Prox;
    }
}

void RelatorioListaUnificadaInvertida(TDescritorU *Unificada){
    TNoU *atual = Unificada->Fim;
    while(atual != NULL){
        printf("CNPJ: %s\n", atual->Dados->CNPJ);
        printf("Razão Social: %s\n", atual->Dados->RazaoSocial);
        printf("Cidade: %s\n", atual->Dados->Cidade);
        printf("Fone: %s\n", atual->Dados->Fone);
        printf("Tipo: %c\n", atual->Dados->Tipo);
        printf("---------------------\n");
        atual = atual->Ant;
    }
}

void ApagarListaIndustrias(TNoI *Inicio){
    TNoI *atual = Inicio;
    TNoI *proximo = NULL;
    while(atual != NULL){
        proximo = atual->Prox;
        free(atual->Dados); // Libera os dados do nó
        free(atual); // Libera o nó em si
        atual = proximo; // Move para o próximo nó
    }
}

void ApagarListaComercio(TNoC *Inicio){
    TNoC *atual = Inicio;
    TNoC *proximo = NULL;
    while(atual != NULL){
        proximo = atual->Prox;
        free(atual->Dados); // Libera os dados do nó
        free(atual); // Libera o nó em si
        atual = proximo; // Move para o próximo nó
    }
}

void ApagarListaServico(TDescritorS *DescritorS){
    TNoS *atual = DescritorS->Inicio;
    TNoS *proximo = NULL;
    while(atual != NULL){
        proximo = atual->Prox;
        free(atual->Dados); // Libera os dados do nó
        free(atual); // Libera o nó em si
        atual = proximo; // Move para o próximo nó
    }
    DescritorS->Inicio = NULL; // Define o início como NULL após apagar a lista
    DescritorS->Fim = NULL; // Define o fim como NULL após apagar a lista
    DescritorS->Tamanho = 0; // Reseta o tamanho do descritor para 0
}

void ApagarListaUnificada(TDescritorU *Unificada){
    TNoU *atual = Unificada->Inicio;
    TNoU *proximo = NULL;
    while(atual != NULL){
        proximo = atual->Prox;
        //free(atual->Dados); // Libera os dados do nó
        free(atual); // Libera o nó em si
        atual = proximo; // Move para o próximo nó
    }
    Unificada->Inicio = NULL; // Define o início como NULL após apagar a lista
    Unificada->Fim = NULL; // Define o fim como NULL após apagar a lista
    Unificada->Tamanho = 0; // Reseta o tamanho do descritor para 0
}


