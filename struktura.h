#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
#include <random>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct duomuo {
    string Vard;
    string Pav;
    vector<int> paz;
    vector<int> mediana;
    int egz;
    double GP = 0;
    double medianai;
};

#endif // STRUKTURA_H_INCLUDED
