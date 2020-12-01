#pragma once

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileHandler
{
public:
	static string readLine(string filename);
	static string readLine(string filename, int row);
	static string readFile(string filename);
	static vector<int> readFileVecInt(string filename);
};

