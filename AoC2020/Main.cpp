#include <iostream>

#include "Day/Day1.h"
#include "Day/Day2.h"

using namespace std;

int main(int argc, char* argv[]) { 

	Day2* day = new Day2();
	day->run();
	cout << "main" << endl;
}