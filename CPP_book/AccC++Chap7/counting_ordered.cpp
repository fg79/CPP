#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::istream;
using std::sort;
using std::pair;

bool compare_value (const pair<string, int>& i, const pair<string, int>& j) 
{ 
	return (i.second < j.second); 
}

int main()
{
	string s;
	map<string, int> counters; // store each word and an associate counter
	vector<pair<string, int> > counters_ordered;

	// read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++counters[s];

	for (map<string, int>::const_iterator it1 = counters.begin(); it1 != counters.end(); ++it1) {
		counters_ordered.push_back(*it1);
	}

	sort(counters_ordered.begin(), counters_ordered.end(), compare_value);

	// write the words and associated counts
	for (vector<pair<string, int> > ::const_iterator it2 = counters_ordered.begin(); it2 != counters_ordered.end(); ++it2) {
		cout << it2->first << "\t" << it2->second << endl;
	}

	return 0;
}
