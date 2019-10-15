#include <iostream>
#include <fstream>
using namespace std;
ifstream f("placare.in");
ofstream g("placare.out");
int nl,nc,l,c,m[300][300]= {{0},{0}},nr,i;
int main()
{
    f>>nl>>nc;
    for(l=0; l<nl; l++)
    {
        for(c=0; c<nc; c++)
        {
            while(m[l][c]==0)
            {
                f>>nr;
                if(nr>0)
                {
                    int cx=nr+c-1;
                    for(i=c; i<=cx; i++)
                    {
                        m[l][i]=nr;
                    }
                }

                else if(nr<0)
                {
                    nr=-nr;
                    int lx=nr+l-1;
                    for(i=l; i<=lx; i++)
                    {
                        m[i][c]=nr;
                    }
                }
            }
        }
    }
    for(l=0; l<nl; l++)
    {
        for(c=0; c<nc; c++)
        {
            g<<m[l][c]<<' ';
        }
        g<<'\n';
    }

    return 0;
}
