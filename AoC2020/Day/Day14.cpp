#include "Day14.h"

void Day14::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	string filename = "./res/Day14.txt";
	//string filename = "./res/Test.txt";
	taskTwo(filename);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day14::taskTest(string filename)
{
}

void Day14::taskOne(string filename)
{
	string mstr = "mask = ";
	parse(filename);
	map<string, string> mem;
	string mask = "";
	pair<string, string> memSet;
	  
	for (int i = 0; i < file.size(); i++) {
		string str = file.at(i);
		size_t found = str.find("mask = ");
		if (found != string::npos) {
			mask = str.substr(mstr.size(), str.back());
			//cout << endl << "mask:\t" << mask << endl;
		}
		else {
			vector<string> split = StrHandler::splitExc(str, "[0-9]*");
			string memAdr = split.at(0);
			string bin = toBin(stoi(split.at(1)));
			string val = maskValue(bin, mask);
			//cout << "bin:\t" << bin << endl;
			//cout << "val:\t" << val << endl;
			mem[memAdr] = val;
		}
	}
	long long sum = 0;

	map<string, string>::iterator it;

	for (auto const& x : mem)
	{
		std::cout << x.first << ':' << x.second << std::endl;
		sum += toDec(it->second);
	}
	cout << "Sum: " << fixed << sum << endl;
}

void Day14::taskTwo(string filename)
{
	string mstr = "mask = ";
	parse(filename);
	map<string, string> mem;
	string mask = "";

	for (int i = 0; i < file.size(); i++) {
		string str = file.at(i);
		size_t found = str.find("mask = ");
		if (found != string::npos) {
			mask = str.substr(mstr.size(), str.back());
			//cout << endl << "mask:\t" << mask << endl;
		}
		else {
			vector<string> split = StrHandler::splitExc(str, "[0-9]*");
			int m = stoi(split.at(0));
			string memAdr = toBin(m);
			vector<string> memVec = maskMem(memAdr, mask);
			string val = split.at(1);
			for (string adr : memVec) {
				mem[adr] = val;
			}
			//cout << "bin:\t" << bin << endl;
			//cout << "val:\t" << val << endl;
		}
	}
	long long sum = 0;
	map<string, string>::iterator it;

	for (auto const& x : mem)
	{
		std::cout << x.first << ':' << x.second << std::endl;
		sum += stoi(x.second);
	}
	cout << "Sum: " << fixed << sum << endl;
}

void Day14::iterations(string adr, vector<string> *vec) {
	size_t t = adr.find_first_of('X');
	if (t!=string::npos) {
		adr[t] = '1';
		iterations(adr, vec);
		adr[t] = '0';
		iterations(adr, vec);
	}
	else {
		vec->push_back(adr);
	}
}

vector<string> Day14::maskMem(string adr, string mask) {
	vector<string> vec;
	for (int m = 0; m < adr.size(); m++) {
		char mi = mask[mask.size() - (m + 1)];
		if (mi == '1' ||mi =='X') {
			adr[adr.size() - (m + 1)] = mi;
		}
	}
	iterations(adr, &vec);
	return vec;
}

string Day14::maskValue(string value, string mask) {
	regex re("(0|1)");
	for (int m = 0; m < value.size(); m++) {
		string s(1, mask[mask.size() - (m+1)]);
		if (regex_match(s, re)){
			value[value.size() - (m + 1)] = mask[mask.size() - (m + 1)];
		}
	}
	return value;
}

long long Day14::toDec(string bin) {
	long long decimal = std::bitset<36>(bin).to_ullong();
	return decimal;
}

string Day14::toBin(int dec) {
	string binary = bitset<36>(dec).to_string(); //to binary
	return binary;
}

void Day14::print(vector<int> vec, string delim) {
	for (int i : vec)
		cout << to_string(i) << delim;
}

void Day14::parse(string filename) {
	file = FileHandler::readFileVecStr(filename);
}

