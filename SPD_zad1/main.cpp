#include <iostream>
#include "problem.h"
#include <chrono>
#include <fstream>

std::istream& operator >>(std::istream& in, Zadania& tmp) {
    int tmpQ, tmpR, tmpP, tmpNu;
    in >> tmpNu;
    in >> tmpR;
    in >> tmpP;
    in >> tmpQ;
    tmp = Zadania(tmpNu, tmpR, tmpP, tmpQ);
    return in;
}

int main() {
    // Przykładowe zadania

    /*std::vector<int> dd = {2,2,3,4,5,6,7,8,9,10};

    for (auto iter = dd.begin(); iter < dd.end();) {
        if (*iter % 2 == 0) iter = dd.erase(iter);
        else iter++;
    }
    */
    std::vector<Zadania> mojeDane2;
    std::fstream plik("dane.txt",std::ios::in|std::ios::out);
    while (plik.is_open()&&!plik.eof()) {
        Zadania temp;
        plik >> temp;
        mojeDane2.push_back(temp);
    }
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::vector<Zadania> VZadania = {
        Zadania(0, 3, 2, 1),
        Zadania(1, 2, 4, 2),
        Zadania(2, 5, 2, 3),
        Zadania(3, 1, 6, 4),
        Zadania(4, 4, 1, 5)
    };
    // Tworzymy problem
    //mojeDane1.erase(mojeDane1.begin() + 12, mojeDane1.end());
    Problem problem(5, mojeDane2);

    // Testujemy Zupełny
    /*
    start = std::chrono::steady_clock::now();
    Rozwiazania rozwiazaniePrzeglad = problem.PrzegladZupelny();
    end = std::chrono::steady_clock::now();
    std::cout << "Czas: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "| Przeglad ";
    for (int zadanie : rozwiazaniePrzeglad.getSolution()) {
      std::cout << zadanie << " ";
    }
    std::cout << "| Cmax: " << rozwiazaniePrzeglad.getCmax() << std::endl;
    */
    // Testujemy Schrange

    start = std::chrono::steady_clock::now();
    Rozwiazania rozwiazanieSchrange = problem.Schrange();
    end = std::chrono::steady_clock::now();
    std::cout << "Czas: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "| Przeglad: \n";
    for (int zadanie : rozwiazanieSchrange.getSolution()) {
        std::cout << zadanie << " ";
    }
    std::cout << "\n| Cmax: " << rozwiazanieSchrange.getCmax() << std::endl;

    return 0;
}
