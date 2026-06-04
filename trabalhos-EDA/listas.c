#include "listas.h"

TNoI *InserirIndustria(TNoI *Inicio, TCadastro *Dados){
    TNoI *novoNo = (TNoI*)malloc(sizeof(TNoI));
    if(novoNo == NULL){
        printf("Erro ao alocar memória para o novo nó.\n");
        return Inicio; // Retorna a cabeça original se a alocação falhar
    }
    novoNo->Dados = Dados;
    novoNo->Prox = Inicio; // O novo nó aponta para o início da lista
    return novoNo; // O novo nó se torna a nova cabeça da lista
}
TNoI *CarregarIndustria(TNoI *Inicio){
    FILE *Arquivo = fopen("Industria.txt", "r");
    if(Arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return Inicio; // Retorna a cabeça original se o arquivo não puder ser aberto
    }
    TCadastro *novo = malloc(sizeof(TCadastro));
    while(fgets(novo->CNPJ, sizeof(novo->CNPJ),Arquivo)){
        fgets(novo->RazaoSocial, sizeof(novo->RazaoSocial), Arquivo);
        fgets(novo->Cidade, sizeof(novo->Cidade), Arquivo);
        fgets(novo->Fone, sizeof(novo->Fone), Arquivo);
        Inicio = InserirIndustria(Inicio, novo);
        novo = malloc(sizeof(TCadastro)); // Aloca um novo cadastro para a próxima leitura
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
        fgets(novo->RazaoSocial, sizeof(novo->RazaoSocial), Arquivo);
        fgets(novo->Cidade, sizeof(novo->Cidade), Arquivo);
        fgets(novo->Fone, sizeof(novo->Fone), Arquivo);
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
        fgets(novo->RazaoSocial, sizeof(novo->RazaoSocial), Arquivo);
        fgets(novo->Cidade, sizeof(novo->Cidade), Arquivo);
        fgets(novo->Fone, sizeof(novo->Fone), Arquivo);
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

void GerarListaUnificada(TNoI *Industria, TNoC *Comercio, TDescritorS *Servico, TDescritorU *Unificada){
 
    TNoI *atualIndustria = Industria;
    TNoC *atualComercio = Comercio;
    TNoS *atualServico = Servico->Inicio;
    
    TCadastroU *novo = malloc(sizeof(TCadastroU));
    while(atualIndustria != NULL){
        strcpy(novo->CNPJ, atualIndustria->Dados->CNPJ);
        strcpy(novo->RazaoSocial, atualIndustria->Dados->RazaoSocial);
        strcpy(novo->Cidade, atualIndustria->Dados->Cidade);
        strcpy(novo->Fone, atualIndustria->Dados->Fone);
        novo->Tipo = 'I';
        InserirListaUnificada(Unificada, novo);
        novo = malloc(sizeof(TCadastroU));
        atualIndustria = atualIndustria->Prox;
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





