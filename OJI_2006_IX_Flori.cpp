#include <iostream>
#include <fstream>
using namespace std;
ifstream f("5-flori.in");
ofstream g("flori.out");
struct buchet
{
    bool v[101];
    int ng;
} b[101];
int nf,n,i,j,nr,t,id,x,y;
int ng=1;
int main()
{
    f>>nf>>n;
    for(i=1; i<=nf; i++)
    {
        for(j=0; j<=n; j++)
        {
            b[i].v[j]=0;
        }
        b[i].ng=0;
    }
    for(j=1; j<=n; j++) ///citesc primul buchet de flori,il salvez in structura, si stabilesc prima grupa
    {
        f>>nr;
        b[1].v[nr]=1;
    }
    b[1].ng=1;
    for(i=2; i<=nf; i++) ///merg pe la toate grupele si compar amprenta curenta cu cele anterioare
    {
        bool vx[100]= {0};
        for(j=1; j<=n; j++)
        {
            f>>nr;    ///formez pe vx dar si amprenta grupei
            vx[nr]=1;
            b[i].v[nr]=1;
        }
        id=0;
        for(t=1; t<i; t++) ///caut flori identice prin grupele dinainte
        {
            for(j=1; j<=101; j++)
            {
                x=b[i].v[j];
                if(x==1)
                {
                    if(b[t].v[j]==b[i].v[j])
                    {
                        id=1;
                        if(b[i].ng==0)
                        {
                            b[i].ng=b[t].ng;
                        }
                        else
                        {
                            b[t].ng=b[i].ng;
                        }
                    }
                }
            }
        }
        if(id==0)
        {
            ng++;
            b[i].ng=ng;
        }
    }
    for(i=1; i<=nf; i++)
        if(b[i].ng!=0)
        {
            cout<<i<<' ';
            for(j=i+1; j<=nf; j++)
            {
                if(b[i].ng==b[j].ng)
                {
                    cout<<j<<' ';
                    b[j].ng=0;
                }
            }
            cout<<'\n';
        }

}
