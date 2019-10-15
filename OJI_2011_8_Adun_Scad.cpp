#include <iostream>
#include <fstream>
#include <cstdlib>///aici se gasec functiile atoi si itoa
#include <cstring>
using namespace std;
ifstream f("adunscad.in");
ofstream g("adunscad.out");
int s,n,i,sc,v[20],in=1,sf=1,j,nr,semn,sol=0;
char sm[20]="";
int main()
{
    f>>s>>n;
 for(i=0;i<n;i++){
   f>>v[i];
 }
 for(i=1;i<n;i++){
    in*=2;
 }
 sf=in*2;

 for(i=in;i<sf;i++){
  itoa(i,sm,2);
  sc=0;
  ///calculez suma cand am 1 la + si 0 la -
  for(j=0;j<n;j++){
    if(sm[j]=='1'){
        semn=1;
    }else {
     semn=-1;
    }
    sc+=v[j]*semn;
  }
  if(sc==s){
      sol=1;
      break;
  }
  sc=0;
  ///calculez suma cand am 1 la - si 0 la +
  for(j=0;j<n;j++)
  {if(sm[j]=='1'){
      semn=-1;
      }else {
       semn=1;
      }
    sc+=v[j]*semn;
  }
  if(sc==s){
    sol=2;
    break;
    }
  }
if(sol==1){
  for(j=0;j<n;j++)
     if(sm[j]=='0'){
       v[j]*=-1;
     }
}
if(sol==2){
  for(j=0;j<n;j++)
     if(sm[j]=='1'){
        v[j]*=-1;
     }
}
if(sol>0)
 {for(j=0;j<n;j++)
   if(j==0||v[j]<0){
        g<<v[j];
   }else {
    g<<"+"<<v[j];
   }
 }else g<<0;

}
