#include <iostream>
#include <string>

//say what standard-library names we use

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()  
{
	// the number of blanks
	const int width = 10;
	const int height = 30;
	string side(2*width,'A');
	
	// write a blank line to separate the output from the input
	cout << endl;

	// write 'rows' rows of output
	// invariant: we have written r rows so far
	for (int r=0; r != height; ++r) {
		string::size_type c = 0;
		
		// invariant: we have written c characters so far in the current row
		while (c != 2*width) {
			if ( (r == 0 || r == height - 1)  && c == 0) {
				cout << side;
				c += side.size();
			}
			else {
				// are we on the boarder?
				if (c == 0 || c == 2*width - 1)
					cout << "A";
				else
					cout << " ";
				++c;
			}			
		}

		cout << endl;		
	}
 	
	return 0;
}
