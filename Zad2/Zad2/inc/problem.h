#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include "zadania.h"
#include "rozwiazania.h"
#include <algorithm>

class Problem {
private:
  int n;
  std::vector<Zadania> VZadania;

public:
  Problem(int _n, const std::vector<Zadania>& _VZadania);  

  Rozwiazania LPT();
  Rozwiazania LSA();
  Rozwiazania PrzegladZupelny();
    
};

#endif
