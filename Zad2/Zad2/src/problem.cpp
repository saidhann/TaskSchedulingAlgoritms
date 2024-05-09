#include "problem.h"
#include <iostream>
#include <climits>

Problem::Problem(int _n, const std::vector<Zadania>& _VZadania)
    : n(_n), VZadania(_VZadania) {}

Rozwiazania Problem::LPT() {
    std::vector<Zadania> VZadaniaSorted = VZadania;
    std::sort(VZadaniaSorted.begin(), VZadaniaSorted.end(), [](const Zadania& a, const Zadania& b) {
        return a.getP() > b.getP();
    });

    std::vector<int> machinesLoad(2, 0); 
    std::vector<int> solution; // Rozwiązanie tymczasowe

    for (const Zadania& zadanie : VZadaniaSorted) {
        int machineIndex = std::distance(machinesLoad.begin(), std::min_element(machinesLoad.begin(), machinesLoad.end()));
        solution.push_back(machineIndex); 
        machinesLoad[machineIndex] += zadanie.getP(); 
    }

    int Cmax = *std::max_element(machinesLoad.begin(), machinesLoad.end()); 

    return Rozwiazania(solution, Cmax);
}

Rozwiazania Problem::LSA() {
    std::vector<int> machinesLoad(2, 0);
    std::vector<int> solution; // Rozwiązanie tymczasowe

    for (const Zadania& zadanie : VZadania) {
        int machineIndex = std::distance(machinesLoad.begin(), std::min_element(machinesLoad.begin(), machinesLoad.end()));
        solution.push_back(machineIndex); 
        machinesLoad[machineIndex] += zadanie.getP(); 
    }

    int Cmax = *std::max_element(machinesLoad.begin(), machinesLoad.end()); 

    return Rozwiazania(solution, Cmax);
}

Rozwiazania Problem::PrzegladZupelny() {
    Rozwiazania najlepsze_rozwiazanie({}, INT_MAX);
    std::vector<int> machinesLoad(2, 0); 

    for (int i = 0; i < (1 << n) / 2; ++i) {
        std::vector<int> combination(n); 
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) { 
                combination[j] = 1; 
            }
        }

        for (int k = 0; k < n; ++k) {
            machinesLoad[combination[k]] += VZadania[k].getP();
        }
        int currentCmax = *std::max_element(machinesLoad.begin(), machinesLoad.end());

        if (currentCmax < najlepsze_rozwiazanie.getCmax()) {
            najlepsze_rozwiazanie = Rozwiazania(combination, currentCmax);
        }

        machinesLoad.assign(2, 0);
    }

    return najlepsze_rozwiazanie;
}
