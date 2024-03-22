#pragma once
#include "task.h"

class Ex {
public:
	Ex(std::vector<Task> vec) : taskVector(vec), currentPermutation(vec) {}
	~Ex() { delete this; };
	int calculateCriterium() {
		// tutaj liczenie kryterium
	}
	bool generateNextPermutation() { return std::next_permutation(currentPermutation.begin(), currentPermutation.end()); [](Task a, Task b) {return (a.getNr() > b.getNr()); }; }
	void sortByHeat() { std::sort(currentPermutation.begin(), currentPermutation.end(), [](Task a, Task b) {return (a.getHeat() > b.getHeat()); }); }
	void sortByArriveTime() { std::sort(currentPermutation.begin(), currentPermutation.end(), [](Task a, Task b) {return (a.getTimeArriving() > b.getTimeArriving()); }); }
	std::vector<Task> brutForce() {
		while (generateNextPermutation()) {
			//tutaj brutforce szukanie po kryterium
		}
	}

private:
	std::vector<Task> taskVector;
	std::vector<Task> currentPermutation;
};