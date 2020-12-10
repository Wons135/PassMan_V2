#pragma once
#include "algorithm.h"
#include "RSA.h"
#include "Ceasar.h"
#include <iostream>
#include <stdlib.h>
#include <tuple>
#include <cmath>
#include <vector>
#include <fstream>
//#include <windows.h>
#include <string>
#include <sstream>

using namespace std;

class User {	//class used to authorize user's access to the program, using a separate textfile and algorithm 
private:
	int tries = 0;
	int choice = 0;
	string userPass;
	string check;
	Algorithm* alg;
	int alChoice = 0;
public:
	fstream user;
	ofstream setP;
	bool access = 0;
	User() {
		user.open("validate.txt", fstream::in | fstream::out);
		/*const wchar_t* file = L"validate.txt";

		int attr = GetFileAttributes(file);

		if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
			SetFileAttributes(file, attr | FILE_ATTRIBUTE_HIDDEN);
		}*/
		if (!user)cout << "Can't open file!" << endl;
		else {
		    	cout << "Which algorithm would you like to use for your password (also used as a 2-step verification)? \n1.RSA\n2.Ceasar" << endl;
			do {
				cin >> alChoice;
			} while (alChoice != 1 && alChoice != 2);

			if (alChoice == 1) {
				alg = new RSA();
			}
			else if (alChoice == 2) {
				alg = new Ceasar();
			}
			else cout << "Error occured during algorithm choosing!" << endl;

			if (isEmpty(user)) {//asks user to set up a password
				cout << "Welcome to Password Manager, please set up a password:";
				cin >> userPass;
				setPass(userPass);
			}
			else {//ask user to type in password and check for validation
				cout << "Welcome to Password Manager, please sign in." << endl;
				cout << "1. Sign in." << endl;
				cout << "2. Change password" << endl;

				do {
					cin >> choice;
					if (choice == 1) {
						getline(user, userPass);
						logIn(userPass);
					}
					else if (choice == 2) {
						getline(user, userPass);
						changePass(userPass);
					}
					else {
						cout << "Please choose option 1 or 2 by typing in the numbers." << endl;
					}
				} while (!access);

			}
		}
	}

	bool isEmpty(fstream& file);
	void setPass(string pass);
	void logIn(string userPass);
	void changePass(string userPass);

	~User() {
		setP.close();
		delete alg;
	}
};