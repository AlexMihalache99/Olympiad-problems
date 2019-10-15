#include <iostream>
#include <fstream>
using namespace std;
ifstream f("elicop.in");
ofstream g("elicop.out");
int m[101][101],nl,nc;
int k;
int l1,c1,l2,c2,p;
int nr0,nr1;
int aux;
int N1,N2;
int v[41];
int main()
{  int i,j,t;
    f>>nl>>nc;
   for(i=1;i<=nl;i++){
    for(j=1;j<=nc;j++){
    f>>m[i][j];
    }
   }
     f>>k;

     for(i=1;i<=k;i++)
     {
      f>>l1>>c1>>l2>>c2>>p;
       if(l1>l2){
      swap(l1,l2);
      swap(c1,c2);
      }
        nr1=0;nr0=0;
       if(c1>c2&&p==-1)
       {aux=0;
        for(j=l2;j>=l1;j--)
         {for(t=c2+aux;t<=c1;t++)
          if(m[j][t]==1){
                nr1++;
          }
            else {
                nr0++;
            }
          aux++;
          }
       }
       else if(c1<c2&&p==-1)///jos-stanga
       {  aux=0;
        for(j=l2;j>=l1;j--)
         {for(t=c1+aux;t<=c2;t++)
          if(m[j][t]==1){
                nr1++;
          }
            else {
                nr0++;
            }
          aux++;
          }
       }
       else if(c1<c2&&p==1)///sus-dreapta
       {aux=0;
        for(j=l1;j<=l2;j++)
         {for(t=c1+aux;t<=c2;t++)
          if(m[j][t]==1){
                nr1++;
          }
            else {
                nr0++;
            }
          aux++;
          }
       }
       else if(c1>c2&&p==1)///sus-stanga
       { aux=0;
        for(j=l1;j<=l2;j++)
         {for(t=c2;t<=c1-aux;t++)
          if(m[j][t]==1){
                nr1++;
          }
            else {
                nr0++;
          }
          aux++;
          }
       }
       if(nr0==0){
            N1++;
       }
        if(nr0>nr1){
            N2++;
            v[N2]=i;
       }
    }
      g<<N1<<'\n';
      g<<N2<<" ";
      for(i=1;i<=N2;i++){
        g<<v[i]<<" ";
      }

}
