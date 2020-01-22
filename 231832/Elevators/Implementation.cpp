#include "definitions.h"


int main() {
	
	double FirstAvgW = 0, SecondAvgW = 0, FirstAvgE = 0, SecondAvgE = 0;	

		{
			// set time for moving between floors
			int speed = 10;
			// make firstFloor (class Floor is double-linked list);
			Floor* floor = new Floor(1);
			// make build with 100 floors
			initBulid(floor, 100);

			// copy pointer to first floor
			Floor* FirstFloor = floor;

			vector<Elevator> elvs;

			// initialize elevators
			for (int i = 0; i < 4; i++) {
				// set pointer to 1st floor, number of elevator, number of start floor, speed(time of moving between floors)
				Elevator* el = new Elevator(FirstFloor, i + 1, 1, speed);
				elvs.push_back(*el);
			}

			// read data about passengers in Data_File_M10.csv and load data into array
			vector<Passenger> arr;
			ifstream fin("Data_File_M10.csv");
			ReadFile(floor, arr, fin);

			// make variables for waiting time(at floor, in elevator)
			double avgW = 0, avgE = 0;
			vector<Elevator>::iterator el;

			/*cout << "Passenger's data, who went out from elevator" << endl;
			cout << "SecondPass | TimePassCame | Elev | WaitTime(atFloor/inElev)" << endl;
			*/

			// Number of serviced passengers, needs for main clock loop
			int NumberServiced = 0;

			cout << "Please Wait" << endl;
			// Main clock
			for (int clock = 0; NumberServiced != arr.size(); clock++) {
				// loop for passengers
				for (int num = 0;  num < arr.size() && arr[num].getTime() < clock ; num++)
				{
					// Checking free elevator for human
					if (!arr[num].status && FindClosest(arr[num].getStart(), arr[num].getEnd(), elvs, &el)) {
						// if elevator was found, change status 
						arr[num].status = WAIT_ELEV;
						// add for elevator floor(human) for stop
						el->addStand(&arr[num]);
						// first increasing of counter 
						arr[num].incW();
					}
					// If wasn't found free elevator, passenger wait elevator or passenger is in elevator
					else {
						// increse counters
						if (arr[num].status == WAIT_ELEV || arr[num].status == WAIT) {
							arr[num].incW(); // counter for waiting time
						}
						if (arr[num].status == IN_ELEV) {
							arr[num].incE(); // counter for time in an Elevator
						}
					}
				}
				// loop all elevators
				for (int i = 0; i < elvs.size(); i++) {
					// main process function of elevator
					elvs[i].process(clock, avgW, avgE, NumberServiced);
				}
				
			}
			// output avg values
			cout << "Average wait time (" << speed << ")" << endl << "at Floor / in Elevator" << endl;
			FirstAvgW = avgW / arr.size();
			FirstAvgE = avgE / arr.size();
			cout << FirstAvgW << "s / " << FirstAvgE << "s " << endl;
			cout << (double)NumberServiced / arr.size() * 100 << " % of passenger was serviced" << endl << endl; // Output average data

			// deleting all data
			elvs.clear();
			delBuild(floor);
			delete floor;
			fin.close();
		}

		// Copy of first algorithm with and change one variable (time between floors)
		// It works the same

		{
			// set time for moving between floors
			int speed = 5;
			// make firstFloor (class Floor is double-linked list);
			Floor* floor = new Floor(1);
			// make build with 100 floors
			initBulid(floor, 100);

			// copy pointer to first floor
			Floor* FirstFloor = floor;

			vector<Elevator> elvs;

			// initialize elevators
			for (int i = 0; i < 4; i++) {
				// set pointer to 1st floor, number of elevator, number of start floor, speed(time of moving between floors)
				Elevator* el = new Elevator(FirstFloor, i + 1, 1, speed);
				elvs.push_back(*el);
			}

			// read data about passengers in Data_File_M10.csv and load data into array
			vector<Passenger> arr;
			ifstream fin("Data_File_M10.csv");
			ReadFile(floor, arr, fin);

			// make variables for waiting time(at floor, in elevator)
			double avgW = 0, avgE = 0;
			vector<Elevator>::iterator el;

			/*cout << "Passenger's data, who went out from elevator" << endl;
			cout << "SecondPass | TimePassCame | Elev | WaitTime(atFloor/inElev)" << endl;
			*/

			// Number of serviced passengers, needs for main clock loop
			int NumberServiced = 0;

			cout << "Please Wait" << endl;
			// Main clock
			for (int clock = 0; NumberServiced != arr.size(); clock++) {
				// loop for passengers
				for (int num = 0; num < arr.size() && arr[num].getTime() < clock; num++)
				{
					// Checking free elevator for human
					if (!arr[num].status && FindClosest(arr[num].getStart(), arr[num].getEnd(), elvs, &el)) {
						// if elevator was found, change status 
						arr[num].status = WAIT_ELEV;
						// add for elevator floor(human) for stop
						el->addStand(&arr[num]);
						// first increasing of counter 
						arr[num].incW();
					}
					// If wasn't found free elevator, passenger wait elevator or passenger is in elevator
					else {
						// increse counters
						if (arr[num].status == WAIT_ELEV || arr[num].status == WAIT) {
							arr[num].incW(); // counter for waiting time
						}
						if (arr[num].status == IN_ELEV) {
							arr[num].incE(); // counter for time in an Elevator
						}
					}
				}
				// loop all elevators
				for (int i = 0; i < elvs.size(); i++) {
					// main process function of elevator
					elvs[i].process(clock, avgW, avgE, NumberServiced);
				}

			}
			// output avg values
			cout << "Average wait time ("<< speed <<")" << endl << "at Floor / in Elevator" << endl;
			SecondAvgW = avgW / arr.size();
			SecondAvgE = avgE / arr.size();
			cout << SecondAvgW << "s / " << SecondAvgE << "s " << endl;
			cout << (double)NumberServiced / arr.size() * 100 << " % of passenger was serviced" << endl << endl; // Output average data

			// deleting all data
			elvs.clear();
			delBuild(floor);
			delete floor;
			fin.close();
		}


		cout << "Average time (at Floor) improves in " << (FirstAvgW - SecondAvgW) / FirstAvgW * 100 << "%" << endl;
		cout << "Average time (in Elev) improves in " << (FirstAvgE - SecondAvgE) / FirstAvgE * 100 << "%" << endl;

		cin.get();
	exit(0);
}