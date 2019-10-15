#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("pluton.in");
ofstream g("pluton.out");
struct soldat
{
    int v[10];
    int ne;
    int np;
    char plc[10];
} v[4000];
int n,i,j,nr,l,t,id,np=1,nemax,npmax,ctmax=0,ns,ap[4000]= {0};
int main()
{
    f>>n;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=9; j++)
        {
            v[i].v[j]=0;
        }
        v[i].np=0;
        v[i].ne=0;
        strcpy(v[i].plc,"");
    }

    for(i=1; i<=n; i++)
    {
        char s[10]="",ch;
        f>>s;
        l=strlen(s);
        for(j=0; j<l; j++) ///am citit soldatul
        {
            ch=s[j];
            nr=ch-48;
            v[i].v[nr]++;
        }
        v[i].ne=l;
        id=0;
        strcpy(v[i].plc,s);
        if(i==1)
        {
            v[i].np=1;
            id=1;
        }
        for(t=i-1; t>=1; t--) ///caut daca se afla in plutoanele dinainte
        {
            id=1;
            if(v[i].ne==v[t].ne)///daca au acelas numar de elemente
            {
                for(j=0; j<=9; j++)
                {
                    if(v[i].v[j]!=v[t].v[j])
                    {
                        id=0;
                        break;
                    }
                }
            }
            else id=0;
            if(id==1)
            {
                v[i].np=v[t].np;;
                break;
            }
        }
        if(id==0)
        {
            np++;
            v[i].np=np;;
        }
    }
    cout<<np<<'\n';
    nemax=0;
    npmax=0;
    for(i=1; i<=n; i++)
    {
        ap[v[i].np]++;
    }
    for(i=1; i<=n; i++)
    {
        if(ap[i]>nemax)
        {
            nemax=ap[i];
            npmax=i;
            ctmax=0;
        }
        if(ap[i]==nemax)
        {
            ctmax++;
        }
    }
    cout<<nemax<<'\n';
    cout<<ctmax<<'\n';
    for(i=1; i<=n; i++)
    {
        if(v[i].np==npmax)
        {
            cout<<v[i].plc<<" ";
        }
    }




    return 0;
}
