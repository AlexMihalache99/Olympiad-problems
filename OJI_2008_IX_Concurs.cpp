#include <iostream>
#include <fstream>
using namespace std;
ifstream f("concurs.in");
ofstream g("concurs.out");
struct elev
{
    int j;
    int e;
} p[501];
int jud[51]= {0};
int nr,i,j,nrj=0,judmax=0,e,srt=0,jx,nrs=0;
int main()
{
    f>>nr;
    for(i=1; i<=nr; i++)
    {
        f>>j>>e;
        p[i].j=j;
        p[i].e=e;
        if(jud[j]==0)
        {
            nrj++;
        }
        jud[j]++;
        if(jud[j]>judmax)
        {
            judmax=jud[j];
            jx=j;
        }
    }
    g<<nrj<<'\n';
    for(i=1; i<=50; i++)
    {
        if(jud[i]!=0)
        {
            g<<jud[i]<<' ';
        }
    }
    g<<'\n';
    while(srt==0)
    {
        srt=1;
        for(i=1; i<nr; i++)
        {
            if(p[i].j!=jx&&p[i+1].j==jx)
            {
                swap(p[i],p[i+1]);
                srt=0;
            }
            else if(p[i].j==jx&&p[i+1].j==jx&&p[i].e>p[i+1].e)
            {
                swap(p[i],p[i+1]);
                srt=0;
            }
            else if(p[i].j>p[i+1].j&&p[i].j!=jx&&p[i+1].j!=jx)
            {
                swap(p[i],p[i+1]);
                srt=0;
            }
            else if(p[i].j==p[i+1].j&&p[i].e>p[i+1].e&&p[i].j!=jx&&p[i+1].j!=jx)
            {
                swap(p[i],p[i+1]);
                srt=0;
            }
        }
    }
    for(i=1; i<=nr; i++)
    {
        cout<<p[i].j<<" "<<p[i].e<<'\n';
    }
    j=judmax+1;
    for(i=1; i<=judmax; i++)
    {
        g<<p[i].j<<" "<<p[i].e<<'\n';
        if(j<=nr)
        {
            g<<p[j].j<<" "<<p[j].e<<'\n';
        }
        j++;
        nrs+=2;
    }
    if(nrs<nr)
    {
        if(p[j].j==p[j-1].j)
        {
            swap(p[j],p[j+1]);
        }
        for(i=j; i<=nr; i++)
        {
            g<<p[i].j<<" "<<p[i].e<<'\n';
        }
    }
    cout<<i<<" "<<j<<" "<<nrs;
}
