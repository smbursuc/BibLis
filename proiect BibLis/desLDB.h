#ifndef _DESLDB_
#define _DESLDB_

#include "BibLib.h"

void desenareLDB(lista L,double rez2,int anim);

void desenCasPrim(double rez2,int anim, int nrLimba);

void desenCasUlt(double rez2,int anim, int nrLimba);

void desenCasElm(int elem,double rez2,int time,int anim,nod* nod_nou,lista L);

void desen_linie(int coord_cas_x1, int coord_cas_y1,int coord_cas_x2,int coord_cas_y2);

void test_LDB(int x, int y, lista &L,int nrRez, int nrLimba, int nrSound);
#endif // _DESLDB_
