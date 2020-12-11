#include "Day10.h"


void Day10::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	string filename = "./res/Day10.txt";
//	string filename = "./res/Test.txt";
	taskTwo(filename);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day10::taskOne(string filename)
{
	file = FileHandler::readFileVecInt(filename);
	file.push_back(0);
	sort(file.begin(), file.end());
	stepThrough();
}

void Day10::taskTwo(string filename)
{
	file = FileHandler::readFileVecInt(filename);
	file.push_back(0);
	sort(file.begin(), file.end());
	vector<int> vec;
	//count = recStep(0, vec);
	recursiveStepThrough(1, 0);
	//search(0, 0);
	//double count = 
	cout << "number of paths: " << fixed << count << endl;
}


void Day10::print() {
	for (int i = 0; i < file.size(); i++) {
		cout << file.at(i) << endl;
	}
}

void Day10::stepThrough() {
	int dist1 = 0;
	int dist3 = 0;
	int i;
	for (i = 0; i < file.size()-1; i++) {
		int dist = file.at(i+1) - file.at(i);
		if (dist >= 0 && dist <= 3) {
			if (dist == 1)
				dist1++;
			if (dist == 3)
				dist3++;
		}
		else {
			cout << "Step through ended at index: " << i << " Value= " << file.at(i) << endl;
		}
	}
	dist3++;
	cout << "dist1 = " << dist1 << " dist3 = " << dist3 << "| Product = " << dist1 * dist3 << endl;


}

void Day10::search(int joltIndex, int prevJolt) {
	if (joltIndex == file.size() - 1) {
		count++;
		return;
	}

	int index = 0;
	while (index < 3 && (index + joltIndex) < file.size()) {
		int currentJolt = file.at(joltIndex);
		int nextJolt = file.at(joltIndex + index);

		if (nextJolt - prevJolt <= 3) {
			//jolt.push_back(nextJolt);
			search(joltIndex + 1, currentJolt);
		}
		index++;
	}
	
}
/*
def getCombinationsFrom(index, adapters, memory):
	if index + 1 == len(adapters):
		return 1
	if index in memory:
		return memory[index]
	ret = 0
	for i in range(index + 1, index + 4):
		if i < len(adapters) and adapters[i] - adapters[index] <= 3:
			ret += getCombinationsFrom(i, adapters, memory)
	memory[index] = ret
	return ret
	*/
double Day10::recStep(int index, vector<int> vec) {
	if (index + 1 == file.size()) {
		return 1;
	}
	if (vec.size() > index) {
		return vec.at(index);
	}
	double ret = 0;
	for (int i = index + 1; i <= index + 4; i++) {
		if (i < file.size() && file.at(i) - file.at(index) <= 3) {
			ret += recStep(i, vec);
		}
	}
	vec.push_back(ret);

	return ret;
}

double Day10::recursiveStepThrough(int index, int prev) {
	if (index == file.size() - 1) {
		count++;
		return 0;
	}
	
	int maxDist = 3;
	int in = 0;
	int current = file.at(index);
	for (in = 0 ; in < 3 && (in+index)<file.size() ; in++) {
		int next = file.at(index + in);
		if (next - current <= 3) {
			recursiveStepThrough(index + 1, index);
		}
	}
	
	


	//double count = 0;
	/*
	if (index > file.size()-1 || file.at(index) - file.at(prev) > maxDist) {
		return 0;
	}
	else if (index == file.size()-1) {
		count++;
	}
	else if (index < file.size()-1) {
		//count += recursiveStepThrough(index + 1, index);
		count += recursiveStepThrough(index + 2, index);
		count += recursiveStepThrough(index + 3, index);
	}*/
	return 0;
}