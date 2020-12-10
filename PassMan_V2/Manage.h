#pragma once
#include "RSA.h"
#include "Algorithm.h"
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <fstream>
//#include <windows.h> used before for hiding file
#include <string>
#include <sstream>

using namespace std;

class Manage {
private:
	vector<tuple<int, string, string, string>> storeAll; //stores key and information of all passwords
	string site, login, pass;
	Algorithm* alg = new RSA();
public:
	fstream base;
	fstream save;
	Manage() {
		base.open("database.txt", fstream::in | fstream::out);
		/*const wchar_t* file = L"dupa.txt";

		int attr = GetFileAttributes(file);
		
		if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
			SetFileAttributes(file, attr | FILE_ATTRIBUTE_HIDDEN);
		}*/
		if (!base)cout << "Can't open database!" << endl;
	}

	bool isEmpty(fstream& file);
	void initialize();
	void showPass(int id);
	void addPass(string info, string login, string password);
	void editPass(int id, string password);
	void deletePass(int id);
	int checkPassStrength(string password);
	void saveChanges();

	~Manage() {
		base.close();
		delete alg;
	}
};