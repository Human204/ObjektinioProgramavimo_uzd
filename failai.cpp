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

void sukurtifaila(int filesize,int ndsk){
  std::random_device rd;
  std::mt19937 mt (rd());
  std::uniform_int_distribution<int> dist(0,10);
  std::stringstream ss,nd;
  int paz_temp;
  vector<stud> studentai;
  studentai.reserve(filesize);
  stud temp;
  ss<<"Stud"<<filesize<<".txt";
  // vector<string>va,pa;
  string failas = ss.str(),nd_tekstas;
  ofstream fout (failas);
  fout<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde";
  for(int i=0;i<ndsk;i++){
    nd<<"ND"<<(ndsk+1);
    nd_tekstas=nd.str();
    fout<<setw(4)<<nd_tekstas;
    nd.str(string());nd.clear();
  }
  std::stringstream vardas, pavarde;
  for(int i=0;i<filesize;i++){
    vardas<<"Vardas"<<(filesize+1);
    pavarde<<"Pavarde"<<(filesize+1);
    temp.vardas=vardas.str();temp.pavarde=pavarde.str();
    temp.pazymiai.reserve(ndsk);
    for(int j=0;j<ndsk;j++){
      paz_temp=dist(mt);
      temp.pazymiai.push_back(paz_temp);
    }
    temp.egzaminas=dist(mt);
    studentai.push_back(temp);
    vardas.str(string());vardas.clear();
    pavarde.str(string());pavarde.clear();
  }

}