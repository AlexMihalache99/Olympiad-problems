#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euro.in");
ofstream g("euro.out");
const int inf=1<<30;
int t,n,vmax;
int val[4002],sol[8002],dif[8002];
int s;
int main()
{
    int i,j,k,x,y;
    f>>t;
    for(k=1; k<=t; k++)
    {
        f>>n>>vmax;
        for(i=1; i<=n; i++)
        {
            f>>val[i];
        }
        sort(val+1,val+n+1);
        for(i=1; i<=vmax; i++)
        {
            sol[i]=inf;
        }
        for(i=1; i<=n; i++)
        {
            sol[val[i]]=0;
            dif[val[i]]=val[i];
        }
        for(i=1; i<n; i++)
        {
            x=val[i];
            s=val[i];
            for(j=i+1; j<=n; j++)
            {
                y=val[j];
                s+=val[j];
                if(x+y<=vmax&&sol[x+y]>y-x)
                {
                    sol[x+y]=y-x;
                }
                if(s<=vmax&&sol[s]>y-x)
                {
                    sol[s]=y-x;
                }
            }
        }

        for(i=1; i<=vmax; i++)
        {
            if(sol[i]==inf)
            {
                g<<"-1"<<" ";
            }
            else
            {
                g<<sol[i]<<" ";
            }
        }
        //g<<'\n';
    }
}
