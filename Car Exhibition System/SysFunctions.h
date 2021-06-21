#include <iostream>
using namespace std;

#ifndef SYSFUNCTIONS
#define SYSFUNCTIONS

void header();
void mainMenu();
void check_password();
void space(short n);
void limitCheck( int& number, int lowLimit, int highLimit);
void limitCheck_ID(int& number, int lowLimit, long long highLimit);
void re_directed();
void error_happen() ;
void back();
bool is_empty_file(string file_name);
void change_password();

#endif