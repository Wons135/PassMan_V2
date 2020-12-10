#include "Generator.h"

using namespace std;

string Generator::generate() {
	loadAscii();
	srand(time(NULL));
	cout << "How long should your password be?";
	do {
		cin >> howLong;
		if (howLong <= 0 || howLong > 32) {
			cout << "Password can't be longer than 32 (or shorter than 0...)!" << endl;
		}
	} while (howLong <= 0 || howLong > 32);

	for (int i = 0; i <= howLong - 1; i++) {
		genPass += asciiTab[rand() % 94].c;
	}
	return genPass;
}

