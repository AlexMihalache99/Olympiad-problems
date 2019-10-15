#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pluricex.in");
ofstream g("pluricex.out");
struct inf
{
    short d;
    short v[11];
} v[25];
int st[100]= {0},n,k,d,i,j,cm;
inline bool valid(int p)
{
    int i;
    for(i=1; i<p; i++)
    {
        if(st[p]<=st[i])
        {
            return 0;
        }
    }
    return 1;
}
inline void tipar(int p)
{
    int i,j,dx,ok=1;
    bool b[11]= {0};
    for(i=1; i<=p; i++)
    {
        dx=v[st[i]].d;
        for(j=1; j<=dx; j++)
        {
            b[v[st[i]].v[j]]=1;
        }
    }
    for(i=1; i<=d; i++)
        if(b[i]==0)
        {
            ok=0;
            break;
        }
    if(ok)
    {
        for(i=1; i<=p; i++)
        {
            g<<st[i]<<" ";
        }
        g<<'\n';
    }
}
inline void backp()
{
    int p=1;
    st[p]=0;
    while(p>0)
    {
        if(st[p]<n)
        {
            st[p]++;
            if(valid(p))
            {
                if(p==k) tipar(p);
                else
                {
                    p++;
                    st[p]=0;
                }
            }

        }
        else p--;
    }

}
int main()
{
    f>>n>>k>>d;
    for(i=1; i<=n; i++)
    {
        f>>cm;
        for(j=1; j<=cm; j++)
        {
            f>>v[i].v[j];
        }
        v[i].d=cm;
    }
    backp();

}

