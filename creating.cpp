#include "creating.h"

int generavimas(int g, std::string a)
{
  std::vector<int> Vect;
  srand(time(NULL));
    for (int i = 0; i < g; i++)
    {
        Vect.push_back(i + 1);
    }
    int dydis = Vect.size();
        std::ofstream f(a);
         f << "Vardas" << std::left << std::setw(15)<<" "
       << "Pavarde" <<  std::left << std::setw(15)<<" ";
        for (int k = 1; k<10; k++){
          f<< "ND" <<std::left << std::setw(3)<< k;}
        f << "EGZ" << std::endl;
        std::random_shuffle( Vect.begin(), Vect.end() );
        for (int elem = 0; elem<dydis; elem++){
        f << "Vardas"<<std::left << std::setw(15)<< Vect[elem]
        << "Pavarde"<< std::left << std::setw(15)<<Vect[elem];
        for (int k = 1; k<10; k++){
          f<< std::left << std::setw(5)<<1 + rand() % 10;}
        f << 1 + rand() % 10<< std::endl;
    }
    f.close();
    return 0;
};

int eilute(){
  std::ifstream file("output1.txt");
  int count = 0;
  string line;
    while (getline(file, line))
        count++;
    return count;
};

bool palyginimas(const duomuo &a, const duomuo &b)
{
    if (a.Vard != b.Vard )
        return a.Vard < b.Vard;
    return a.Pav < b.Pav;
};
