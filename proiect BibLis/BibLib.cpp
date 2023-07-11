#include "BibLib.h"
#include <stdlib.h>
#include <time.h>

///STIVA
bool esteVidaS(stiva S)
{
    return S.nrElemente==0;
}

void initializeazaS(stiva& S)
{
    S.varf=NULL; S.nrElemente=0;
}

void push(stiva &S, tip element)
// adauga un element la stiva, in varf (LIFO)
{
    nod * nod_nou;
    if (esteVidaS(S))
    {
        S.nrElemente=1;
        S.varf=new nod;
        S.varf->info=element;
        S.varf->urm=NULL;
    }
    else
    {
        S.nrElemente++;
        nod_nou = new nod;
        nod_nou->info=element;
        nod_nou->urm=S.varf;
        S.varf=nod_nou;
    }
}

tip pop(stiva &S)
// scoate elementul din varful stivei
{
    if (!esteVidaS(S))
    {
        tip element;
        nod* varf_nou;
        element=S.varf->info;
        varf_nou=S.varf->urm;
        delete S.varf;
        S.varf=varf_nou;
        S.nrElemente--;
        return element;
    }
}

void golesteS(stiva &S)
{
    tip element;
    while (!esteVidaS(S)) element=pop(S);
}

void creareAleatoare_stiva(stiva &S)
{
    golesteS(S);
    int n=3+rand()%8;
    for (int i=1; i<=n; i++)
        push(S,rand()%20-rand()%20);
}

///COADA
void initializeazaC(coada& C)
	{
		C.prim=NULL; C.ultim=NULL; C.nrElemente=0;
	}

bool esteVidaC(coada C)
{
    return C.nrElemente==0;
}

tip peek(coada C)
// ia informatia din primul nod al cozii, fara a-l elimina
{
    if (!esteVidaC(C))
        return C.prim->info;
}

tip dequeue(coada &C)
// scoate primul element din coada, din capul cozii
{
    if (!esteVidaC(C))
    {
        tip element=peek(C);
        nod* primul;
        primul=C.prim;
        C.prim=C.prim->urm;
        delete primul;
        C.nrElemente--;
        return element;
    }
}

void golesteC(coada &C)
{
    tip element;
    while (!esteVidaC(C)) element=dequeue(C);
}

void enqueue(coada &C, tip element)
// adauga un element la coada, dupa ultimul element (FIFO)
{
    nod * nod_nou;
    if (esteVidaC(C))
    {
        C.nrElemente=1;
        C.prim=new nod;
        C.prim->info=element;
        C.prim->urm=NULL;
        C.ultim=C.prim;
    }
    else
    {
        C.nrElemente++;
        nod_nou = new nod;
        nod_nou->info=element;
        nod_nou->urm=NULL;
        C.ultim->urm=nod_nou;
        C.ultim=nod_nou;
    }
}

void creareAleatoare_coada(coada &C)
{
    golesteC(C);
    int n=3+rand()%8;
    for (int i=1; i<=n; i++)
        enqueue(C,rand()%20-rand()%20);
}

///LISTE DUBLU-INLTANTUITE
bool esteVidaL(lista L)
{
    return L.nrElemente==0;
}

void initializeazaL(lista& L)
{
    L.stanga=new nod;
    L.dreapta= new nod;
    L.stanga->info=0;
    L.dreapta->info=0;
    L.stanga->urm=L.dreapta;
    L.stanga->prec=NULL;
    L.dreapta->prec=L.stanga;
    L.dreapta->urm=NULL;
    L.curent=NULL;
    L.prim=NULL;
    L.ultim=NULL;
    L.nrElemente=0;
}

tip scoatePrimul(lista &L)
{
    if (!esteVidaL(L))
    {
        L.nrElemente--;
        L.prim=L.prim->urm;
    }
}

tip scoateUltimul(lista &L)
{
    if(!esteVidaL(L))
    {
        L.nrElemente--;
        L.ultim->urm=NULL;
        L.ultim=L.ultim->prec;
        L.curent=L.ultim;
    }
}

void golesteL(lista &L)
{
    tip element;
    while (!esteVidaL(L)) element=scoatePrimul(L);
}

void adaugaInFata(lista &L, tip element)
{
    nod * nod_nou;
    nod_nou = new nod;
    nod_nou->info=element;
    if (L.nrElemente>0)
    {
        nod_nou->urm=L.prim;
        L.prim->prec=nod_nou;
        nod_nou->prec=L.stanga;
        L.stanga->urm=nod_nou;
        L.prim=nod_nou;
        L.curent=L.prim;
    }
    else
    {
        nod_nou->urm=L.dreapta;
        nod_nou->prec=L.stanga;
        L.stanga->urm=nod_nou;
        L.dreapta->prec=nod_nou;
        L.prim=nod_nou;
        L.ultim=L.prim; L.curent=L.prim;
    }
    L.nrElemente++;
}

void adaugaLaSpate(lista &L, tip element)
{
    nod * nod_nou;
    nod_nou = new nod;
    nod_nou->info=element;
    if (L.nrElemente>0)
    {
        nod_nou->prec=L.ultim;
        L.ultim->urm=nod_nou;
        nod_nou->urm=L.dreapta;
        L.dreapta->prec=nod_nou;
        L.ultim=nod_nou;
        L.curent=L.ultim;
    }
    else
    {
        nod_nou->urm=L.dreapta;
        nod_nou->prec=L.stanga;
        L.stanga->urm=nod_nou;
        L.dreapta->prec=nod_nou;
        L.prim=nod_nou;
        L.ultim=L.prim; L.curent=L.prim;
    }
    L.nrElemente++;
}

void adaugaDupaCurent(lista &L, tip element)
{
    nod * nod_nou;
    nod_nou = new nod;
    nod_nou->info=element;
    nod_nou->prec=L.curent;
    nod_nou->urm=L.curent->urm;
    L.curent->urm->prec=nod_nou;
    L.curent->urm=nod_nou;
    L.curent=nod_nou;
    L.nrElemente++;
}

tip scoateCurent(lista &L)
{
    if (L.curent == L.prim)
            scoatePrimul(L);
    else
        scoateUltimul(L);
}

void creareAleatoare_LDB(lista &L)
{
    golesteL(L);
    int n=3+rand()%8;
    for (int i=1; i<=n; i++)
        adaugaInFata(L,rand()%20-rand()%20);
}

///LISTE SIMPLE INLANUITE

void initializeazaLis_sim(lis_sim &X)
{
    X.prim=NULL;
    X.ultim=NULL;
}

void adauga(lis_sim &X, tip element, int poz)
{
    nod * nod_nou;
    nod_nou= new nod;
    nod_nou->info=element;          ///inserez elementul nou
    if (!poz || X.prim == NULL)
    {
        nod_nou->urm=X.prim;
        X.prim=nod_nou;
        if (X.ultim == NULL)
            X.ultim=nod_nou;
    }
    else
    {
        nod * nod_nou2;
        nod_nou2= new nod;
        nod_nou2=X.prim;
        int j=0;
        while(j<poz-1 && nod_nou2!= X.ultim)       ///parcurgere pana la k-1,   k-pozitia variabilei poz
        {
            nod_nou2=nod_nou2->urm;
            ++j;
        }
        nod_nou->urm=nod_nou2->urm;         ///se face conexiunea dintre elementul nou cu urmatorul si
        nod_nou2->urm=nod_nou;              ///conexiunea dintre nodul precedent cu cel nou
        if(nod_nou2 == X.ultim)
            X.ultim=nod_nou;
    }
}

int pop(lis_sim &X, int poz)
// scoate elementul de pe poz K
{
    if (X.prim!= NULL && X.ultim!=NULL)
    {
        if (poz == 0)
            X.prim=X.prim->urm;
        else
        {
            nod * nod_nou2;
            nod_nou2= new nod;
            nod_nou2=X.prim;
            int j=0;
            while(j<poz-1 && nod_nou2!= X.ultim)    ///parcurge pana la pozitia k-1,  k - pozitia variabilei poz
            {
                nod_nou2=nod_nou2->urm;
                ++j;
            }
            nod *test_nod=nod_nou2->urm;        ///leaga nodul de la pozitia k-1
            nod_nou2->urm=test_nod->urm;        ///la poztia k+1
        }
    }
}

void golesteX(lis_sim &X)
{
    while (X.prim !=NULL && X.ultim!=NULL)
        pop(X,0);
}

void creareAleatoare_X(lis_sim &X, int &nr_el)
{
    golesteX(X);
    nr_el=3+rand()%15;
    for (int i=1; i<=nr_el; i++)
        adauga(X,rand()%40-rand()%40,0);
}
