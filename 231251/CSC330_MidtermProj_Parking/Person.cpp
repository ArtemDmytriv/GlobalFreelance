#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{

}
Person::Person(string inName)
{
	name = inName;
}

string Person::getName()
{
	return name;
}

//void Person::setName(string inName)
//{
//	name = inName;
//}

int Person::getTotal()
{
	return total;
}

void Person::setTotal(int inTotal)
{
	total = inTotal;
}