#include <iostream>
#include <vector>
#include <string>

using std::istream;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;


istream& read_words(istream& in, vector<string>& words,vector<int>& count)
{
	int index = 0;
	bool found;

	if (in) {
		// get rid of previous contents
		words.clear();

		// read homework grades
		string x;
		while (in >> x)
		{
			found = 0;

			for(index=0; index<words.size(); index++) {
				if (words[index] == x) {
					count[index]++;
					found = 1;
					break;
				}
			}

			if (!found){
				words.push_back(x);
				count.push_back(1);
			}
		}

		// clear the stream so that input will work for the next student
		in.clear();		
	}

	return in;
}


int main()
{
	vector<string> words;
    vector<int> count;
	int index;

	read_words(cin,words,count);

	for(index=0; index<words.size(); index++) {
		cout << "count[" << words[index] << "] = " << count[index] << endl;
	}

	return 0;	
}
