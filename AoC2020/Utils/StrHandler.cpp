#include "StrHandler.h"


vector<string> StrHandler::split(string input, string regex)
{
    std::vector<std::string> vec;
    std::regex re(regex);
    std::regex_iterator<std::string::iterator> rit(input.begin(), input.end(), re);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
        vec.push_back(rit->str());
        ++rit;
    }
    return vec;
}

vector<string> StrHandler::splitExc(string input, string regex)
{
    std::vector<std::string> vec;
    std::regex re(regex);
    std::regex_iterator<std::string::iterator> rit(input.begin(), input.end(), re);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
        if (rit->str().size()>0)
            vec.push_back(rit->str());
        ++rit;
    }
    return vec;
}

vector<string> StrHandler::splitWithDelim(string input, string delim)
{
    vector<string> vec;
    size_t current, prev = 0;
    current = input.find(delim);
    while (current != string::npos) {
        vec.push_back(input.substr(prev, current - prev));
        prev = current + 1;
        current = input.find(delim, prev);
    }
    if (prev < input.size()) {
        vec.push_back(input.substr(prev));
    }
    
    return vec;
}

vector<int> StrHandler::splitIntWithDelim(string input, string delim)
{
    vector<int> vec;
    size_t current, prev = 0;
    current = input.find(delim);
    while (current != string::npos) {
        string str = input.substr(prev, current - prev);
        int stri;
        try {stri = stoi(str);}
        catch (const std::invalid_argument& ia) {stri = 0;}
        vec.push_back(stri);
        prev = current + 1;
        current = input.find(delim, prev);
    }
    if (prev < input.size()) {
        int stri;
        try { stri = stoi(input.substr(prev)); }
        catch (const std::invalid_argument& ia) { stri = 0; }
        vec.push_back(stri);
    }

    return vec;
}

vector<int> StrHandler::splitInt(string input, string regex)
{
    vector<int> vec;
    std::regex re(regex);
    std::regex_iterator<std::string::iterator> rit(input.begin(), input.end(), re);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
        //string st = rit->str();

        vec.push_back(stoi(rit->str()));
        ++rit;
    }

    return vec;
}

size_t StrHandler::countOccurrences(string str, char find) {
    return std::count(str.begin(), str.end(), find);
    
}