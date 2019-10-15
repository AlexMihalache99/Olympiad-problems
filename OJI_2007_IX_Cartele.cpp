#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cartele.in");
ofstream g("cartele.out");
typedef char matrice[55][55];
short n,nc,l,c;
matrice m1,m2,m3,m4,m5,m6,m7,m8;
void roti(matrice a,matrice b)
{
    int l,c;
    for(l=1; l<=n; l++)
    {
        for(c=1; c<=n; c++)
        {
            b[c][n-l+1]=a[l][c];
        }
    }


}
int main()
{
    f>>n>>nc;
    for(l=1; l<=n; l++)
    {
        for(c=1; c<=n; c++)
        {
            f>>m1[l][c];
        }
    }
    roti(m1,m2);
    for(l=1; l<=n; l++)
    {
        for(c=1; c<=n; c++)
        {
            cout<<m2[l][c]<<" ";
        }
        cout<<'\n';
    }
}
