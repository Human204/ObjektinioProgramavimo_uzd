#ifndef SKAICIAVIMAI_H
#define SKAICIAVIMAI_H
#include "MyLib.h"

class Timer {
private:
using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
std::chrono::time_point<hrClock> start;
public:
Timer() : start{ hrClock::now() } {}
void reset() {
start = hrClock::now();
}
double elapsed() const {
return durationDouble (hrClock::now() - start).count();
}
};

void vidurkis(studentas &temp);
void mediana(studentas &temp);
void galutinis(studentas &temp,string tipas);


bool palygintivardus(studentas& a, studentas& b);
bool palygintigalutinius(studentas& a,studentas& b);
#endif