#include "Manage.h"

using namespace std;

bool Manage::isEmpty(fstream& file) { //checks if text file is  empty
	return file.peek() == fstream::traits_type::eof();
}

void Manage::initialize() {//method that to reads the content of the file and save it to the vector
	string line;
	if (isEmpty(base)) {//asks user to set up a password
		cout << "Looks like your database is empty, add your first entry! \nSite: ";
		cin >> site;
		cout << "Login: ";
		cin >> login;
		cout << "Password: ";
		cin >> pass;
		addPass(site, login, pass);
	}
	else {
		cout << "Id, info, login, password" << endl;
		while (getline(base, line)) {
			istringstream iss(line);
			int key;
			string info, login, pass;

			iss >> key >> info >> login >> pass;
			tuple<int, string, string, string> temp(key, info, login, pass);
			storeAll.push_back(temp);
		}

		for (int i = 0; i < storeAll.size(); i++) {
			cout << get<0>(storeAll[i]) << ". " << get<1>(storeAll[i]) << ": " << get<2>(storeAll[i]) << ", " << get<3>(storeAll[i]) << endl;
		}
		base.close();
	}
}

void Manage::showPass(int id) {//reads one password requested by user
	for (int i = 0; i < storeAll.size(); i++) {
		if (id == get<0>(storeAll[i])) cout << "Id: " << to_string(get<0>(storeAll[i])) << " Site: " << get<1>(storeAll[i]) << " Login: " << get<2>(storeAll[i]) << " Password: " << alg->decrypt(get<3>(storeAll[i]));
	}
	cout << endl;
}

void Manage::addPass(string info, string login, string password) {//adds tuple of information to the end of vector
	int id = storeAll.size() + 1;
	if (checkPassStrength(password) < 75) cout << "Your password is weak, please consider changing it!!" << endl;
	storeAll.push_back(tuple<int, string, string, string>(id, info, login, alg->encrypt(password)));
	cout << endl;

}

void Manage::editPass(int id, string password) {//changes passowrds at the choosen key
	if (checkPassStrength(password) < 75) cout << "Your password is weak, please consider changing it!!" << endl;
	for (int i = 0; i < storeAll.size(); i++) {
		if (id == get<0>(storeAll[i])) {
			string newInfo = get<1>(storeAll[i]);
			string newLogin = get<2>(storeAll[i]);
			string newPass = get<3>(storeAll[i]);
			deletePass(id);
			addPass(newLogin, newLogin, newPass);
		}
	}
}

void Manage::deletePass(int id) {//deletes choosen password along with all the information

	storeAll.erase(std::remove_if(storeAll.begin(), storeAll.end(), [&id](const auto& tuple) {return get<0>(tuple) == id; }));
}

int Manage::checkPassStrength(string password) {//checks the strength of password
	int strength = 0;
	bool length = false, specialChar = false, number = false, capitalLetter = false;

	if (password.size() >= 8) {
		strength += 25;
		length = true;
	}

	for (char c : password) {
		if (((c >= 33 && c <= 47) || (c >= 58 && c <= 64)) && !specialChar) {
			strength += 25;
			specialChar = true;
		}
		if ((c >= 48 && c <= 57) && !number) {
			strength += 25;
			number = true;
		}
		if ((c >= 65 && c <= 90) && !capitalLetter) {
			strength += 25;
			capitalLetter = true;
		}
	}
	return strength; //strength higher than 75 yields an acceptable password
}

void Manage::saveChanges() {
	save.open("database.txt", fstream::in | fstream::out | fstream::trunc);
	if (save) {
		for (int i = 0; i < storeAll.size(); i++) {
			save << get<0>(storeAll[i]) << " " << get<1>(storeAll[i]) << " " << get<2>(storeAll[i]) << " " << get<3>(storeAll[i]) << "\n";
			save.flush();
		}
	}
	else cout << "Couldn't save the data, contact support!";
}