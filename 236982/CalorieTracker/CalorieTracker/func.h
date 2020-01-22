#pragma once
#include "head.h"
#include "Meal.h"
#include "Food.h"

int UserInputInt();
void printMenu();
void printAllDayRation(Meal dayRation[], const int n, double target);
void printBriefDayRation(Meal dayRation[], const int n, double target);

void addMenu(Meal dayRation[], const int n);
void addFoodMenu(Meal& meal);
void delMenu(Meal dayRation[], const int n);
void delFoodMenu(Meal& meal);