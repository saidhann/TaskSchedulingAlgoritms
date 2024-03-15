#pragma once
#include <vector>
#include <algorithm>
#include <queue>

class Task {
public:
	Task(int he, int co, int ar, int n) : heat(he), timeToComplete(co), timeArriving(ar), nr(n) {};
	~Task() { delete this; };
	Task(Task& tmp) : heat(tmp.getHeat()), timeToComplete(tmp.getTimeToComplete()), timeArriving(tmp.getTimeArriving()), nr(tmp.getNr()) {};

	int getTimeToComplete() { return timeToComplete; };
	int getTimeArriving() { return timeArriving; };
	int getHeat() { return heat; };
	int getNr() { return nr; };

	void setTimeToComplete(const int& tmp) { timeToComplete = tmp; };
	void setTimeArriving(const int& tmp) { timeArriving = tmp; };
	void setHeat(const int& tmp) { heat = tmp; };
	void setNr(const int& tmp) { nr = tmp; };

private:
	int heat;
	int timeToComplete;
	int timeArriving;
	int nr;
};