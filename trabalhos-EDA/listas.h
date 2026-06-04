#ifndef LISTAS_H
#define LISTAS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Cadastro{
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
} TCadastro;

typedef struct CadastroU{
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo;
} TCadastroU;

typedef struct NoI{
    TCadastro *Dados;
    struct NoI *Prox;
} TNoI;

typedef struct NoC{
    TCadastro *Dados;
    struct NoC *Ant;
    struct NoC *Prox;
} TNoC;

typedef struct NoS{
    TCadastro *Dados;
    struct NoS *Ant;
    struct NoS *Prox;
} TNoS;

typedef struct DescritorS{
    TNoS *Inicio;
    int Tamanho;
    TNoS *Fim;
} TDescritorS;

typedef struct NoU{
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;

typedef struct DescritorU{
    TNoU *Inicio;
    int Tamanho;
    TNoU *Fim;
} TDescritorU;

TNoI *InserirIndustria(TNoI *Inicio, TCadastro *Dados);
TNoI *CarregarIndustria(TNoI *Inicio);
TNoC *InserirComercio(TNoC *Inicio, TCadastro *Dados);
TNoC *CarregarComercio(TNoC *Inicio);
void InserirServico(TDescritorS *DescritorS, TCadastro *Dados);
void CarregarServico(TDescritorS *DescritorS);
void InserirListaUnificada(TDescritorU *Unificada, TCadastroU *Dados);
void CarregarListaUnificada(TDescritorU *Unificada);
void RelatorioIndustria(TNoI *Inicio);
void RelatorioComercio(TNoC *Inicio);
void RelatorioServico(TDescritorS *DescritorS);
void RelatorioComercioInvertido(TNoC *Fim);
void RelatorioServicoInvertido(TDescritorS *DescritorS);

#endif