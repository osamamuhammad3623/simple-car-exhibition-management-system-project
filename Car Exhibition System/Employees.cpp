#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Windows.h"
#include "SysFunctions.h"
#include "Employees.h"

using namespace std;

void viewEmployees()
{
	ifstream *employees_file = new ifstream();
	(*employees_file).open("Employees.txt");

	if ((*employees_file).is_open()){

		string line;
		while (getline(*employees_file, line))
		{
			cout << line << endl;
		}
		back();
		(*employees_file).close();
	}
	else
	{
		error_happen();
	}
}
