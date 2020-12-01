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
