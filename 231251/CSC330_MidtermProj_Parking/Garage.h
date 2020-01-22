#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <utility>
#include "Person.h"

using namespace std;

class Garage
{
public:
	Garage();
	Garage(int Floors, int CarsPerFloor, int Hourlyrate, int Monthlyfee);
	void readGarage(ifstream &garFile); // read in parking garage database
	void writeGarage(ofstream& garFile); // read in parking garage database
	string findSpot(string type); // for finding and choosing parkspot
	void clearSpot(string spot);
	void print();

private:
	vector<pair<bool, string> > parkspot;
	int floors;
	int carsperfloor;
	int hourlyrate;
	int monthlyfee;
};