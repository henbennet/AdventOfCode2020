#include "AoCprofile.h"

void AoCprofile::parseResults()
{
}

void AoCprofile::parseFile()
{
	string filename = "./results/952422_2020-12-06_00.02.json";
	vector<string> file = FileHandler::readFileVecStr(filename);
	int level = 0;
	vector<Member*> members;
	Member *m;
	regex re_membID("(.*)([0-9]{4,6})(.*)");
	
	for (string line : file) {
		if (regex_match(line, re_membID) && level == 1) {
			m = new Member();
			continue;
		}

		if (line.find('{')) {
			level++;
		}
		else if (line.find('}')) {
			level--;
		}
	}


	
}
