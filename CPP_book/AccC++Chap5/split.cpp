#include <cctype>
#include <iostream>
#include <vector>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
 
	//invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, currrent j) is a space
		while (j != s.size() && !isspace(s[j]))
			++j;

		
		// if we found some nonwhitespaces characters
		if (i != j) {
			// copy from s starting at i and taking j-i chars
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	
	return ret;
}


int main()
{
	string s1, s2;

	cout << "Using split method: " << endl << endl;

	// read and split each line of output
	while (getline(cin, s1)){
		vector<string> v = split(s1);

		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << "v[" << i << "] = " << v[i] << " size  = " << v[i].size() << endl;
	}

	cout << endl << endl << "Using 'standard' method: " << endl << endl;

	cin.clear();

	while (cin >> s2)
		cout << s2 << endl;

	return 0;
}
