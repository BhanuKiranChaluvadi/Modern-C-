#include<iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>

using namespace std;

int main() {

	/* Properties of vector
	* 1. fast insert/remove at the end: O(1)
	* 2. slow insertion/remove at the beginning or in the middle: O(n)
	* 3. slow search: O(n)
	*/
	vector <int> vect = {1, 2, 3};
	vector<int>vec;		//vec.size() == 0
	vec.push_back(4);vec.push_back(1);vec.push_back(8); // vec: {4, 1, 8}, vec.size() == 3

	// Vector specific operations:
	cout << vec[2] << " ";			// 8 (no range check)
	cout << vec.at(2) << endl;;		// 8 (throw range_error exception of out of range)

	for (int i=0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl;
	for (int it : vec) // c++ 11
		cout << it << " ";

	// vector is a dynamically allocated contiguous array in memory
	int *p = &vec[0];
	p[2] = 6;

	// common member functions of all containers
	//vec: {4, 1, 6}
	cout << endl;
	if (vec.empty()) { cout << "Empty vector.\n"; }
	cout << vec.size() << endl;
	vector<int> vec2(vec); //copy constructor, vec2: {4, 1, 6}
	vec.clear();	// Remove all items in vec; vec.size() == 0;
	vec2.swap(vec); // vec2 becomes empty and vec has 3 items.

	// Deque
	deque<int> deq = { 4, 6,7 };
	deq.push_front(2);	//deq: {2, 4, 6, 7}
	deq.push_back(3);	//deq: {2, 4, 6, 7, 3}

	/* 
	* list
	* -- double linked list
	* 1. Faster insert/removal at any place: O(1)
	* 2. slow search: O(n) // slower than vector
	* 3. no random access, no [] operator.
	* 4. killing function splice
	*/
	cout << "List" << endl;
	list<int> mylist = { 5, 2, 9 };
	mylist.push_back(6);	//mylist: { 5, 2, 9, 6}
	mylist.push_front(4);	//mylist: { 4, 5, 2, 9, 6}
	;
	list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2);	//itr->2
	mylist.insert(itr, 8);		// mylist: { 4, 5, 8, 2, 9, 6}
								// O(1), faster than vector/deque
	itr++;						// itr -> 9
	cout << *itr << endl;
	mylist.erase(itr);			// mylist: {4, 8, 5, 2, 6} O(1)
	cout << *itr << endl;
	
	list<int> mylist2 = { 1, 2, 3 };
	list<int>::iterator itr2 = mylist2.begin();
	list<int>::iterator itr_a, itr_b;
	itr_a = itr2; itr_b = ++++itr2;

	mylist.splice(itr, mylist2, itr_a, itr_b);  // O(1)
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
		cout << "end" << endl;
		cout << *itr << " ";
	}

	std::list<int> mylist3;
	std::list<int>::iterator it1, it2;
	// set some values:
	for (int i = 1; i<10; ++i) mylist.push_back(i * 10);
	it1 = it2 = mylist.begin();
	advance(it2, 6);
	++it1;

	/*
	* Array
	*/
	// has to form array container
	array<int, 3> a= {3, 4, 5};
	a.begin();
	a.end();
	a.size();
	//a.swap();
	array<int, 4> b = { 5, 6, 7, 8 };
	// can't assign a to b because of diffrent type <int, 3> and <int, 4>
	return 0;
}