#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lanterna.in");
ofstream g("lanterna.out");
#define INFINITY 99999999
typedef struct
{
    int in, sf, ds,w;
} muchie;
struct dis_con
{
    int d;
    int c;
};
int n,nm,k,i,cmax=0;
bool vp[56];
muchie vm[1300];
dis_con d[56];
void bellman_ford(int s)
{
    int i, j;
    for (i =1; i <=n; i++)
        d[i].d = INFINITY;
    d[1].d = 0;
    for (i =1; i <n ; ++i)
    {
        for (j = 1; j<=nm; ++j)
        {
            if (d[vm[j].in].d + vm[j].ds < d[vm[j].sf].d)d[vm[j].sf].d = d[vm[j].in].d + vm[j].ds;
            if(d[vm[i].w].c + vm[j].w <=k)
            {
                if(vp[j]==1)
                {
                    d[vm[i].w].c=0;
                }
                else
                {
                    d[vm[i].w].c+=vm[j].w;
                }
                if(d[vm[i].w].c>cmax)
                {
                    cmax=d[vm[i].w].c;
                }

            }
        }
    }
}
int main()
{
    f>>n>>k;
    for(i=1; i<=n; i++)
    {
        f>>vp[i];
    }
    f>>nm;
    for (i = 1; i <=nm; i++)
    {
        f>>vm[i].in>>vm[i].sf>>vm[i].ds>>vm[i].w;
    }


    bellman_ford(0);

    g<<d[n].d<<" "<<cmax;
    return 0;
}
