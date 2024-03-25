#include "rozwiazania.h"


Rozwiazania::Rozwiazania(const std::vector<int>& vec, int cmax) : solution(vec), Cmax(cmax) {
}

int Rozwiazania::CalculateCmax(const std::vector<Zadania>& VZadaniaSorted) {
    int currentTime = 0;
    int maxEndTime = 0;
    for (const auto& zadanie : VZadaniaSorted) {
        currentTime = std::max(currentTime, zadanie.getR()) + zadanie.getP();
        maxEndTime = std::max(maxEndTime, currentTime + zadanie.getQ());
    }
    return maxEndTime;
}
//Rozwiazania::~Rozwiazania() {
//}
