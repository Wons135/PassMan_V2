#pragma once
#include "algorithm.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>


using namespace std;


class Generator : public Algorithm {
private:
	int howLong = 0;
	string genPass;
public:

	Generator() {

	}

	string generate();

	~Generator() {

	}
};