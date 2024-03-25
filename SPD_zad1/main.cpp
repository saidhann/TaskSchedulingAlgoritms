#include <iostream>
#include "problem.h"

int main() {
    // Przykładowe zadania
    std::vector<Zadania> VZadania = {
        Zadania(0, 3, 2, 1),
        Zadania(1, 2, 4, 2),
        Zadania(2, 5, 2, 3),
        Zadania(3, 1, 6, 4),
        Zadania(4, 4, 1, 5)
    };

    // Tworzymy problem
    Problem problem(5, VZadania);

    // Testujemy SortPoR
    Rozwiazania rozwiazanieR = problem.PrzegladZupelny();
    std::cout << "Przeglad ";
    for (int zadanie : rozwiazanieR.getSolution()) {
      std::cout << zadanie << " ";
    }
    std::cout << "| Cmax: " << rozwiazanieR.getCmax() << std::endl;


    return 0;
}
