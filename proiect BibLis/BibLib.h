#ifndef _BIBLIB_H_
#define _BIBLIB_H_

#define tip int

///STIVA
struct nod {
    tip info;
    nod * urm;
    nod * prec;
};

struct stiva {
    nod* varf;
    int nrElemente;
};

///COADA
struct coada {
    nod* prim;
    nod* ultim;
    int nrElemente;
};

///LISTE DUBLU-INLTANTUITE
struct lista
{
    nod* stanga;
    nod* prim;
    nod* curent;
    nod* ultim;
    nod* dreapta;
    int nrElemente;
};

///LISTE SIMPLE INLANTUITE
struct lis_sim {
    nod* prim;
    nod* ultim;
};

///STIVA
bool esteVidaS(stiva S);

void initializeazaS(stiva& S);

tip pop(stiva &S);

void golesteS(stiva &S);

void push(stiva &S, tip element);

void creareAleatoare_stiva(stiva &S);

///COADA
bool esteVidaC(coada C);

void initializeazaC(coada& C);

tip peek(coada C);

tip dequeue(coada &C);

void golesteC(coada &C);

void enqueue(coada &C, tip element);

void creareAleatoare_coada(coada &C);

///LISTE DUBLU-INLTANTUITE
bool esteVidaL(lista L);

void initializeazaL(lista& L);

tip scoatePrimul(lista &L);

tip scoateUltimul(lista &L);

void golesteL(lista &L);

void adaugaInFata(lista &L, tip element);

void adaugaLaSpate(lista &L, tip element);

void adaugaDupaCurent(lista &L, tip element);

tip scoateCurent(lista &L);

void creareAleatoare_LDB(lista &L);

///LISTE SIMPLE INLANTUITE
void initializeazaLis_sim(lis_sim &X);

void adauga(lis_sim &X, int element, int poz);

tip pop(lis_sim &X, int poz);

void golesteX(lis_sim &X);

void creareAleatoare_X(lis_sim &X, int &nr_el);
#endif // _BIBLIB_H_
