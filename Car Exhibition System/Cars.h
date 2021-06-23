#include <iostream>
#include <string>
#include "SysFunctions.h"

using namespace std;

void viewCars();
void addCars(ofstream *cars_file);
void searchForCars(ifstream *cars_file, string search_word);

struct Cars {
	string car_company;
	string car_model;
	int price{};
	int release_year{};
	int number{};
};
