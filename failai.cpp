#include "MyLib.h"
#include "skaiciavimai.h"
#include "failai.h"

void Skaitymas(vector<studentas> &temp,std::stringstream &temp2){
  int temp_paz,l=0;
  studentas temp3;
  string check,tp;
  temp2>>check>>check;
  while(true){
    temp2>>check;
    if(check[0]=='N')l++;
    else{
      break;
    } 
  }
  while(temp2>>temp3.vardas>>temp3.pavarde){
      for(int i=0;i<l;i++){
      temp3.paz.reserve(l);
      temp2>>temp_paz;
      temp3.paz.push_back(temp_paz);
      temp_paz=0;
    }
    temp2>>temp3.egz;
    mediana(temp3);
    vidurkis(temp3);
    temp3.paz.clear();
    galutinis(temp3,"failas");
    temp.push_back(temp3);
  }
  
}

void outf(vector<studentas> &temp){
  ofstream fout ("out.txt");
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(16)<<"Galutinis (Vid.) "<<setw(16)<<"Galutinis (Med.)\n";
  fout<<"---------------------------------------------------------------\n";
    for(int i=0;i<temp.size();i++){
      // cout<<temp[i].vardas<<endl;
      fout<<left<<setw(15)<<temp[i].vardas<<setw(15)<<temp[i].pavarde<<setw(16);
      fout.precision(2);
      fout<<std::fixed;
      fout<<temp[i].galutinis;
      fout<<" "<<setw(16);
      fout.precision(2);
      fout<<std::fixed;
      fout<<temp[i].galutinis2<<'\n';
    }
    fout.close();
}