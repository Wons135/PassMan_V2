#include "RSA.h"

using namespace std;

double RSA::toNum(string str) { //connverts hexadecimalcode to double
	double num = 0;
	const char* tempc;
	string tempStr = "";
	double x = 0.00;
	for (int i = 0; i < str.size(); i++) {
		double x = str.size() - (i + 1.0);
		tempStr = str.substr(i, 1);
		tempc = tempStr.c_str();
		if (isalpha(double(*tempc))) num += (double(*tempc) - 55) * pow(16.0, x);
		else num += (double(*tempc) - 48) * pow(16.0, x);
	}
	return num;
}

double RSA::powBig(double num, int exp, int mod) {//alternative of storage of big numbers
	double sum = num;
	for (int i = exp; i > 1; i--) {
		sum = int((num * sum)) % mod;
	}
	return sum;
}

string RSA::numToHex(int decimal) {//connverts integer into hexadecimal code
	string hexNum = "";
	int org_decimal = decimal;
	if (decimal == 0) hexNum += "0";
	while (decimal > 0) {
		if (decimal % 16 > 9) hexNum += (decimal % 16) + 55;
		else hexNum += (decimal % 16) + 48;
		decimal /= 16;
	}
	if (org_decimal < 16)
		hexNum += "0";

	reverse(hexNum.begin(), hexNum.end());

	return hexNum;
}

string RSA::toHex(string c) {//converts string to hexadecimal code
	string str = "";
	for (int i = 0; i < asciiTab.size(); i++) {
		if (asciiTab[i].c == c) str = asciiTab[i].v;
	}
	return str;
}

string RSA::toChar(string str) { // converts hexadecimal code into ascii sign accoridng to table from ascii.txt
	string c = "";
	for (int i = 0; i < asciiTab.size(); i++) {
		if (asciiTab[i].v == str) c = asciiTab[i].c;
	}
	return c;
}

string RSA::encrypt(string str ){//returns encrypted password
	key key = this->priv;
	string cStr = "";
	string strHex = "";
	double strNum = 0;
	double tempNum = 0;
	double firstNum = 0;
	int c = 0;
	string cHex = "";
	for (int i = 0; i < str.size(); i++) {
		strHex = toHex(str.substr(i, 1));
		strNum = toNum(strHex);
		tempNum = int(strNum) % key.q;
		firstNum = (strNum - tempNum) / key.q;
		c = powBig(tempNum, key.p, key.q);
		cHex = numToHex(firstNum);
		cHex += numToHex(c);

		cStr += cHex;
	}
	return cStr;
}

string RSA::decrypt(string str) {//returns decrypted password
	key key = this->pub;
	string cStr = "";
	double firstNum = 0;
	double c = 0;
	double mTemp = 0;
	string strTemp = "";
	string m = "";

	for (int i = 0; i < str.size(); i += 4) {
		firstNum = toNum(str.substr(i, 2));
		c = toNum(str.substr(i + 2, 2));
		mTemp = powBig(c, key.p, key.q);
		mTemp += (firstNum * key.q);
		strTemp = numToHex(mTemp);
		m = toChar(strTemp);
		cStr += m;
	}

	return cStr;
}