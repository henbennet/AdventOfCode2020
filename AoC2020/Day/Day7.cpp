
#include "Day7.h"


void Day7::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day7::taskOne()
{
	//string filename = "./res/Test.txt"; 700 287
	string filename = "./res/Day7.txt";
	populateBags(filename);
	countColors("shiny gold");


}

void Day7::taskTwo()
{
	//string filename = "./res/Test.txt"; //700 287
	string filename = "./res/Day7.txt";

	populateBags(filename);
	string bag = "shiny gold";
	int count = countBags(bag) -1;
	cout << "Number of bags in [" << bag << "]: " <<  count << endl;

}


/*
[dark olive] bags contain 3 faded blue bags, 4 dotted black bags.
[vibrant plum] bags contain 5 faded blue bags, 6 dotted black bags.
[faded blue] bags contain no other bags.
*/

void Day7::populateBags(string filename) {
	vector<string> file = FileHandler::readFileVecStr(filename);

	regex reg("(.*?)(?= bags contain)");
	regex reg_contain("(([0-9]{1,3})(.*)(?= bag\.| bag,| bags,)|([0-9]{1,3})(.*)(?= bags. | bag.))");
	regex re("( bag[a-z]{0,1}(\.|,|)( |\.))");

	for (string line : file) {
		string key;
		vector<pair<int, string>> cont;
		smatch match;
		if (regex_search(line, match, reg))
			key = match[0];
		else
			continue;

		smatch match_contain;
		if (regex_search(line, match_contain, reg_contain)) {
			string str = match_contain[0];

			sregex_token_iterator iter(str.begin(), str.end(), re, -1);
			sregex_token_iterator end;
			for (; iter != end; ++iter) {
				int num = stoi(iter->str().substr(0, 1));
				string nam = iter->str().substr(2, iter->str().length());
				cont.push_back({ num, nam });
			}
		}
		bagMap.insert({ key, cont });
	}
	//cout << "Bags populated" << endl;
}

int Day7::countColors(string lookFor) {
	int count = 0;
	map<string, vector<pair<int,string>>>::iterator it;
	for (it = bagMap.begin(); it != bagMap.end(); it++)
	{
		if (searchRec(lookFor, (*it).first) > 0)
			count++;
	}
	cout << "number of colors with goldend ops: " << count << endl;
	return count;
}


int Day7::countBags(string lookFor) {
	vector<pair<int, string>> vec = bagMap[lookFor];
	int count = 1;
	int mult = 0;

	for (int i = 0; i < vec.size(); i++) {
		mult = vec.at(i).first;
		count += mult * countBags(vec.at(i).second);
	}
	return count;

	/*
	map<string, vector<pair<int, string>>>::iterator it;
	for (it = bagMap.begin(); it != bagMap.end(); it++)
	{
		count += searchRec(lookFor, (*it).first);
	}
	cout << "number of colors with goldend ops: " << count << endl;
	return count;
	*/
}

int Day7::searchRec(string lookFor, string color) {
	vector<pair<int, string>> vec = bagMap[color];
	int count = 0;
	int mult = 1;
	for (int i = 0; i < vec.size(); i++) {
		mult = vec.at(i).first;
		if (vec.at(i).second.compare(lookFor) == 0) {
			//cout << vec.at(i).second << endl;
			//count = vec.at(i).first;
			count++;
		}
		//count = count + mult * searchRec(lookFor, vec.at(i).second);
		count = count + searchRec(lookFor, vec.at(i).second);
	}
	return count;
}