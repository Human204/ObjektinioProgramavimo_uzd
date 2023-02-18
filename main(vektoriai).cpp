#include "MyLib.h"
const int paz_sk = 5;
struct studentas {
  string vardas = "", pavarde = "";
  vector<int> paz;
  int egz=0;
  double vid=0.0;
  double med=0.0;
  double galutinis=0.0;
};

void Irasymas(studentas &temp);
void vidurkis(studentas &temp);
void mediana(studentas &temp);
void galutinis(studentas &temp,string tipas);
void out(studentas &temp);


int main(){
    srand(time(NULL));
    int n=1;
    string tipas;
    char pabaiga;
    studentas temp2;
    while(true){
      cout<<"Skaiciuoti vidurki ar mediana?(vid/med): ";
      cin>>tipas;
      cin.ignore(10000,'\n');
      if(tipas=="vid"||tipas=="med")break;
    }
    vector <studentas>grupe;
    grupe.reserve(10);
    Irasymas(temp2);
    grupe.push_back(temp2);
    while(true){
      cout<<"Ar norite testi ivesti? (y/n) ";
      cin>>pabaiga;
      cin.ignore(10000,'\n');
      if(pabaiga=='y'||pabaiga=='Y'){
        n++;
        // grupe.resize(n);
        Irasymas(temp2);
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

void Irasymas(studentas &temp){
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
      cout<<"Iveskite studento pazymius, maksimum "<<paz_sk<<", iveskite 0 noredami baigti ivesti: ";
      
      // temp.paz=new int[paz_sk];
      for(int i=0;i<paz_sk;i++){
        arr[i]=0;
      }
      for(int i=0;i<paz_sk;i++){
        cin>>arr[i];
        if(!cin)cout<<"Iveskite skaiciu nuo 0 iki 10";
        else if(arr[i]==0)break;
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
  for(int i=0;i<paz_sk;i++){
      temp.paz.push_back(arr[i]);
    }
}

void vidurkis(studentas &temp){
  double paz_sum=0.0;
  for(int i=0;i<paz_sk;i++){
    paz_sum+=temp.paz[i];
  }
  temp.vid=paz_sum/paz_sk;
}

void mediana(studentas &temp){
  double arr[paz_sk];
  for(int i=0;i<paz_sk;i++)arr[i]=temp.paz[i];
  sort(&arr[0],&arr[paz_sk]);
  if(paz_sk%2!=0)temp.med=arr[(paz_sk/2)];
  else temp.med=(arr[((paz_sk-1)/2)]+arr[(paz_sk/2)])/2;
}

void galutinis(studentas &temp,string tipas){
  if(tipas=="vid"){
    temp.galutinis=(temp.vid*0.4+temp.egz*0.6);
  }
  else if(tipas=="med"){
    temp.galutinis=(temp.med*0.4+temp.egz*0.6);
  }
}

void out(studentas &temp){
      cout<<left<<setw(15)<<temp.vardas<<setw(15)<<temp.pavarde<<setw(16);
      cout.precision(2);
      cout<<std::fixed;
      cout<<temp.galutinis<<'\n';
}