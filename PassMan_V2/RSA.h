#pragma once
#include "Algorithm.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class RSA : public Algorithm {
private:
	struct key {
		int p;
		int q;
	};

	key priv;
	key pub;
public:
	RSA() {
		loadAscii();
		pub.p = toNum("07");
		pub.q = toNum("42");

		priv.p = toNum("0D");
		priv.q = toNum("42");

	}

	double toNum(string str);

	double powBig(double num, int exp, int mod);

	string numToHex(int decimal);

	string toHex(string c);

	string toChar(string str);

	virtual string encrypt(string str)override;

	virtual string decrypt(string str)override;

	~RSA() {}
};

