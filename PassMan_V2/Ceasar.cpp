#include "Ceasar.h"

using namespace std;


string Ceasar::encrypt(string str) {//returns encrypted password
	string cStr;
	for (int i = 0; i < str.size(); i++) {
		cStr += (int(str[i]) + 1);
	}
	return cStr;
}

string Ceasar::decrypt(string str) {//returns decrypted password
	return str;
}