#include <iostream>
#include <fstream>
using namespace std;
ifstream f("16-secven.in");
ofstream g("secvente.out");
int nsec,n,nr,p,k,i,j,ok,s,nrs;
bool v[30003]= {0};
struct inf
{
    bool d;
} b[30003];
struct solutie
{
    int in;
    int sf;
} vs[15010];
int main()
{
    v[0]=1;
    v[1]=0;
    for(i=2; i<=180; i++)
    {
        if(v[i]==0)
        {
            for(j=i*i; j<=30000; j+=i)
            {
                v[j]=1;
            }
        }
    }
    f>>nsec;
    for(i=1; i<=nsec; i++)
    {
        nrs=0;
        f>>n>>p>>k;
        for(j=1; j<=n; j++)
        {
            f>>nr;
            if(nr==1)
            {
                b[j].d=0;
            }
            else
            {
                while(nr%p==0)
                {
                    nr/=p;
                }
                if(v[nr]==0)
                {
                    b[j].d=1;
                }
            }
        }
        for(int x=1; x<=n; x++)
            if(b[x].d==1)
            {
                j=x;
                s=1;
                while(j<n&&s<k)
                {
                    j++;
                    if(b[j].d==1)
                    {
                        s++;
                    }
                }
                if(s==k)
                {
                    nrs++;
                    vs[nrs].in=x;
                    vs[nrs].sf=j;
                }
            }
        g<<nrs<<'\n';
        for(j=1; j<=nrs; j++)
        {
            g<<vs[j].in<<" "<<vs[j].sf<<'\n';
        }

    }
}
