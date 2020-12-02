#include "FileHandler.h"
#include <string>

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



string FileHandler::readFileToString(string filename)
{
    return readFileToString(filename, ";");
}

string FileHandler::readFileToString(string filename, string delim)
{
    string file = "";
    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (myfile >> line) {
            file.append(line);
            file.append(delim);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return file;
}

vector<string> FileHandler::readFileVecStr(string filename)
{
    vector<string> file;
    string line;
    ifstream myfile(filename);

    if (myfile.is_open())
    {
        while (getline(myfile, line)) {
            file.push_back(line);
        }/*
        while (myfile >> line) {
            file.push_back(line);
        }*/
        myfile.close();
    }
    else cout << "Unable to open file";
    return file;
}

vector<int> FileHandler::readFileVecInt(string filename)
{
    vector<int> file;
    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (myfile >> line) {
            file.push_back(stoi(line));
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return file;
}

