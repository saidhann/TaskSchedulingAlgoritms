#include <iostream>
#include "problem.h"
#include <chrono>
#include <fstream>
#include <cassert>

std::istream& operator >>(std::istream& in, Zadania& tmp) {
    int tmpQ, tmpR, tmpP;
    in >> tmpR;
    in >> tmpP;
    in >> tmpQ;
    tmp = Zadania(tmpR, tmpP, tmpQ);
    return in;
}

enum class SortType
{
    PrzegladZupelny,
    Schrange,
    mojAlgorytm,
    sortPoQ,
    sortPoR
};

void test(Problem& myProblem,const SortType& sortName ) {

    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    Rozwiazania noweRozwiazanie;

    std::cout << "Rodzaj Algorytmu:";

    switch (sortName) {
    case SortType::PrzegladZupelny:
        std::cout << "Przeglad zupelny\n";
        start = std::chrono::steady_clock::now();
        noweRozwiazanie = myProblem.PrzegladZupelny();
        end = std::chrono::steady_clock::now();
        break;

    case SortType::Schrange:
        std::cout << "Schrange\n";
        start = std::chrono::steady_clock::now();
        noweRozwiazanie = myProblem.Schrange();
        end = std::chrono::steady_clock::now();
        break;

    case SortType::mojAlgorytm:
        std::cout << "Algorytm Wlasny\n";
        start = std::chrono::steady_clock::now();
        noweRozwiazanie = myProblem.MyAlgorithm();
        end = std::chrono::steady_clock::now();
        break;
    case SortType::sortPoQ:
        std::cout << "Sort po Q\n";
        start = std::chrono::steady_clock::now();
        noweRozwiazanie = myProblem.SortPoQ();
        end = std::chrono::steady_clock::now();
        break;
    case SortType::sortPoR:
        std::cout << "Sort po R\n";
        start = std::chrono::steady_clock::now();
        noweRozwiazanie = myProblem.SortPoR();
        end = std::chrono::steady_clock::now();
        break;
    default:
        break;
    }
    std::cout << "Czas: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    /*std::cout << "| Przeglad ";
    for (int zadanie : noweRozwiazanie.getSolution()) {
        std::cout << zadanie << " ";
    }
    */
    std::cout << "| Cmax: " << noweRozwiazanie.getCmax() << std::endl<<std::endl;
}



int main() {
    // Przykładowe zadania

    std::vector<Zadania> mojeDane2;
    std::fstream plik("dane.DAT",std::ios::in|std::ios::out);
    int numer = 1;
    while (plik.is_open()&&!plik.eof()) {
        Zadania temp;
        plik >> temp;
        temp.setNu(numer);
        mojeDane2.push_back(temp);
        numer++;
    }

    mojeDane2.pop_back();
 
    // Tworzymy problemy
    Problem problem5(5, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 5));
    Problem problem7(7, std::vector<Zadania>(mojeDane2.begin(),mojeDane2.begin() + 7));
    Problem problem9(9, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 9));
    Problem problem11(11, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 11));
    Problem problem50(50, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 50));
    Problem problem200(200, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 200));
    Problem problem500(500, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 500));
    Problem problem1000(1000,mojeDane2);
    //Problem problem2000(2000, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 2000));
    //Problem problem3000(3000, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 3000));
    //Problem problem4000(4000, std::vector<Zadania>(mojeDane2.begin(), mojeDane2.begin() + 4000));
    
    // Testujemy 5

    test(problem5, SortType::PrzegladZupelny);
    test(problem5, SortType::mojAlgorytm);
    test(problem5, SortType::Schrange);
    test(problem5, SortType::sortPoQ);
    test(problem5, SortType::sortPoR);

    // Testujemy 7

    test(problem7, SortType::PrzegladZupelny);
    test(problem7, SortType::mojAlgorytm);
    test(problem7, SortType::Schrange);
    test(problem7, SortType::sortPoQ);
    test(problem7, SortType::sortPoR);

    // Testujemy 9

    test(problem9, SortType::PrzegladZupelny);
    test(problem9, SortType::mojAlgorytm);
    test(problem9, SortType::Schrange);
    test(problem9, SortType::sortPoQ);
    test(problem9, SortType::sortPoR);

    // Testujemy 11

    test(problem11, SortType::PrzegladZupelny);
    test(problem11, SortType::mojAlgorytm);
    test(problem11, SortType::Schrange);
    test(problem11, SortType::sortPoQ);
    test(problem11, SortType::sortPoR);

    // Testujemy 500

    test(problem500, SortType::mojAlgorytm);
    test(problem500, SortType::Schrange);
    test(problem500, SortType::sortPoQ);
    test(problem500, SortType::sortPoR);

    // Testujemy 1000

    test(problem1000, SortType::mojAlgorytm);
    test(problem1000, SortType::Schrange);
    test(problem1000, SortType::sortPoQ);
    test(problem1000, SortType::sortPoR);


    return 0;
}
