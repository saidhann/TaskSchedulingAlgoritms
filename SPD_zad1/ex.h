#pragma once
#include "task.h"

class Ex {
public:
	Ex(std::vector<Task> vec) : taskVector(vec), currentPermutation(vec) {}
	~Ex() { delete this; };
	void sortEx() { std::sort(taskVector.begin(), taskVector.end()); }
	void generateNextPermutation() { std::next_permutation(currentPermutation.begin(), currentPermutation.end()); }

private:
	std::vector<Task> taskVector;
	std::vector<Task> currentPermutation;
};