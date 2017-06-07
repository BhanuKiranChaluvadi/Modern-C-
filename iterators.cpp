#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <forward_list>
#include <set>
#include <algorithm>

using namespace std;

void Myfunction() {

}

int main() {
	/* Iterators  */
	// 1. Random access Iterators: vector, deque, array
	vector<int> vec = {1, 2, 3, 4, 5, 6};
	vector<int>::iterator itr, itr1, itr2;
	itr = vec.begin();
	itr1 = itr + 5;	// advance iterator by 5
	itr2 = itr1 - 4;	// 
	if (itr1 > itr2)
		cout << " itr2 is less than itr1" << endl;
	++itr;		// faster than itr++;
	--itr;

	// 2. Bidirectional Iterator: list, set/multiset, map/multimap 
	// (list + associative container)
	// can do itr + 3 etc , compare two iterators
	list<int>::iterator list_itr;
	++itr; --itr;

	// 3. Forward Iterator: forward_list
	forward_list<int>::iterator fwList_itr;
	++fwList_itr;

	// unordered containers provide "at least" forward iterator

	// 4. Input iterator: read and process value while iterating "forward".
	int x = *itr;

	// 5. output iterator: output values while iterating "forward".
	*itr = 100;

	// Every container has a iterator and a const_iterator
	set<int>::iterator itr;
	set<int>::const_iterator citr;	//read only access to conatiner elements

	set<int> myset = {2, 4, 5, 1, 9};
	for (citr = myset.begin(); citr != myset.end(); ++citr) {
		cout << *citr << endl;
		//*citr = 3;
	}

	for_each (myset.cbegin(), myset.cend(), Myfunction);	// Only in c++ 11

	// Iterator Functions
	advance(itr, 5);		// Move itr forward 5 spots. itr+=5;
	distance(itr1, itr2);	// Measure the distance between itr1 and itr2

	return 0;
}