#include <iostream>
#include <cstdlib>
#include <stdexcept>


using std::cin;
using std::cout;
using std::endl;


#define RAND_MAX_TEST 555

int nrand(int n)
{
	if (n <= 0)
		throw std::domain_error("Argument to nrand is out of range");

	if (n < RAND_MAX_TEST) {
		const int bucket_size = RAND_MAX_TEST / n;
		int r;

		do r = rand() / bucket_size;
		while (r >= n);

		return r;
	} 
	else if (n > RAND_MAX_TEST) {
		unsigned int a,b;

		a = rand();
		b = rand();

		return ((~a) + b)/2;  
	}
	else 
		return rand();

}


int main()
{
	srand ( time(NULL) );

	for (int i=1; i<1000; i += 10) {
		cout << "nrand(" << i << ")= " << nrand(i);
		cout << endl;
	}
	
	cout << endl;



	return 0;
}
