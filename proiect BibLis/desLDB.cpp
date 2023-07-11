#include "desLDB.h"
#include <winbgim.h>
#include "UI.h"
#include <fstream>

using namespace std;

ofstream g("dateLDB.txt");

double rez2;
int coord_cas_x1;
int coord_cas_y1;
int coord_cas_x2;
int coord_cas_y2;
int width=1280*rez2,height=720*rez2; ///pt rezolutia asta
bool animaLDB;
///0=normal fara primul, 1=normal, 2=add, 3=adauga un element prima casuta goala, 4=normal fara ultimul
void desenCasPrim(double rez2,int anim, int nrLimba)
{
    int coord_cas_x1_prim=10*rez2;
    int coord_cas_y1_prim=10*rez2;
    int coord_cas_x2_prim=110*rez2;
    int coord_cas_y2_prim=60*rez2;
    rectangle(coord_cas_x1_prim,coord_cas_y1_prim,coord_cas_x2_prim,coord_cas_y2_prim);
    if (!nrLimba)
    outtextxy(35*rez2,25*rez2,"Prim");
    else
        outtextxy(35*rez2,25*rez2,"First");
    line(coord_cas_x2_prim,(coord_cas_y2_prim-coord_cas_y1_prim)/2+coord_cas_y1_prim, coord_cas_x2_prim+50*rez2, (coord_cas_y2_prim-coord_cas_y1_prim)/2+coord_cas_y1_prim);
}
void desenCasUlt(double rez2,int time, int nrLimba)
{
    delay(time);
    rectangle(coord_cas_x1,coord_cas_y1,coord_cas_x2,coord_cas_y2);
    delay(time);
    if(!nrLimba)
    outtextxy(coord_cas_x1+20*rez2,coord_cas_y1+15*rez2,"Ultim");
    else
        outtextxy(coord_cas_x1+20*rez2,coord_cas_y1+15*rez2,"Last");
}
void desenCasElm(int elem,double rez2,int time,int anim, nod* nod_nou,lista L)
{
    char test[25];
    itoa(elem,test,10);
    if(!(nod_nou==L.prim && anim==0))
    {
        delay(time);
        rectangle(coord_cas_x1,coord_cas_y1,coord_cas_x2,coord_cas_y2);
    }
    int x1_linia_1=((coord_cas_x2-coord_cas_x1)-textwidth(test)*rez2)/2+coord_cas_x1;
    if(!(nod_nou==L.prim && anim==0))
    {
    delay(time);
    line( x1_linia_1-1*rez2,coord_cas_y1,x1_linia_1-1*rez2,coord_cas_y2 );
    delay(time);
    circle( (x1_linia_1-coord_cas_x1)/2+coord_cas_x1, (coord_cas_y2-coord_cas_y1)/2+coord_cas_y1, 3*rez2 );
    delay(time);
    outtextxy(x1_linia_1+1*rez2,coord_cas_y1+15*rez2,test);
    delay(time);
    line(x1_linia_1+1*rez2+textwidth(test)*rez2,coord_cas_y1,x1_linia_1+1*rez2+textwidth(test)*rez2,coord_cas_y2);
    delay(time);
    circle( (x1_linia_1-coord_cas_x1)/2+x1_linia_1+1*rez2+textwidth(test)*rez2, (coord_cas_y2-coord_cas_y1)/2+coord_cas_y1, 3 *rez2);
    }
}

void desenareLDB(lista L,double rez2,int anim, int nrLimba)
{
    if (L.prim == NULL)
        return;
    int time=0;
    nod * nod_nou = new nod;
    nod_nou=L.prim;
    desenCasPrim(rez2,time, nrLimba);
    coord_cas_x1=160*rez2;
    coord_cas_y1=10*rez2;
    coord_cas_x2=260*rez2;
    coord_cas_y2=60*rez2;
    width=1280*rez2;
    height=720*rez2;
    while(nod_nou->urm!=NULL )
    {
        if(nod_nou->urm->urm==NULL&&anim==4)
        {
            if (coord_cas_x2+150*rez2 <width)
            {
                delay(time);
                line(coord_cas_x2, (coord_cas_y2-coord_cas_y1)/2+coord_cas_y1,coord_cas_x2+50*rez2,(coord_cas_y2-coord_cas_y1)/2+coord_cas_y1);
            }
            int cord_lin_x1=coord_cas_x2;
            int cord_lin_y1=coord_cas_y2;
            coord_cas_x1=coord_cas_x2+50*rez2;
            coord_cas_x2=coord_cas_x1+100*rez2;
            nod_nou=nod_nou->urm;
            continue;
        }
        if(nod_nou==L.ultim && anim==2)
            time=500;
        if (coord_cas_x2+150*rez2 <width)
            {
                delay(time);
                line(coord_cas_x2, (coord_cas_y2-coord_cas_y1)/2+coord_cas_y1,coord_cas_x2+50*rez2,(coord_cas_y2-coord_cas_y1)/2+coord_cas_y1);
            }
        int cord_lin_x1=coord_cas_x2;
        int cord_lin_y1=coord_cas_y2;
        if(nod_nou==L.prim&&anim==3&&L.nrElemente!=0)
        {
            coord_cas_x1=coord_cas_x2+50*rez2;
            coord_cas_x2=coord_cas_x1+100*rez2;
            line(coord_cas_x2, (coord_cas_y2-coord_cas_y1)/2+coord_cas_y1,coord_cas_x2+50*rez2,(coord_cas_y2-coord_cas_y1)/2+coord_cas_y1);
        }
        desenCasElm(nod_nou->info,rez2,time,anim,nod_nou,L);
        coord_cas_x1=coord_cas_x2+50*rez2;
        coord_cas_x2=coord_cas_x1+100*rez2;
        if(coord_cas_x2 > width)
        {
            coord_cas_x1=10*rez2;
            coord_cas_y1=coord_cas_y2+50*rez2;
            coord_cas_x2=110*rez2;
            coord_cas_y2=coord_cas_y1+50*rez2;
            delay(time);
            line(cord_lin_x1,cord_lin_y1,coord_cas_x1,coord_cas_y1);
        }
        if (animaLDB)
            g << nod_nou->info<<" ";
        nod_nou=nod_nou->urm;
    }
    if (animaLDB)
        g << '\n';
    desenCasUlt(rez2,time,nrLimba);
}

void test_LDB(int x, int y, lista &L,int nrRez,int nrLimba,int nrSound)
{

    char c;
    cleardevice();
    if(nrRez==2)
        rez2=1;
    else if(nrRez==1)
        rez2=0.75;
    else if(nrRez==3)
        rez2=1.5;
    if(rez2!=1)
    {
        closegraph();
        initwindow(1280*rez2,720*rez2);
    }
    bar(1*rez2,465*rez2,1280*rez2,468*rez2);///bara sus
    if(rez2==0.75)
        settextstyle(3,HORIZ_DIR,1);
    if(rez2==1)
        settextstyle(9,HORIZ_DIR,1);
    if(rez2==1.5)
        settextstyle(9,HORIZ_DIR,3);
    readimagefile("imag/backButton.jpg",15*rez2,665*rez2,65*rez2,710*rez2);     ///undo
    if(nrLimba==0)
    {
        outtextxy(76*rez2,473*rez2,"Functii:");
        outtextxy(86*rez2,503*rez2," inserareInFata(x)");
        outtextxy(86*rez2,533*rez2," inserareInSpate(x)");
        outtextxy(86*rez2,563*rez2," eliminaInFata");
        outtextxy(86*rez2,593*rez2," eliminaInSpate");
        outtextxy(86*rez2,623*rez2," golire");
        outtextxy(86*rez2,653*rez2," creareAleatorie");
        outtextxy(1040*rez2,473*rez2,"Istoric comenzi:");
        outtextxy(370*rez2,473*rez2,"Consola:");
        outtextxy(700*rez2,473*rez2,"Cod executat: ");
    }
    else
    {
        outtextxy(76*rez2,473*rez2,"Functions:");
        outtextxy(86*rez2,503*rez2," addInFront(x)");
        outtextxy(86*rez2,533*rez2," addInBack(x)");
        outtextxy(86*rez2,563*rez2," removeFront");
        outtextxy(86*rez2,593*rez2," removeBack");
        outtextxy(86*rez2,623*rez2," empty");
        outtextxy(86*rez2,653*rez2," randomCreate");
        outtextxy(1040*rez2,473*rez2,"Executed commands:");
        outtextxy(370*rez2,473*rez2,"Console:");
        outtextxy(700*rez2,473*rez2,"Executed code: ");
    }
    int numar=0;
    char buffer[20];
    int coord_y_istoric=501*rez2;
    int coord_y_consola=501*rez2;
    int int_c=0;
    stiva S;
    coada C;
    lis_sim X;
    while(true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(coord_y_istoric>=688*rez2)    ///reset istoric
        {
            coord_y_istoric=501*rez2;
            bar(950*rez2,500*rez2,1280*rez2,720*rez2);
        }

        if(coord_y_consola>=688*rez2)    ///reset consola
        {
            coord_y_consola=501*rez2;
            bar(370*rez2,496*rez2,370*rez2+2*textwidth("Valoare: ")*rez2,705*rez2);
        }

        if(x>=15*rez2 && x<=65*rez2 && y>=665*rez2&&y<=710*rez2)  ///undo
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            closegraph(CURRENT_WINDOW);
            initwindow(1280,720);
            meniu_selectare_lis(S,C,L,X, false,nrRez,nrLimba,nrSound);
        }
        if(x>=93*rez2&&x<=267*rez2 && y>=511*rez2&&y<=518*rez2)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            int numar=0;
            int int_c=0;
            if(nrLimba==0)
                outtextxy(370*rez2,coord_y_consola,"Valoare: ");
            else
                outtextxy(370*rez2,coord_y_consola,"Value:");
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
                        outtextxy(370*rez2+textwidth("Valoare: "),coord_y_consola,itoa(numar,buffer,10));
                    else
                        outtextxy(370*rez2+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                }
                if (c == 8)   ///backspace
                {
                    numar=numar/10;
                    setfillstyle(SOLID_FILL, BLACK);
                    if(nrLimba==0)
                        {
                            bar(370*rez2+textwidth("Valoare: "),coord_y_consola,603*rez2,coord_y_consola+16*rez2);
                            outtextxy(370*rez2+textwidth("Valoare: "),coord_y_consola,itoa(numar,buffer,10));
                        }
                    else
                        {
                            bar(370*rez2+textwidth("Value: "),coord_y_consola,603*rez2,coord_y_consola+16*rez2);
                            outtextxy(370*rez2+textwidth("Value: "),coord_y_consola,itoa(numar,buffer,10));
                        }
                }
            }
            outtextxy(1040*rez2,coord_y_istoric,"addInFront");
            outtextxy(1200*rez2,coord_y_istoric,itoa(numar,buffer,10));
            g <<"Adaugare in fata: "<<numar<<'\n';
            coord_y_istoric+=20*rez2;
            coord_y_consola+=20*rez2;
            int esteVid=0;
            if(L.prim==NULL)
                esteVid=1;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            bar(695*rez2,490*rez2,1033*rez2,711*rez2);
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez2,500*rez2,"nod_nou=new nod; nod_nou->info=element");
                    outtextxy(700*rez2,530*rez2,"nod_nou->urm=L.dreapta");
                    outtextxy(700*rez2,560*rez2,"nod_nou->prec=L.Stanga");
                    outtextxy(700*rez2,590*rez2,"L.stanga->urm=nod_nou");
                    outtextxy(700*rez2,620*rez2,"L.dreapta->prec=nod_nou");
                    outtextxy(700*rez2,650*rez2,"L.prim=nod_nou");
                    outtextxy(700*rez2,680*rez2,"L.ultim=L.prim; L.curent=L.prim");
                }
                else
                {
                    outtextxy(700*rez2,510*rez2,"nod_nou->urm=L.prim");
                    outtextxy(700*rez2,540*rez2,"L.prim->prec=nod_nou");
                    outtextxy(700*rez2,570*rez2,"nod_nou->prec=L.stanga");
                    outtextxy(700*rez2,600*rez2,"L.stanga->urm=nod_nou");
                    outtextxy(700*rez2,630*rez2,"L.prim=nod_nou");
                    outtextxy(700*rez2,660*rez2,"L.curent=L.prim");
                }
            }
            else
            {
                if(esteVid==1)
                {
                    outtextxy(700*rez2,500*rez2,"new_node=new nod;new_node->info=element");
                    outtextxy(700*rez2,530*rez2,"new_node->next=L.right");
                    outtextxy(700*rez2,560*rez2,"new_node->prev=L.left");
                    outtextxy(700*rez2,590*rez2,"L.left->next=new_node");
                    outtextxy(700*rez2,620*rez2,"L.right->prev=new_node");
                    outtextxy(700*rez2,650*rez2,"L.first=new_node");
                    outtextxy(700*rez2,680*rez2,"L.last=L.first; L.current=L.first");
                }
                else
                {
                    outtextxy(700*rez2,510*rez2,"new_node->next=L.first");
                    outtextxy(700*rez2,540*rez2,"L.first->prev=new_node");
                    outtextxy(700*rez2,570*rez2,"new_node->prev=L.left");
                    outtextxy(700*rez2,600*rez2,"L.left->next=new_node");
                    outtextxy(700*rez2,630*rez2,"L.first=new_node");
                    outtextxy(700*rez2,660*rez2,"L.current=L.first");
                }
            }
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(9,HORIZ_DIR,3);

            if(L.nrElemente==0)
            {
                adaugaInFata(L,numar);
                desenareLDB(L,rez2,2,nrLimba);
            }
            else
            {
                bar(5*rez2,3*rez2,1280*rez2,456*rez2);
                desenareLDB(L,rez2,3,nrLimba);
                delay(1000);
                bar(5*rez2,3*rez2,1280*rez2,456*rez2);
                adaugaInFata(L,numar);
                desenareLDB(L,rez2,1,nrLimba);
            }
        }

        if(x>=93*rez2&&x<=229*rez2 && y>=540*rez2&&y<=549*rez2)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            int int_c=0;
            int numar=0;
            if(nrLimba==0)
                outtextxy(370*rez2,coord_y_consola,"Valoare:");
            else
                outtextxy(370*rez2,coord_y_consola,"Value:");
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
                        outtextxy(370*rez2+textwidth("Valoare: ")*rez2,coord_y_consola,itoa(numar,buffer,10));
                    else
                        outtextxy(370*rez2+textwidth("Value: ")*rez2,coord_y_consola,itoa(numar,buffer,10));
                }
            }
            if(nrLimba==0)
                outtextxy(1040*rez2,coord_y_istoric,"adaugareSpate");
            else
                outtextxy(1040*rez2,coord_y_istoric,"addInBack");
            outtextxy(1200*rez2,coord_y_istoric,itoa(numar,buffer,10));
            g <<"Adaugare in spate: "<<numar<<'\n';
            coord_y_istoric+=20*rez2;
            coord_y_consola+=20*rez2;
            int esteVid=0;
            if(L.prim==NULL)
                esteVid=1;
            adaugaLaSpate(L,numar);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            bar(695*rez2,490*rez2,1033*rez2,711*rez2);
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                if(esteVid==1)
                {
                    outtextxy(700,500,"nod_nou=new nod; nod_nou->info=element");
                    outtextxy(700,530,"nod_nou->urm=L.dreapta");
                    outtextxy(700,560,"nod_nou->prec=NULL");
                    outtextxy(700,590,"L.stanga->urm=nod_nou");
                    outtextxy(700,620,"L.dreapta->prec=nod_nou");
                    outtextxy(700,650,"L.prim=nod_nou");
                    outtextxy(700,680,"L.curent=L.prim; L.ultim=L.prim");
                }
                else
                {
                    outtextxy(700*rez2,510*rez2,"nod_nou->urm=L.prim");
                    outtextxy(700*rez2,540*rez2,"L.prim->prec=nod_nou");
                    outtextxy(700*rez2,570*rez2,"nod_nou->prec=L.stanga");
                    outtextxy(700*rez2,600*rez2,"L.stanga->urm=nod_nou");
                    outtextxy(700*rez2,630*rez2,"L.prim=nod_nou");
                    outtextxy(700*rez2,660*rez2,"L.curent=L.prim");
                }
            }
            else
            {
                if(esteVid==1)
                {
                    outtextxy(700,500,"new_node=new node;new_node->info=element");
                    outtextxy(700,530,"new_node->next=L.right");
                    outtextxy(700,560,"new_node->prev=NULL");
                    outtextxy(700,590,"L.left->next=new_node");
                    outtextxy(700,620,"L.right->prev=new_node");
                    outtextxy(700,650,"L.first=new_node");
                    outtextxy(700,680,"L.current=L.first; L.last=L.first");
                }
                else
                {
                    outtextxy(700*rez2,510*rez2,"new_node->next=L.first");
                    outtextxy(700*rez2,540*rez2,"L.first->prev=new_node");
                    outtextxy(700*rez2,570*rez2,"new_node->prev=L.left");
                    outtextxy(700*rez2,600*rez2,"L.left->next=new_node");
                    outtextxy(700*rez2,630*rez2,"L.first=new_node");
                    outtextxy(700*rez2,660*rez2,"L.current=L.first");
                }
            }
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenareLDB(L,rez2,2,nrLimba);
        }

        if(x>=91*rez2&&x<=235*rez2 && y>=570*rez2&&y<=576*rez2)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez2,coord_y_istoric,"eliminareInFata");
            else outtextxy(1040*rez2,coord_y_istoric,"removeFront");
            g <<"Eliminare in fata"<<'\n';
            coord_y_istoric+=20*rez2;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            bar(695*rez2,490*rez2,1033*rez2,711*rez2);
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                outtextxy(700*rez2,500*rez2,"L.nrElemente=L.nrElemente-1");
                outtextxy(700*rez2,530*rez2,"L.prim=L.prim->urm");
            }
            else
            {
                outtextxy(700*rez2,500*rez2,"L.nrElements=L.nrElements-1");
                outtextxy(700*rez2,530*rez2,"L.first=L.first->next");
            }
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenareLDB(L,rez2,0,nrLimba);
            delay(1000);
            scoatePrimul(L);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            desenareLDB(L,rez2,1,nrLimba);

        }

        if(x>=94*rez2&&x<=244*rez2 && y>=600*rez2&&y<=607*rez2)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez2,coord_y_istoric,"eliminareInSpate");
            else outtextxy(1040*rez2,coord_y_istoric,"removeBack");
            g <<"Eliminare in spate"<<'\n';
            coord_y_istoric+=20*rez2;
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            bar(695*rez2,490*rez2,1033*rez2,711*rez2);
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(3,HORIZ_DIR,3);
            outtextxy(700*rez2,500*rez2,"L.nrElements=L.nrElements-1");
            outtextxy(700*rez2,530*rez2,"L.last->next=NULL");
            outtextxy(700*rez2,560*rez2,"L.last=L.last->prev");
            outtextxy(700*rez2,590*rez2,"L.current=L.last");
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenareLDB(L,rez2,4,nrLimba);
            scoateUltimul(L);
            delay(1000);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            desenareLDB(L,rez2,1,nrLimba);
        }

        if(x>=94*rez2&&x<=149*rez2 && y>=631*rez2&&y<=638*rez2)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez2,coord_y_istoric,"golire");
            else outtextxy(1040*rez2,coord_y_istoric,"empty");
            g <<"Golire"<<'\n';
            coord_y_istoric+=20*rez2;
            golesteL(L);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            bar(695*rez2,490*rez2,1033*rez2,711*rez2);
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                outtextxy(700*rez2,500*rez2,"int element");
                outtextxy(700*rez2,530*rez2,"while (!esteVida(L))");
                outtextxy(700*rez2,560*rez2,"element=scoatePrimul(L)");
            }
            else
            {
                outtextxy(700*rez2,500*rez2,"int element");
                outtextxy(700*rez2,530*rez2,"while (!isEmpty(L))");
                outtextxy(700*rez2,560*rez2,"element=removeFront(L)");
            }
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(9,HORIZ_DIR,3);
            desenareLDB(L,rez2,1,nrLimba);
        }

        if(x>=94*rez2&&x<=247*rez2 && y>=660*rez2&&y<=667*rez2)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==0)
                outtextxy(1040*rez2,coord_y_istoric,"creareAleatorie");
            else outtextxy(1040*rez2,coord_y_istoric,"randomCreate");
            g <<"CreareAleatorie"<<'\n';
            coord_y_istoric+=20*rez2;
            creareAleatoare_LDB(L);
            setfillstyle(SOLID_FILL,BLACK);
            bar(5*rez2,3*rez2,1280*rez2,456*rez2);
            bar(695*rez2,490*rez2,1033*rez2,711*rez2);
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(3,HORIZ_DIR,3);
            if(nrLimba==0)
            {
                outtextxy(700*rez2,500*rez2,"goleste(L))");
                outtextxy(700*rez2,530*rez2,"srand(time(NULL))");
                outtextxy(700*rez2,560*rez2,"int n=3+rand()%8");
                outtextxy(700*rez2,590*rez2,"for (int i=1; i<=n; i++)");
                outtextxy(700*rez2,620*rez2,"adaugaInFata(L,rand()%20-rand()%20)");
            }
            else
            {
                outtextxy(700*rez2,500*rez2,"empty");
                outtextxy(700*rez2,530*rez2,"srand(time(NULL))");
                outtextxy(700*rez2,560*rez2,"int n=3+rand()%8");
                outtextxy(700*rez2,590*rez2,"for (int i=1; i<=n; i++)");
                outtextxy(700*rez2,620*rez2,"addInFront(L,rand()%20-rand()%20)");
            }
            if(rez2==0.75)
                settextstyle(3,HORIZ_DIR,1);
            if(rez2==1)
                settextstyle(9,HORIZ_DIR,1);
            if(rez2==1.5)
                settextstyle(9,HORIZ_DIR,3);
            animaLDB=true;
            desenareLDB(L,rez2,1,nrLimba);
            animaLDB=false;
        }
    }
}
