#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

void viewEmployees();

struct Employees {

	string full_name;
	int id{};
	string job;
	int salary{};
};
