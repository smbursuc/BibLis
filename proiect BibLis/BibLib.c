#include "BibLib.h"

bool esteVida(stiva S)
{
    return S.nrElemente==0;
}

void initializeaza(stiva& S)
{
    S.varf=NULL; S.nrElemente=0;
}
