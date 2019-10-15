#include <iostream>
#include <fstream>
using namespace std;
ifstream f("maxd.in");
ofstream g("maxd.out");
int n;
int a,b,i,j,nrdiv,contor,mini,v[100001];
bool m[100001]= {0};
int nrd(int x)
{
    int i,nrdiv=0;
    for(i=2; i<=x/2; i++)
    {
        if(x%i==0)
        {
            nrdiv++;
        }
    }
    return nrdiv+2;

}
int main()
{
    f>>a>>b;
    n=10000;
    //cout<<nrd(200);
    m[0]=1;
    m[1]=1;
    for(i=2; i<=n/2; i++)
    {
        if(m[i]==0)
        {
            for(j=i*i; j<=n; j+=i)
            {
                m[j]=1;
            }
        }
    }
    for(i=a; i<=b; i++)
    {
        if(m[i]==0)
        {
            v[i]=2;
        }
        else
        {
            v[i]=nrd(i);
        }
    }
    nrdiv=v[a];
    for(i=a+1; i<=b; i++)
    {
        if(v[i]>nrdiv)
        {
            nrdiv=v[i];
        }
    }
    //cout<<nrdiv;
    for(i=a; i<=b; i++)
    {
        if(v[i]==nrdiv)
        {
            contor++;
        }
    }
    //cout<<contor;
    for(i=a; i<=b; i++)
    {
        if(v[i]==nrdiv)
        {
            mini=i;
            break;
        }
    }
    //cout<<mini;
    cout<<mini<<' '<<nrdiv<<' '<<contor;

}
