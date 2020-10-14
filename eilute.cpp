#include "eilute.h"
int eilute(){
  std::ifstream file("output1.txt");
  int count = 0;
  string line;
    while (getline(file, line))
        count++;
    return count;
}
