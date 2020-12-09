#include "Day8.h"


void Day8::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day8::taskOne()
{
	//string filename = "./res/Test.txt"; 
	string filename = "./res/Day8.txt";
	parseFile(filename);
	runProgram();

}

void Day8::taskTwo()
{
	//string filename = "./res/Test.txt";
	string filename = "./res/Day8.txt";
	parseFile(filename);
	int accum = 0;
	for (int in = 0; in < infinit.size(); in++) {
		
		string stored = infinit.at(in).instr;
		if (infinit.at(in).instr.compare("nop") == 0) {
			infinit.at(in).instr = "jmp";
		}
		else if (infinit.at(in).instr.compare("jmp") == 0) {
			infinit.at(in).instr = "nop";
		}
		pair<int, int> acc = runProgram();

		if (acc.second >= infinit.size()) {
			accum = acc.first;
			cout << stored << " changed to " << infinit.at(in).instr << " at index: " << in << endl;
			break;
		}
		reset(in, stored);
	}

	cout << "accumulator value: " << accum << endl;

}

void Day8::reset(int in, string stored) {
	infinit.at(in).instr = stored;
	for (int i = 0;i < infinit.size(); i++) {
		infinit.at(i).visited = false;
	}
}

pair<int,int> Day8::runProgram() {
	int acc = 0;
	int index = 0;
	for (; index < infinit.size(); ) {
		if (infinit.at(index).visited)
			break;

		infinit.at(index).visited = true;

		if (infinit.at(index).instr.compare("jmp") == 0) {
			index += infinit.at(index).number;
			continue;
		}
		else if (infinit.at(index).instr.compare("acc") == 0) {
			acc += infinit.at(index).number;
		}
		else if (infinit.at(index).instr.compare("nop") == 0) {}
		index++;
	}
	//cout << "accumulator value: " << acc << ", index: " << index << endl;
	return { acc, index };
}

void Day8::parseFile(string filename) {
	vector<string> file = FileHandler::readFileVecStr(filename);
	for (string line : file) {
		vector<string> vec = StrHandler::splitWithDelim(line, " ");
		string ins = vec.at(0);
		int num = stoi(vec.at(1));
		infinit.push_back(instruction(num, ins));
	}
}

