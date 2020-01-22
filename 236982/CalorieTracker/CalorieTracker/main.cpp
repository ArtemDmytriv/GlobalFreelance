#include "head.h"
#include "Meal.h"
#include "Food.h"

int main() {
	
	const int N = 5; // 5 meals (3 main meals, 2 snacks)
	Meal dayRation[N]; 
	
	/* Data for first start (without binary file)
	dayRation[0].setName("Breakfast");
	dayRation[1].setName("Snack 1");
	dayRation[2].setName("Lunch");
	dayRation[3].setName("Snack 2");
	dayRation[4].setName("Dinner");
	*/

	// reading data from binary file
	fstream fin("Day.dat", ios::in | ios::binary);
	if (fin.good()) {
		for (auto & meal : dayRation) {
			meal.readBinary(fin);
		}
	}
	fin.close();
	
	// set target value
	double target;
	cout << "Please set your target calories value: ";
	cin >> target;
	cin.get();
	//

	// choice - system variable for moving in menu
	int choice = 1;

	// main cycle
	while (choice != 6) { // 6 for Exit
		printMenu(); // prints menu interface
		choice = UserInputInt();

		switch (choice)
		{
		case 1:
			printBriefDayRation(dayRation, N, target); // brief info about all 5 meals (3 meals, 2 snacks) 
			break;
		case 2: 
			printAllDayRation(dayRation, N, target); // wide version of meals info
			break;
		case 3:
			addMenu(dayRation, N); // func, that call "add menu", user can add new food/drink to all meals
			break;
		case 4:
			delMenu(dayRation, N); // func, that call "delete menu", user can delete food/drink from meals
			break;
		case 5: // set new calories target
			cout << endl << "New target = ";
			cin >> target;
			cin.get();
			break;
		case 6:
			cout << "Good Bye" << endl;
			break;
		default:
			cout <<"Unknown choice, try again" << endl;
			break;
		}

	}

	// saving data in file Day.dat
	fstream fout("Day.dat", ios::out | ios::binary);
	for (auto meal : dayRation) {
		meal.writeBinary(fout);
	}

	fout.close();
	return 0;
}