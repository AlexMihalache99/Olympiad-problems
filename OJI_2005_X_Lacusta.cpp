#include <iostream>
#include <fstream>
using namespace std;
ifstream f("0-lacust.in");
ofstream g("lacusta.out");
unsigned short int nl,nc,l,c,m[251][251],i,j,sum,minim,lx,cx,s[251][251];
bool ok;
int main()
{
    f>>nl>>nc;
    for(l=1; l<=nl; l++)
    {
        for(c=1; c<=nc; c++)
        {
            f>>m[l][c];
        }
    }
    for(i=1; i<nl; i++)
    {
        for(j=1; j<=nc; j++)
        {
            if(i==1&&j==1);
            else
            {
                s[i][j]=m[i][j]+m[i+1][j];
            }
        }
        sum=m[1][1];
        l=1;
        c=1;
        for(i=1; i<nl; i++)
        {
            ok=0;
            minim=260;
            for(j=1; j<=nc; j++)
                if((i!=l||j!=c)&&minim>s[i][j])
                {
                    minim=s[i][j];
                    lx=i+1;
                    cx=j;
                    ok=1;
                }
            sum+=minim;
            if(ok==1)
            {
                l=lx;
                c=cx;
            }
            else
            {
                l=i+1;
                c=cx-i+1;
            }
        }
        sum+=m[nl][nc];
        g<<sum<<'\n';



    }
