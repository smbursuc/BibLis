#include "desCoad.h"
#include <winbgim.h>
#include "UI.h"
#include <fstream>

using namespace std;

ofstream ff("dateCoada.txt");

double rez3;
bool animaC=false;
void desenare_coada(coada C,double rez3,int nrLimba, int anim)
{
    ///0=normal fara primul, 1=normal, 2=add
    int width=1280*rez3;  ///rez3
    int height=720*rez3;  ///rez3
    int start_x1=10*rez3;
    int start_y1=10*rez3;
    int latimeCasutaCoada=70*rez3;
    int coord_x1_casutaC=start_x1;
    int coord_y1_casutaC=start_y1;
    int coord_x2_casutaC=0;
    int coord_y2_casutaC=0;
    char buffer[20];
    int check=1;
    int time=0;
    nod * nod_nou = new nod;
    nod_nou=C.prim;

    while(nod_nou!=NULL)
    {
        if(anim==1)
        {
            time=0;
        }
        if(anim==0)
        {
            time=0;
        }
        if(anim==2)
        {
            if(nod_nou->urm==NULL)
            time=500;
        }
        if(check)
        {
            if(nrLimba==0)
                coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("prim")*rez3;
            else coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("first")*rez3;
            coord_y2_casutaC = coord_y1_casutaC + latimeCasutaCoada;
            if(nrLimba==0)
                outtextxy(coord_x1_casutaC+15*rez3,coord_y1_casutaC+25*rez3,"prim");
            else outtextxy(coord_x1_casutaC+15*rez3,coord_y1_casutaC+25*rez3,"first");
            delay(time);
            rectangle(coord_x1_casutaC,coord_y1_casutaC,coord_x2_casutaC,coord_y1_casutaC+latimeCasutaCoada);
            delay(time);
            line(coord_x2_casutaC,coord_y1_casutaC + 3*latimeCasutaCoada/4,coord_x2_casutaC + 30*rez3,coord_y1_casutaC + 3*latimeCasutaCoada/4);
            coord_x1_casutaC=coord_x2_casutaC + 30*rez3;
            check=0;
            continue;
        }

        if(coord_x1_casutaC+30*rez3+textwidth(itoa(nod_nou->info,buffer,10))*rez3>width)
        {
            coord_y1_casutaC=coord_y2_casutaC+70*rez3;
            coord_x1_casutaC=start_x1;
            delay(time);
            line(coord_x1_casutaC,coord_y1_casutaC,coord_x2_casutaC,coord_y2_casutaC);
        }

        coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth(itoa(nod_nou->info,buffer,10))*rez3;
        coord_y2_casutaC = coord_y1_casutaC + latimeCasutaCoada;
        delay(time);
        if(!(nod_nou==C.prim && anim==0))
        outtextxy(coord_x1_casutaC+15*rez3,coord_y1_casutaC+10*rez3,itoa(nod_nou->info,buffer,10));
        delay(time);
        if(!(nod_nou==C.prim && anim==0))
        rectangle(coord_x1_casutaC,coord_y1_casutaC,coord_x2_casutaC,coord_y2_casutaC); ///casuta

        if(coord_x2_casutaC + 80*rez3 < width )
            {
                delay(time);
                line(coord_x2_casutaC,coord_y1_casutaC + 3*latimeCasutaCoada/4,coord_x2_casutaC + 30*rez3,coord_y1_casutaC + 3*latimeCasutaCoada/4); ///linie conectoare
            }

        delay(time);
        if(!(nod_nou==C.prim && anim==0))
        line(coord_x1_casutaC,coord_y1_casutaC + latimeCasutaCoada/2,coord_x2_casutaC,coord_y1_casutaC + latimeCasutaCoada/2); ///linie mijloc

        delay(time);
        if(!(nod_nou==C.prim && anim==0))
        circle(coord_x1_casutaC+(coord_x2_casutaC-coord_x1_casutaC)/2,coord_y1_casutaC+3*latimeCasutaCoada/4,2*rez3); ///cerc

        coord_x1_casutaC=coord_x2_casutaC + 30*rez3;
        if (animaC)
        ff << nod_nou->info<<" ";
        nod_nou=nod_nou->urm;
    }
        if (animaC)
        ff <<'\n';
    if(check)
    {
        if(nrLimba==0)
            coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("prim")*rez3;
        else coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("first")*rez3;
        coord_y2_casutaC = coord_y1_casutaC + latimeCasutaCoada;
        if(nrLimba==0)
            outtextxy(coord_x1_casutaC+15*rez3,coord_y1_casutaC+25*rez3,"prim");
        else outtextxy(coord_x1_casutaC+15*rez3,coord_y1_casutaC+25*rez3,"first");
        delay(time);
        rectangle(coord_x1_casutaC,coord_y1_casutaC,coord_x2_casutaC,coord_y1_casutaC+latimeCasutaCoada);
        delay(time);
        line(coord_x2_casutaC,coord_y1_casutaC + 3*latimeCasutaCoada/4,coord_x2_casutaC + 30*rez3,coord_y1_casutaC + 3*latimeCasutaCoada/4);
        coord_x1_casutaC=coord_x2_casutaC + 30*rez3;
        check=0;
    }

    if(coord_x1_casutaC+30+textwidth("ultim")>width && nrLimba==0 || coord_x1_casutaC+30+textwidth("last")>width && nrLimba==1)
    {
        coord_y1_casutaC=coord_y2_casutaC+70*rez3;
        coord_x1_casutaC=start_x1;
        delay(time);
        line(coord_x1_casutaC,coord_y1_casutaC,coord_x2_casutaC,coord_y2_casutaC);
        if(nrLimba==0)
            coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("prim")*rez3;
        else coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("first")*rez3;
        coord_y2_casutaC = coord_y1_casutaC + latimeCasutaCoada;
    }
    if(nrLimba==0)
        coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("ultim")*rez3;
    else coord_x2_casutaC = coord_x1_casutaC + 30*rez3+textwidth("last")*rez3;
    coord_y2_casutaC = coord_y1_casutaC + latimeCasutaCoada;
    delay(time);
    rectangle(coord_x1_casutaC,coord_y1_casutaC,coord_x2_casutaC,coord_y2_casutaC); ///casuta
    if(nrLimba==0)
        {
            delay(time);
            outtextxy(coord_x1_casutaC+15*rez3,coord_y1_casutaC+25*rez3,"ultim");
        }
    else
    {
        delay(time);
        outtextxy(coord_x1_casutaC+15*rez3,coord_y1_casutaC+25*rez3,"last");
    }
}

void test_coada(int x, int y, coada &C,int nrRez,int nrLimba,int nrSound)
{
    char c;
    cleardevice();
    if(nrRez==2)
        rez3=1;
    else if(nrRez==1)
        rez3=0.75;
    else if(nrRez==3)
        rez3=1.5;
    if(rez3!=1)
    {
        closegraph();
        initwindow(1280*rez3,720*rez3);
    }
    bar(1*rez3,465*rez3,1280*rez3,468*rez3);///bara sus
    if(rez3==0.75)
        settextstyle(3,HORIZ_DIR,1);
    if(rez3==1)
        settextstyle(9,HORIZ_DIR,1);
    if(rez3==1.5)
        settextstyle(9,HORIZ_DIR,3);
    readimagefile("imag/backButton.jpg",15*rez3,665*rez3,65*rez3,710*rez3);     ///undo
    if(nrLimba==0)
    {
        outtextxy(76*rez3,473*rez3,"Functii:");
        outtextxy(86*rez3,503*rez3," inserare(x)");
        outtextxy(86*rez3,533*rez3," eliminare");
        outtextxy(86*rez3,563*rez3," golire");
        outtextxy(86*rez3,593*rez3," creareAleatorie");
        outtextxy(1040*rez3,473*rez3,"Istoric comenzi:");
        outtextxy(370*rez3,473*rez3,"Consola:");
        outtextxy(700*rez3,473*rez3,"Cod executat: ");
    }
    else
    {
        outtextxy(76*rez3,473*rez3,"Functions:");
        outtextxy(86*rez3,503*rez3," add(x)");
        outtextxy(86*rez3,533*rez3," remove");
        outtextxy(86*rez3,563*rez3," empty");
        outtextxy(86*rez3,593*rez3," randomCreate");
        outtextxy(1040*rez3,473*rez3,"Executed commands:");
        outtextxy(370*rez3,473*rez3,"Console:");
        outtextxy(700*rez3,473*rez3,"Executed code: ");
    }
    int numar=0;
    char buffer[20];
    int coord_y_istoric=501*rez3;
    int coord_y_consola=501*rez3;
    int int_c=0;
    stiva S;
    lista L;
    lis_sim X;
    while(true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(coord_y_istoric>=688*rez3)
        {
            coord_y_istoric=501*rez3;
            bar(950*rez3,500*rez3,1280*rez3,720*rez3);
        }

        if(x>=15*rez3 && x<=65*rez3 && y>=665*rez3&&y<=710*rez3)  ///undo
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            closegraph(CURRENT_WINDOW);
            initwindow(1280,720);
            meniu_selectare_lis(S,C,L,X, false,nrRez,nrLimba,nrSound);
        }

        if(coord_y_consola>=688*rez3)
        {
            coord_y_consola=501*rez3;
            bar(370*rez3,496*rez3,370*rez3+2*textwidth("Valoare: ")*rez3,705*rez3);
        }

        if(x>=93*rez3&&x<=200*rez3 && y>=511*rez3&&y<=518*rez3)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            int numar=0;
            int int_c=0;
            if(nrLimba==0)
                outtextxy(370*rez3,coord_y_consola,"Valoare:");
            else
                outtextxy(370*rez3,coord_y_consola,"Value:");
            while(true)
            {
                c=(char)getch();
                if(c==13)
                {
                    if(nrSound==1)
                        PlaySound(TEXT("soundFX/enter-key.wav"), NULL, SND_ASYNC);
                    break;
                }
                if(c>=48 && c<=57)
                {
                    int_c=c-'0';
                    numar=numar*10+int_c;
                    if(nrLimba==0)
                        outtextxy(370*rez3+textwidth("Valoare: "),coord_y_consola,itoa(numar,buffer,10));
                    else
                        outtextxy(370*rez3+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                }
                if (c == 8)   ///backspace
                {
                    numar=numar/10;
                    setfillstyle(SOLID_FILL, BLACK);
                    if(nrLimba==0)
                        {
                            bar(370*rez3+textwidth("Valoare: "),coord_y_consola,603*rez3,coord_y_consola+16*rez3);
                            outtextxy(370*rez3+textwidth("Valoare: "),coord_y_consola,itoa(numar,buffer,10));
                        }
                    else
                        {
                            bar(370*rez3+textwidth("Value: "),coord_y_consola,603*rez3,coord_y_consola+16*rez3);
                            outtextxy(370*rez3+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                        }
                }
            }
            if(nrLimba==0)
                outtextxy(1040*rez3,coord_y_istoric,"adaugare");
            else
                outtextxy(1040*rez3,coord_y_istoric,"add");
            outtextxy(1140*rez3,coord_y_istoric,itoa(numar,buffer,10));
            ff <<"Adaugare: "<<numar<<'\n';
            coord_y_istoric+=20*rez3;
            coord_y_consola+=20*rez3;
            int esteVid=0;
            if(C.prim==NULL)
                esteVid=1;
            enqueue(C,numar);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez3,3*rez3,1272*rez3,456*rez3);
            bar(695*rez3,500*rez3,950*rez3,720*rez3);
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez3,500*rez3,"C.nrElemente=1");
                    outtextxy(700*rez3,530*rez3,"C.prim=new nod");
                    outtextxy(700*rez3,560*rez3,"C.prim->info=element");
                    outtextxy(700*rez3,590*rez3,"C.prim->urm=NULL");
                    outtextxy(700*rez3,620*rez3,"C.ultim=C.prim");
                }
                else
                {
                    outtextxy(700*rez3,500*rez3,"C.nrElemente++");
                    outtextxy(700*rez3,530*rez3,"nod_nou=new nod");
                    outtextxy(700*rez3,560*rez3,"nod_nou->info=element");
                    outtextxy(700*rez3,590*rez3,"nou_nou->urm=NULL");
                    outtextxy(700*rez3,620*rez3,"C.ultim->urm=nod_nou");
                    outtextxy(700*rez3,650*rez3,"C.ultim=nod_nou");
                }
            }
            else
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez3,500*rez3,"Q.nrElements=1");
                    outtextxy(700*rez3,530*rez3,"Q.first=new node");
                    outtextxy(700*rez3,560*rez3,"Q.first->info=element");
                    outtextxy(700*rez3,590*rez3,"Q.first->next=NULL");
                    outtextxy(700*rez3,620*rez3,"Q.last=C.first");
                }
                else
                {
                    outtextxy(700*rez3,500*rez3,"Q.nrElements++");
                    outtextxy(700*rez3,530*rez3,"new_node=new node");
                    outtextxy(700*rez3,560*rez3,"new_node->info=element");
                    outtextxy(700*rez3,590*rez3,"new_node->next=NULL");
                    outtextxy(700*rez3,620*rez3,"Q.last->next=new_node");
                    outtextxy(700*rez3,650*rez3,"Q.last=new_node");
                }
            }
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenare_coada(C,rez3,nrLimba,2);
        }

        if(x>=93*rez3&&x<=189*rez3 && y>=540*rez3&&y<=549*rez3)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez3,coord_y_istoric,"eliminare");
            else outtextxy(1040*rez3,coord_y_istoric,"remove");
            ff <<"Eliminare"<<'\n';
            coord_y_istoric+=20*rez3;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez3,3*rez3,1272*rez3,456*rez3);
            bar(695*rez3,500*rez3,950*rez3,720*rez3);
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
            outtextxy(700*rez3,500*rez3,"nod* primul");
            outtextxy(700*rez3,530*rez3,"primul=C.prim");
            outtextxy(700*rez3,560*rez3,"C.prim=C.prim->urm");
            outtextxy(700*rez3,590*rez3,"delete primul");
            }
            else
            {
                outtextxy(700*rez3,500*rez3,"node* first");
                outtextxy(700*rez3,530*rez3,"first=Q.first");
                outtextxy(700*rez3,560*rez3,"Q.first=Q.first->next");
                outtextxy(700*rez3,590*rez3,"delete first");
            }
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenare_coada(C,rez3,nrLimba,0);
            delay(1000);
            bar(5*rez3,3*rez3,1272*rez3,456*rez3);
            dequeue(C);
            desenare_coada(C,rez3,nrLimba,1);
        }

        if(x>=91*rez3 &&x <=149*rez3 && y>=570*rez3 &&y<=576*rez3)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez3,coord_y_istoric,"golire");
            else outtextxy(1040*rez3,coord_y_istoric,"empty");
            ff <<"Golire"<<'\n';
            coord_y_istoric+=20*rez3;
            golesteC(C);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez3,3*rez3,1272*rez3,456*rez3);
            bar(695*rez3,500*rez3,950*rez3,720*rez3);
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                outtextxy(700*rez3,500*rez3,"int element");
                outtextxy(700*rez3,530*rez3,"while (!esteVidaC(C))");
                outtextxy(700*rez3,560*rez3,"element=remove(C)");
            }
            else
            {
                outtextxy(700*rez3,500*rez3,"int element");
                outtextxy(700*rez3,530*rez3,"while (!isEmpty(Q))");
                outtextxy(700*rez3,560*rez3,"element=remove(Q)");
            }
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenare_coada(C,rez3,nrLimba,3);
        }

        if(x>=94*rez3&&x<=249*rez3 && y>=600*rez3&&y<=607*rez3)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez3,coord_y_istoric,"creareAleatorie");
            else outtextxy(1040*rez3,coord_y_istoric,"randomCreate");
            ff <<"Creare Aleatorie"<<'\n';
            coord_y_istoric+=20*rez3;
            creareAleatoare_coada(C);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez3,3*rez3,1272*rez3,456*rez3);
            bar(695*rez3,500*rez3,950*rez3,720*rez3);
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
            outtextxy(700*rez3,500*rez3,"goleste(C))");
            outtextxy(700*rez3,530*rez3,"srand(time(NULL))");
            outtextxy(700*rez3,560*rez3,"int n=3+rand()%8");
            outtextxy(700*rez3,590*rez3,"for (int i=1; i<=n; i++)");
            outtextxy(700*rez3,620*rez3,"enqueue(C,rand()%20-rand()%20)");
            }
            else
            {
                outtextxy(700*rez3,500*rez3,"empty(Q)");
                outtextxy(700*rez3,530*rez3,"srand(time(NULL))");
                outtextxy(700*rez3,560*rez3,"int n=3+rand()%8");
                outtextxy(700*rez3,590*rez3,"for (int i=1; i<=n; i++)");
                outtextxy(700*rez3,620*rez3,"add(Q,rand()%20-rand()%20)");
            }
            if(rez3==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez3==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez3==1.5)
                settextstyle(9,HORIZ_DIR,3);
            animaC=true;
            desenare_coada(C,rez3,nrLimba,1);
            animaC=false;
        }
    }
}
