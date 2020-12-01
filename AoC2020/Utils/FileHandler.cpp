#include "FileHandler.h"

string FileHandler::readLine(string filename)
{
    return readLine(filename, 0);
}

string FileHandler::readLine(string filename, int row)
{
    string line;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        for (int i = 0; i <= row && !myfile.eof(); i++) {
            myfile >> line;
        }
    }
    myfile.close();
    return line;
}

string FileHandler::readFile(string filename)
{
    string file = "";
    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (myfile >> line) {
            file.append(line);
            file.append(";");
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return file;
}
