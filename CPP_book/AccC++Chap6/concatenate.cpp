#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// true if the argument is whitespace, false otherwise
bool space(char c)
{
	return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end()) {
		
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find the end of the next word
		iter j = find_if(i, str.end(), space);

		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;		
	}

	return ret;
}

int main()
{
	vector<string> vec;
	string s1, s2;

	cout << "Insert the string: " << endl << endl;

	getline(cin, s1);

	vec = split(s1);

	s2 = accumulate(vec.begin(), vec.end(), s2);

	cout << endl << "concatenated string: " << s2 << endl;
}

