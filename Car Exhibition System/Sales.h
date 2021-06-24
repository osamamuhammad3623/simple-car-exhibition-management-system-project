#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

void viewSales();
void addSales(ofstream *sales_file);

struct Sales {
	string client_name;
	string sold_car_company;
	string sold_car_model;
	string sold_car_release_year;
	int price{};
	string date;
	string time;
};
