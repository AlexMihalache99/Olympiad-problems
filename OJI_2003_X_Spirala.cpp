#include <iostream>
#include <fstream>
using namespace std;
ifstream f("spirala.in");
ofstream g("spirala.out");
int n,k,m[51][51],mi[51][51],l,c,nr=0,in,sf,v[2601],kp,i,npi=0,ni=-1;///nr de pozitii identice
int main()
{
    f>>n>>k;
    kp=n*n;
///generez matricea initiala
    for(l=1; l<=n; l++)
    {
        if(l%2==1)
            for(c=1; c<=n; c++)
            {
                nr++;
                mi[l][c]=nr;
            }
        else
        {
            for(c=n; c>=1; c--)
            {
                nr++;
                mi[l][c]=nr;
            }
        }
    }
    for(l=1; l<=kp; l++)
    {
        v[l]=l;
    }
///de aici incep generalizarea
    while(npi!=k)
    {
        nr=0;
        ni++;
        for(l=1; l<=n; l++)
        {
            if(l%2==1)
            {
                for(c=1; c<=n; c++)
                {
                    nr++;
                    m[l][c]=v[nr];
                }
            }
            else
            {
                for(c=n; c>=1; c--)
                {
                    nr++;
                    m[l][c]=v[nr];
                }
            }
        }
        npi=0;
        if(ni>0)
        {
            for(l=1; l<=n; l++)
            {
                for(c=1; c<=n; c++)
                {
                    if(m[l][c]==mi[l][c])
                    {
                        npi++;
                    }
                }
            }
        }
        if(npi!=k)
        {
            in=1;
            sf=n;
            nr=0;
            while(in<sf)
            {
                for(c=in; c<sf; c++)
                {
                    nr++;
                    v[nr]=m[in][c];
                }
                for(l=in; l<sf; l++)
                {
                    nr++;
                    v[nr]=m[l][sf];
                }
                for(c=sf; c>in; c--)
                {
                    nr++;
                    v[nr]=m[sf][c];
                }
                for(l=sf; l>in; l--)
                {
                    nr++;
                    v[nr]=m[l][in];
                }
                in++;
                sf--;
            }
        }
    }
    g<<ni;
}
