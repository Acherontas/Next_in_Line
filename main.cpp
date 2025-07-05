#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int ar[1000];
int xvc=0;
vector<int> xvc_rst;
string mlis;

int fl=0;
int m=0;
int cdi=0;
int cd(int n){
  m=n%10;
  cdi+=m;
  fl=-1;
  if(n/10==0){
     fl=1;
     if(fl==1){}
     return cdi;
  }
  else{
      cd(n/10);
      }
  return cdi;
}

int calc(int aar,int x){
   int tmp=0;
   int ty=-1;
   int incr=10;
   int crti=0;
   int i=0;
   bool fl=false;
   bool kfl=true;
   int y=0;
   int kl=0;
  for(;;){
     for(i=1;i<=aar;i++){
       cdi=0;
       ty=cd(ar[i]);
       if(ty>9){while(ty>9){cdi=0;ty=cd(ty);if(ty<=9){break;}}}
      if(ty==tmp){tmp=0;}
      //cout<<"using main " << ar[i] << " with tmp " << tmp <<" and incr " << incr <<" and i " << i <<"\n";
      cout<<"using main " << ar[i] << " with main cd of "  <<ty <<" and incr " << incr << " -----> ";
      while(ty!=tmp){
        cdi=0;
        //cout<<"internal incr to test "<< incr <<"\n";
        tmp=cd(incr);
        if(tmp>9){while(tmp>9){cdi=0;tmp=cd(tmp);if(tmp<=9){break;}}}
        if(tmp!=ty){incr+=1;
                    //cout<<"increasing to " << incr <<"\n";
                    goto B;}
        if(incr==100){incr=10;break;}
        if(tmp==ty){crti=tmp;
                    //cout<<"exiting with " << tmp << " with incr " << incr <<"\n";
                    break;}
        B:cout<<"";
      }
      cout<<"returning main " << ar[i] << " --> " << incr << "\n";
     // if(kl==0){ xvc_rst.push_back(-2);kl+=1;}
      xvc_rst.push_back(incr);
      xvc+=1;
        if(incr<100){incr=incr+1;}
        if(incr>=100){incr=10;fl=true;break;}
      //cout<<"continuing with incr " << incr <<"\n";
     }
     cout<<"----------------------\n";
     y+=1;//kl=0;
     //xvc_rst.push_back(-2);
     if(x==y){incr=10;fl=true;break;}
    // cout<<"resetting with incr " << incr <<"\n";
     if(fl==true){break;}
  }
  return 0;
}

int check_calc_equal(int one,int two){
  cdi=0;
  int on=0,tw=0;
  on=cd(one);
  if(on>9){while(on>9){cdi=0;on=cd(on);if(on<=9){break;}}}
  cdi=0;
  tw=cd(two);
  if(tw>9){while(tw>9){cdi=0;tw=cd(tw);if(tw<=9){break;}}}
  int rti=0;
  if(on==tw){rti=1;}
  if(on!=tw){rti=2;}
  //cout<<"returning with rti " << rti <<"\n" ;
  return rti;
}

int spl_and_get(int kk){
  //cout<<"using " << kk <<"\n";
  string l;
  l+=to_string(kk);
  //cout<<"to " << l <<"\n";
  char k;
  int lk;
  k=l.at(1);
  lk=stoi(&k);
  //cout<<"returning lk " << lk <<"\n";
  return lk;
}

int show_calc(int xt,int pivt){
   cout<<"xvc " << xvc <<"\n";
   for(int i=0;i<=xvc-1;i++){cout<<xvc_rst.at(i) << " " ;}
   cout<<"\n";
   cout<<"\n";
 /*for(int i=0;i<=xvc-1;i++){
     cout<<xvc_rst.at(i) <<"  ";
     if(xvc_rst.at(i)==-2){cout<<"\n";}
 } */
    int mv=pivt;
    int lv=(xvc/pivt);
    int lm=0;
    int kpvt=0;
    int xti=0;
    int ckci=0;
    cout<<"lv " << lv <<"\n";
    cout<<"pvt "<< pivt <<"\n";
    cout<<"\n";
    int l[pivt][lv];int mn_pvt=1;int rst_rw=0;mlis.clear();int xl_diak=0;int xld;
    for(int i=0;i<=pivt-1;i++){
        ckci=0;
        //cout<<"using xti " << xti << " and lm " << lm <<" @ i " << i << "\n";
        for(int j=0;j<=lv;j++){
           // cout<<"inserting  " << i << "  " << j << " " << xvc_rst.at(lm) <<" @ lm " << lm << " @ xvc " << xvc <<"\n";
            ckci=check_calc_equal(xvc_rst.at(xti),xvc_rst.at(lm));
            if(ckci==1 && xvc_rst.at(lm)<=99){l[i][j]=xvc_rst.at(lm);}
            if(ckci==1 && xvc_rst.at(lm)>99){l[i][j]=-1;}
            if(ckci==2){l[i][j]=-1;}
            //cout<<xvc_rst.at(lm) << " " ;
            cout<< l[i][j] <<" ";
            if(xl_diak==0){mlis+=to_string(ar[mn_pvt]);mlis+=" :: ";xl_diak=1;}
            //mlis+=to_string(l[i][j]);
            if(xl_diak==1 && l[i][j]>-1 && (l[i][j]>l[i-1][j-1] || l[i][j]>-1)){xld=spl_and_get(l[i][j]);
            mlis+=to_string(xld);
            mlis+=" ";}
            lm+=pivt;
            if(lm>=xvc){
               //cout<<"lowering lm \n";
               lm=0;
            }
      }
      cout<<"\n";
      //cout<<mlis<<"\n";
      lm=0;
      xti+=1;
      mn_pvt+=1;xl_diak=0;
      mlis+="\n";
      rst_rw=0;
      lm=xti;
      if(lm>=xvc){
         //cout<<"lowering lm \n";
         lm=0;
         }
      kpvt+=1;
    }
  return 0;
}

int main(int argc,char ** argv)
{
    cout<<"how many numbers u want max 1000 ? : ";
    int mynumsum=0;
    cin>>mynumsum;
    cout<<"u enter : " << mynumsum <<"\n";
    int curr_num=0;
    cout<<"enter the loop times till 100 : ";
    int xl=0;
    cin>>xl;
    if(mynumsum>1000){goto A;}
    for(int i=1;i<=mynumsum;i++){
      cout<<"for " << i << " enter number : "  ;
      cin>>curr_num;
      ar[i]=curr_num;
      curr_num=0;
    }
    cout<<"\n";
    calc(mynumsum,xl);
    cout<<"\n";
    show_calc(xvc,mynumsum);
    cout<<"\n";
    cout<<"of string \n";
    cout << mlis <<"\n";
    A: cout<<" " ;
    return 0;
}
