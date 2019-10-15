#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream f("cifre.in");
ofstream g("cifre.out");
struct date{
    int l;
    int r;
    char n[11];
}v[100001];///r-ramas

int a[10]={0},n,i,l,j,tcf=0,cf=9,ct,r;
bool srt=0;
char c;
long long int s=0;
int main()
{   f>>n;
 for(i=1;i<=n;i++){
  char nr[11]="";
  f>>nr;
  l=strlen(nr);
  v[i].l=l;v[i].r=0;
  for(j=0;j<l;j++){
  a[nr[j]-48]++;
  tcf++;
  }
 }
while(srt==0){
  srt=1;
  for(i=1;i<n;i++){
   if(v[i].l<v[i+1].l){
    swap(v[i],v[i+1]);
    srt=0;
    }
   }
 }
 i=1;
 while(tcf>0){
   while(a[cf]==0){
    cf--;
   }
  ct=a[cf];
  c=char(cf+48);
  l=v[i].l;
  while(l==v[i].l&&ct>0){
        r=v[i].r;///extrag ramasita
        v[i].n[r]=c;///introduc cifra
        ct--;///scad nr de cifre cf
        v[i].r++;///cresc ramasita
        v[i].l--;///scad lungimea numarului
        i++;///trec la urmatorul nr
        a[cf]--;///scad nr de ap al lui cf
        tcf--;///scad totalul de cifre
  }
  if(l!=v[i].l){
    i=1;
  }///daca am iesit din while
  ///din cauza ca am trecut la numere cu nr de cifre mai mic decat cele initiale
  ///in exemplu prob de la nr cu 4 cifre la nr cu 3 cifre
  /// luam totul de la capat pana terminam toata categoria cu 4 cifre
}
/// in cazul in care formam numere care sa inceapa cu 0 si cu minim 2 cifre le modificam
for(i=n;i>=1;i--){
 if(v[i].n[0]=='0'&&v[i].r>1){
    l=v[i].r;
    for(j=i-1;j>=1;j--){
        if(v[j].r>l&&v[j].n[v[j].r-l]!='0'){
           v[i].n[0]=v[j].n[v[j].r-l];///luam cifre de la numere cu lungimea mai mare decat a numarului gresit
           v[j].n[v[j].r-l]='0';
           break;
          }
     }
}
}
     for(i=1;i<=n;i++){
      s+=atoi(v[i].n);
      g<<s<<'\n';
     }
        for(i=1;i<=n;i++){
      g<<v[i].n<<'\n';
      }

}
