#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/*
* Algorithms
*/
bool isOdd(int i) {
	return i % 2;
}
int main() {
	vector<int> vec = {4, 2, 5, 1, 3, 9};
	vector<int>::iterator itr = min_element(vec.begin(), vec.end()); // itr -> 1

	// Note 1: Algorithms always process ranges in a hapf-open way: [begin, end)
	sort(vec.begin(), itr);		// vec: {2, 4, 5, 1, 3, 9}
	reverse(itr, vec.end());	// vec: {2, 4, 5, 9, 3, 1}  itr => 9

	// Note 2: require 2 ranges
	vector<int> vec2(3);
	copy(itr, vec.begin(), // source
		vec2.begin());		// destination		/ over writting
	// vec2 needs to have at least space for 3 elements.

	// Note 3: inserting not over writting
	vector<int> vec3;
	copy(itr, vec.end(), back_inserter(vec3)); // Inserting instead of overwritting
	// back insert iterator Not efficient

	vec3.insert(vec.begin(), itr, vec.end());	//Efficient and safe

	// Note 4: Algorithm with function
	vector<int>::iterator itr1 = find_if(vec.begin(), vec.end(), isOdd); //itr -> 5

	// Note 5: Algorithm with native c++ array
	int arr[4] = {6, 3, 7, 4};
	sort(arr, arr + 4);

	return 0;
}