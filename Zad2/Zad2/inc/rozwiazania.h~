#ifndef ROZWIAZANIA_H
#define ROZWIAZANIA_H

#include <vector>
#include "zadania.h"

class Rozwiazania {
private:
    std::vector<int> solution;
    int Cmax;

public:
    Rozwiazania(const std::vector<int>& vec, int cmax);
  //~Rozwiazania();

    const std::vector<int>& getSolution() const { return solution; }
    int getCmax() const { return Cmax; }
    static int CalculateCmax(const std::vector<Zadania>& VZadaniaSorted);
};

#endif
