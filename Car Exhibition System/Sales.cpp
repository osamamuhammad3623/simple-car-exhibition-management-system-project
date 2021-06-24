#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Windows.h"
#include "SysFunctions.h"
#include "Sales.h"

using namespace std;

void viewSales(){

    ifstream *sales_file = new ifstream();
    (*sales_file).open("Sales.txt");

    if ((*sales_file).is_open())
    {
        string line;
        while (getline(*sales_file, line))
        {
            cout << line << endl;
        }
        back();
        (*sales_file).close();
    }
    else
    {
        error_happen();
    }
}

void fillTableHeader(ofstream *sales_file)
{
    *sales_file << setw(30) << left << "Client Name" << setw(10) << left
    << "Company" << setw(10) << left << "Model" << setw(10) << left
    << "Release year" << setw(10) << left << "Price" << setw(15) << left
    << "Date" << setw(15) << left << "Time\n\n";
}

void addSales(ofstream *sales_file){

    if (is_empty_file("Sales.txt"))
	{
		fillTableHeader(sales_file);
	}

    // Taking data from the manager
	space(4);
	cout << "How many sales do you want to add : ";
	int n;
	cin >> n;

    vector <Sales> sale_list= vector<Sales>(n);
    for (short j = 0; j < n; ++j)
    {
        space(4);
        cout << "Client name : ";
        string clientName;
        getline(cin, clientName);
        sale_list[j].client_name = clientName;
        cout << endl;

        space(4);
        cout << "Car Company : ";
        string soldCarCompany;
        getline(cin, soldCarCompany);
        sale_list[j].sold_car_company = soldCarCompany;
        cout << endl;

        space(4);
        cout << "Car Model : ";
        string soldCarModel;
        getline(cin, soldCarModel);
        sale_list[j].sold_car_model = soldCarModel;
        cout << endl;

        space(4);
        cout << "Release year : ";
        string soldCarReleaseYear;
        getline(cin, soldCarReleaseYear);
        sale_list[j].sold_car_release_year = soldCarReleaseYear;
        cout << endl;

        space(4);
        cout << "Price : ";
        short price;
        cin >> price;
        sale_list[j].price = price;
        cout << endl;

        space(4);
        cout << "Date : ";
        string date;
        getline(cin, date);
        sale_list[j].date = date;
        cout << endl;

        space(4);
        cout << "Time : ";
        string time;
        getline(cin, time);
        sale_list[j].time = time;
        cout << endl;

        *sales_file << setw(30) << left << sale_list[j].client_name << setw(10) << left
        << sale_list[j].sold_car_company << setw(10) << left << sale_list[j].sold_car_model
        << setw(10) << left << sale_list[j].sold_car_release_year << setw(10) << left
        << sale_list[j].price << setw(15) << left << sale_list[j].date << setw(15) << left
        << sale_list[j].time << endl;

    }
    (*sales_file).close();
}