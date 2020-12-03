#pragma once
#include "../stdafx.h"

class Matrix
{
public:
	int getInputSizeY();
	
	char getData();
	void setData(char);
	
	void insertRow(string);

	void print();
	void printToFile(string);

	//Tree map
	void move(int hor, int ver);
	void moveLeft(int m=1);
	void moveRight(int m=1);
	void moveUp(int m=1);
	void moveDown(int m=1);
	//int move(string command);

	int getX();
	int getY();
	void resetPos();

private:
	int posX, posY = 0;
	vector<string> matrix;
};

