#include "Day13.h"

void Day13::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	string filename = "./res/Day13.txt";
	//string filename = "./res/Test.txt";
	taskTwo(filename);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day13::taskTest(string filename)
{
}

void Day13::taskOne(string filename)
{
	vector<string> file = FileHandler::readFileVecStr(filename);
	int timestamp = stoi(file.at(0));
	vector<string> bus = StrHandler::split(file.at(1), "([0-9]*)");
	int nextBusTime = 99999;
	int nextBusID = 0;
	for (int i = 0;i < bus.size();i++) {
		if (bus.at(i).size() > 0) {

			int busid = stoi(bus.at(i));
			float d1 = (float)timestamp / (float)busid;
			//float d2 = d1-(int)d1;
			int delta = round((d1-(int)d1) * (float)busid);
			int timeto = busid - delta;
			//int delta = (div - (int)div) * busid;

			if (timeto < nextBusTime) {
				nextBusID = busid;
				nextBusTime = timeto;
			}
			//cout << "BusID " << busid << " d1=" << d1 << " d2=" << d2 << " delta " << delta << " timeto=" << timeto << endl;
		}
	}
	cout << "BusID " << nextBusID << ", time to: " << nextBusTime << endl;
	cout << "Mult = " << nextBusID * nextBusTime << endl;
}

void Day13::taskTwo(string filename)
{
	vector<string> file = FileHandler::readFileVecStr(filename);
	vector<string> buss_string = StrHandler::splitWithDelim(file.at(1), ",");
	
	vector<pair<int, int>> busses;
	for (int i = 0;i < buss_string.size(); i++) {
		if (buss_string.at(i).compare("x") != 0) {
			busses.push_back({ i, stoi(buss_string.at(i)) });
		}
	}

	timestamp = 0;
	bool found = false;
	while (!found) {
		found = true;
		for (int i = 0; i < busses.size() && found; i++) {	
			int ti = timestamp + busses.at(i).first;
			int bussid = busses.at(i).second;
			if ((ti%bussid) != 0) {
				found = false;
				timestamp += busses.at(0).second;
				continue;
			}
		}
	}
	cout << "Timestamp = " << fixed << timestamp << endl;

}
int getIndex(vector<string> busses, string bussID) {
	vector<string>::iterator it = find(busses.begin(), busses.end(), bussID);
	if (it == busses.end())
		return -1;
	else
		return distance(busses.begin(), it);
}

void Day13::print() {

}
