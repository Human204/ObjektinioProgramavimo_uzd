#include "MyLib.h"
#include "skaiciavimai.h"

void vidurkis(studentas &temp){
  double paz_sum=0.0;
  double mm=temp.paz.size();
  if(temp.paz.size()==0){
    temp.vid=0.0;
  }
  else{
    for(int i=0;i<mm;i++){
      paz_sum+=temp.paz.at(i);
    }
    // temp.vid=paz_sum/(temp.paz.size()-1);
    // cout<<temp.paz.size()<<endl;
    temp.vid=paz_sum/(mm);
    // cout<<paz_sum/mm<<endl;
  }
}

void mediana(studentas &temp){
  double mm=temp.paz.size();
  sort(temp.paz.begin(),temp.paz.end()-1);
  if(temp.paz.size()%2!=0){temp.med=temp.paz.at((temp.paz.size()/2));}
  else{
   temp.med=(temp.paz.at((temp.paz.size()-1)/2)+temp.paz.at(((temp.paz.size()/2))))/2.0;
  }
}

void galutinis(studentas &temp,string tipas){
  if(tipas=="vid"){
    temp.galutinis=(temp.vid*0.4+temp.egz*0.6);
  }
  else if(tipas=="med"){
    temp.galutinis=(temp.med*0.4+temp.egz*0.6);
  }
  else if(tipas=="failas"){
    temp.galutinis=(temp.vid*0.4+temp.egz*0.6);
    temp.galutinis2=(temp.med*0.4+temp.egz*0.6);
  }
}
bool palygintivardus(studentas& a, studentas& b){
  return tie(a.vardas,a.pavarde)<tie(b.vardas,b.pavarde);
}
bool palygintigalutinius(studentas& a,studentas& b){
  return a.galutinis<b.galutinis;
}