#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED
#include "include_using.h"
struct duomuo {
    string Vard;
    string Pav;
    vector<int> paz;
    vector<int> mediana;
    int egz;
    double GP = 0;
    double medianai;
};

bool palyginimas(const duomuo &a, const duomuo &b);
#endif // STRUKTURA_H_INCLUDED
