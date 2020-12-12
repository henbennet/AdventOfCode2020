#pragma once
#include "../stdafx.h"
class Day12b
{
public:
	void run();
	/*
	* Direction
		NORTH = 0,
		EAST = 1,
		SOUTH = 2,
		WEST = 3,
		MOD = 4
	
	* Heading
		LEFT = -1,
		FWD = 0,
		RIGHT = 1
	*/

private:


	int currentDir = 1;
	int posX = 0;
	int posY = 0;

	int wpX = 10;
	int wpY = 1;

	void taskTest(string filename);

	void taskOne(string);
	void taskTwo(string);

	void move(string str);

	int charToHead(char c);
	int charToDir(char c);

	void rotate(char c, int dist);
	void moveToWP(int dist);
	void moveWP(int d, int dist);

	int calcDistance(int x, int y);


};

