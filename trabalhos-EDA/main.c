#include "listas.h"

int main(){
    TNoI *Industria = NULL;
    TNoC *Comercio = NULL;
    TDescritorS DescritorS = {NULL, 0, NULL};
    TDescritorU DescritorU = {NULL, 0, NULL};

    Industria = CarregarIndustria(Industria);
    Comercio = CarregarComercio(Comercio);
    
    GerarListaUnificada(Industria, Comercio, &DescritorS, &DescritorU);


    return 0;
}