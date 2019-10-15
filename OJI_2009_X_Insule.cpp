#include <iostream>
#include <fstream>
using namespace std;
ifstream f("insule.in");
ofstream g("insule.out");
struct punct
{
    char c;
    int i;
};
typedef punct harta[101][101];
harta m;
///typedef int vect[100];vect v;
int nl,nc,l,c,in,sf,ct1=0,ct2=0,ct3=0,lmin=10000000,ln;
struct coada
{
    int l;
    int c;
} cd[10202]; ///sem=1=>cand intalnesc pe 2 ma opresc
inline void lee(int i,int j,char a,harta &m)
{
    int l,c,v;
    in=0;
    sf=0;
    v=a-48;
    m[i][j].i=v;
    cd[in].l=i;
    cd[in].c=j;
    while(in<=sf)
    {
        l=cd[in].l;
        c=cd[in].c;///iau linia si coloana inceputului din coada
        ///v=m[l][c].i;///afluu valoarea inceputului de coada
        ///caut vecinii inceputului
        if(l-1>=1) ///daca nu iese afara
        {
            if(m[l-1][c].c==a&&m[l-1][c].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c;///am adaugat in coada
                m[l-1][c].i=v;
            }
        }
        if(l+1<=nl) ///daca nu iese afara
        {
            if(m[l+1][c].c==a&&m[l+1][c].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c;///am adaugat in coada
                m[l+1][c].i=v;
            }
        }
        if(c-1>=1)///daca nu iese afara
            if(m[l][c-1].c==a&&m[l][c-1].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l;
                cd[sf].c=c-1;///am adaugat in coada
                m[l][c-1].i=v;
            }
        if(c+1<=nc) ///daca nu iese afara
        {
            if(m[l][c+1].c==a&&m[l][c+1].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l;
                cd[sf].c=c+1;///am adaugat in coada
                m[l][c+1].i=v;
            }
        }
        in++;///elimin din coada elementul pentru care am studiat vecinii
    }
    if(a=='1')
    {
        ct1++;
    }
    else if(a=='2')
    {
        ct2++;
    }
    else if(a=='3')
    {
        ct3++;
    }
}
inline int lee(int i,int j,harta &m)
{
    int l,c,v,ib=0;
    in=0;
    sf=0;
    v=1;
    m[i][j].i=v;
    cd[in].l=i;
    cd[in].c=j;
    while(in<=sf)
    {
        l=cd[in].l;
        c=cd[in].c;///iau linia si coloana inceputului din coada
        v=m[l][c].i;///afluu valoarea inceputului de coada
        ///caut vecinii inceputului
        if(l-1>=1)///daca nu iese afara
        {
            if(m[l-1][c].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l-1;
                cd[sf].c=c;///am adaugat in coada
                m[l-1][c].i=v+1;
            }
            else if(m[l-1][c].i==2)
            {
                ib=1;
                break;
            }
        }
        if(l+1<=nl)///daca nu iese afara
        {
            if(m[l+1][c].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l+1;
                cd[sf].c=c;///am adaugat in coada
                m[l+1][c].i=v+1;
            }
            else if(m[l+1][c].i==2)
            {
                ib=1;
                break;
            }
        }
        if(c-1>=1)///daca nu iese afara
        {
            if(m[l][c-1].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l;
                cd[sf].c=c-1;///am adaugat in coada
                m[l][c-1].i=v+1;
            }
            else if(m[l][c-1].i==2)
            {
                ib=1;
                break;
            }
        }
        if(c+1<=nc)///daca nu iese afara
        {
            if(m[l][c+1].i==0)///daca face parte din insula
            {
                sf++;
                cd[sf].l=l;
                cd[sf].c=c+1;///am adaugat in coada
                m[l][c+1].i=v+1;
            }
            else if(m[l][c+1].i==2)
            {
                ib=1;
                break;
            }
        }
        in++;///elimin din coada elementul pentru care am studiat vecinii
    }
///sterg urmele pe unde am trecut
    for(in=0; in<=sf; in++)
    {
        m[cd[in].l][cd[in].c].i=0;
    }
    if(ib==1)
    {
        return v+1;
    }
    else
    {
        return 10000009;
    }
}
int main()
{
    f>>nl>>nc;
    for(l=1; l<=nl; l++)
        for(c=1; c<=nc; c++)
        {
            f>>m[l][c].c;
            m[l][c].i=0;
        }

    for(l=1; l<=nl; l++)
    {
        for(c=1; c<=nc; c++)
        {
            if(m[l][c].c!='0'&&m[l][c].i==0)
            {
                lee(l,c,m[l][c].c,m);
            }
        }
    }
    cout<<ct1<<" "<<ct2<<" "<<ct3<<" ";
    for(l=1; l<=nl; l++)
    {
        for(c=1; c<=nc; c++)
        {
            if(l==6&&c==5)
            {
                in=1;
                if(m[l][c].i==0)
                {
                    if(m[l-1][c].i==1||m[l+1][c].i==1||m[l][c+1].i==1||m[l][c-1].i==1)
                    {
                        ln=lee(l,c,m);
                        if(ln<lmin)lmin=ln;
                    }
                }
            }
        }
    }
}
cout<<lmin;
/*for(l=1;l<=nl;l++)
 {for(c=1;c<=nc;c++)
  cout<<m[l][c].i<<' ';
     cout<<'\n';}*/

}
