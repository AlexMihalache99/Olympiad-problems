#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream f("par.in");
ofstream g("paritate.out");
char s[48500000]="";
int l,i,j,nr,p;
bool ok=0,o=1;
int main()
{
    f>>s;
    l=strlen(s);
    if(l%8==0)
    {
        for(i=0; i<l; i+=8)
        {
            ok=0;
            for(j=i+1; j<=i+7; j++)
            {
                if(s[j]=='1')
                {
                    ok=ok-1;
                }
            }
            if(ok!=s[i]-48&&o)
            {
                o=0;
                g<<"NU\n"<<i/8<<" ";
            }
            else if(ok!=s[i]-48&&o==0)
            {
                g<<i/8<<" ";
            }
        }
        if(o)
        {
            g<<"DA"<<"\n";
            for(i=0; i<l; i+=8)
            {
                p=1;
                nr=0;
                for(j=i+7; j>=i+1; j--)
                {
                    nr+=(s[j]-48)*p;
                    p*=2;
                }
                g<<char(nr);
            }
        }
    }
}
