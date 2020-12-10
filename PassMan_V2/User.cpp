#include "User.h"


using namespace std;

bool User::isEmpty(fstream& file) { //checks if text file is  empty
	return file.peek() == fstream::traits_type::eof();
}

void User::setPass(string pass) {
	setP.open("validate.txt", ofstream::in | ofstream::trunc);
	setP << alg->encrypt(pass);
	cout << endl;
	cout << "Program will now exit to save your password. Please restart." << endl;
	exit(1);
}

void User::logIn(string userPass) {
	do {
		cout << "Verify your acces:";
		cin >> check;
		tries++;
		if (alg->encrypt(check) != userPass) {
			cout << "Wrong password! " << 5 - tries << "tries left!" << endl;
		}
		if (tries == 5)  exit(1);

	} while (alg->encrypt(check) != userPass);

	cout << "Access granted! \n";
	access = 1;
}

void User::changePass(string userPass) {
	string newPass;
	logIn(userPass);
	if (access) {
		cout << "Please enter your new password:";
		do {
			cin >> newPass;
			if (newPass == userPass) cout << "New Password can't be the same as old one." << endl;
		} while (newPass == userPass);

		cout << endl;

		setPass(newPass);
	}

}