#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream f("expresie.in");
ofstream g("expresie.out");
char s[100001]="",upd,c,snr[4];
int l,i,ctn=0,in,sf,lv=-1,maxim,sum=0;
short nr=0,v[50001],semn=1;
float x=1024;
bool srt,gata=0,ok;
int main()
{   f>>s;
///cout<<(sizeof(s)/x)/x;

 l=strlen(s);
 for(i=0;i<l;i++){
    c=s[i];
    if(c>='0'&&c<='9'){
    nr=nr*10+c-48;
    }else{
    if(nr>0){
    ctn++;
    }
    nr=0;
    }
   }
 cout<<ctn<<'\n';
///strcpy(s+6,s+18);///a=b
//cout<<s;
while(gata==0){
    in=0;
    sf=0;
    for(i=0;i<l;i++){
        c=s[i];
       ///caut pozitiile de in si sf ale parantezelor
        if(c=='('){
        upd='(';
        in=i;
        }else if(c=='['){
         upd='[';
         in=i;
         }else if(upd=='('&&c==')'){
         sf=i;
         break;
         }else if(upd=='['&&c==']'){
         sf=i;
         break;
         }
       }
    lv=0;
    semn=1;
    nr=0;
    for(i=in;i<=sf;i++){
    c=s[i];
    if(c>='0'&&c<='9'){
    nr=nr*10+c-48;
    }else if(c=='-'){
    semn=-1;
    }else{
    if(nr>0){
     lv++;
     v[lv]=nr*semn;
    }
     nr=0;
     semn=1;
    }
    }
    if(upd=='['){
     srt=0;
     ok=0;
     while(srt==0){
     srt=1;
      for(i=1;i<lv;i++){
        if(v[i]>v[i+1]){
     swap(v[i],v[i+1]);
     srt=0;
     }
     }
     }
     nr=v[(lv+1)/2];

     itoa(nr,snr,10);///transforma un int in char
     l=strlen(snr);
     for(i=0;i<l;i++){
     s[in]=snr[i];
     in++;
     }
     strcpy(s+in,s+sf+1);///cout<<s;
     }else{///caz paranteze rotunde
      ok=1;
      maxim=sum;
      for(i=1;i<=lv;i++){
      int x;
      x=v[i];
      if(sum+x<x){
      sum=x;
      }else {
      sum+=x;
      }
       if(sum>maxim){
       maxim=sum;
       }
       }
       itoa(maxim,snr,10);
       l=strlen(snr);
       for(i=0;i<l;i++){
       s[in]=snr[i];
       in++;
       }
     strcpy(s+in,s+sf+1);
     }
 l=strlen(s);
 if(l==0&&ok==0){
  cout<<nr;
  gata=1;
 }else if(l==0&&ok==1){
  cout<<maxim;
  gata=1;
  }
 if(in==0&&sf==0){
   int ss=0;
   for(i=1;i<=lv;i++){
    ss+=v[i];}
    cout<<ss;
    gata=1;
 }

}

}
