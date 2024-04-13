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
    Problem(int _n, const std::vector<Zadania>& _VZadania);  // konstruktor

    Rozwiazania SortPoR();
    Rozwiazania SortPoQ();
    Rozwiazania PrzegladZupelny();
    Rozwiazania Schrange();
    Rozwiazania MyAlgorithm();
    std::vector<int> convertToSolution(const Problem &myProblem) {
        std::vector<int> temp;
        for (auto iter : myProblem.VZadania) temp.push_back(iter.getNu());
        return temp;
    }
};

#endif
