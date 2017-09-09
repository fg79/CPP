#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::istream;

int main()
{
	string s;
	map<string, int> counters; // store each word and an associate counter

	// read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++counters[s];

	// write the words and associated counts
	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}

	return 0;
}
