#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 

using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::max;


int num_len(int num)
{
	int num_len = 0;

	do {
    	++num_len; 
     	num /= 10;
	} while (num);

	return num_len;
}


int main()  
{
	int limit = 10000000;
	int i, square;
	string title1 = "number";
	string title2 = "square";
    int pad = max((int)(num_len(limit*limit) - title2.size() + 1), 2);
	string string_pad (pad, ' ');

	cout << title1 << string_pad << title2 << endl << endl;

	for (i=1; i<limit; i++) 
	{
		square = i*i;
		
		cout << setw(title1.size()) << i << setw(title2.size()+pad) << square << endl;
	}

	return 0;
}
