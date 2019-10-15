#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("rj.in");
ofstream g("rj.out");
char s[101]="";
int nl,nc,l,c,in,sf,i,j,v=0,lr,cr,lj,cj,li,ci,vi;
struct romeojulieta
{
    int r;
    int j;
} m[101][101];
struct coada
{
    int l;
    int c;
} cd[10202];
int main()
{
    f>>nl>>nc;
    f.getline(s,100);
    for(i=0; i<nl; i++)
    {
        f.getline(s,100);
        l=strlen(s);
        for(j=0; j<l; j++)
        {
            if(s[j]==' ')
            {
                m[i][j].r=0;
                m[i][j].j=0;
            }
            else if(s[j]=='X')
            {
                m[i][j].r=-1;
                m[i][j].j=-1;
            }
            else if(s[j]=='R')
            {
                lr=i;
                cr=j;
            }
            else if(s[j]=='J')
            {
                lj=i;
                cj=j;
            }
        }
    }



    in=0;
    sf=0;
    m[lr][cr].r=1;
    cd[in].l=lr;
    cd[in].c=cr;
    while(in<=sf)
    {
        l=cd[in].l;
        c=cd[in].c;
        v=m[l][c].r;
        if(l-1>=0)
        {
            if(m[l-1][c].r==0)
            {
                m[l-1][c].r=v+1;
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c;
            }
        }
        if(l+1<nl)
        {
            if(m[l+1][c].r==0)
            {
                m[l+1][c].r=v+1;
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c;
            }
        }
        if(c-1>=0)
        {
            if(m[l][c-1].r==0)
            {
                m[l][c-1].r=v+1;
                sf++;
                cd[sf].l=l;
                cd[sf].c=c-1;
            }
        }
        if(c+1<nc)
        {
            if(m[l][c+1].r==0)
            {
                m[l][c+1].r=v+1;
                sf++;
                cd[sf].l=l;
                cd[sf].c=c+1;
            }
        }
        if(l+1<nl&&c+1<nc)
        {
            if(m[l+1][c+1].r==0)
            {
                m[l+1][c+1].r=v+1;
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c+1;
            }
        }
        if(l+1<nl&&c-1>=0)
        {
            if(m[l+1][c-1].r==0)
            {
                m[l+1][c-1].r=v+1;
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c-1;
            }
        }
        if(l-1>=0&&c+1>nc)
        {
            if(m[l-1][c+1].r==0)
            {
                m[l-1][c+1].r=v+1;
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c+1;
            }
        }
        if(l-1>=0&&c-1>=0)
        {
            if(m[l-1][c-1].r==0)
            {
                m[l-1][c-1].r=v+1;
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c-1;
            }
        }
        in++;

    }


    in=0;
    sf=0;
    m[lj][cj].j=1;
    cd[in].l=lj;
    cd[in].c=cj;
    while(in<=sf)
    {
        l=cd[in].l;
        c=cd[in].c;
        v=m[l][c].j;
        if(l-1>=0)
        {
            if(m[l-1][c].j==0)
            {
                m[l-1][c].j=v+1;
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c;
                if(m[l-1][c].j==m[l-1][c].r)
                {
                    vi=v+1;
                    li=l-1;
                    ci=c;
                    break;
                }
            }
        }
        if(l+1<nl)
        {
            if(m[l+1][c].j==0)
            {
                m[l+1][c].j=v+1;
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c;
                if(m[l+1][c].j==m[l+1][c].r)
                {
                    vi=v+1;
                    li=l+1;
                    ci=c;
                    break;
                }
            }
        }
        if(c-1>=0)
        {
            if(m[l][c-1].j==0)
            {
                m[l][c-1].j=v+1;
                sf++;
                cd[sf].l=l;
                cd[sf].c=c-1;
                if(m[l][c-1].j==m[l][c-1].r)
                {
                    vi=v+1;
                    li=l;
                    ci=c-1;
                    break;
                }
            }
        }
        if(c+1<nc)
        {
            if(m[l][c+1].j==0)
            {
                m[l][c+1].j=v+1;
                sf++;
                cd[sf].l=l;
                cd[sf].c=c+1;
                if(m[l][c+1].j==m[l][c+1].r)
                {
                    vi=v+1;
                    li=l;
                    ci=c+1;
                    break;
                }
            }
        }
        if(l+1<nl&&c+1<nc)
        {
            if(m[l+1][c+1].j==0)
            {
                m[l+1][c+1].j=v+1;
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c+1;
                if(m[l+1][c+1].j==m[l+1][c+1].r)
                {
                    vi=v+1;
                    li=l+1;
                    ci=c+1;
                    break;
                }
            }
        }
        if(l+1<nl&&c-1>=0)
        {
            if(m[l+1][c-1].j==0)
            {
                m[l+1][c-1].j=v+1;
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c-1;
                if(m[l+1][c-1].j==m[l+1][c-1].r)
                {
                    vi=v+1;
                    li=l+1;
                    ci=c-1;
                    break;
                }
            }
        }
        if(l-1>=0&&c+1<nc)
        {
            if(m[l-1][c+1].j==0)
            {
                m[l-1][c+1].j=v+1;
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c+1;
                if(m[l-1][c+1].j==m[l-1][c+1].r)
                {
                    vi=v+1;
                    li=l-1;
                    ci=c+1;
                    break;
                }
            }
        }
        if(l-1>=0&&c-1>=0)
        {
            if(m[l-1][c-1].j==0)
            {
                m[l-1][c-1].j=v+1;
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c-1;
                if(m[l-1][c-1].j==m[l-1][c-1].r)
                {
                    vi=v+1;
                    li=l-1;
                    ci=c-1;
                    break;
                }
            }
        }
        in++;

    }
    g<<vi<<" "<<li+1<<" "<<ci+1;

}
