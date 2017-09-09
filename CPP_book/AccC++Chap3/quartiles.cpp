#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;


int main()  
{	
	vector<double> numbers;	
	double x;

	// ask for the homework grades
	cout << "Enter all your numbers, "
			"followed by end-of-file: ";

	// invariant: numbers contains all the numbers read so far
	while (cin >> x) 
		numbers.push_back(x);

	// check that the user entered some numbers
	typedef vector<double>::size_type vec_sz;
	vec_sz size = numbers.size();
	if (size == 0) {
		cout << endl << "You must enter your numbers.	"
						"Please try again." << endl;

		return 1;
	}

	//sort the numbers
	sort(numbers.begin(), numbers.end());

	// compute the quartiles
	vec_sz quartiles_index[3];	
	vec_sz index;

	quartiles_index[1] = size / 2;
	quartiles_index[0] = quartiles_index[1] / 2;
	quartiles_index[2] = (size - quartiles_index[1])/2 + quartiles_index[1];

	for (index = 0; index<size; index++) {
		if (index == 0) {
			cout << endl << "First quartile: " << endl; 
		}
		else if (index == quartiles_index[0]) {
			cout << endl << "Second quartile: " << endl; 
		}
		else if (index == quartiles_index[1]) {
			cout << endl << "third quartile: " << endl; 
		}
		else if (index == quartiles_index[2]) {
			cout << endl << "fourth quartile: " << endl; 
		}
		
		cout << numbers[index] << " ";
	}	

	cout << endl;

}



