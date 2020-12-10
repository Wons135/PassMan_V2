#include "Algorithm.h"

using namespace std;

void Algorithm::loadAscii() { //loads ascii table from text file
	table temp;
	ifstream ascii;
	ascii.open("ascii.txt");
	if (!ascii.is_open())
		cout << "Error opening file" << endl;;
	while (!ascii.eof()) {
		ascii >> temp.v;
		if (temp.v == "20") temp.c = ' ';
		else ascii >> temp.c;
		asciiTab.push_back(temp);
	}
	ascii.close();
}
string Algorithm::encrypt(string str) {
	return str;
}
string Algorithm::decrypt(string str) {
	return str;
}