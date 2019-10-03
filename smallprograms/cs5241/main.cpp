// File: main.cpp
// Driver/main program, executable

#include <iostream>

#include "Distance.h"

using namespace std;

int main(int argc, char** argv) {
	cout << Distance("intention", "execution").calculate() << endl;
	return 0;
}
