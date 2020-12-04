#include "Day4.h"

void Day4::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day4::taskOne()
{
	string filename = "./res/Day4a.txt";
	vector<string> vec = FileHandler::readFileVecStr(filename);

	vector<string> validators = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"/*, "cid" */ };
	string pass;
	int valid = 0;
	for (string line : vec) {
		if (line.size() > 0) {
			pass.append(line);
		}
		else {
			valid += validatePass(pass, validators);
			pass.clear();
		}
	}
	valid += (validatePass(pass, validators)?1:0);
	cout << "Number of valid passports: " << valid << endl;

}

void Day4::taskTwo()
{
	string filename = "./res/Day4a.txt";
	//string filename = "./res/Day4Test.txt";
	vector<string> vec = FileHandler::readFileVecStr(filename);

	//vector<string> validators = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"/*, "cid" */ };
	vector<string> validators;
	validators.push_back("byr:(19[2-8][0-9]|199[0-9]|200[0-2])( |$)");
	validators.push_back("iyr:(201[0-9]|2020)( |$)");
	validators.push_back("eyr:(202[0-9]|2030)( |$)");
	validators.push_back("hgt:((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)( |$)");
	validators.push_back("hcl:#([0-9a-f]){6}( |$)");
	validators.push_back("ecl:(amb|blu|brn|gry|grn|hzl|oth)( |$)");
	validators.push_back("pid:([0-9]){9}( |$)");
	
	string pass;
	int valid = 0;
	for (string line : vec) {
		if (line.size() > 0) {
			pass.append(line + " ");
		}
		else {
			valid += (validatePass(pass, validators) ? 1 : 0);
			pass.clear();
		}
	}
	valid += (validatePass(pass, validators) ? 1 : 0);
	cout << "Number of valid passports: " << valid << endl;

}
/*
byr (Birth Year)
iyr (Issue Year)
eyr (Expiration Year)
hgt (Height)
hcl (Hair Color)
ecl (Eye Color)
pid (Passport ID)
cid (Country ID) (optional)
*/
bool Day4::validatePass(string pass, vector<string> validators)	 {
	bool value = true;
	for (string val : validators) {
		string reg = "(.*)(" + val + ")(.*)";
		regex re(reg); 
		value = value && regex_match(pass, re);
	}
	/*
	cout << pass << endl;
	if (value) cout << "Is valid" << endl;
	else cout << "Is invalid" << endl;
	*/
	return value;
}


