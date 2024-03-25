#include "problem.h"
#include <iostream>
Problem::Problem(int _n, const std::vector<Zadania>& _VZadania)
    : n(_n), VZadania(_VZadania) {}



Rozwiazania Problem::SortPoR() {
    
    std::vector<Zadania> VZadaniaSorted = VZadania;

    std::sort(VZadaniaSorted.begin(), VZadaniaSorted.end(), [](const Zadania& a, const Zadania& b) {
        return a.getR() < b.getR();
    });


    std::vector<int> solution;
    for (const auto& zadanie : VZadaniaSorted) {
        solution.push_back(zadanie.getNu());
    }
    int Cmax = Rozwiazania::CalculateCmax(VZadaniaSorted);

    return Rozwiazania(solution, Cmax);

}


Rozwiazania Problem::SortPoQ() {
   
   std::vector<Zadania> VZadaniaSorted = VZadania;

    std::sort(VZadaniaSorted.begin(), VZadaniaSorted.end(), [](const Zadania& a, const Zadania& b) {
        return a.getR() < b.getR();
    });

    
    int temp = 0;
    
    for (size_t i = 0; i < VZadaniaSorted.size(); ++i) {
      temp = temp +  VZadaniaSorted[i].getR();
	
	  for (size_t j = i+1; j < VZadaniaSorted.size(); ++j)
	    {
	      if(VZadaniaSorted[j].getR() <= temp)
		{
		  if(VZadaniaSorted[i].getQ() < VZadaniaSorted[j].getQ())
		    {
		      std::swap(VZadaniaSorted[i], VZadaniaSorted[j]);
		    }
		}
	    }
	  temp = temp + VZadaniaSorted[i].getP();
	
     
    }





    
    std::vector<int> solution;
    for (const auto& zadanie : VZadaniaSorted) {
        solution.push_back(zadanie.getNu());
    }





    
    int Cmax = Rozwiazania::CalculateCmax(VZadaniaSorted);
    return Rozwiazania(solution, Cmax);
}


Rozwiazania Problem::PrzegladZupelny() {
    std::vector<Zadania> VZadaniaSorted = VZadania;
    std::vector<Zadania> VBest = VZadaniaSorted;
  
    int Cmax = Rozwiazania::CalculateCmax(VZadaniaSorted);

    do {
        int newCmax = Rozwiazania::CalculateCmax(VZadaniaSorted);
        if (newCmax < Cmax) {
            VBest = VZadaniaSorted;
            Cmax = newCmax;
        }
	std::cout << "( ";
	for (const Zadania& zadanie : VZadaniaSorted) {
        
        std::cout << zadanie.getNu() << ",";
    }
	std::cout << ")" << newCmax <<std::endl;
	
    } while (std::next_permutation(VZadaniaSorted.begin(), VZadaniaSorted.end()));

    std::vector<int> solution;
    for (const Zadania& zadanie : VBest) {
        solution.push_back(zadanie.getNu());
        std::cout << zadanie.getNu() << std::endl;
    }

    return Rozwiazania(solution, Cmax);
}
