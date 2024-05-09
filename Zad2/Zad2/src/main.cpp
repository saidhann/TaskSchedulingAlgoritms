#include <iostream>
#include "problem.h"

int main() {
    // Przykładowe zadania
    std::vector<Zadania> VZadania = {
        Zadania(0, 1),
        Zadania(1, 4),
        Zadania(2, 1),
        Zadania(3, 7),
        Zadania(4, 3),
	Zadania(5, 4)
    };

    // Tworzymy problem
    Problem problem(6, VZadania);

    // Testujemy SortPoR
    Rozwiazania rozwiazanieR1 = problem.LPT();
    Rozwiazania rozwiazanieR2 = problem.LSA();
    Rozwiazania rozwiazanieR = problem.PrzegladZupelny();
    std::cout << "Przeglad ";
    for (int zadanie : rozwiazanieR.getSolution()) {
      std::cout << zadanie << " ";
    }
    std::cout << "| Cmax: " << rozwiazanieR.getCmax() << std::endl;

    std::cout << "LPT ";
    for (int zadanie : rozwiazanieR1.getSolution()) {
      std::cout << zadanie << " ";
    }
    std::cout << "| Cmax: " << rozwiazanieR1.getCmax() << std::endl;

    std::cout << "LSA";
    for (int zadanie : rozwiazanieR2.getSolution()) {
      std::cout << zadanie << " ";
    }
    std::cout << "| Cmax: " << rozwiazanieR2.getCmax() << std::endl;

    return 0;
}
