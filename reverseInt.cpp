// Reverse an input integer. Assume integer to be non negative
//Emily Schadt 5/28/21

#include <iostream>
#include <vector>

using namespace std;

int pow10(int p);
int reverseInt(int n);

int main()
{

		cout << reverseInt(123) << endl; // Should print 321
		cout << reverseInt(4444) << endl; // Should print 4444
		cout << reverseInt(210) << endl; // Should print 12
		cout << reverseInt(0) << endl; // Should print 0
		return 0;
}

int reverseInt(int n) {
// Your code here
	vector <int> integer (0); 
	int num = 0;
	int z = 0;
	int final = 0;
	
	//do whiile loop to get each digit, reverse it, and put them in a vector
	do {
		num = n % 10;
		n /= 10;

		
		integer.push_back(num);
		
	}while(n > 0);

	int size = integer.size();
	
	//multiply each digit by the correspoding power
	for(int i = 0; i < size; i++){
		integer.at(i)*= pow10(size-i);
	}
	
	//add each digit together and divide by ten to get the reversed input
	for(int i = 0; i < size; i++){
		final += integer.at(i);
	}
	final /= 10;
	
	return final;
}

// Returns 10^p
int pow10(int p) {
	int prod = 1;
	while (p > 0) {
		prod = prod*10;
	p--;
	}
	return prod;
}
