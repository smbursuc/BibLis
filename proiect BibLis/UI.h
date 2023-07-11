#ifndef _UI_
#define _UI_

#include "BibLib.h"

void meniu_principal(stiva &S, coada &C, lista &L, lis_sim &X, int nrRez, int nrLimba, int nrSound);

void meniu_selectare_lis(stiva &S, coada &C, lista &L, lis_sim &X, bool Switch,int nrRez,int nrLimba,int nrSound);

void settings(stiva S, coada C, lista L, lis_sim X,int nrRez, int nrLimba, int nrSound);

void credits (stiva S, coada C, lista L, lis_sim X,int nrRez, int nrLimba, int nrSound);

void easter_egg(stiva S, coada C, lista L, lis_sim X,int nrRez, int nrLimba, int nrSound);
#endif // _UI_
