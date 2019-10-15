#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("templu.in");
ofstream g("templu.out");
int v,n,l,c,i,np,in,sf,m[51][51],s,a[51],st=0,nr=0,nri=0,cf,lx=0,x[2500],mx=0;
int main()
{  f>>v>>n;
  if(n%2==0){
  np=n/2;
  }else {
  np=n/2+1;
  }
  in=1;
  sf=n;
  for(i=1;i<=np;i++){
    for(c=in;c<=sf;c++){
    m[in][c]=v;
    }
    for(l=in;l<=sf;l++){
    m[l][sf]=v;
    }
    for(c=sf;c>=in;c--){
    m[sf][c]=v;
    }
    for(l=sf;l>=in;l--){
    m[l][in]=v;
    }
    in++;
    sf--;
    v++;
    }

    /*for(l=1;l<=n;l++)
    {for(c=1;c<=n;c++)
      cout<<m[l][c]<<' ';
        cout<<'\n';
     }*/
    //cout<<'\n';

    for(l=1;l<=np;l++){
      s=0;
    for(c=1;c<=n;c++){
      s+=m[l][c];
      a[l]=s;
      //cout<<s<<' ';
     }
      i=n;
      for(l=1;l<=np;l++){
      a[i]=a[l];
      i--;
     }
      for(i=1;i<=n;i++){
      st+=a[i];
     }
        //cout<<st;
      sort(a+1,a+n+1);
      n++;
      a[n]=st;
      for(i=1;i<=n;i++){
      nr=a[i];
      nri=0;
     while(nr>0){
      cf=nr%10;
      nri=nri*10+cf;
      nr=nr/10;
     }
     while(nri>0){
      cf=nri%10;
      lx++;
      x[lx]=cf;
      nri=nri/10;
     }

    }

    for(i=1;i<=lx;i++){
       cout<<x[i];
       cout<<'\n';
    }

   for(i=1;i<=lx;i++){
     if(x[i]*10+x[i+1]>mx){
     mx=x[i]*10+x[i+1];
     }
   }

     cout<<mx;


    return 0;
}
