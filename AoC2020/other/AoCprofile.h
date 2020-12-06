#pragma once

#include "../stdafx.h"
struct Member
{
	int id;
	int stars[5]; //total, week1, week2, week3, week4
	string name;
	int localScore;
};


class AoCprofile
{
public:
	void parseResults();
	
private:
	void parseFile();

};

