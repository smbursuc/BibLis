#include <winbgim.h>
#include "desStiv.h"
#include "desLDB.h"
#include "desCoad.h"
#include "UI.h"
#include "desLisSim.h"

void easter_egg(stiva S, coada C, lista L, lis_sim X,int nrRez, int nrLimba, int nrSound)
{
    cleardevice();
    int x,y;
    int midY=360,midX=640,z=50;
    settextstyle(9,HORIZ_DIR,3);
    PlaySound(TEXT("soundFX/easter_egg.wav"), NULL, SND_ASYNC);
    delay(17600);

    for(int i=1; i<=4; i++)
    {
        settextstyle(9,HORIZ_DIR,3);
        x=midX-textwidth("every second")/2;
        y=midY-textheight("every second")/2-z;
        outtextxy(x,y,"every second");
        delay(1100);
        cleardevice();

        settextstyle(9,HORIZ_DIR,4);
        x=midX-textwidth("every minute")/2;
        y=midY-textheight("every minute")/2-z;
        outtextxy(x,y,"every minute");
        delay(1100);
        cleardevice();

        settextstyle(9,HORIZ_DIR,5);
        x=midX-textwidth("every hour")/2;
        y=midY-textheight("every hour")/2-z;
        outtextxy(x,y,"every hour");
        delay(1100);
        cleardevice();

        settextstyle(9,HORIZ_DIR,6);
        x=midX-textwidth("EVERY DAY!!")/2;
        y=midY-textheight("EVERY DAY!!")/2-z;
        outtextxy(x,y,"EVERY DAY!!");
        if(i==2)
        {
            delay(1200);
        }
        else
            delay(1800);
        cleardevice();

        x=midX-textwidth("IT NEVER ENDS")/2;
        y=midY-textheight("IT NEVER ENDS")/2-z;
        outtextxy(x,y,"IT NEVER ENDS");
        delay(1800);
        cleardevice();

        x=midX-textwidth("IT NEVER ENDS !!")/2;
        y=midY-textheight("IT NEVER ENDS !!")/2-z;
        outtextxy(x,y,"IT NEVER ENDS !!");
        if(i==4)
            delay(3000);
        else delay(1200);
        cleardevice();

        if(i!=4)
        {
            delay(250);
            cleardevice();
            settextstyle(9,HORIZ_DIR,4);
            x=midX-textwidth("e")/2;
            y=midY-textheight("e")/2-z;
            outtextxy(x,y,"e");
            delay(250);
            cleardevice();
            settextstyle(9,HORIZ_DIR,5);
            x=midX-textwidth("e")/2;
            y=midY-textheight("e")/2-z;
            outtextxy(x,y,"e");
            delay(250);
            cleardevice();
            settextstyle(9,HORIZ_DIR,6);
            x=midX-textwidth("e")/2;
            y=midY-textheight("e")/2-z;
            outtextxy(x,y,"e");
            delay(250);
            cleardevice();
        }
    }

    delay(5000);
    settings(S,C,L,X,nrRez,nrLimba,nrSound);
}

void settings(stiva S, coada C, lista L, lis_sim X,int nrRez, int nrLimba, int nrSound)
{
    int x,y,midRez=741+(878-741)/2+5,midSound=653+(745-653)/2,midText=627+(745-627)/2,nrRezOr,nrLimbaOr,nrSoundOr,midSetari=1280/2;
    nrRezOr=nrRez;
    nrSoundOr=nrSound;
    nrLimbaOr=nrLimba;
    if(nrLimba==1)
        readimagefile("imag/setariEng.jpg",0,0,1280,720);
    else readimagefile("imag/setariRo.jpg",0,0,1280,720);
    settextstyle(10,HORIZ_DIR,3);
    if(nrLimba==1)
        outtextxy(midText-textwidth("English")/2,331,"English");
    else outtextxy(midText-textwidth("Romana")/2,331,"Romana");
    if(nrSound==1)
        outtextxy(midSound-textwidth("ON")/2,408,"ON");
    else outtextxy(midSound-textwidth("OFF")/2,408,"OFF");
    settextstyle(10,HORIZ_DIR,2);
    if(nrRez==2)
        outtextxy(midRez-textwidth("1280x720")/2,372,"1280x720");
    else if(nrRez==3)
        outtextxy(midRez-textwidth("1920x1080")/2,372,"1920x1080");
        else if(nrRez==1)
            outtextxy(midRez-textwidth("960x540")/2,372,"960x540");
    settextstyle(10,HORIZ_DIR,3);
    while(1)
    {
        settextstyle(10,HORIZ_DIR,1);
        if(nrRez!=nrRezOr || nrSound!=nrSoundOr || nrLimba!=nrLimbaOr)
        {
            if(nrLimbaOr==1)
                outtextxy(midSetari-textwidth("Changes have been made. Return to apply.")/2,611,"Changes have been made. Return to apply.");
            if(nrLimbaOr==0)
                outtextxy(midSetari-textwidth("Au fost facute schimbari. Intoarce pentru a aplica.")/2,611,"Au fost facute schimbari. Intoarce pentru a aplica.");
        }
        else
        {
            setfillstyle(SOLID_FILL,BLACK);
            bar(353,608,922,627);
        }
        settextstyle(10,HORIZ_DIR,3);
        while (!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (x>=1202 && x<=1248 && y>=25 && y<=70)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            meniu_principal(S,C,L,X,nrRez,nrLimba,nrSound);
        }
        if(x>=601 && x<=603 && y>=381 && y<384)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            easter_egg(S,C,L,X,nrRez,nrLimba,nrSound);
        }
        if(x>=718 && x<=738 && y>=367 && y<=393)
        {
            settextstyle(10,HORIZ_DIR,2);
            setfillstyle(SOLID_FILL,BLACK);
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrRez==2)
            {
                bar(743,370,868,389);
                outtextxy(midRez-textwidth("960x540")/2,372,"960x540");
                nrRez=1;
                settextstyle(10,HORIZ_DIR,3);
                continue;
            }
            if(nrRez==1)
            {
                bar(743,370,868,389);
                outtextxy(midRez-textwidth("1920x1080")/2,372,"1920x1080");
                nrRez=3;
                settextstyle(10,HORIZ_DIR,3);
                continue;
            }
            if(nrRez==3)
            {
                bar(743,370,868,389);
                outtextxy(midRez-textwidth("1280x720")/2,372,"1280x720");
                nrRez=2;
                settextstyle(10,HORIZ_DIR,3);
                continue;
            }
        }
        if(x>=884&&x<=905 && y>=372 && y<=393)
        {
            settextstyle(10,HORIZ_DIR,2);
            setfillstyle(SOLID_FILL,BLACK);
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrRez==2)
            {
                bar(743,370,868,389);
                outtextxy(midRez-textwidth("1920x1080")/2,372,"1920x1080");
                nrRez=3;
                settextstyle(10,HORIZ_DIR,3);
                continue;
            }
            if(nrRez==3)
            {
                bar(743,370,868,389);
                outtextxy(midRez-textwidth("960x540")/2,372,"960x540");
                nrRez=1;
                settextstyle(10,HORIZ_DIR,3);
                continue;
            }
            if(nrRez==1)
            {
                bar(743,370,868,389);
                outtextxy(midRez-textwidth("1280x720")/2,372,"1280x720");
                nrRez=2;
                settextstyle(10,HORIZ_DIR,3);
                continue;
            }
            settextstyle(10,HORIZ_DIR,3);

        }
        if(x>=630&&x<=648 && y>=409&&y<=426 || x>=751 && x<=770 && y>=408 && y<=426)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);

            if(nrSound==1)
            {
                setfillstyle(SOLID_FILL,BLACK);
                bar(652,408,745,425);
                outtextxy(midSound-textwidth("OFF")/2,408,"OFF");
                nrSound=0;
                continue;
            }
            if(nrSound==0)
            {
                setfillstyle(SOLID_FILL,BLACK);
                bar(652,408,745,425);
                outtextxy(midSound-textwidth("ON")/2,408,"ON");
                nrSound=1;
                continue;
            }
        }
        if(x>=607&&x<=625 && y>=329&&y<=351 || x>=748 && x<=766 && y>=333 && y<=355)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/press1.wav"), NULL, SND_ASYNC);
            if(nrLimba==1)
            {
                setfillstyle(SOLID_FILL,BLACK);
                bar(628,329,744,351);
                outtextxy(midText-textwidth("Romana")/2,329,"Romana");
                nrLimba=0;
                continue;
            }
            if(nrLimba==0)
            {
                setfillstyle(SOLID_FILL,BLACK);
                bar(628,329,744,351);
                outtextxy(midText-textwidth("English")/2,329,"English");
                nrLimba=1;
                continue;
            }
        }

    }
}

void credits (stiva S, coada C, lista L, lis_sim X, int nrRez, int nrLimba, int nrSound)
{
    int x,y;
    if(nrLimba==1)
        readimagefile("imag/creditsEng.jpg",0,0,1280,720);
    else readimagefile("imag/creditsRo.jpg",0,0,1280,720);
    while(true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN)) {}

        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (x>=1202 && x<=1248 && y>=25 && y<=70)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            meniu_principal(S,C,L,X,nrRez,nrLimba,nrSound);
        }
    }
}

void meniu_principal(stiva &S, coada &C, lista &L, lis_sim &X, int nrRez, int nrLimba, int nrSound)
{
    int x,y;
    if(nrLimba==1)
        readimagefile("imag/mainEng.jpg",0,0,1280,720);
    else readimagefile("imag/mainRo.jpg",0,0,1280,720);
    while(true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN)) {}

        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=590&&x<=668 && y>=451&&y<=471)
        {
            PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            exit(0);
        }
        if(x>=583&&x<=681 && y>=316&&y<=337)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            meniu_selectare_lis(S,C,L,X,false,nrRez,nrLimba,nrSound);
        }
        if (x>=543 && x<=723 && y>=356 && y<=392)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            settings(S,C,L,X,nrRez,nrLimba,nrSound);
        }
        if (x>=549 && x<=709 && y>=403 && y<=432)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            credits(S,C,L,X,nrRez,nrLimba,nrSound);
        }
    }
}

void meniu_selectare_lis(stiva &S, coada &C, lista &L, lis_sim &X, bool Switch,int nrRez,int nrLimba,int nrSound)
{
    int x,y;
    bool ok=false;                  ///val 0-info meniu nu este afisata    1-info meniu este afisat
    if (!Switch && nrLimba==1)
        readimagefile("imag/meniuEng.jpg",0,0,1280,720);
    else if(Switch && nrLimba==1)
        readimagefile("imag/LSmeniuEng.jpg",0,0,1280,720);

    if (!Switch && nrLimba==0)
        readimagefile("imag/meniuRo.jpg",0,0,1280,720);
    else if(Switch && nrLimba==0)
        readimagefile("imag/LSmeniuRo.jpg",0,0,1280,720);
    if(nrLimba==1)
    {
        rectangle(124,224,248,261); ///stack
        rectangle(1019,211,1138,254); ///queue
        rectangle(478,190,749,278); ///LDB
        rectangle(462,291,757,316);  ///chenar switch
    }
    if(nrLimba==0)
    {
        rectangle(419,190,795,267); ///LDB
        rectangle(1013,213,1138,246); ///queue
        rectangle(105,222,230,258); ///stack
        rectangle(434,288,784,304); ///switch
    }
    while(true)
    {
        while (!ismouseclick(WM_LBUTTONDOWN)) {}

        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=1019&&x<=1138 && y>=211&&y<=249 || x>=1013 && x<=1138 && y>=213 && y<=246) ///COADA
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            initializeazaC(C);
            test_coada(x,y,C,nrRez,nrLimba,nrSound);
        }
        if(x>=124&&x<=248 && y>=224&&y<=254 || x>=105 && x<=230 && y>=222 && y<=258) ///STIVA
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            initializeazaS(S);
            test_stiva(x,y,S,nrRez,nrLimba,nrSound);
        }
        if((x>=485&&x<=752 && y>=193&&y<=273 || x>=419 && x<=795 && y>=190 && y<=267) && !Switch) ///LDB
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            initializeazaL(L);
            test_LDB(x,y,L,nrRez,nrLimba,nrSound);
        }
        if((x>=462&&x<=757 && y>=293&&y<=315 || x>=434 && x<=784 && y>=288 && y<=304) && !Switch) ///switch
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            if(nrLimba==1)
                {
                    readimagefile("imag/LSmeniuEng.jpg",0,0,1280,720);
                    rectangle(124,224,248,261); ///stack
                    rectangle(1019,211,1138,254); ///queue
                    rectangle(478,190,749,278); ///lis_sim
                    rectangle(462,291,757,316);  ///chenar switch
                }
            else
            {
                readimagefile("imag/LSmeniuRo.jpg",0,0,1280,720);
                rectangle(419,190,795,267); ///LDB
                rectangle(1013,213,1138,246); ///queue
                rectangle(105,222,230,258); ///stack
                rectangle(434,288,784,304); ///switch
            }
            Switch=true;            ///switch true - se afiseaza meniu cu lista sim
        }                           ///switch false - se afiseaza meniu cu lista dubl
        else if(x>=462&&x<=757 && y>=293&&y<=315 && Switch)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            meniu_selectare_lis(S,C,L,X,false,nrRez,nrLimba,nrSound);
        }
        if(x>=485&&x<=752 && y>=193&&y<=273 && Switch) ///lis_sim
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            initializeazaLis_sim(X);
            test_lis_sim(x,y,X,nrRez,nrLimba,nrSound);
        }
        if(x>=1084&&x<=1107 && y>=74&&y<=94 && !ok && !Switch)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/infoIN.wav"), NULL, SND_ASYNC);
            if(nrLimba==1)
                {
                    readimagefile("imag/meniuEngDet.jpg",0,0,1280,720);
                    rectangle(124,224,248,261); ///stack
                    rectangle(1019,211,1138,254); ///queue
                    rectangle(478,190,749,278); ///LDB
                    rectangle(462,291,757,316);  ///chenar switch
                }

            else
            {
                readimagefile("imag/meniuRoDet.jpg",0,0,1280,720);
                rectangle(419,190,795,267); ///LDB
                rectangle(1013,213,1138,246); ///queue
                rectangle(105,222,230,258); ///stack
                rectangle(434,288,784,304); ///switch
            }
            ok=true;
        }
        else if(x>=1084&&x<=1107 && y>=74&&y<=94 && !ok && Switch)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/infoIN.wav"), NULL, SND_ASYNC);
            if(nrLimba==1)
                {
                    readimagefile("imag/LSmeniuEngDet.jpg",0,0,1280,720);
                    rectangle(124,224,248,261); ///stack
                    rectangle(1019,211,1138,254); ///queue
                    rectangle(478,190,749,278); ///lis_sim
                    rectangle(462,291,757,316);  ///chenar switch
                }
            else
            {
                readimagefile("imag/LSmeniuRoDet.jpg",0,0,1280,720);
                rectangle(419,190,795,267); ///LDB
                rectangle(1013,213,1138,246); ///queue
                rectangle(105,222,230,258); ///stack
                rectangle(434,288,784,304); ///switch
            }
            ok=true;
        }
        else if(x>=1084&&x<=1107 && y>=74&&y<=94 && ok && !Switch)   ///buton informatii
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/infoOUT.wav"), NULL, SND_ASYNC);
            meniu_selectare_lis(S,C,L,X, false,nrRez,nrLimba,nrSound);
        }
        else if(x>=1084&&x<=1107 && y>=74&&y<=94 && ok && Switch)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/infoOUT.wav"), NULL, SND_ASYNC);
            meniu_selectare_lis(S,C,L,X, true,nrRez,nrLimba,nrSound);
        }

        if (x>=1202 && x<=1248 && y>=25 && y<=70)
        {
            if(nrSound==1)
                PlaySound(TEXT("soundFX/menuFX.wav"), NULL, SND_ASYNC);
            meniu_principal(S,C,L,X,nrRez,nrLimba,nrSound);
        }
    }
}
