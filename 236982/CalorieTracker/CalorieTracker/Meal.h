#pragma once
#include "head.h"
#include "Food.h"

class Meal {
private:
	string name;
	int countFood;
	int countBeverage;
	vector <Food> food;
	vector <Beverage> bev;

public:
	enum type { FOOD, BEVERAGE};

	Meal() : name(""), countFood(0), countBeverage(0) {}
	Meal(string n) : name(n), countFood(0), countBeverage(0) {}

	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}

	int find(string name) // finds number of food in Meal array 
	{
		for (int i = 0; i < food.size(); i++) {
			if (name == food[i].getName()) {
				return i;
			}
		}
		for (int i = 0; i < bev.size(); i++) {
			if (bev[i].getName() == name) {
				return i;
			}
		}
		return -1; // if not found
	}
	void del(string name) { // delete food from meal
		int num = find(name); // searches food by name
		while (num != -1) { // if food has been found
			if (name == food[num].getName()) {
				food.erase(food.begin() + num);
				countFood--;
			}
			else {
				bev.erase(bev.begin() + num);
				countBeverage--;
			}
			cout << name << " has been successful deleted" << endl;
			num = find(name);
		}
	}
	void add(Food& mfood, type t = FOOD, int count = 1) {
		if (t == FOOD) {
			while (count > 0) {
				food.push_back(mfood);
				count--;
				countFood++;
			}
		}
		else {
			while (count > 0) {
				bev.push_back(Beverage(mfood.getName(), mfood.getFat(), mfood.getProtein(), mfood.getCarbohydrates()));
				count--;
				countBeverage++;
			}
		}
	}

	double totalCalories() {
		double  sum = 0;
		for (auto item : food) {
			sum += item.totalCalories();
		}
		for (auto item : bev) {
			sum += item.totalCalories();
		}
		return sum;
	}

	void display(ostream& os = cout) {
		os << "\t\t<<" << name << ">>" << endl;
		os << "\tFoods:" << endl;
		for (int i = 0; i < food.size(); i++) {
			cout << '\t' <<i + 1 << '\t';
			food[i].display(os);
		}
		os << "\tDrinks:" << endl;
		for (int i = 0; i < bev.size(); i++) {
			cout << '\t' << i + 1 << '\t';
			bev[i].display(os);
		}
		os << endl << "\tTotal calories: " << totalCalories() << " cal" << endl;
		os << "--------------------------------------------------------" << endl;
	}
	void writeBinary(ostream& os) {
		// writes name of meal
		int len = name.size();
		os.write((char*)& len, sizeof(len));
		os.write((char*)name.c_str(), len);

		// writes foods
		os.write((char*)& countFood, sizeof(countFood)); // writes count of foods in binary
		for (int i = 0; i < countFood; i++) {
			food[i].writeBinary(os);
		}

		// writes drinks
		os.write((char*)& countBeverage, sizeof(countBeverage));  // writes count of beverages in binary
		for (int i = 0; i < countBeverage; i++) { 
			bev[i].writeBinary(os);
		}
	}
	void readBinary(istream& is) {
		// reads name of meal
		int len;
		is.read((char*)& len, sizeof(len));
		name.resize(len); // resize Meal name
		is.read(&name[0], len); // fill Meal name with char from binary file 
		
		// reads foods
		is.read((char*)& countFood, sizeof(countFood));
		food.resize(countFood);
		for (int i = 0; i < countFood; i++) {
			food[i].readBinary(is);
		}
		// reads drinks
		is.read((char*)& countBeverage, sizeof(countBeverage));
		bev.resize(countBeverage);
		for (int i = 0; i < countBeverage; i++) {
			bev[i].readBinary(is);
		}
	}
};

