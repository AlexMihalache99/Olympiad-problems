#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");
int i,j,n,mini,maxi,x;
bool b[250002]= {0};
int main()
{
    f>>n;
    for(i=1; i<=n*n; i++)
    {
        f>>x;
        b[x]=1;
    }
    for(i=1; i<=n*n; i++)
    {
        if(b[i]==0)
        {
            mini=i;
            break;
        }
    }
    for(i=n*n; i>=1; i--)
    {
        if(b[i]==0)
        {
            maxi=i;
            break;
        }
    }
    cout<<mini<<' '<<maxi;


}
