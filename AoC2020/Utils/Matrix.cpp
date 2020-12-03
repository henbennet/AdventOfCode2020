#include "Matrix.h"


char Matrix::getData()
{
	return matrix.at(posY).at(posX);
}
void Matrix::setData(char c)
{
	matrix.at(posY).at(posX) = c;
}

void Matrix::insertRow(string x_row)
{	
	matrix.push_back(x_row);
}

/*

[x,y]
[0,0] [1,0] [2,0] [3,0]
[0,1] [1,1] [2,1] [3,1]
[0,2] [1,2] [2,2] [1,2]
[0,3] [1,3] [2,3] [3,3]

*/
void Matrix::print()
{
	for (int y = 0; y < matrix.size(); y++) {
		for (int x = 0; x < matrix.at(y).size(); x++) {
			cout << matrix.at(y).at(x);
		}
		cout << endl;
	}
	cout << endl;
	cout << "Input size - X*Y - " << matrix.size() << " * " << ((matrix.size()>0)?matrix.at(0).size():0) << endl;

}

void Matrix::printToFile(string filename) {
	ofstream myfile;
	myfile.open(filename);
//	myfile << "Writing this to a file.\n";

	for (int y = 0; y < matrix.size(); y++) {
		for (int x = 0; x < matrix.at(y).size(); x++) {
			myfile << matrix.at(y).at(x);
		}
		myfile << endl;
	}
	myfile.close();
}
/*
* ver: -1 up 1 down
* hor: -1 left 1 right
*/
void Matrix::move(int hor, int ver)
{
	posX = (posX + hor) % matrix.at(posY).size();
	posY += ver;
}

void Matrix::moveLeft(int m)
{
	posX = (posX - m) % matrix.at(posY).size(); //inputSizeX;
}

void Matrix::moveRight(int m)
{
	posX = (posX + m) % matrix.at(posY).size(); //inputSizeX;
}

void Matrix::moveUp(int m)
{
	posY = (posY - m) % matrix.size(); //inputSizeY;
}

void Matrix::moveDown(int m)
{
	posY = (posY + m); //matrix.size(); //% inputSizeY;
}

int Matrix::getX()
{
	return posX;
}

int Matrix::getY()
{
	return posY;
}

void Matrix::resetPos()
{
	posX = 0;
	posY = 0;
}

int Matrix::getInputSizeY() {
	return matrix.size();
}
