#pragma once
#include "Algorithm.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Ceasar : public Algorithm {
private:
	int temp = 0;
public:
	Ceasar() {
		
	}


	string encrypt(string str)override;
	string decrypt(string str)override;

	~Ceasar() {}
};