#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()  
{	
	string word, longest, shortest;
	bool first = 1;

	// ask for the homework grades
	cout << "Enter all your words, "
			"followed by end-of-file: ";

	// invariant: words contains all the words read so far
	while (cin >> word) {
		if (first) {
			shortest = word;
			longest = word;
			first = 0;
		}
		else if (word.size() > longest.size())
			longest = word;
		else if (word.size() < shortest.size())
			shortest = word;
	} 

	cout << "longest = " << longest << " size = " << longest.size() <<endl
		 << "shortest = " << shortest << " size = " << shortest.size() <<endl;
}
