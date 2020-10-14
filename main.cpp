
#include "include_using.h"
#include "struktura.h"
#include "eilute.h"
#include "creating.h"
#include "palyginimas.h"
int main()
{
  generavimas(10, "output1.txt");
  FILE *read;
  if( (read=fopen("output1.txt","r"))!=NULL)
  {std :: ifstream read("output1.txt");
  int eilutes;
  eilutes = eilute()-1;
    srand(time(NULL));
    vector<duomuo> Eil_vect;
    string vardas, pavarde;
    int integer;
    int pazym;
    read>>vardas>>pavarde;
    int kiek=0;
    while(vardas!="EGZ")
    {
      read>>vardas;
      kiek++;
    }
    kiek-=1;
    std :: ofstream F;
  F.open("kietiakiai.txt", std::ios::out);
    F<< std::left << std::setw(15)<<"Vardas"
       <<  std::left << std::setw(15)<< "Pavarde";
        for (int k = 1; k<(kiek+1); k++){
          F<< "ND" <<std::left << std::setw(3)<< k;}
        F << "EGZ" << std::endl;
    std:: ofstream G;
  G.open("vargšiukai.txt", std::ios::out);
    G<< std::left << std::setw(15)<<"Vardas"
       <<  std::left << std::setw(15)<< "Pavarde";
        for (int k = 1; k<(kiek+1); k++){
          G<< "ND" <<std::left << std::setw(3)<< k;}
        G << "EGZ" << std::endl;
    for(int i=0;i<eilutes;i++)
    {
        Eil_vect.push_back(duomuo());
        read>>vardas;
        read>>pavarde;
        Eil_vect[i].Vard = vardas;
        Eil_vect[i].Pav = pavarde;
        for(int j=0;j<(kiek);j++)
        {
          read>>pazym;
          if (pazym >=1 && pazym <=10){
          Eil_vect[i].paz.push_back(pazym);
          Eil_vect[i].GP+=Eil_vect[i].paz[j];
          Eil_vect[i].mediana.push_back(pazym);
          }
          else {
            printf("Faile yra netinkamo formato pazymys");
            return 0;}
        }
          read>>integer;
          if (integer >=1 && integer <=10){
          Eil_vect[i].egz=integer;
          Eil_vect[i].mediana.push_back(integer);
          }
          else {
            printf("Faile yra netinkamo formato pazymys");
            return 0;}

      if (Eil_vect[i].GP != 0){
        Eil_vect[i].GP = Eil_vect[i].GP / (kiek)/1.0;}
        Eil_vect[i].GP = Eil_vect[i].GP * 0.4 + 0.6 * Eil_vect[i].egz;
        //medianai skaiciuot
        std::sort(Eil_vect[i].mediana.begin(), Eil_vect[i].mediana.end());
        if ((kiek+1) % 2 != 0)
        Eil_vect[i].medianai = Eil_vect[i].mediana[(kiek) / 2];
        else Eil_vect[i].medianai = (Eil_vect[i].mediana[(kiek+1) / 2] + Eil_vect[i].mediana[ (kiek+1) / 2 - 1]) / 2.0;
    }
    std::sort(Eil_vect.begin(), Eil_vect.end(), palyginimas);
    for (int st= 0; st<eilutes; st++){
      if (Eil_vect[st].GP >= 5){
        F <<std::left << std::setw(15)<< Eil_vect[st].Vard
        <<std::left << std::setw(15)<<Eil_vect[st].Pav;
        for (int k = 0; k<(kiek); k++){
          F<< std::left<<std::setw(5)<<Eil_vect[st].paz[k];}
        F << Eil_vect[st].egz << std::endl;}
      else if (Eil_vect[st].GP < 5){
        G <<std::left << std::setw(15)<< Eil_vect[st].Vard
        <<std::left << std::setw(15)<<Eil_vect[st].Pav;
        for (int k = 0; k<(kiek); k++){
          G<< std::left<<std::setw(5)<<Eil_vect[st].paz[k];}
        G << Eil_vect[st].egz << std::endl;}
      }

    cout << std::left << std::setw(15)<< "Vardas" <<std::left <<std::setw(15)<< "Pavarde ";
    cout<<std::left<< std::setw(15)<<"Galutinis paz"<<"Mediana"<<std::endl;
    cout<<"__________________________________________________"<<std::endl;
    for(int i=0;i<eilutes;i++)
    {
      cout << std::left << std::setw(15)<< Eil_vect[i].Vard <<std::left <<std::setw(15)<< Eil_vect[i].Pav;
      cout<< std::left<< std::setw(15)<< std::setprecision(3)<<Eil_vect[i].GP << std::setprecision(3) << Eil_vect[i].medianai <<std::endl;
    }
    read.close();
    F.close();
    G.close();
  }
  else {printf("Negalima atidaryti failo"); exit(0);}
  system("pause");
}
