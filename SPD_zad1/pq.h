#pragma once
#include "task.h"

class Pq {
	Pq(std::vector<Task> vec) : taskVector(vec), currentPermutation(std::m) {}
private:
	std::vector<Task> taskVector;
	std::priority_queue<Task> currentPermutation;
};