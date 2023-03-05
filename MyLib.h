#pragma once
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<tuple>
#include<random>
#include <chrono>


using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::string;
using std::sort;
using std::rand;
using std::fixed;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::istringstream;
using std::stoi;
using std::tie;

struct studentas {
  string vardas = "", pavarde = "";
  // vector<int8_t> paz;
  vector<int> paz;
  int egz=0;
  double vid=0.0;
  double med=0.0;
  double galutinis=0.0;
  double galutinis2=0.0;
  double gal_vid=0.0;
};