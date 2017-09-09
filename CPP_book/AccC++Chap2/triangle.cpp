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
	const int height = 20;
	const int width = 40;
	
	// write 'rows' rows of output
	// invariant: we have written r rows so far
	for (int r=0; r != height; ++r) {
		string::size_type c = 0;
		
		int d = r * (width/height) / 2;

		// invariant: we have written c characters so far in the current row
		while (c != width/2+d) {
			if (c == width/2-d-1 || c == width/2+d-1)
				cout << "*";
			else {
				if (r == height-1) cout << "*";
				else cout << " ";
			}

			++c;		
		}

		cout << endl;		
	}
 	
	return 0;
}
