#include "definitions.h"

// ELEVATOR Class

void Elevator::process(int clock, double& avgW, double& avgE, int& cnt) {

	set<int> route; // makes route, automatically sorted

	for (unsigned int i = 0; i < nextStands.size(); i++) {
		route.insert(nextStands[i]->getStart());
	}
	for (unsigned int i = 0; i < pass.size(); i++) {
		route.insert(pass[i]->getEnd());
	}

	//  Check thw correctness of direction of movement 
	if (status == MOVING_UP && *route.rbegin() < currentFloor->number) {
		status = MOVING_DOWN;
	}
	if (status == MOVING_DOWN && *route.begin() > currentFloor->number) {
		status = MOVING_UP;
	}


	if (find(route.begin(), route.end(), currentFloor->number) != route.end()) {
		status = STOPPING;
	}
	else if (transition == 0) {
		transition = timeMove;
	}

	// moving between floors
	if (transition != 0 && status != STOPPED && status != STOPPING) 
	{
		transition--;
		if (transition == 0) {
			currentFloor = (status == MOVING_UP )? currentFloor->next : currentFloor->prew;
		}
	}

	// stopping 
	if (status == STOPPING) {
		if (--brake == 0) {
			brake = timeStop;
			status = STOPPED;
		}
	}
	// if stopped
	if (status == STOPPED) {
		unsigned int n = nextStands.size(); // needs for correct deleting
		for (unsigned int i = 0; i < n; i++) {
			if (nextStands[i]->getStart() == currentFloor->number) {
				nextStands[i]->status = IN_ELEV;
				pass.push_back(nextStands[i]);
				route.erase(nextStands[i]->getStart());
				nextStands.erase(nextStands.begin() + i);
				n--;
			}
		}

		n = pass.size(); // needs for correct deleting
		for (unsigned int i = 0; i < n; i++) {
			if (pass[i]->getEnd() == currentFloor->number) {
				/*
				cout << setw(8) << clock << " s |     ";
				cout << setw(6) << left << pass[i]->getTime() << " s |"; 
				cout << right << setw(3) << number << setw(4) << "|";
				cout << setw(9) << pass[i]->getW() << " s " << setw(6) << pass[i]->getE() << " s " << endl;
				*/

				route.erase(pass[i]->getEnd());
				pass[i]->status = EXIT;
				cnt++;
				avgW += pass[i]->getW();
				avgE += pass[i]->getE();
				pass.erase(pass.begin() + i);
				n--;
				capacity--;
			}
		}

		if (route.size() == 0) {
			status = STOPPED;
			return;
		}

		if (abs(*route.begin() - currentFloor->number) > abs(*route.rbegin() - currentFloor->number)) {
			status = MOVING_DOWN;
		}
		else {
			status = MOVING_UP;
		}

		transition = timeMove;
		
		}

}

int Elevator::getStop() {
	return timeStop;
}

int Elevator::getMove() {
	return timeMove;
}

int Elevator::getCurrent() {
	return currentFloor->number;
}

bool Elevator::isFull() {
	return capacity == maxCapacity;
}

void Elevator::addStand(Passenger * p) {
	nextStands.push_back(p);
	capacity++;
	if (p->getEnd() > currentFloor->number) {
		status = MOVING_UP;
	}
	else {
		status = MOVING_DOWN;
	}
}

void Elevator::SetNum(int n) {
	number = n;
}

// HUMAN Class

int Passenger::getTime() {
	return startTime;
}

int Passenger::getEnd() {
	return endFloor->number;
}

int Passenger::getStart() {
	return startFloor->number;
}

void Passenger::incW() {
	counterW++;
}

void Passenger::incE() {
	counterE++;
}

int Passenger::getW() {
	return counterW;
}

int Passenger::getE() {
	return counterE;
}

// Functions 

void ReadFile(Floor * floor, vector<Passenger>& arr, istream & is) {
	string temp;
	int time, start, end;
	getline(is, temp); // Miss title string

	while (!is.eof()) {
		getline(is, temp); // Miss title string
		istringstream str(temp); // Read one row

		getline(str, temp, ','); // Read Start time
		time = stoi(temp);
		getline(str, temp, ','); // Read Start Floor
		start = stoi(temp);
		getline(str, temp, '\n'); // Read End Floor
		end = stoi(temp);

		Passenger* hum = new Passenger(floor, time, start, end);
		arr.push_back(*hum);
	}
}

bool FindClosest(int start, int end, vector<Elevator> & elvs, vector<Elevator>::iterator * el) {
	bool fl = 0;
	int dist = 100;
	for (unsigned int i = 0; i < elvs.size(); i++) {
		if (end - start >= 0) {
			if (!elvs[i].isFull() && ((elvs[i].status == MOVING_UP && start - elvs[i].getCurrent() > 0) || elvs[i].status == STOPPED)
				&& start - elvs[i].getCurrent() < dist) {

				dist = start - elvs[i].getCurrent();
				*el = elvs.begin() + i;
				fl = 1;
			}
		}
		else if (end - start < 0) {
			if (!elvs[i].isFull() && ((elvs[i].status == MOVING_DOWN && elvs[i].getCurrent() - start > 0) || elvs[i].status == STOPPED)
				&& elvs[i].getCurrent() - start < dist) {
				
				dist = elvs[i].getCurrent() - start;
				*el = elvs.begin() + i;
				fl = 1;
			}
		}
	}
	return fl;
}

void initBulid(Floor* firstFloor, int count) {
	
	int num = 1;
	firstFloor->prew = NULL;

	Floor* ptr = firstFloor;
	while(--count){
		Floor* nextFloor = new Floor(++num);
		ptr->next = nextFloor;
		nextFloor->prew = ptr;
		ptr = nextFloor;
	}
	ptr->next = NULL;
}

void delBuild(Floor* firstFloor) {

	Floor* ptr = firstFloor->next;
	
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	while (ptr->prew != NULL) {
		Floor* forDel = ptr;
		ptr = ptr->prew;
		delete forDel;
	}

}