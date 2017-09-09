#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

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
	string s1, s2;

	cout << "Using split method: " << endl << endl;

	// read and split each line of output
	while (getline(cin, s1)){
		vector<string> v = split(s1);
		
		string::size_type maxlen = 0;
		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			if (v[i].size()>maxlen) maxlen = v[i].size();

		for (vector<string>::size_type i = 0; i != v.size(); ++i) {
			string padding(maxlen - v[i].size() + 1, ' ');
	
			cout << "v[" << i << "] = " << v[i] << padding << " size  = " << v[i].size() 
			<< " palindrome = " << (is_palindrome(v[i]) ? "TRUE" : "FALSE") << endl;
		}

		cout << endl;
	}

	return 0;
}

