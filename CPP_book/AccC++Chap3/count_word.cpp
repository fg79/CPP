#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main()  
{	
	vector<string> words;	
	vector<int> count;
	string word;
	int index;

	// ask for the homework grades
	cout << "Enter all your words, "
			"followed by end-of-file: ";

	// invariant: words contains all the words read so far
	while (cin >> word) {
		for(index=0; index<words.size(); index++) {
			if (words[index] == word) {
				count[index]++;
				break;
			}
		}

		if (index == words.size()) { // new word
			words.push_back(word);
			count.push_back(1);
		}
	} 

	// check that the user entered some words
	typedef vector<string>::size_type vec_sz;
	vec_sz size = words.size();
	if (size == 0) {
		cout << endl << "You must enter your words.	"
						"Please try again." << endl;

		return 1;
	}

	for(index=0; index<words.size(); index++) {
		cout << "word[" << index + 1 << "] = " << words[index] 
			 << "  count = " << count[index] << endl; 				
	}	

	cout << endl;
}

