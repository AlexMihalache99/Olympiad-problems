#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("reteta.in");
ofstream g("reteta.out");
char s[1001],cv[21]="",ch;
int up=0,t=0,i,j,ls,nr,lcv=-1,ct=0,tt=0;
int pi=1,pf=1,lv=-1,pcv,srt=0;
struct reteta
{
    char cv[21];
    int ct;
} v[101];
int main()
{
    f.getline(s,1001);
    ls=strlen(s);
    while(ls>0&&pi!=0&&pf!=0)
    {
        ls=strlen(s);
        pi=0;
        pf=0;
        for(i=0; i<ls; i++)
        {
            if(s[i]=='(')
            {
                pi=i;
            }
            else if(s[i]==')')
            {
                pf=i;
                break;
            }
        }
        ///cout<<pi<<" "<<pf<<'\n';
        lcv=-1;
        ct=0;
        for(i=pi+1; i<pf; i++)
        {
            ch=s[i];
            if(ch>='a'&&ch<='z')
            {
                lcv++;
                cv[lcv]=ch;
            }
            else if(ch>='0'&&ch<='9')
            {
                ct=ct*10+(ch-48);
            }
            else if (ch==' '&&s[i-1]!=' '&&i-1>=0)
            {
                if(s[i-1]>='a'&&s[i-1]<='z')///daca am avut cuvant
                {
                    char cx[21]="";///cuvantul devine nul
                    for(j=0; j<=lcv; j++)
                    {
                        cx[j]=cv[j];   ///copiez cuvantul lit cu lit in cx
                    }
                    for(j=0; j<=lv; j++) ///caut pe cx in vectorul v
                        if(strcmp(v[j].cv,cx)==NULL)
                        {
                            pcv=j;    ///daca il gas. ii retin pcv
                            break;
                        }
                    if(j>lv)
                    {
                        lv++;    ///daca nu il gasesc il adaug la sf lui v
                        strcpy(v[j].cv,cx);
                        v[j].ct=0;
                        pcv=lv;
                    }
                    lcv=-1;
                }
                else ///daca am o cantitate
                {
                    v[pcv].ct+=ct;
                    ct=0;
                }

            }
        }
        if(s[pf-1]>='0'&&s[pf-1]<='9')
        {
            v[pcv].ct+=ct;   ///daca am ) la sf actualizez
        }
        ///trebuie sa caut numarul
        t=0;
        for(i=pf+1; i<ls; i++)
        {
            ch=s[i];
            if(ch>='0'&&ch<='9')
            {
                t=t*10+(ch-48);
            }
            else if(t>0)
            {
                break;   ///daca am format timpul si am altceva in afara de spatii ma opresc
            }
        }
        tt+=t;
        pf=i;///pana aici tai
        strcpy(s+pi,s+pf);
        //cout<<s<<" "<<tt<<'\n';
    }
    g<<tt<<'\n';
    while(srt==0)
    {
        srt=1;
        for(i=0; i<lv; i++)
        {
            if(strcmp(v[i].cv,v[i+1].cv)>0)
            {
                swap(v[i],v[i+1]);
                srt=0;
            }
        }
    }
    for(i=0; i<=lv; i++)
    {
        g<<v[i].cv<<" "<<v[i].ct<<'\n';
    }
    ///strcpy(s,s+74);ls=strlen(s);cout<<s<<" "<<ls;
    return 0;
}
