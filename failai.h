#ifndef FAILAI_H
#define FAILAI_H
#include "MyLib.h"
struct stud{
    string vardas,pavarde;
    vector<int>pazymiai;
    int egzaminas;

};
void Skaitymas(vector<studentas> &temp,std::stringstream &temp2);
void outf(vector<studentas> &temp);
void sukurtifaila(int filesize,int ndsk);
void isskaidymas(vector<studentas> &studentai);
void out_failo_sukurimas(vector<studentas> &temp,string tipas);

#endif