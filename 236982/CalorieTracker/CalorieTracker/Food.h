#pragma once
#include "head.h"

class Food { // class for food
private:
	string name; // name of food
	double fat; // count of fat
	double protein; // count of protein
	double carbohydrates;
public:
	Food() : name("None"), fat(0), protein(0), carbohydrates(0) { }
	Food(string n, double f, double p, double c) : name(n), fat(f), protein(p), carbohydrates(c) { }

	double totalCalories() {
		return 4 * (carbohydrates + protein) + fat * 9;
	}

	string getName() { return name; }
	double getFat() { return fat; }
	double getProtein() { return protein; }
	double getCarbohydrates() { return carbohydrates; }

	void setName (string mname) { 
		name = mname; 
	}
	void setFat(double mfat) {
		fat = mfat >= 0 ? mfat : 0 ; 
	}
	void setProtein(double mprotein) { 
		protein = mprotein >= 0 ? mprotein : 0;
	}
	void setCarbohydrates(double mcarbohydrates) {
		carbohydrates = mcarbohydrates >= 0 ? mcarbohydrates : 0;
	}

	virtual void display(ostream& os = cout) {
		os << "(Food) " << this->getName() << ": fat " << this->getFat() << "g, protein ";
		os << this->getProtein() << "g, carbohydrates " << this->getCarbohydrates() << "g" << endl;
	}

	void writeBinary(ostream& os) {
		os.write((char*)&fat, sizeof(fat));
		os.write((char*)&protein, sizeof(protein));
		os.write((char*)&carbohydrates, sizeof(carbohydrates));
		int len = name.size(); // save length of name
		os.write((char*)& len, sizeof(len)); // write length
		os.write((char*)name.c_str(), len); // write data in file, func name.c_str() returns food name as array of chars.
	}

	void readBinary(istream& is) {
		is.read((char*)& fat, sizeof(fat));
		is.read((char*)& protein, sizeof(protein));
		is.read((char*)& carbohydrates, sizeof(carbohydrates));
		int len;
		is.read((char*)& len, sizeof(len));
		name.resize(len); // resize Meal name
		is.read(&name[0], len); // fill Meal name with char from binary file 
	}
};

class Beverage : public Food {
public:
	Beverage() : Food() {}
	Beverage(string name, double f, double p, double c) : Food(name, f, p, c) {}

	virtual void display(ostream& os = cout){
		os << "(Bev) " << this->getName() << " : fat " << this->getFat() << "g, protein ";
		os << this->getProtein() << "g, carbohydrates " << this->getCarbohydrates() << "g" << endl;
	}
};

