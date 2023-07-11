#include <winbgim.h>
#include "UI.h"
#include <fstream>

using namespace std;

ofstream gg("dateLisSim.txt");

double rez4;
int test_poz_animata,test_poz;
int poz_x1_anim;
int poz_y1_anim;
int poz_x2_anim;
int poz_y2_anim;
int creare_rand;
int elim_test_x;
bool animaLis;
void desenare_lis_sim(lis_sim X,double rez4,int nrLimba)
{
    int width=1280*rez4;  ///rez
    int height=720*rez4;  ///rez
    int start_x1=10*rez4;
    int start_y1=10*rez4;
    int latimeCasutaX=70*rez4;
    int coord_x1_casutaX=start_x1;
    int coord_y1_casutaX=start_y1;
    int coord_x2_casutaX=0;
    int coord_y2_casutaX=0;
    char buffer[20];
    int check=1;
    nod * nod_nou = new nod;
    nod_nou=X.prim;
    test_poz_animata=1;
    while(nod_nou!=NULL)
    {
        if(check)
        {
            if(nrLimba==0)
                coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("prim")*rez4;
            else coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("first")*rez4;
            coord_y2_casutaX = coord_y1_casutaX + latimeCasutaX;
            if(nrLimba==0)
                outtextxy(coord_x1_casutaX+15*rez4,coord_y1_casutaX+25*rez4,"prim");
            else outtextxy(coord_x1_casutaX+15*rez4,coord_y1_casutaX+25*rez4,"first");
            rectangle(coord_x1_casutaX,coord_y1_casutaX,coord_x2_casutaX,coord_y1_casutaX+latimeCasutaX);
            line(coord_x2_casutaX,coord_y1_casutaX + 3*latimeCasutaX/4,coord_x2_casutaX + 30*rez4,coord_y1_casutaX + 3*latimeCasutaX/4);
            coord_x1_casutaX=coord_x2_casutaX + 30*rez4;
            check=0;
            continue;
        }

        if(coord_x1_casutaX+30*rez4+textwidth(itoa(nod_nou->info,buffer,10))*rez4>width)
            {
                coord_y1_casutaX=coord_y2_casutaX+70*rez4;
                coord_x1_casutaX=start_x1;
                line(coord_x1_casutaX,coord_y1_casutaX,coord_x2_casutaX,coord_y2_casutaX);
            }

        coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth(itoa(nod_nou->info,buffer,10));
        coord_y2_casutaX = coord_y1_casutaX + latimeCasutaX;

        if(test_poz_animata != test_poz+1 || creare_rand)
        {
            outtextxy(coord_x1_casutaX+15*rez4,coord_y1_casutaX+10*rez4,itoa(nod_nou->info,buffer,10));

            rectangle(coord_x1_casutaX,coord_y1_casutaX,coord_x2_casutaX,coord_y2_casutaX); ///casuta

            if(coord_x2_casutaX + 80*rez4 < width )
                line(coord_x2_casutaX,coord_y1_casutaX + 3*latimeCasutaX/4,coord_x2_casutaX + 30*rez4,coord_y1_casutaX + 3*latimeCasutaX/4); ///linie conectoare

            line(coord_x1_casutaX,coord_y1_casutaX + latimeCasutaX/2,coord_x2_casutaX,coord_y1_casutaX + latimeCasutaX/2); ///linie mijloc

            circle(coord_x1_casutaX+(coord_x2_casutaX-coord_x1_casutaX)/2,coord_y1_casutaX+3*latimeCasutaX/4,2*rez4); ///cerc
        }
        else if (test_poz_animata == test_poz+1)
        {
            elim_test_x=nod_nou->info;
            poz_x1_anim=coord_x1_casutaX;
            poz_y1_anim=coord_y1_casutaX;
            poz_x2_anim=coord_x2_casutaX;
            poz_y2_anim=coord_y2_casutaX;
        }

        coord_x1_casutaX=coord_x2_casutaX + 30*rez4;
        if (animaLis)
            gg<<nod_nou->info<<" ";
        nod_nou=nod_nou->urm;
        ++test_poz_animata;
    }
        if (animaLis)
            gg <<'\n';
    if(check)
        {
            if(nrLimba==0)
                coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("prim")*rez4;
            else coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("first")*rez4;
            coord_y2_casutaX = coord_y1_casutaX + latimeCasutaX;
            if(nrLimba==0)
                outtextxy(coord_x1_casutaX+15*rez4,coord_y1_casutaX+25*rez4,"prim");
            else outtextxy(coord_x1_casutaX+15*rez4,coord_y1_casutaX+25*rez4,"first");
            rectangle(coord_x1_casutaX,coord_y1_casutaX,coord_x2_casutaX,coord_y1_casutaX+latimeCasutaX);
            line(coord_x2_casutaX,coord_y1_casutaX + 3*latimeCasutaX/4,coord_x2_casutaX + 30*rez4,coord_y1_casutaX + 3*latimeCasutaX/4);
            coord_x1_casutaX=coord_x2_casutaX + 30*rez4;
            check=0;
        }

    if(coord_x1_casutaX+30*rez4+textwidth("ultim")*rez4>width && nrLimba==0 || coord_x1_casutaX+30*rez4+textwidth("last")*rez4>width && nrLimba==1)
    {
                coord_y1_casutaX=coord_y2_casutaX+70*rez4;
                coord_x1_casutaX=start_x1;
                line(coord_x1_casutaX,coord_y1_casutaX,coord_x2_casutaX,coord_y2_casutaX);
                if(nrLimba==0)
                    coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("prim")*rez4;
                else coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("first")*rez4;
                coord_y2_casutaX = coord_y1_casutaX + latimeCasutaX;
    }
    if(nrLimba==0)
        coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("ultim")*rez4;
    else coord_x2_casutaX = coord_x1_casutaX + 30*rez4+textwidth("last")*rez4;
    coord_y2_casutaX = coord_y1_casutaX + latimeCasutaX;
    rectangle(coord_x1_casutaX,coord_y1_casutaX,coord_x2_casutaX,coord_y2_casutaX); ///casuta
    if(nrLimba==0)
        outtextxy(coord_x1_casutaX+15*rez4,coord_y1_casutaX+25*rez4,"ultim");
    else outtextxy(coord_x1_casutaX+15*rez4,coord_y1_casutaX+25*rez4,"last");
}

void test_lis_sim(int x, int y, lis_sim &X,int nrRez,int nrLimba,int nrSound)
{
    char c;
    cleardevice();
    if(nrRez==2)
        rez4=1;
    else if(nrRez==1)
        rez4=0.75;
    else if(nrRez==3)
        rez4=1.5;
    if(rez4!=1)
    {
        closegraph();
        initwindow(1280*rez4,720*rez4);
    }
    bar(1*rez4,465*rez4,1280*rez4,468*rez4);///bara sus
    if(rez4==0.75)
        settextstyle(3,HORIZ_DIR,1);
    if(rez4==1)
        settextstyle(9,HORIZ_DIR,1);
    if(rez4==1.5)
        settextstyle(9,HORIZ_DIR,3);
    readimagefile("imag/backButton.jpg",15*rez4,665*rez4,65*rez4,710*rez4);     ///undo
    if(nrLimba==0)
    {
        outtextxy(76*rez4,473*rez4,"Functii:");
        outtextxy(86*rez4,503*rez4," inserare(x,poz)");
        outtextxy(86*rez4,533*rez4," eliminare(poz)");
        outtextxy(86*rez4,563*rez4," golire");
        outtextxy(86*rez4,593*rez4," creareAleatorie");
        settextstyle(3,HORIZ_DIR,1);
        outtextxy(86*rez4,623*rez4, "Indexarea incepe de la 0");
        if(rez4==0.75)
            settextstyle(3,HORIZ_DIR,1);
        if(rez4==1)
            settextstyle(9,HORIZ_DIR,1);
        if(rez4==1.5)
            settextstyle(9,HORIZ_DIR,3);
        outtextxy(1040*rez4,473*rez4,"Istoric comenzi:");
        outtextxy(370*rez4,473*rez4,"Consola:");
        outtextxy(700*rez4,473*rez4,"Cod executat: ");
    }
    else
    {
        outtextxy(76*rez4,473*rez4,"Functions:");
        outtextxy(86*rez4,503*rez4," add(x,pos)");
        outtextxy(86*rez4,533*rez4," remove(pos)");
        outtextxy(86*rez4,563*rez4," empty");
        outtextxy(86*rez4,593*rez4," randomCreate");
        settextstyle(3,HORIZ_DIR,1);
        outtextxy(86*rez4,623*rez4, "Indexing starts from 0");
        if(rez4==0.75)
            settextstyle(3,HORIZ_DIR,1);
        if(rez4==1)
            settextstyle(9,HORIZ_DIR,1);
        if(rez4==1.5)
            settextstyle(9,HORIZ_DIR,3);
        outtextxy(1040*rez4,473*rez4,"Executed commands:");
        outtextxy(370*rez4,473*rez4,"Console:");
        outtextxy(700*rez4,473*rez4,"Executed code: ");
    }
    int numar=0;
    char buffer[20];
    int coord_y_istoric=501*rez4;
    int coord_y_consola=501*rez4;
    int int_c=0;
    stiva S;
    lista L;
    coada C;
    int nr_el=0;
    while(true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN)){}

        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(coord_y_istoric>=688*rez4)
        {
            coord_y_istoric=501*rez4;
            bar(1000*rez4,500*rez4,1280*rez4,720*rez4);
        }

        if(x>=15*rez4 && x<=65*rez4 && y>=665*rez4&&y<=710*rez4)  ///undo
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            closegraph(CURRENT_WINDOW);
            initwindow(1280,720);
            meniu_selectare_lis(S,C,L,X, false,nrRez,nrLimba,nrSound);
        }

        if(coord_y_consola>=688*rez4)
        {
            coord_y_consola=501*rez4;
            bar(370*rez4,496*rez4,370*rez4+2*textwidth("Valoare: ")*rez4,705*rez4);
        }

        if(x>=93*rez4&&x<=200*rez4 && y>=511*rez4&&y<=518*rez4)
        {
            bar(478*rez4,473*rez4,643*rez4,494*rez4);
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            int numar=0;
            int int_c=0;
            if(nrLimba==0)
                outtextxy(370*rez4,coord_y_consola,"Valoare:");
            else outtextxy(370*rez4,coord_y_consola,"Value:");
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
                        outtextxy(370*rez4+textwidth("Valoare:  "),coord_y_consola,itoa(numar,buffer,10));
                    else
                        outtextxy(370*rez4+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                }
                if (c == 8)   ///backspace
                {
                    numar=numar/10;
                    setfillstyle(SOLID_FILL, BLACK);
                    if(nrLimba==0)
                        {
                            bar(370*rez4+textwidth("Valoare:  "),coord_y_consola,603*rez4,coord_y_consola+16*rez4);
                            outtextxy(370*rez4+textwidth("Valoare:  "),coord_y_consola,itoa(numar,buffer,10));
                        }
                    else
                        {
                            bar(370*rez4+textwidth("Value: "),coord_y_consola,603*rez4,coord_y_consola+16*rez4);
                            outtextxy(370*rez4+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                        }
                }
            }
            coord_y_consola+=20*rez4;
            if(nrLimba==0)
                outtextxy(370*rez4,coord_y_consola,"Pozitie:");
            else outtextxy(370*rez4,coord_y_consola,"Position:");
            int pozitie=0;
            while(true)
            {
                c=(char)getch();
                if(c==13)
                {
                    if((pozitie!=0 && X.prim==NULL && X.ultim==NULL) || (pozitie > nr_el) )
                        {
                            settextstyle(3,HORIZ_DIR,1);
                            setfillstyle(SOLID_FILL,BLACK);
                            if(nrLimba==0)
                                {
                                    bar(478*rez4,473*rez4,643*rez4,494*rez4);
                                    delay(100);
                                    outtextxy(370*rez4+textwidth("Consola ")+50*rez4,473*rez4,"Pozitia incorecta");
                                }
                            else
                            {
                                bar(478*rez4,473*rez4,643*rez4,494*rez4);
                                delay(100);
                                outtextxy(370*rez4+textwidth("Console ")+50*rez4,473*rez4,"Incorrect position");
                            }
                            if(rez4==0.75)
                                settextstyle(3,HORIZ_DIR,1);
                            if(rez4==1)
                                settextstyle(9,HORIZ_DIR,1);
                            if(rez4==1.5)
                                settextstyle(9,HORIZ_DIR,3);
                        }
                    else
                    {
                        if(nrSound==1)
                            PlaySound(TEXT("soundFX/enter-key.wav"), NULL, SND_ASYNC);
                        setfillstyle(SOLID_FILL,BLACK);
                        delay(100);
                        bar(478*rez4,473*rez4,643*rez4,494*rez4);
                        break;
                    }
                }
                if(c>=48 && c<=57)
                {
                    int_c=c-'0';
                    pozitie=pozitie*10+int_c;
                    if(nrLimba==0)
                        outtextxy(370*rez4+textwidth("Pozitie: "),coord_y_consola,itoa(pozitie,buffer,10));
                    else
                        outtextxy(370*rez4+textwidth("Position: "),coord_y_consola,itoa(pozitie,buffer,10));
                }
                if (c == 8)   ///backspace
                {
                    pozitie=pozitie/10;
                    setfillstyle(SOLID_FILL, BLACK);
                    if(nrLimba==0)
                        {
                            bar(370*rez4+textwidth("Pozitie: "),coord_y_consola,603*rez4,coord_y_consola+16*rez4);
                            outtextxy(370*rez4+textwidth("Pozitie: "),coord_y_consola,itoa(pozitie,buffer,10));
                        }
                    else
                        {
                            bar(370*rez4+textwidth("Position: "),coord_y_consola,603*rez4,coord_y_consola+16*rez4);
                            outtextxy(370*rez4+textwidth("Position: "),coord_y_consola,itoa(pozitie,buffer,10));
                        }
                }
            }
            if(nrLimba==0)
                outtextxy(1040*rez4,coord_y_istoric,"adaugare");
            else outtextxy(1040*rez4,coord_y_istoric,"add");
            gg <<"Adaugare: "<<numar<<" pe pozitia: "<<pozitie<<'\n';
            outtextxy(1140*rez4,coord_y_istoric,itoa(numar,buffer,10));
            coord_y_istoric+=20*rez4;
            coord_y_consola+=20*rez4;
            adauga(X,numar,pozitie);
            ++nr_el;
            test_poz=pozitie;   ///copie dupa variabila pozitie
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez4,3*rez4,1280*rez4,456*rez4);
            bar(695*rez4,500*rez4,1040*rez4,720*rez4);
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(3,HORIZ_DIR,3);
            int esteVid=0;
            if(X.prim==NULL)
                esteVid=1;
            if(nrLimba==0)
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez4,500*rez4,"nod_nou=new nod; nod_nou->info=element");
                    outtextxy(700*rez4,530*rez4,"if(!poz || LS.prim == NULL");
                    outtextxy(700*rez4,560*rez4,"nod_nou->urm=LS.prim; LS.prim=nod_nou");
                    outtextxy(700*rez4,590*rez4,"if (LS.ultim == NULL)");
                    outtextxy(700*rez4,620*rez4,"LS.ultim=nod_nou");
                }
                else
                {
                    outtextxy(700*rez4,500*rez4,"nod* nod_nou2; nod_nou2=new nod");
                    outtextxy(700*rez4,530*rez4,"nod_nou2=LS.prim; int j=0");
                    outtextxy(700*rez4,560*rez4,"while(j<poz-1 && nod_nou2!= LS.ultim)");
                    outtextxy(700*rez4,590*rez4,"   nod_nou2=nod_nou2->urm; ++j");
                    outtextxy(700*rez4,620*rez4,"nod_nou->urm=nod_nou2->urm");
                    outtextxy(700*rez4,650*rez4,"nod_nou2->urm=nod_nou");
                    outtextxy(700*rez4,680*rez4,"if(nod_nou2 == LS.ultim) X.ultim=nod_nou");
                }
            }
            else
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez4,500*rez4,"new_node=new node; new_node->info=element");
                    outtextxy(700*rez4,530*rez4,"if(!poz || SL.first == NULL)");
                    outtextxy(700*rez4,560*rez4,"new_node->next=SL.first; SL.first=new_node");
                    outtextxy(700*rez4,590*rez4,"if(SL.last == NULL");
                    outtextxy(700*rez4,620*rez4,"SL.last==new_node");
                }
                else
                {
                    outtextxy(700*rez4,500*rez4,"node* new_node2; new_node2=new node");
                    outtextxy(700*rez4,530*rez4,"new_node2=SL.first; int j=0");
                    outtextxy(700*rez4,560*rez4,"while(j<pos-1 && new_node2!= SL.last)");
                    outtextxy(700*rez4,590*rez4,"   new_node2=new_node2->next; ++j");
                    outtextxy(700*rez4,620*rez4,"new_node->next=new_node2->next");
                    outtextxy(700*rez4,650*rez4,"new_node2->next=new_node");
                    outtextxy(700*rez4,680*rez4,"if(new_node2 == SL.last) SL.last=new_node");
                }
            }
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenare_lis_sim(X,rez4,nrLimba);
            delay(500);
            outtextxy(poz_x1_anim+15*rez4,poz_y1_anim+10*rez4,itoa(numar,buffer,10));
            delay(500);
            rectangle(poz_x1_anim,poz_y1_anim,poz_x2_anim,poz_y2_anim); ///casuta

            if(poz_x2_anim + 80*rez4 < 1280*rez4 )
                {
                    delay(500);
                    line(poz_x2_anim,poz_y1_anim + 3*70*rez4/4,poz_x2_anim + 30*rez4,poz_y1_anim + 3*70*rez4/4); ///linie conectoare
                }
            delay(500);
            line(poz_x1_anim,poz_y1_anim + 70*rez4/2,poz_x2_anim,poz_y1_anim + 70*rez4/2); ///linie mijloc
            delay(500);
            circle(poz_x1_anim+(poz_x2_anim-poz_x1_anim)/2,poz_y1_anim+3*70*rez4/4,2*rez4); ///cerc
        }

        if(x>=93*rez4&&x<=189*rez4 && y>=540*rez4&&y<=549*rez4 && nr_el > 0)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez4,coord_y_istoric,"eliminare(poz)");
            else outtextxy(1040*rez4,coord_y_istoric,"remove(pos)");
            if(nrLimba==0)
                outtextxy(370*rez4,coord_y_consola,"Pozitie:");
            else outtextxy(370*rez4,coord_y_consola,"Position:");
            int pozitie=0;
            while(true)
            {
                c=(char)getch();
                if(c==13)
                {
                    if(pozitie >= nr_el)
                        {
                            settextstyle(3,HORIZ_DIR,1);
                            setfillstyle(SOLID_FILL,BLACK);
                            if(nrLimba==0)
                                {
                                    bar(478*rez4,473*rez4,643*rez4,494*rez4);
                                    delay(100);
                                    outtextxy(370*rez4+textwidth("Consola ")+50*rez4,473*rez4,"Pozitia incorecta");
                                }
                            else
                            {
                                bar(478*rez4,473*rez4,643*rez4,494*rez4);
                                delay(100);
                                outtextxy(370*rez4+textwidth("Console ")+50*rez4,473*rez4,"Incorrect position");
                            }
                            if(rez4==0.75)
                                settextstyle(3,HORIZ_DIR,1);
                            if(rez4==1)
                                settextstyle(9,HORIZ_DIR,1);
                            if(rez4==1.5)
                                settextstyle(9,HORIZ_DIR,3);
                        }
                    else
                    {
                        if(nrSound==1)
                            PlaySound(TEXT("soundFX/enter-key.wav"), NULL, SND_ASYNC);
                        break;
                    }
                }
                if(c>=48 && c<=57)
                {
                    int_c=c-'0';
                    pozitie=pozitie*10+int_c;
                    if(nrLimba==0)
                        outtextxy(370*rez4+textwidth("Pozitie: "),coord_y_consola,itoa(pozitie,buffer,10));
                    else
                        outtextxy(370*rez4+textwidth("Position: "),coord_y_consola,itoa(pozitie,buffer,10));
                }
                if (c == 8)   ///backspace
                {
                    pozitie=pozitie/10;
                    setfillstyle(SOLID_FILL, BLACK);
                    if(nrLimba==0)
                        {
                            bar(370*rez4+textwidth("Pozitie: "),coord_y_consola,603*rez4,coord_y_consola+16*rez4);
                            outtextxy(370*rez4+textwidth("Pozitie: "),coord_y_consola,itoa(pozitie,buffer,10));
                        }
                    else
                        {
                            bar(370*rez4+textwidth("Position: "),coord_y_consola,603*rez4,coord_y_consola+16*rez4);
                            outtextxy(370*rez4+textwidth("Position: "),coord_y_consola,itoa(pozitie,buffer,10));
                        }
                }
            }
            bar(478*rez4,473*rez4,643*rez4,494*rez4);
            coord_y_istoric+=20*rez4;
            coord_y_consola+=20*rez4;
            gg <<"Eliminare pe pozitia: "<<pozitie<<'\n';
            pop(X,pozitie);
            --nr_el;
            test_poz=pozitie;   ///copie dupa variabila pozitie
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez4,3*rez4,1280*rez4,456*rez4);
            bar(695*rez4,500*rez4,1040*rez4,720*rez4);
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(pozitie==1)
            {
                if(nrLimba==0)
                {
                    outtextxy(700*rez4,500*rez4,"LS.prim=LS.prim->urm");
                }
                else
                {
                    outtextxy(700*rez4,500*rez4,"SL.first=SL.first->next");
                }
            }
            else
            {
                if(nrLimba==0)
                {
                    outtextxy(700*rez4,500*rez4,"nod * nod_nou2");
                    outtextxy(700*rez4,530*rez4,"nod_nou2= new nod");
                    outtextxy(700*rez4,560*rez4,"nod_nou2=LS.prim; int j=1");
                    outtextxy(700*rez4,590*rez4,"while(j<pozitie-1 && nod_nou2!=LS.ultim)");
                    outtextxy(700*rez4,620*rez4," nod_nou2=nod_nou2->urm");
                    outtextxy(700*rez4,650*rez4," ++j");
                    outtextxy(700*rez4,680*rez4,"nod *test_nod=nod_nou2->urm");
                    outtextxy(700*rez4,720*rez4,"nod_nou2->urm=test_nod->urm");
                }
                else
                {
                    outtextxy(700*rez4,500*rez4,"node * new_node2");
                    outtextxy(700*rez4,530*rez4,"new_node2= new node");
                    outtextxy(700*rez4,560*rez4,"new_node2=SL.first; int j=1");
                    outtextxy(700*rez4,590*rez4,"while(j<position-1 && new_node2!=SL.last)");
                    outtextxy(700*rez4,620*rez4," new_node2=new_node2->next");
                    outtextxy(700*rez4,650*rez4," ++j");
                    outtextxy(700*rez4,680*rez4,"node *test_node=new_node2->next");
                    outtextxy(700*rez4,720*rez4,"new_node2->next=test_node->next");
                }
            }
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenare_lis_sim(X,rez4,nrLimba);
            if (pozitie < nr_el)
            {
                delay(500);
            outtextxy(poz_x1_anim+15*rez4,poz_y1_anim+10*rez4,itoa(elim_test_x,buffer,10));
            delay(500);
            rectangle(poz_x1_anim,poz_y1_anim,poz_x2_anim,poz_y2_anim); ///casuta

            if(poz_x2_anim + 80*rez4 < 1280*rez4 )
                {
                    delay(500);
                    line(poz_x2_anim,poz_y1_anim + 3*70*rez4/4,poz_x2_anim + 30*rez4,poz_y1_anim + 3*70*rez4/4); ///linie conectoare
                }
            delay(500);
            line(poz_x1_anim,poz_y1_anim + 70*rez4/2,poz_x2_anim,poz_y1_anim + 70*rez4/2); ///linie mijloc
            delay(500);
            circle(poz_x1_anim+(poz_x2_anim-poz_x1_anim)/2,poz_y1_anim+3*70*rez4/4,2*rez4); ///cerc
            }
        }
        else if(x>=93*rez4&&x<=189*rez4 && y>=540*rez4&&y<=549*rez4 && nr_el == 0)
        {
            settextstyle(3,HORIZ_DIR,1);
            setfillstyle(SOLID_FILL,BLACK);
            if(nrLimba==0)
                {
                    bar(478*rez4,473*rez4,643*rez4,494*rez4);
                    delay(100);
                    outtextxy(370*rez4+textwidth("Consola ")+50*rez4,473*rez4,"Nu exista elemente");
                }
            else
            {
                bar(478*rez4,473*rez4,643*rez4,494*rez4);
                delay(100);
                outtextxy(370*rez4+textwidth("Console ")+50*rez4,473*rez4,"No elements left");
            }
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(9,HORIZ_DIR,3);
        }
        if(x>=91*rez4&&x<=149*rez4 && y>=570*rez4&&y<=576*rez4)
        {
            bar(478*rez4,473*rez4,643*rez4,494*rez4);
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez4,coord_y_istoric,"golire");
            else outtextxy(1040*rez4,coord_y_istoric,"empty");
            gg<<"Golire"<<'\n';
            coord_y_istoric+=20*rez4;
            golesteX(X);
            nr_el=0;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez4,3*rez4,1280*rez4,456*rez4);
            bar(695*rez4,500*rez4,1040*rez4,720*rez4);
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                outtextxy(700*rez4,500*rez4,"while (LS.prim !=NULL && LS.ultim!=NULL)");
                outtextxy(700*rez4,530*rez4,"pop(LS,1)");
            }
            else
            {
                outtextxy(700*rez4,500*rez4,"while (SL.first !=NULL && SL.last!=NULL)");
                outtextxy(700*rez4,530*rez4,"pop(SL,1)");
            }
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenare_lis_sim(X,rez4,nrLimba);
        }

        if(x>=94*rez4&&x<=249*rez4 && y>=600*rez4&&y<=607*rez4)
        {
            bar(478*rez4,473*rez4,643*rez4,494*rez4);
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez4,coord_y_istoric,"creareAleatorie");
            else outtextxy(1040*rez4,coord_y_istoric,"randomCreate");
            gg<<"Creare Aleatorie"<<'\n';
            coord_y_istoric+=20*rez4;
            creareAleatoare_X(X,nr_el);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez4,3*rez4,1280*rez4,456*rez4);
            bar(695*rez4,500*rez4,1040*rez4,720*rez4);
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
            outtextxy(700*rez4,500*rez4,"goleste");
            outtextxy(700*rez4,530*rez4,"srand(time(NULL))");
            outtextxy(700*rez4,560*rez4,"int n=3+rand()%8");
            outtextxy(700*rez4,590*rez4,"for (int i=1; i<=n; i++)");
            outtextxy(700*rez4,620*rez4,"adauga(X,rand()%20-rand()%20,1);");
            }
            else
            {
                outtextxy(700*rez4,500*rez4,"empty");
                outtextxy(700*rez4,530*rez4,"srand(time(NULL))");
                outtextxy(700*rez4,560*rez4,"int n=3+rand()%8");
                outtextxy(700*rez4,590*rez4,"for (int i=1; i<=n; i++)");
                outtextxy(700*rez4,620*rez4,"add(SL,rand()%20-rand()%20,1);");
            }
            if(rez4==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez4==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez4==1.5)
                settextstyle(9,HORIZ_DIR,3);
                creare_rand=1;
            animaLis=true;
            desenare_lis_sim(X,rez4,nrLimba);
            animaLis=false;
                creare_rand=0;
        }
    }
}
