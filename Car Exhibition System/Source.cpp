#include <iostream>
#include <string>
#include "Windows.h"
#include "Cars.h"
#include "Employees.h"
#include "Sales.h"
#include "Windows.h"
#include <fstream>
#include <iomanip> 

using namespace std;

// FUNCTIONS

void header() {
	system("cls");
	cout << "\t\t\t\t\t\t ***Car Exhibition System***" << endl;
	cout << endl; cout << endl;
}
void mainMenu() {
	cout << "\t\t\t1. View all cars." << endl;
	cout << "\t\t\t2. Add a car." << endl;
	cout << "\t\t\t3. Search for a car." << endl;
	cout << endl;

	cout << "\t\t\t4. View all sales." << endl;
	cout << "\t\t\t5. Add a successful sale." << endl;
	cout << endl;

	cout << "\t\t\t6. View all employees info." << endl;
	cout << "\t\t\t7. Add an employee" << endl;
	cout << "\t\t\t8. Remove an employee's info" << endl;
	cout << "\t\t\t9. Search for an employee." << endl;
	cout << endl;

	cout << "\t\t\t10. Change password." << endl;
	cout << "\t\t\t11. Exit" << endl;
	cout << endl;
}

void space4() {
	cout << "\t\t\t\t";
}
void space6() {
	cout << "\t\t\t\t\t\t";
}
void space7() {
	cout << "\t\t\t\t\t\t\t";
}

void limitCheck( int& number, int lowLimit, int highLimit) {
	while (number < lowLimit || number > highLimit) {
		space4(); cout << "Enter a valid input" << endl;
		space4(); cin >> number;
	}}
void limitCheck_ID(int& number, int lowLimit, long long highLimit) {
	while (number < lowLimit || number > highLimit) {
		space4(); cout << "Enter a valid input" << endl;
		space4(); cin >> number;
	}
}

void error_happen() {
	space4(); cout << "Error in data files" << endl;
	space4(); cout << "You'll be directed to Main Menu in 2 seconds.";
	Sleep(2000);
}
void back() {
	cout << endl;
	space4(); cout << "Press B/b to back to Main Menu : ";
	char b_choice;
	cin >> b_choice;
	while (b_choice != 'B' && b_choice != 'b') {
		space4(); cout << "Try again ! ";
		cin >> b_choice;
	}
}

// Main Function

int main() {

	header();
	
	//checking the password with the one stored in password.file
	{Getting_Password:
	space4(); cout << "\tEnter password to access : ";

	ifstream password_file;
	password_file.open("password.file");
	string stored_password;
	getline(password_file, stored_password);
	string password;
	getline(cin, password);
	while (password != stored_password) {
		cout << endl;
		space7(); cout << "Try again";
		Sleep(1500);
		header();
		goto Getting_Password;
	}
	password_file.close(); }

Main_Menu:

	header();
	mainMenu();

	space4();
	int choice1; //a number from main menu
	cin >> choice1;
	limitCheck(choice1, 1, 11);

	//View all cars
	if (choice1 == 1) {

		header();
		ifstream cars_file;
		cars_file.open("Cars.txt");

		if (cars_file.is_open()) {
			string line;
			while (getline(cars_file, line)) {
				cout << line << endl;
			}
			back();
			cars_file.close();
			goto Main_Menu;
		}
		else {
			error_happen();
			goto Main_Menu;
		}
	}

	//Add a car
	if (choice1 == 2) {
		header();
		Cars car_list[30];
		ofstream cars_file;
		cars_file.open("Cars.txt");
		if (cars_file.is_open()) {

			// The table first row
			cars_file << setw(25) << left << "Manufacture Company" << setw(25) << left << "Model"
				<< setw(25) << left << "Release year" << setw(16) << left << "Cost" << setw(5) << left << "No." << endl;
			cars_file << endl;

			// Taking data from the manager
			for (int j=0; j <= 30; ++ j) {
				cin.ignore(1000, '\n');
				space4(); cout << "Name of manufacturing company : ";
				string carCompany; getline(cin, carCompany);
				car_list[j].car_company = carCompany;
				cout << endl;

				space4(); cout << "Model name : ";
				string carModel; getline(cin, carModel);
				car_list[j].car_model = carModel;
				cout << endl;

				space4(); cout << "Cost : ";
				int cost; cin >> cost; limitCheck(cost, 50000, 5000000);
				//assuming no car - in the exhibition - is less than 50k or more than 5m
				car_list[j].price = cost;
				cout << endl;

				space4(); cout << "Release year : ";
				int carYear; cin >> carYear; limitCheck(carYear, 2010, 2022);
				car_list[j].release_year = carYear;
				cout << endl;

				space4(); cout << "Number of cars added : ";
				int carNumber; cin >> carNumber; limitCheck(carNumber, 1, 30);
				car_list[j].number = carNumber;
				cout << endl;

				cars_file << setw(25) << left << car_list[j].car_company << setw(25) << left << car_list[j].car_model
					<< setw(25) << left << car_list[j].release_year << setw(16) << left << car_list[j].price
					<< setw(5) << left << car_list[j].number << endl;

				space4(); cout << "Add another car (Y/N) ? : ";
				char more_choice;
				cin >> more_choice;
				while (more_choice != 'Y' && more_choice != 'y' && more_choice != 'N' && more_choice != 'n') {
					space4(); cout << "Enter a valid option : ";
					cin >> more_choice;
				}
				if (more_choice == 'Y' || more_choice == 'y') {
					cout << endl;
					continue;
				}
				else {
					cout << endl;
					space4(); cout << "You'll be directed to Main Menu in 2 seconds.";
					Sleep(2000);
					goto Main_Menu;
				}
			}
			cars_file.close();
		}
		else {
			error_happen();
			goto Main_Menu;
		}
	}

	//Search for a car
	if (choice1 == 3) {
		header();
		cout << "\t\t\t";  cout << "Enter any info about the car you want to search for (model/company) : ";
		string search_word;
		cin >> search_word;

		ifstream cars_file;
		cars_file.open("Cars.txt");

		if (cars_file.is_open()) {
			string line;
			while (getline(cars_file, line)) {
				if (line.find(search_word) != string::npos ) {
					cout << line << endl;
				}
			}
			back();
			goto Main_Menu;
		}
		else {
			error_happen();
			goto Main_Menu;
		}
		cars_file.close();
	}

	//View all sales
	if (choice1 == 4) {
		header();

		ifstream sales_file;
		sales_file.open("Sales.txt");

		if (sales_file.is_open()) {
			string line;
			while (getline(sales_file, line)) {
				cout << line << endl;
			}
			back();
			sales_file.close();
			goto Main_Menu;
		}
		else {
			error_happen();
			goto Main_Menu;
		}
	}

	// Add a successful sale
	if (choice1 == 5) {
		header();

		Sales sale_list[30];
		ofstream sales_file;
		sales_file.open("Sales.txt");

		if (sales_file.is_open()) {

			sales_file << setw(30) << left << "Client Name" << setw(30) << left << "Car Info" << setw(20) << left << "Date"
				<< setw(20) << left << "Time"<< endl;
			sales_file << endl;

			for (int j=0 ; j <= 29; ++j) {
				cin.ignore(1000, '\n');
				space4(); cout << "Client name : ";
				string clientName; getline(cin, clientName);
				sale_list[j].client_name = clientName;
				cout << endl;

				space4(); cout << "Car Info (company,model,release year) : ";
				string soldCarInfo; getline(cin, soldCarInfo);
				sale_list[j].sold_car_info = soldCarInfo;
				cout << endl;

				space4(); cout << "Date (day/month/year) : ";
				string date; getline(cin, date);
				sale_list[j].date = date;
				cout << endl;

				space4(); cout << "Time (hour:minute) : ";
				string time; getline(cin, time);
				sale_list[j].time = time;
				cout << endl;

				sales_file << setw(30) << left << sale_list[j].client_name << setw(30) << left << sale_list[j].sold_car_info
					<< setw(20) << left << sale_list[j].date << setw(20) << left << sale_list[j].time << endl;

				space4(); cout << "Add another sale (Y/N) ? : ";
				char more_choice;
				cin >> more_choice;
				while (more_choice != 'Y' && more_choice != 'y' && more_choice != 'N' && more_choice != 'n') {
					space4(); cout << "Enter a valid option : ";
					cin >> more_choice;
				}
				if (more_choice == 'Y' || more_choice == 'y') {
					cout << endl;
					continue;
				}
				else {
					cout << endl;
					space4(); cout << "You'll be directed to Main Menu.";
					Sleep(2000);
					goto Main_Menu;
				}
			}
			sales_file.close();
		}
		else {
			error_happen();
			goto Main_Menu;
		}
	}

	// View all employees info
	if (choice1 == 6) {
		header();

		ifstream employees_file;
		employees_file.open("Employees.txt");

		if (employees_file.is_open()) {
			string line;
			while (getline(employees_file, line)) {
				cout << line << endl;
			}
			back();
			employees_file.close();
			goto Main_Menu;
		}
		else {
			error_happen();
			goto Main_Menu;
		}
	}

	// Add an employee
	if (choice1 == 7) {
		header();

		Employees employee_list[30];
		ofstream employees_file;
		employees_file.open("Employees.txt");

		if (employees_file.is_open()) {

			employees_file << setw(30) << left << "Full Name" << setw(15) << left << "National ID" << setw(25) << left << "Job position"
				<< setw(10) << left << "Salary"<< endl;
			employees_file << endl;

			for (int i = 1; i <= 31; ++i) {
				cin.ignore(1000, '\n');
				space4(); cout << "Full name of the employee : ";
				string fullName; getline(cin, fullName);
				employee_list[i].full_name = fullName;
				cout << endl;

				space4(); cout << "National ID : ";
				int nationalID; cin >> nationalID; limitCheck_ID(nationalID, 0, 999999999999999);
				//IDs is 15-digit long
				employee_list[i].id = nationalID;
				cout << endl;

				cin.ignore(1000, '\n');
				space4(); cout << "Job position : ";
				string job; getline(cin, job);
				employee_list[i].job = job;
				cout << endl;

				space4(); cout << "Salary : ";
				int salary; cin >> salary; limitCheck(salary, 1000, 50000);
				//assuming no salary is less that 1k or more than 50k
				employee_list[i].salary = salary;
				cout << endl;

				employees_file << setw(30) << left << employee_list[i].full_name << setw(15) << left << employee_list[i].id << setw(25)
					<< left << employee_list[i].job << setw(10) << left << employee_list[i].salary << endl;

				space4(); cout << "Add another employee (Y/N) ? : ";
				char more_choice;
				cin >> more_choice;
				while (more_choice != 'Y' && more_choice != 'y' && more_choice != 'N' && more_choice != 'n') {
					space4(); cout << "Enter a valid option : ";
					cin >> more_choice;
				}
				if (more_choice == 'Y' || more_choice == 'y') {
					cout << endl;
					continue;
				}
				else {
					cout << endl;
					space4(); cout << "You'll be directed to Main Menu in 2 seconds.";
					Sleep(2000);
					goto Main_Menu;
				}
			}
			employees_file.close();
		}
		else {
			error_happen();
			goto Main_Menu;
		}
	}

	// Remove an employee's info
	if (choice1 == 8) {
		header();

		ifstream employees_file; employees_file.open("Employees.txt"); //regular employees file
		ifstream employees_file_edit; employees_file_edit.open("Employees.txt"); //same file for editing operations
		ofstream temp; temp.open("temp.txt");
		
		if (employees_file.is_open()) {
			string line;
			while (getline(employees_file, line)) {
				cout << line << endl;
			}
			cout << endl;
			cout << "\t\t\t";; cout << "Enter the index number of the employee you want to remove : ";
			int remove_index; cin >> remove_index; limitCheck(remove_index, 1, 31);
			cout << endl;

			if (temp.is_open()) {
				int count = 0;

				while (getline(employees_file_edit, line)) {

					if (count == (remove_index + 1)) {
						// so here, when the required line is reached, it's not copied to the new file.
					}
					else { temp << line << endl; }// copying the lines to a temp text file
					count++;
				}
				
				employees_file.close(); temp.close(); employees_file_edit.close();

				char employees_old_file[] = "Employees.txt";
				char old_tmep[] = "temp.txt";
				char new_file[] = "Employees.txt";

				if (remove(employees_old_file) == 0) {

					if (rename(old_tmep, new_file) == 0) {//remove() & rename() functions need char parameters the point to the files
						header();
						space4(); cout << "Updated !" << endl;
						space4(); cout << "You'll be directed to Main Menu.";
						Sleep(2000);
						goto Main_Menu;
					}
					else {
						error_happen();
						goto Main_Menu;
					}
					
				}
				else {
					error_happen();
					goto Main_Menu;
				}
			}
			else {
				error_happen();
				goto Main_Menu;
			}
		}
		else {
			error_happen();
			goto Main_Menu;
		}
	}

	// Search for an employee
	if (choice1 == 9) {
		header();

		space4();  cout << "Enter any info about the employee you want to search for : ";
		string search_word;
		cin >> search_word;

		ifstream employees_file;
		employees_file.open("Employees.txt");

		if (employees_file.is_open()) {
			string line;
			while (getline(employees_file, line)) {
				if (line.find(search_word) != string::npos ) {
					cout << line << endl;
				}
			}
			back();
			goto Main_Menu;
		}
		else {
			error_happen();
			goto Main_Menu;
		}
		employees_file.close();
	}

	// Change password
	if (choice1 == 10) {
		header();

		space4(); cout << "Enter the new password : ";
		string new_pass;
		cin >> new_pass;

		ofstream password_file_new;
		password_file_new.open("password.file");
		password_file_new << new_pass;;
		password_file_new.close();

		space4(); cout << "New password is saved !" << endl;
		space4(); cout << "You'll be directed to Main Menu in 2 seconds.";
		Sleep(2000);
		goto Main_Menu;
	}

	// Exit
	if (choice1 == 11) {
		return 0;
	}
}

// Osama Muhammad