#include "MyLib.h"
// const int paz_sk = 15;
struct studentas {
  string vardas = "", pavarde = "";
  vector<int8_t> paz;
  int egz=0;
  double vid=0.0;
  double med=0.0;
  double galutinis=0.0;
  double galutinis2=0.0;
};

void Irasymasranka(studentas &temp,int paz_sk);
void vidurkis(studentas &temp);
void mediana(studentas &temp);
void galutinis(studentas &temp,string tipas);
void out(studentas &temp);
void Skaitymas(vector<studentas> &temp,std::stringstream &temp2);
void outf(vector<studentas> &temp);
bool palygintivardus(studentas& a, studentas& b){
  return tie(a.vardas,a.pavarde)<tie(b.vardas,b.pavarde);
}


int main(){
    srand(time(NULL));
    int n=1,paz_sk;
    string tipas,failas_ar_ranka,failas;
    char pabaiga;
    studentas temp2;
    while(true){
      cout<<"ar noresite duomenis skaityti is failo ar irasyti ranka? (failas/ranka) ";
      cin>>failas_ar_ranka;
      cin.ignore(1000,'\n');
      if(failas_ar_ranka=="failas"||failas_ar_ranka=="ranka")break;
    }
    std::stringstream eilute;
    vector <studentas>grupe;
    grupe.reserve(1000000);
    if(failas_ar_ranka=="ranka"){
      while(true){
      cout<<"Skaiciuoti vidurki ar mediana?(vid/med): ";
      cin>>tipas;
      cin.ignore(10000,'\n');
      if(tipas=="vid"||tipas=="med")break;
    }
      while(true){
      cout<<"Kiek daugiausiai namu darbu pazymiu turi studentai?:  ";
      cin>>paz_sk;
      cin.ignore(10000,'\n');
      if(cin)break;
    }
      Irasymasranka(temp2,paz_sk);
      grupe.push_back(temp2);
      while(true){
        cout<<"Ar norite testi ivesti? (y/n) ";
        cin>>pabaiga;
        cin.ignore(10000,'\n');
        if(pabaiga=='y'||pabaiga=='Y'){
          n++;
          // grupe.resize(n);
          Irasymasranka(temp2,paz_sk);
          grupe.push_back(temp2);
        }
        else if (pabaiga=='n'||pabaiga=='N')break;
        else cout<<"Iveskite y arba n: ";
      }
      if(tipas=="vid"){
        cout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(16)<<"Galutinis (Vid.)\n";
        cout<<"----------------------------------------------\n";
      }
      else if(tipas=="med"){
        cout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(16)<<"Galutinis (Med.)\n";
        cout<<"----------------------------------------------\n";
      }
      for (int i = 0; i < n; i++)
      {
        if(tipas=="vid"){
          vidurkis(grupe[i]);
          galutinis(grupe[i],"vid");
          
        }
        else if(tipas=="med"){
          mediana(grupe[i]);
          galutinis(grupe[i],"med");
        }
        out(grupe[i]);
      }
    }
    else{
      cout<<"Iveskite failo pavadinima: ";
      cin>>failas;
      ifstream fin;
      fin.open(failas);
      if(!fin){
        cout<<"Tokio failo nera";
        return 0;
      }
      eilute<<fin.rdbuf();
      Skaitymas(grupe,eilute);
      fin.close();
      sort(grupe.begin(),grupe.end()-1,palygintivardus);
      outf(grupe);
    }
    grupe.clear();
}

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

void out(studentas &temp){
      cout<<left<<setw(15)<<temp.vardas<<setw(15)<<temp.pavarde<<setw(16);
      cout.precision(2);
      cout<<std::fixed;
      cout<<temp.galutinis<<'\n';
      // cout<<temp.vid<<" "<<temp.med<<"\n";
}

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