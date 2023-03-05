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
  double laikas;
  vector <studentas> studentai;
  studentai.reserve(filesize);
  studentas temp;
  Timer t_vis,t_dal;
  ss<<"Stud"<<filesize<<".txt";
  string failas = ss.str(),nd_tekstas;
  ofstream fout (failas);
  fout<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde";
  for(int i=0;i<ndsk;i++){
    nd<<"ND"<<(i+1);
    nd_tekstas=nd.str();
    fout<<setw(4)<<left<<nd_tekstas;
    nd.str(string());nd.clear();
  }
  fout<<setw(4)<<left<<"Egz.\n";
  std::stringstream vardas, pavarde;
  for(int i=0;i<filesize;i++){
    vardas<<"Vardas"<<(i+1);
    pavarde<<"Pavarde"<<(i+1);
    temp.vardas=vardas.str();temp.pavarde=pavarde.str();
    fout<<setw(15)<<left<<temp.vardas<<setw(15)<<left<<temp.pavarde;
    temp.paz.reserve(ndsk);
    for(int j=0;j<ndsk;j++){
      paz_temp=dist(mt);
      temp.paz.push_back(paz_temp);
      fout<<setw(4)<<left<<temp.paz[j];
      paz_temp=0;
    }
    temp.egz=dist(mt);
    vidurkis(temp);
    mediana(temp);
    galutinis(temp,"failas");
    temp.gal_vid=(temp.galutinis+temp.galutinis2)/2;
    studentai.push_back(temp);
    temp={};
    fout<<setw(4)<<left<<temp.egz<<endl;
    vardas.str(string());vardas.clear();
    pavarde.str(string());pavarde.clear();
  }
  cout<<"Failo kurimas ir duomenu saugojimas uztruko: "<<t_dal.elapsed()<<endl;
  isskaidymas(studentai);
  studentai.clear();
  cout<<"Visas programos veikimo laikas: "<<t_dal.elapsed()<<endl;
}

void isskaidymas(vector<studentas> &studentai){
  bool skaidymo_zenkl=false;
  Timer t_dal;
  sort(studentai.begin(),studentai.end()-1,palygintigalutinius);
  cout<<"Studentu rikiavimas uztruko: "<<t_dal.elapsed()<<endl;
  t_dal.reset();
  vector<studentas> cringe,based;
  cringe.reserve(studentai.size()*0.7);based.reserve(studentai.size()*0.7);
  for(int i=0;i<studentai.size();i++){
    if(studentai[i].gal_vid<5){
      cringe.push_back(studentai[i]);
    }
    else based.push_back(studentai[i]);
  }
  studentai.clear();
  cout<<"Studentu suriusiavimas i 2 dalis uztruko: "<<t_dal.elapsed()<<endl;
  t_dal.reset();
  out_failo_sukurimas(cringe,"cringe");
  cout<<"'Cringe' studentu irasymas uztruko: "<<t_dal.elapsed()<<endl;
  t_dal.reset();
  out_failo_sukurimas(based,"based");
  cout<<"'Based' studentu irasymas uztruko: "<<t_dal.elapsed()<<endl;
  cringe.clear();
  based.clear();
}

void out_failo_sukurimas(vector<studentas> &temp,string tipas){
  string file;
  std::stringstream ss;
  ss<<tipas<<".txt";
  file=ss.str();
  ofstream fout(file);
  fout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(13)<<"Galutiniu vid\n";
  fout<<"-----------------------------------------------\n";
  for(int i=0;i<temp.size();i++){
    fout<<setw(15)<<left<<temp[i].vardas<<setw(15)<<left<<temp[i].pavarde;
    fout.precision(2);
    fout<<std::fixed;
    fout<<temp[i].gal_vid<<'\n';
  }
}