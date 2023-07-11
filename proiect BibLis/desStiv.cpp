#include "desStiv.h"
#include <winbgim.h>
#include "UI.h"
#include <fstream>

using namespace std;

ofstream f("dateStiva.txt");

double rez;             ///rezolutia pe care o folosim

int coord_x1_elem=10;   ///coordonatele x1 a casutei unui elem
int coord_y1_elem=80;   ///coordonatele y1 a casutei unui elem
int coord_y2_elem=160;  ///coordonatele y2 a casutei unui elem
int coord_x2_elem=60;   ///coordonatele x1 a casutei unui elem

int coord_x1_cas_vf=10;  ///coordonatele x1 a casutei varfului
int coord_y1_cas_vf=10;  ///coordonatele y1 a casutei varfului
int coord_x2_cas_vf=125; ///coordonatele x2 a casutei varfului
int coord_y2_cas_vf=50;  ///coordonatele y2 a casutei varfului

char buff[25]; ///variabila ajutatoare la functia itoa

int testx=1;    ///variabila pentru a verifica daca am trecut de primul nod adaugat sau scos

bool animaS;
void desen_casuta_varf(double rez,int nrLimba, stiva S)     ///functie de desenare a chenarului S.varf
{
    if(!nrLimba)        ///verific daca in setari se foloseste limba romana sau engleza
    {
        rectangle(coord_x1_cas_vf,coord_y1_cas_vf,textwidth("S.varf     ")+textwidth(itoa(S.nrElemente,buff,10)),coord_y2_cas_vf);     ///cadranul varfului
        outtextxy(12,(coord_y2_cas_vf-coord_y1_cas_vf)/2,"S.varf");                     ///afisarea textului S.varf
        line(coord_x1_cas_vf+textwidth("S.varf "),coord_y1_cas_vf,coord_x1_cas_vf+textwidth("S.varf "),coord_y2_cas_vf);    ///linia ce desparte textul S.varf de numarul elementelor din stiva
        if (S.nrElemente < 10)                                                          ///conditie pentru incadrarea nr elementelor dupa 10 in casuta
        outtextxy(coord_x1_cas_vf+textwidth("S.varf")+14*rez,(coord_y2_cas_vf-coord_y1_cas_vf)/2,itoa(S.nrElemente,buff,10));
        else
            outtextxy(coord_x1_cas_vf+textwidth("S.varf ")+8*rez,(coord_y2_cas_vf-coord_y1_cas_vf)/2,itoa(S.nrElemente,buff,10));       /// afiseaza numarul elementelor de pe stiva
        line(coord_x1_cas_vf+textwidth("S.varf ")/2,coord_y2_cas_vf,coord_x1_cas_vf+textwidth("S.varf ")/2,coord_y2_cas_vf+30);     ///linia ce uneste casuta S.varf de urmatoarea casuta
    }
    else            ///se foloseste engleza
    {
        rectangle(coord_x1_cas_vf,coord_y1_cas_vf,textwidth("S.peak     ")+textwidth(itoa(S.nrElemente,buff,10)),coord_y2_cas_vf);     ///cadranul varfului
        outtextxy(12,(coord_y2_cas_vf-coord_y1_cas_vf)/2,"S.peak");                     ///afisarea textului S.varf
        line(coord_x1_cas_vf+textwidth("S.peak "),coord_y1_cas_vf,coord_x1_cas_vf+textwidth("S.peak "),coord_y2_cas_vf);    ///linia ce desparte textul S.varf de numarul elementelor din stiva
        if (S.nrElemente < 10)                                                          ///conditie pentru incadrarea nr elementelor dupa 10 in casuta
        outtextxy(coord_x1_cas_vf+textwidth("S.peak")+14*rez,(coord_y2_cas_vf-coord_y1_cas_vf)/2,itoa(S.nrElemente,buff,10));       ///afiseaza nr elementelor de pe stiva
        else
            outtextxy(coord_x1_cas_vf+textwidth("S.peak ")+8*rez,(coord_y2_cas_vf-coord_y1_cas_vf)/2,itoa(S.nrElemente,buff,10));
        line(coord_x1_cas_vf+textwidth("S.peak ")/2,coord_y2_cas_vf,coord_x1_cas_vf+textwidth("S.peak ")/2,coord_y2_cas_vf+30);     ///linia ce uneste casuta S.varf de urmatoarea casuta
    }
}
void desenare(int numar,double rez,int nrLimba, stiva S)        ///functie de desenare a chenarului unui element
{
    desen_casuta_varf(1,1,S);       ///apelarea functiei desen_cas_varf
    rectangle(coord_x1_elem,coord_y1_elem,coord_x2_elem+textwidth(itoa(numar,buff,10)),coord_y2_elem);  ///desenarea casutei nod
    line(coord_x1_elem,coord_y1_elem+(coord_y2_elem-coord_y1_elem)/2,coord_x2_elem+textwidth(itoa(numar,buff,10)),coord_y1_elem+(coord_y2_elem-coord_y1_elem)/2);   ///linia ce desparte elem nod, de cerc;
    outtextxy(coord_x1_elem+(coord_x2_elem-coord_x1_elem)/2,coord_y1_elem+((coord_y2_elem-coord_y1_elem)/2)/2-7,itoa(numar,buff,10));   ///afisarea elem nod
    circle(coord_x1_elem+(coord_x2_elem+textwidth(itoa(numar,buff,10))-coord_x1_elem)/2,coord_y1_elem+(coord_y2_elem-coord_y1_elem)/2+((coord_y2_elem-coord_y1_elem)/2)/2,4);   ///desenare cerc
}

void testS(stiva S,double rez,int nrLimba)
{
    nod * nod_nou=S.varf;       ///se incepe parcurgerea
    if (nod_nou == NULL)
    {
        desen_casuta_varf(rez,nrLimba,S);
        return;
    }
    coord_x1_elem=10;       ///reactualizare coordonatele x1 a casutei unui elem
    coord_y1_elem=80;       ///reactualizare coordonatele y1 a casutei unui elem
    coord_y2_elem=150;      ///reactualizare coordonatele y2 a casutei unui elem
    coord_x2_elem=60;       ///reactualizare coordonatele x2 a casutei unui elem
    int sens=1; ///sens - 1 cand merge de sus in jos, sens - 2 cand merge de jos in sus, pentru efect de spirala
    testx=1;
    while(nod_nou != NULL)
    {
        if(sens == 1)
        {
            if(testx!=1)    ///desenez la sfarsit ultima casuta adaugata
            desenare(nod_nou->info,rez,nrLimba,S);
            desen_casuta_varf(1,1,S);           ///desenez varful
            if (coord_y2_elem+70*rez < 468*rez)     ///daca depaseste linia de jos,incepe parcurgerea in spirala
            {
                nod *nod_nou2=new nod;  ///creerea unei copi a urmatorului nod pentru a determina mijlocul lungimei elementului
                nod_nou2=nod_nou;
                nod_nou2=nod_nou2->urm;
                if(nod_nou2!=NULL)
                line(coord_x1_elem+(coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10))-coord_x1_elem)/2,coord_y2_elem,coord_x1_elem+(coord_x2_elem+textwidth(itoa(nod_nou2->info,buff,10))-coord_x1_elem)/2,coord_y2_elem+30);   ///linia ce leaga casuta nod de urmatoarea casuta
                coord_y1_elem=coord_y2_elem+30;     ///reactualizare coord y1
                coord_y2_elem=coord_y1_elem+70;     ///reactualizare coord y2
            }
            else        ///daca depaseste linia de jos, continua alta spirala
                {
                    sens=2;
                    line(coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10)),coord_y1_elem+(coord_y2_elem-coord_y1_elem)/2+((coord_y2_elem-coord_y1_elem)/2)/2,coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10))+70,coord_y1_elem+(coord_y2_elem-coord_y1_elem)/2+((coord_y2_elem-coord_y1_elem)/2)/2);
                    coord_x1_elem=coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10))+70;     ///reactualizare coord x1
                    coord_x2_elem=coord_x1_elem+50;     ///reactualizare coord x2
                }
        }
        else if (sens == 2)
        {
            desenare(nod_nou->info,rez,nrLimba,S);
            if(coord_y1_elem != coord_y2_cas_vf+30)
            {
                nod *nod_nou2=new nod;  ///creerea unei copi a urmatorului nod pentru a determina mijlocul lungimei elementului
                nod_nou2=nod_nou;
                nod_nou2=nod_nou2->urm;
                if(nod_nou2!=NULL)
                line(coord_x1_elem+(coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10))-coord_x1_elem)/2,coord_y1_elem,coord_x1_elem+(coord_x2_elem+textwidth(itoa(nod_nou2->info,buff,10))-coord_x1_elem)/2,coord_y1_elem-30);
                coord_y2_elem=coord_y1_elem-30;     ///reactualizare coord y2
                coord_y1_elem=coord_y2_elem-70;     ///reactualizare coord y1
            }
            else if(coord_y1_elem == coord_y2_cas_vf+30)
            {
                sens=1;
                line(coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10)),coord_y1_elem+(coord_y2_elem-coord_y1_elem)/2+((coord_y2_elem-coord_y1_elem)/2)/2,coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10))+70,coord_y1_elem+(coord_y2_elem-coord_y1_elem)/2+((coord_y2_elem-coord_y1_elem)/2)/2);
                coord_x1_elem=coord_x2_elem+textwidth(itoa(nod_nou->info,buff,10))+70;     ///reactualizare coord x1
                coord_x2_elem=coord_x1_elem+50;     ///reactualizare coord x2
            }
        }
        if (animaS)
            f << nod_nou->info <<" ";
        nod_nou=nod_nou->urm;           ///trecerea urmatorului nod
        ++testx;
    }
    if (animaS)
        f <<'\n';
    nod_nou=S.varf;                                 ///ma duc la adresa primului nod neafisat
    delay(500);        ///delay pentru efect de animatie
    rectangle(10,80,60+textwidth(itoa(nod_nou->info,buff,10)),150);  ///desenarea casutei nod
    delay(500);        ///delay pentru efect de animatie
    line(10,80+(150-80)/2,60+textwidth(itoa(nod_nou->info,buff,10)),80+(150-80)/2);   ///linia ce desparte elem nod, de cerc
    delay(500);        ///delay pentru efect de animatie
    outtextxy(10+(60-10)/2,80+((150-80)/2)/2-7,itoa(nod_nou->info,buff,10));   ///afisarea elem nod
    delay(500);        ///delay pentru efect de animatie
    circle(10+(60+textwidth(itoa(nod_nou->info,buff,10))-10)/2,80+(150-80)/2+((150-80)/2)/2,4);   ///desenare cerc
}

void test_stiva(int x, int y, stiva &S,int nrRez, int nrLimba, int nrSound)
{
    char c;
    cleardevice();
    if(nrRez==2)
        rez=1;
    else if(nrRez==1)
        rez=0.75;
    else if(nrRez==3)
        rez=1.5;
    if(rez!=1)
    {
        closegraph();
        initwindow(1280*rez,720*rez);
    }
    if(nrRez==3)
        settextstyle(9,HORIZ_DIR,3);
    if(nrRez==2)
        settextstyle(9,HORIZ_DIR,1);
    if(nrRez==1)
        settextstyle(3,HORIZ_DIR,1);
    bar(1*rez,465*rez,1280*rez,468*rez);///bara sus
    readimagefile("imag/backButton.jpg",15*rez,665*rez,65*rez,710*rez);     ///undo
    if(nrLimba==0)
    {
        outtextxy(76*rez,473*rez,"Functii:");
        outtextxy(86*rez,503*rez," push(x)");
        outtextxy(86*rez,533*rez," pop");
        outtextxy(86*rez,563*rez," golire");
        outtextxy(86*rez,593*rez," creareAleatorie");
        outtextxy(1040*rez,473*rez,"Istoric comenzi:");
        outtextxy(370*rez,473*rez,"Consola:");
        outtextxy(700*rez,473*rez,"Cod executat: ");
    }
    else
    {
        outtextxy(76*rez,473*rez,"Functions:");
        outtextxy(86*rez,503*rez," push(x)");
        outtextxy(86*rez,533*rez," pop");
        outtextxy(86*rez,563*rez," empty");
        outtextxy(86*rez,593*rez," randomCreate");
        outtextxy(1040*rez,473*rez,"Executed commands:");
        outtextxy(370*rez,473*rez,"Console:");
        outtextxy(700*rez,473*rez,"Executed code: ");
    }
    int numar=0;
    char buffer[20];
    int coord_y_istoric=501*rez;
    int coord_y_consola=501*rez;
    int coord_y_codExecutat=501*rez;
    int int_c=0;
    int x1=7*rez,y1=71*rez,x2=106*rez,y2=111*rez;
    lista L;
    coada C;
    lis_sim X;
    while(true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(coord_y_istoric>=688*rez)    ///reset istoric
        {
            coord_y_istoric=501;
            setfillstyle(SOLID_FILL, BLACK);
            bar(950*rez,500*rez,1280*rez,720*rez);
        }

        if(x>=15*rez && x<=65*rez && y>=665*rez&&y<=710*rez)  ///undo
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            closegraph(CURRENT_WINDOW);
            initwindow(1280,720);
            meniu_selectare_lis(S,C,L,X, false,nrRez,nrLimba,nrSound);
        }

        if(coord_y_consola>=688*rez)    ///reset consola
        {
            coord_y_consola=501*rez;
            setfillstyle(SOLID_FILL, BLACK);
            bar(370*rez,496*rez,370*rez+2*textwidth("Valoare: ")*rez,705*rez);
        }

        if(x>=93*rez&&x<=157*rez && y>=511*rez&&y<=518*rez)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            int numar=0;
            int int_c=0;
            if(nrLimba==0)
                outtextxy(370*rez,coord_y_consola,"Valoare:");
            else
                outtextxy(370*rez,coord_y_consola,"Value:");
            while(true)
            {
                c=(char)getch();
                if(c==13)   ///enter
                {
                    if(nrSound==1)
                        PlaySound(TEXT("soundFX/enter-key.wav"), NULL, SND_ASYNC);
                    break;
                }
                if(c>=48 && c<=57)    ///0-9
                {
                    int_c=c-'0';
                    numar=numar*10+int_c;
                    if(nrLimba==0)
                        outtextxy(370*rez+textwidth("Valoare: "),coord_y_consola,itoa(numar,buffer,10));
                    else
                        outtextxy(370*rez+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                }
                if (c == 8)   ///backspace
                {
                    numar=numar/10;
                    setfillstyle(SOLID_FILL, BLACK);
                    if(nrLimba==0)
                        {
                            bar(370*rez+textwidth("Valoare: "),coord_y_consola,603*rez,coord_y_consola+16*rez);
                            outtextxy(370*rez+textwidth("Valoare: "),coord_y_consola,itoa(numar,buffer,10));
                        }
                    else
                        {
                            bar(370*rez+textwidth("Value: "),coord_y_consola,603*rez,coord_y_consola+16*rez);
                            outtextxy(370*rez+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                        }
                }
            }
            int esteVid=0;
            if(S.varf==NULL)
                esteVid=1;
            push(S,numar);
            outtextxy(1040*rez,coord_y_istoric,"push");  ///istoric
            outtextxy(1100*rez,coord_y_istoric,itoa(numar,buffer,10));
            f << "Push "<<numar <<'\n';
            coord_y_istoric+=20*rez;
            coord_y_consola+=20*rez;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez,3*rez,1272*rez,456*rez);
            bar(695*rez,500*rez,950*rez,720*rez);
            if(rez==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez,500*rez,"S.nrElemente=1");
                    outtextxy(700*rez,530*rez,"S.varf=new nod");
                    outtextxy(700*rez,560*rez,"S.varf->info=element");
                    outtextxy(700*rez,590*rez,"S.varf->urm=NULL");
                }
                else
                {
                    outtextxy(700*rez,500*rez,"S.nrElemente++");
                    outtextxy(700*rez,530*rez,"nod_nou = new nod");
                    outtextxy(700*rez,560*rez,"nod_nou->info=element");
                    outtextxy(700*rez,590*rez,"nod_nou->urm=S.varf");
                    outtextxy(700*rez,620*rez,"S.varf=nod_nou");
                }
            }
            else
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez,500*rez,"S.nrElements=1");
                    outtextxy(700*rez,530*rez,"S.top=new node");
                    outtextxy(700*rez,560*rez,"S.top->info=element");
                    outtextxy(700*rez,590*rez,"S.top->next=NULL");
                }
                else
                {
                    outtextxy(700*rez,500*rez,"S.nrElements++");
                    outtextxy(700*rez,530*rez,"new_node = new node");
                    outtextxy(700*rez,560*rez,"new_node->info=element");
                    outtextxy(700*rez,590*rez,"new_node->next=S.top");
                    outtextxy(700*rez,620*rez,"S.top=new_node");
                }
            }
            if(nrRez==3)
                settextstyle(9,HORIZ_DIR,3);
            if(nrRez==2)
                settextstyle(9,HORIZ_DIR,1);
            if(nrRez==1)
                settextstyle(3,HORIZ_DIR,1);
            testS(S,rez,nrLimba);
        }

        if(x>=93*rez&&x<=129*rez && y>=540*rez&&y<=549*rez)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            outtextxy(1040*rez,coord_y_istoric,"pop");
            f << "Pop "<<'\n';
            pop(S);
            coord_y_istoric+=20*rez;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez,3*rez,1272*rez,456*rez);
            bar(695*rez,500*rez,950*rez,720*rez);
            if(rez==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
            outtextxy(700*rez,500*rez,"int element; nod* varf_nou");
            outtextxy(700*rez,530*rez,"element=S.varf->info");
            outtextxy(700*rez,560*rez,"varf_nou=S.varf->urm");
            outtextxy(700*rez,590*rez,"delete S.varf");
            outtextxy(700*rez,620*rez,"S.varf=varf_nou");
            outtextxy(700*rez,650*rez,"S.nrElemente=S.nrElemente-1");
            outtextxy(700*rez,680*rez,"return element");
            }
            else
            {
                outtextxy(700*rez,500*rez,"int element; node* new_top");
                outtextxy(700*rez,530*rez,"element=S.top->info");
                outtextxy(700*rez,560*rez,"new_top=S.top->next");
                outtextxy(700*rez,590*rez,"delete S.top");
                outtextxy(700*rez,620*rez,"S.top=new_top");
                outtextxy(700*rez,650*rez,"S.nrElements=S.nrElements-1");
                outtextxy(700*rez,680*rez,"return element");
            }
            if(nrRez==3)
                settextstyle(9,HORIZ_DIR,3);
            if(nrRez==2)
                settextstyle(9,HORIZ_DIR,1);
            if(nrRez==1)
                settextstyle(3,HORIZ_DIR,1);
            testS(S,rez,nrLimba);
        }

        if(x>=91*rez&&x<=149*rez && y>=570*rez&&y<=576*rez)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez,coord_y_istoric,"golire");
            else outtextxy(1040*rez,coord_y_istoric,"empty");
            f << "Golire "<<'\n';
            golesteS(S);
            coord_y_istoric+=20*rez;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez,3*rez,1272*rez,456*rez);
            bar(695*rez,500*rez,950*rez,720*rez);
            if(rez==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
            outtextxy(700*rez,500*rez,"int element");
            outtextxy(700*rez,530*rez,"while(!esteVida(S)");
            outtextxy(700*rez,560*rez,"element=pop(S)");
            }
            else
            {
                outtextxy(700*rez,500*rez,"int element");
                outtextxy(700*rez,530*rez,"while(!isEmpty(S)");
                outtextxy(700*rez,560*rez,"element=pop(S)");
            }
            if(nrRez==3)
                settextstyle(9,HORIZ_DIR,3);
            if(nrRez==2)
                settextstyle(9,HORIZ_DIR,1);
            if(nrRez==1)
                settextstyle(3,HORIZ_DIR,1);
            testS(S,rez,nrLimba);
        }

        if(x>=94*rez&&x<=249*rez && y>=600*rez&&y<=607*rez)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez,coord_y_istoric,"creareAleatorie");
            else outtextxy(1040*rez,coord_y_istoric,"randomCreate");
            coord_y_istoric+=20*rez;
            f << "CreareAleatoare" <<'\n';
            creareAleatoare_stiva(S);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez,3*rez,1272*rez,456*rez);
            bar(695*rez,500*rez,950*rez,720*rez);
            if(rez==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
            outtextxy(700*rez,500*rez,"goleste(S))");
            outtextxy(700*rez,530*rez,"srand(time(NULL))");
            outtextxy(700*rez,560*rez,"int n=3+rand()%8");
            outtextxy(700*rez,590*rez,"for (int i=1; i<=n; i++)");
            outtextxy(700*rez,620*rez,"push(S,rand()%20-rand()%20)");
            }
            else
            {
                outtextxy(700*rez,500*rez,"empty(S))");
                outtextxy(700*rez,530*rez,"srand(time(NULL))");
                outtextxy(700*rez,560*rez,"int n=3+rand()%8");
                outtextxy(700*rez,590*rez,"for (int i=1; i<=n; i++)");
                outtextxy(700*rez,620*rez,"push(S,rand()%20-rand()%20)");
            }
            if(nrRez==3)
                settextstyle(9,HORIZ_DIR,3);
            if(nrRez==2)
                settextstyle(9,HORIZ_DIR,1);
            if(nrRez==1)
                settextstyle(3,HORIZ_DIR,1);
            animaS=true;
            testS(S,rez,nrLimba);
            animaS=false;
        }
    }
}
