#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("text.in");
ofstream g("text.out");
int m,l,i,x[50],j,k=-1,lcv,ss=0,ls,spatii;
char s[1009],cv[26],cx[1];
bool ok;
struct cuvinte
{
    char cv[26];
    int l;
} v[50];
int main()
{
    f>>m;
    f.getline(s,1002);
    cx[0]=' ';
    while(f.getline(s,1002))
    {

        strcat(s,cx);
        l=strlen(s);
        lcv=-1;
        k=-1;
        for(i=0; i<l; i++)
        {
            if(s[i]==' '&&s[i-1]!=' ')
            {
                k++;
                for(j=0; j<=lcv; j++)
                {
                    v[k].cv[j]=cv[j];
                }
                v[k].l=lcv;
                x[k]=lcv+1;
                lcv=-1;
            }
        }
        else if(s[i]!=' ')
        {
            lcv++;
            cv[lcv]=s[i];
        }
        ss=0;
        for(j=0; j<=k; j++)
        {
            ss+=x[j];
            if(ss>m)
            {
                ss-=x[j];
                spatii=(m-ss)/(j-1);
                ls=j-1;
                ok=0;
                break;
            }
            if(j==k&&ss<m)
            {
                ok=1;
                for(j=0; j<=k; j++)
                {
                    for(i=0; i<x[j]; i++)g<<v[j].cv[i];
                    g<<" ";
                }
                g<<'\n';
            }
        }
        if(ok==0)
        {
            for(j=0; j<=k; j++)
            {
                if(j<ls+1)
                {
                    for(i=0; i<x[j]; i++)g<<v[j].cv[i];
                    for(i=1; i<=spatii; i++)g<<" ";
                }
                else if(j==ls+1)
                {
                    g<<'\n';
                    for(i=0; i<x[j]; i++)g<<v[j].cv[i];
                    g<<" ";
                }
                else for(i=0; i<x[j]; i++)g<<v[j].cv[i];
                g<<" ";
            }
        }
    }
}
