#include"MyLib.h"
#include "skaiciavimai.h"
#include "ranka.h"

void Irasymasranka(studentas &temp, int paz_sk){
  int arr[paz_sk];
  cout<<"Irasykite studento varda ir pavarde: ";
  cin>>temp.vardas>>temp.pavarde;
  cin.ignore(10000,'\n');
  char ran;
  cout<<"Ar noresite atsitiktinai generuotu pazymiu? (y/n) ";
  //cin>>ran;
  while(true){
    cin>>ran;
    cin.ignore(10000,'\n');
    if(ran=='y'||ran=='Y'){
      for(int i=0;i<paz_sk;i++){
        arr[i]=rand()%11;
      }
      temp.egz=rand()%11;
      break;
    }
    else if (ran=='n'||ran=='N'){
      cout<<"Iveskite studento pazymius, maksimum "<<paz_sk<<", iveskite -1 noredami baigti ivesti: ";
      
      // temp.paz=new int[paz_sk];
      // for(int i=0;i<paz_sk;i++){
      //   arr[i]=0;
      // }
      int l,t=0;
      while (cin>>l){
        temp.paz.push_back(l);
        t++;
        if(!cin)cout<<"Iveskite skaiciu nuo 0 iki 10";
        else if(t==(paz_sk)){
          if(l==-1){
            temp.paz.pop_back();
          }
          break;
        }
        else if(l==-1){
          temp.paz.pop_back();
          break;
        }
        cin.clear();
      }
      cin.ignore(1000,'\n');
      cout<<"Iveskite egzamino pazymi: ";
      cin>>temp.egz;
      cin.ignore(10000,'\n');
      break;
    }
    else cout<<"Iveskite y arba n: ";
  }
  
}


void out(studentas &temp){
      cout<<left<<setw(15)<<temp.vardas<<setw(15)<<temp.pavarde<<setw(16);
      cout.precision(2);
      cout<<std::fixed;
      cout<<temp.galutinis<<'\n';
      // cout<<temp.vid<<" "<<temp.med<<"\n";
}
