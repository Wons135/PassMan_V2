#pragma once
#include "Manage.h" //class containing apps services
#include "Generator.h" //class conating MD5 algorithm
#include "User.h" //class containing user validation feature
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <fstream>
//#include <windows.h>
#include <string>
#include <sstream>
//memory leak 
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>



using namespace std;

int main() {

	User user;
	Manage app;
	int menu, id;
	string site, login, pass;
	Generator gen;
	if (user.access) {
		app.initialize();

		cout << "Menu:" << endl;
		cout << "1. Read password." << endl;
		cout << "2. Add password." << endl;
		cout << "3. Delete password." << endl;
		cout << "4. Edit password." << endl;
		cout << "5. Add generated password (recommended for secuity)." << endl;
		cout << "6. Replace your password with a generated one (recommended ofr security)." << endl;
		cout << "7. Save and exit." << endl;

		while (true) {
			cout << "What would you like to do?";
			cin >> menu;
			cout << endl;
			switch (menu) {
			case 1: //read one decrypted password
				cout << "Id of the entry you want to see:";
				cin >> id;
				app.showPass(id);
				break;
			case 2: //add password to the base 
				cout << "Site:" << endl;
				cin >> site;
				cout << "Login:" << endl;
				cin >> login;
				cout << "Password:" << endl;
				cin >> pass;
				app.addPass(site, login, pass);
				break;
			case 3: //delete one password
				cout << "Id of entry to be deleted:";
				cin >> id;
				app.deletePass(id);
				break;
			case 4: //edit password
				cout << "Id of entry to be edited:";
				cin >> id;
				cout << "Your new password:";
				cin >> pass;
				app.editPass(id, pass);
				break;
			case 5: //add generated password
				cout << "Site:" << endl;
				cin >> site;
				cout << "Login:" << endl;
				cin >> login;
				pass = gen.generate();
				app.addPass(site, login, pass);
				break;
			case 6: //replace with generated password
				cout << "Id of entry to be edited:";
				cin >> id;
				pass = gen.generate();
				app.editPass(id, pass);
				break;
			case 7: // save and exit
				app.saveChanges();
				/*_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();*/
				return 0;
				break;
			}
		}

	}

	return 0;
}




