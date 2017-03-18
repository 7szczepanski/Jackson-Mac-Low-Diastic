/*
Simple yet elegant solution to Jackson Mac Low Diastic
In file called dictionary every word needs to be in new line.


Created by Mateusz Szczepanski 18.03.2017
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void pushWords(vector<string> &dic);

string diastic(string seed, vector<string> &dic);


int main() {
	string seed;
	vector<string> words;
	pushWords(words);

	cout << "Please give me a sentence" << endl;
	getline(cin, seed);
	
	string phrase = diastic(seed, words);
	cout << phrase;

	cin.ignore();
	return 0;
}

void pushWords(vector<string> &dic) {
	fstream file("dictionary.txt");
	string mystr;
	while (file >> mystr) {
		dic.push_back(mystr);
	}
}

string diastic(string seed, vector<string> &dic) {
	int currentWord=0;
	int currentSeed = 0;
	string phrase;
	for (int i = 0; i < seed.length(); i++) {
		char c;
		c = seed.at(i);
		for (int j = currentWord; j < dic.size(); j++) {
			string str;
			if (c == ' ') { str = " "; phrase += str + "\n"; break; }
			if (c == '?') { str = '?'; phrase += str + "\n"; break; }
			if (c == '!') { str = '!'; phrase += str + "\n"; break; }
			if (c == '.') { str = '.'; phrase += str + "\n"; break; }
			if (dic[j].at(0) == c) {
				str = dic[j];
				phrase += str + "\n";
				currentWord = j + 1;
				break;
			}
		}
	}
	return phrase;
}

