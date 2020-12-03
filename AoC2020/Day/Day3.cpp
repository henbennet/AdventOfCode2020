#include "Day3.h"

void Day3::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day3::test()
{
	string filename = "./res/Day3Test.txt";
	readFile(filename);
	int count = 0;
	while (matrix.getY() < matrix.getInputSizeY()) {
		matrix.moveRight(3);
		matrix.moveDown();
		if (matrix.getY() <= matrix.getInputSizeY()-1) {
			if (matrix.getData() == '#') {
				count++;
				matrix.setData('X');
			}
			else {
				matrix.setData('O');
			}
				
		}
	}

	cout << "number of trees: " << count << endl;
	//matrix.print();
}

void Day3::taskOne()
{
	string filename = "./res/Day3a.txt";
	readFile(filename);
	double count = 0;
	while (matrix.getY() < matrix.getInputSizeY()) {
		if (matrix.getData() == '#') {
			count++;
		}
		matrix.moveRight(3);
		matrix.moveDown();
		
	}
	cout << "number of trees: " << count << endl;
}

void Day3::taskTwo()
{
	string filename = "./res/Day3a.txt";
	readFile(filename);
	//matrix.printToFile("test.txt");
	double mult = 1;
	double col= 0;
	matrix.resetPos();
	while (matrix.getY() < matrix.getInputSizeY()) {
		if (matrix.getData() == '#') {
			col++;
		}
		matrix.move(1, 1);
	}
	mult *= col;
	cout << col << " ";

	col = 0;
	matrix.resetPos();
	while (matrix.getY() < matrix.getInputSizeY()) {
		if (matrix.getData() == '#')
			col++;
		matrix.move(3, 1);
	}
	mult *= col;
	cout << col << " ";

	col = 0;
	matrix.resetPos();
	while (matrix.getY() < matrix.getInputSizeY()) {
		if (matrix.getData() == '#') 
			col++;
		matrix.move(5, 1);
	}
	mult *= col;
	cout << col << " ";

	col = 0;
	matrix.resetPos();
	while (matrix.getY() < matrix.getInputSizeY()) {
		if (matrix.getData() == '#') 
			col++;
		matrix.move(7, 1);
	}
	mult *= col;
	cout << col << " ";

	col = 0;
	matrix.resetPos();
	while (matrix.getY() < matrix.getInputSizeY()) {
		if (matrix.getData() == '#') 
			col++;
		matrix.moveRight(1);
		matrix.moveDown(2);
	}
	mult *= col;
	cout << col << endl;

	printf("mult: %lf\n", mult);
}

void Day3::readFile(string filename) {
	vector<string> file = FileHandler::readFileVecStr(filename);
	for (string line : file) {
		matrix.insertRow(line);
	}
}
