#include "Day12.h"

void Day12::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	string filename = "./res/Day12.txt";
//	string filename = "./res/Test.txt";
	taskOne(filename);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day12::taskTest(string filename)
{
}

void Day12::taskOne(string filename)
{ //879 low
	vector<string> file = FileHandler::readFileVecStr(filename);
	for (string line : file) {
		move(line);
		cout << line << " | x = " << posX << " y = " << posY << " dir = " << currentDir << endl;
	}
	int dist = calcDistance(0, 0);
	//cout << "x = " << posX << " y = " << posY << endl;
	cout << "Dist = " << dist << endl;
}

void Day12::taskTwo(string)
{
}

void Day12::move(string str) {
	char c = str[0];
	int dist = stoi(str.substr(1, str.length() - 1));

	if (c == 'L' || c == 'F' || c == 'R') {
		rotate(charToHead(c), dist);
	}
	else if (c == 'N' || c == 'E' || c == 'S' || c == 'W') {
		moveWP(charToDir(c), dist);
	}
	else {
		cout << "Something wrong - " << str << endl;
	}
}


int Day12::charToHead(char c) {
	if (c == 'L')
		return -1;
	if (c == 'F')
		return 0;
	if (c == 'R')
		return 1;
}

int Day12::charToDir(char c) {
	if (c == 'N')
		return 0;
	if (c == 'E')
		return 1;
	if (c == 'S')
		return 2;
	if (c == 'W')
		return 3;
}

void Day12::rotate(int h, int dist)
{
	if (h == 0)
		moveWP(currentDir, dist);
	else
		currentDir = ((currentDir + (h * dist / 90)) % 4 + 4) % 4;

	//cout << h << "\t" << dist << " | x = " << posX << " y = " << posY << " dir = " << currentDir << endl;
	
}

void Day12::moveWP(int d, int dist)
{
	switch (d) {
	case 0: posY += dist; break;
	case 2: posY -= dist; break;
	case 1: posX += dist; break;
	case 3: posX -= dist; break;
	}
}

int Day12::calcDistance(int x, int y)
{
	return abs(posX - x) + abs(posY - y);
}
