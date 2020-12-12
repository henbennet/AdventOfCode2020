#include "Day12b.h"

void Day12b::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	string filename = "./res/Day12.txt";
//	string filename = "./res/Test.txt";
	taskTwo(filename);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day12b::taskTest(string filename)
{
	vector<string> file = FileHandler::readFileVecStr(filename);
	cout << "_" << "\t| x = " << posX << " y = " << posY << " wpX = " << wpX << " wpY = " << wpY << endl;
	move("R180");
	cout << "R180" << "\t| x = " << posX << " y = " << posY << " wpX = " << wpX << " wpY = " << wpY << endl;
	move("R180");
	cout << "R180" << "\t| x = " << posX << " y = " << posY << " wpX = " << wpX << " wpY = " << wpY << endl;
}

void Day12b::taskTwo(string filename)
{
	vector<string> file = FileHandler::readFileVecStr(filename);
	
	for (string line : file) {
		move(line);
		//cout << "R180" << "\t| x = " << posX << " y = " << posY << " wpX = " << wpX << " wpY = " << wpY << endl;
	}
	int dist = calcDistance(0, 0);
	cout << "Dist = " << dist << endl;
}

void Day12b::taskOne(string)
{
}

void Day12b::move(string str) {
	char c = str[0];
	int dist = stoi(str.substr(1, str.length() - 1));

	if (c == 'F') {
		moveToWP(dist);
	}
	else if (c == 'L' || c == 'R') {
		rotate(c, dist);
	}
	else if (c == 'N' || c == 'E' || c == 'S' || c == 'W') {
		moveWP(charToDir(c), dist);
	}
	else {
		cout << "Something wrong - " << str << endl;
	}
}


int Day12b::charToHead(char c) {
	if (c == 'L')
		return -1;
	if (c == 'R')
		return 1;
}

int Day12b::charToDir(char c) {
	if (c == 'N')
		return 0;
	if (c == 'E')
		return 1;
	if (c == 'S')
		return 2;
	if (c == 'W')
		return 3;
}

void Day12b::rotate(char c, int dist)
{
	for (int i = 0;i<dist/90;i++) {
		if (c == 'R') {
			int temp = wpX * -1;
			wpX = wpY;
			wpY = temp;
		}
		else if (c == 'L') {
			int temp = wpX;
			wpX = wpY * -1;
			wpY = temp;
		}
	}
}
void Day12b::moveToWP(int dist) {
	posX += wpX * dist;
	posY += wpY * dist;
}

void Day12b::moveWP(int d, int dist)
{
	switch (d) {
	case 0: wpY += dist; break;
	case 1: wpX += dist; break;
	case 2: wpY -= dist; break;
	case 3: wpX -= dist; break;
	}
}

int Day12b::calcDistance(int x, int y)
{
	return abs(posX - x) + abs(posY - y);
}
