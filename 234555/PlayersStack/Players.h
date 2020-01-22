#ifndef PLAYERS
#define PLAYERS

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Players{
private:
  double lowestAvgBat = 0;
  double highestAvgBat = 0;

  stack<string> lowestStack;
  stack<string> highestStack;

public:
void addPlayer(string name, double batAvg);
double getLowestBat();
double getHighestBat();

void printHighest();
void printLowest();
void print();

void clear();
};


#endif