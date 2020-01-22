#include "Players.h"

void Players::addPlayer(string name, double batAvg) {
	if (lowestStack.empty()) {
		lowestStack.push(name);
		lowestAvgBat = batAvg;

		highestStack.push(name);
		highestAvgBat = batAvg;
	}
	else if (lowestAvgBat == batAvg) {
		lowestStack.push(name);
	}
	else if (highestAvgBat == batAvg) {
		highestStack.push(name);
	}
	else if (highestAvgBat < batAvg) {
		while (!highestStack.empty())
			highestStack.pop();

		highestAvgBat = batAvg;
		highestStack.push(name);
	}
	else if (lowestAvgBat > batAvg) {
		while (!lowestStack.empty())
			lowestStack.pop();

		lowestAvgBat = batAvg;
		lowestStack.push(name);
	}
}

double Players::getLowestBat() {
	return lowestAvgBat;
}

double Players::getHighestBat() {
	return highestAvgBat;
}

void Players::printHighest() {
	if (!highestStack.empty()) {
		cout << "Highest Average = " << highestAvgBat << endl;
		while (!highestStack.empty()) {
			cout << highestStack.top() << endl;
			highestStack.pop();
		}
		cout << endl;
	}
}

void Players::printLowest() {
	if (!lowestStack.empty()) {
		cout << "Lowest Average = " << lowestAvgBat << endl;
		while (!lowestStack.empty()) {
			cout << lowestStack.top() << endl;
			lowestStack.pop();
		}
		cout << endl;
	}
}

void Players::print() {
	this->printLowest();
	this->printHighest();
}

void Players::clear() {
	while (!highestStack.empty())
		highestStack.pop();

	while (!lowestStack.empty())
		lowestStack.pop();

}