#include <iostream>
#include <fstream>
using namespace std;
ifstream f("0-reactivi.in");
ofstream g("reactivi.out");
struct inf
{
    short i;
    short s;
} v[8001],s[8000];
int n,i,ls=1,in,sf,j,a,b,minim,maxim;
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
            else
            {
                if(v[i].i==v[i+1].i)
                    if(v[i].s>v[i+1].s)
                    {
                        swap(v[i],v[i+1]);
                        srt=0;
                    }
            }
        }
    }
    s[1]=v[1];
    for(i=2; i<=n; i++)
    {
        in=v[i].i;
        sf=v[i].s;
        int amfin=0;
        for(j=1; j<=ls; j++)
        {
            a=s[j].i;
            b=s[j].s;
            maxim=max(a,in);
            minim=min(b,sf);
            if(maxim<=minim)
            {
                s[j].i=maxim;
                s[j].s=minim;
                amfin=1;
                break;
            }
        }
        if(amfin==0)
        {
            ls++;
            s[ls].i=in;
            s[ls].s=sf;
        }

    }
    cout<<ls;
}
