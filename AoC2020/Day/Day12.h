#pragma once
#include "../stdafx.h"
class Day12
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

	void taskTest(string filename);

	void taskOne(string);
	void taskTwo(string);

	void move(string str);

	int charToHead(char c);
	int charToDir(char c);

	void rotate(int h, int dist);
	void moveWP(int d, int dist);

	int calcDistance(int x, int y);


	void moveToWP(int dist);

};

