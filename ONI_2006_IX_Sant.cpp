#include <iostream>
#include <fstream>
using namespace std;
ifstream f("8-sant.in");
ofstream g("sant.out");
struct inf
{
    short i;
    short s;
} v[10009],s[10009];
struct dinf
{
    short p;
    short d;
} x[10009];
short i,n,j,in,sf,ls=1,a,b,minim,maxim,lx=1,z,y;
bool srt=0;
int main()
{
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>v[i].i>>v[i].s;
    }
    while(srt==0)
    {
        srt=1;
        for(i=1; i<n; i++)
        {
            if(v[i].i>v[i+1].i)
            {
                swap(v[i],v[i+1]);
                srt=0;
            }
        }
    }
//for(i=1;i<=n;i++)
    //cout<<v[i].i<<" "<<v[i].s<<'\n';
    s[1]=v[1];
    x[1].p=1;
    x[1].d=1;
    for(i=2; i<=n; i++)
    {
        in=v[i].i;
        sf=v[i].s;
        int amint=0;
        for(j=1; j<=ls; j++)
        {
            a=s[j].i;
            b=s[j].s;
            minim=min(b,sf);
            maxim=max(a,in);
            if(maxim<=minim)
            {
                s[j].i=maxim;
                s[j].s=minim;
                amint=1;
                lx++;
                x[lx].p=j;
                x[lx].d=i;
                break;
            }
        }
        if(amint==0)
        {
            ls++;
            s[ls].i=in;
            s[ls].s=sf;
            lx++;
            x[lx].p=ls;
            x[lx].d=i;
        }
    }
    /*for(i=1;i<=lx;i++)
    {cout<<x[i].p<<" "<<x[i].d;
      cout<<'\n';}*/
    g<<lx-1<<'\n';
    for(i=1; i<=lx; i++)
    {
        z=s[i].s;
        if(z!=0)
        {
            g<<i<<" "<<s[i].i<<" "<<s[i].s;
        }
        g<<'\n';
        for(j=1; j<=lx; j++)
        {
            y=x[j].p;
            if(y==i) g<<x[j].d<<" ";
        }
        g<<'\n';

    }
}
