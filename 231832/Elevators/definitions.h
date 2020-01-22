#pragma once

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Elevator;
class Passenger;
class Floor;
enum statusH { WAIT, WAIT_ELEV, IN_ELEV, EXIT };
enum statusE{ STOPPED, STOPPING, MOVING_UP, MOVING_DOWN };

// func for reading data from file .csv
void ReadFile(Floor * floor, vector<Passenger>& arr, istream & is);
// initialize floors and building 
void initBulid(Floor* firstFloor, int count);

void delBuild(Floor* firstFloor);
// func to finding *free* elevator for waiting passanger
bool FindClosest(int start, int end, vector<Elevator> & elvs, vector<Elevator>::iterator * el);

// class for floors, works as double-linked list

class Floor{
public:
	int number;

	Floor* next; // pointer to next floor 
	Floor* prew; // pointer to prew floor

	Floor(int num = 1) : number(num), next(NULL), prew(NULL) {};
};


// class for elevator

class Elevator {
private:
	const static int maxCapacity = 8; 
	int number; // number of elevator (1..4)
	Floor *  currentFloor;
	int capacity; // of elevator

	int timeStop; // Time for stopping
	int timeMove; // Time for moving 

	vector <Passenger*> nextStands; // array of stop floors
	vector <Passenger*> pass; // array of passngers
	
public:
	statusE status; // status (STOPPED, STOPPING, MOVING_UP...)
	int brake; // counter for brake (STOPPING)
	int transition; // counter for moving between the floors

	// Beginning constructor
	Elevator(Floor * floor, int numElev, int floorNum = 1, int tMove = 10, int tStop = 2) : // starting floor
		timeStop(tStop), // time stop 
		timeMove(tMove), // time speed
		capacity(0),  // starting capacity
		number(numElev) 
	{
		while (floor->number != floorNum) {
			floor = floor->next;
		}
		currentFloor = floor;

		brake = timeStop; // Set brake
		transition = timeMove; // Set moving counter
		status = STOPPED; // Set status
	}
	
	// Main process func, must performs every second (ñlock)
	void process(int clock, double &, double &, int &); 
	
	// check if elevator is full
	bool isFull();
	
	// add new floor for stopping
	void addStand(Passenger * p);

	// set number of elevator (1..4)
	void SetNum(int n);

	// getters
	int getCurrent();
	int getStop();
	int getMove();
};

class Passenger {
private:
	int startTime; // coming time
	Floor * startFloor; // starting floor
	Floor * endFloor; // ending floor

	int counterW; // wait time
	int counterE; // wait time in elevator
public:
	statusH status; // status (WAIT, WAIT_ELEV, IN_ELEV, EXIT)

	// Constructor of passenger
	Passenger(Floor * floor, int sTime, int startFloor, int endFloor) : 
		startTime(sTime), counterW(0), counterE(0), status(WAIT) 
	{
		
		Floor* tfloor = floor;
		while (tfloor->number != startFloor) {
			tfloor = tfloor->next;
		}
		this->startFloor = tfloor;

		while (floor->number != endFloor){
			floor = floor->next;
		}
		this->endFloor = floor;
	}
	
	// timer increase
	void incW();
	// timer in elevator increase
	void incE();

	// get counter of waiting
	int getW();
	// get counter of time of elvator
	int getE();

	// getters
	int getTime();
	int getStart();
	int getEnd();
};