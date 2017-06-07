#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);  //vec: {4, 1, 8}

	vector<int>::iterator itr1 = vec.begin(); // half-open: [begin, end)
	vector<int>::iterator itr2 = vec.end();

	// although iterator is a class but i behaves like a regular pointer
	for (vector<int>::iterator itr = itr1; itr != itr2; itr++) 
		cout << *itr << " ";				// print: 4 1 8
	cout <<"\n";
	// algorithm - doesn't work on container. It works on iterator
	sort(itr1, itr2);	// vec:: {1, 4, 8}	
	for (vector<int>::iterator itr = itr1; itr != itr2; itr++)
		cout << *itr << " ";

	// Bad idea 
	//cout << *vec.end() << endl; // Ouch!!
	return 0;
}