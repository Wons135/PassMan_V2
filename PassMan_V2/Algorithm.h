#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Algorithm {
private:

public:
	struct table {
		string v; //value
		string c; //character
	};
	vector<table> asciiTab;

	Algorithm() {

	}

	virtual void loadAscii();
	virtual string encrypt(string str);
	virtual string decrypt(string str);

	~Algorithm() {

	}
};