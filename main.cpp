#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;

#include <map>
using std::map;


void writeFile(map<string, int> mappy, ofstream& file) {
	
	file.open("output.txt");
	
	map<string, int>::iterator ptr;

	for (map<string, int>::iterator it = mappy.begin(); it != mappy.end(); ++it) {

		for (int i = 0; i < it->second; i++) {
			file << it->first;
		}
	}


	file.close();
}

 void readFile(vector<string> holder, string name, ifstream& file) {

	 string temp;
	file.open(name);
	if (file.is_open()) {

		while (getline(file, temp)) {

			holder.push_back(temp);
		}
		file.close();
	}
	

}

int main() {

	map <string, int> tally;
	string words;
	string temp;
	ifstream input;
	ofstream output;
	vector<string> holder;

	input.open("example.txt");

	while (getline(input, words)) {
		
		++tally[words];

	}

	input.close();

	// readFile(holder, "example.txt", input);
	
	

	output.open("output.txt");

	

	for (map<string, int>::iterator it = tally.begin(); it != tally.end(); ++it) {
		for (int i = 0; i < it->second; i++) {
			output << it->first;
		}
	}

	output.close();
	
	system("pause");
	return 0;
}