#include <iostream>
#include <string>
#include <fstream>
#include "Windows.h"
using namespace std;

void header() {
	system("cls");
	cout << "\t\t\t\t\t ***Exhibition Management System***" << endl;
	cout << "\n\n";
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

void space(short n) {
	for (int i = 0; i < n; i++) {
		cout << "\t";
	}
}

void check_password(){
	Getting_Password:
	space(4); cout << "\tEnter password to access : ";

	ifstream password_file;
	password_file.open("password.file");
	string stored_password;
	getline(password_file, stored_password);
	string password;
	getline(cin, password);
	while (password != "osama") {
		cout << endl;
		space(7); cout << "Try again";
		Sleep(1500);
		header();
		goto Getting_Password;
	}
	password_file.close(); 
}

void limitCheck( int& number, int lowLimit, int highLimit) {
	while (number < lowLimit || number > highLimit) {
		space(4); cout << "Enter a valid input" << endl;
		space(4); cin >> number;
	}
}

void limitCheck_ID(int& number, int lowLimit, long long highLimit) {
	while (number < lowLimit || number > highLimit) {
		space(4); cout << "Enter a valid input" << endl;
		space(4); cin >> number;
	}
}

void re_directed() {
	space(4); cout << "You'll be directed to Main Menu in 2 seconds.";
	Sleep(2000);
}

void error_happen() {
	space(4); cout << "Error in data files" << endl;
	re_directed();
}

void back() {
	cout << endl;
	space(4); cout << "Press B/b to back to Main Menu : ";
	char b_choice;
	cin >> b_choice;
	while (b_choice != 'B' && b_choice != 'b') {
		space(4); cout << "Try again ! ";
		cin >> b_choice;
	}
}

bool is_empty_file(string file_name) {
	ifstream file; file.open(file_name);
	return (file.peek() == ifstream::traits_type::eof());
}

void change_password(){
	space(4); cout << "Enter the new password : ";
	string new_pass;
	cin >> new_pass;
	ofstream password_file_new;
	password_file_new.open("password.file");
	password_file_new << new_pass;
	password_file_new.close();
	space(4); cout << "New password is saved !" << endl;
}

// void acceptValidInput(){
// 	char addOneMore;
// 	cin >> addOneMore;
// 	while (addOneMore != 'Y' && addOneMore != 'y' && addOneMore != 'N' && addOneMore != 'n') {
// 		space(4); cout << "Enter a valid option : ";
// 		cin >> addOneMore;
// 	}
// 	if (addOneMore == 'Y' || addOneMore == 'y') {
// 		cout << endl;
// 	}
// 	else {
// 		cout << endl;
// 		space(4);
// 		cout << "You'll be directed to Main Menu.";
// 		Sleep(2000);
// 	}
// }