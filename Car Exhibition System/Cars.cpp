#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Windows.h"
#include "SysFunctions.h"
#include "Cars.h"

using namespace std;

void viewCars()
{
	ifstream *cars_file = new ifstream();
	(*cars_file).open("Cars.txt");

	if ((*cars_file).is_open()){

		string line;
		while (getline(*cars_file, line))
		{
			cout << line << endl;
		}
		back();
		(*cars_file).close();
	}
	else
	{
		error_happen();
	}
}

void fillTableHeader(ofstream *cars_file)
{
	*cars_file << setw(25) << left << "Manufacture Company" << setw(25) << left
		<< "Model" << setw(25) << left << "Release year" << setw(16) << left << "Cost" 
		<< setw(5) << left << "No.\n\n";
}

void addCars(ofstream *cars_file)
{
	if (is_empty_file("Cars.txt"))
	{
		fillTableHeader(cars_file);
	}

	// Taking data from the manager
	space(4);
	cout << "How many cars do you want to add : ";
	int n;
	cin >> n;

	vector <Cars> car_list= vector<Cars>(n);
	for (short j = 0; j < n; ++j)
	{
		space(4);
		cout << "Name of manufacturing company : ";
		string carCompany;
		getline(cin, carCompany);
		car_list[j].car_company = carCompany;
		cout << endl;

		space(4);
		cout << "Model name : ";
		string carModel;
		getline(cin, carModel);
		car_list[j].car_model = carModel;
		cout << endl;

		space(4);
		cout << "Cost : ";
		//assuming no car is less than 20k or more than 5m
		int cost;
		cin >> cost;
		limitCheck(cost, 2e4, 5e6);
		car_list[j].price = cost;
		cout << endl;

		space(4);
		cout << "Release year : ";
		int carYear;
		cin >> carYear;
		limitCheck(carYear, 2010, 2022);
		car_list[j].release_year = carYear;
		cout << endl;

		space(4);
		cout << "Number of cars added : ";
		int carNumber;
		cin >> carNumber;
		limitCheck(carNumber, 1, 30);
		car_list[j].number = carNumber;
		cout << endl;

		(*cars_file) << setw(25) << left << car_list[j].car_company << setw(25) << left 
			<< car_list[j].car_model << setw(25) << left << car_list[j].release_year <<
			setw(16) << left << car_list[j].price << setw(5) << left << car_list[j].number << endl;
	}
	(*cars_file).close();
}

void searchForCars(ifstream *cars_file, string search_word){
	string line;
	while (getline(*cars_file, line))
	{
		if (line.find(search_word) != string::npos)
		{
			cout << line << endl;
		}
	}

	back();
}