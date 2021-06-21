#include <iostream>
#include <string>
#include "SysFunctions.h"

using namespace std;

void viewCars();
void addCars();

struct Cars {
	string car_company;
	string car_model;
	int price{};
	int release_year{};
	int number{};
};
