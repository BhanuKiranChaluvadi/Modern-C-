#include <iostream>
#include <set>
#include <map>
#include <iterator>

using namespace std;

/*
* 1. Fast search: O(log(n))
* 2. Traversing is slow (compared to vector & deque)
* 3. no randome access, no[] operator.
*/

int main() {

	/*
	* Associative container - Set
	* Always sorted, default criteria is <
	* No push_back, push_front()
	* No duplicate items
	*/
	set<int> myset;
	myset.insert(3);	// myset: {3}
	myset.insert(1);	// myset: {1, 3}
	myset.insert(7);	// myset: {1, 3, 7} O(log(n))

	set<int>::iterator it;
	it = myset.find(7);		// O(log(n))  it points to 7
	// Sequence containers don't even have find() member functino

	pair<set<int>::iterator, bool> ret;
	ret = myset.insert(3);	// no element is inserted. since 3 is already present
	if (ret.second == false)
		it = ret.first;		// "it" now points to element 3

	myset.insert(it, 9);	// myset: {1, 3, 7, 9}  O(log(n)) => O(1)
							// it point to 3
							// it give a clue, to insert in memory log time becomes const time
	myset.erase(it);		// myset: {1, 7, 9}
	myset.erase(7);			// myset: {1, 9}

	/*
	* multi - Set
	* Allow duplicate items
	*/
	multiset <int> multiSet;
	multiset<int>::iterator itr;
	// set/multiset: value of the elements can't be modified
	//*itr = 10	// *itr is read only

	/*
	* Map - No duplicate key
	*/
	map<char, int> mymap;
	mymap.insert(pair<char, int>('a', 100));
	mymap.insert(make_pair('z', 200));

	std::map<char, int>::iterator itra = mymap.begin();
	mymap.insert(itra, pair<char, int>('b', 300));	// "it" is a hint

	itra = mymap.find('z');	// O(log(n))
	
	// showing contents
	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		cout << (*it).first << " => " << (*it).second << endl;
	}

	// multimap is a map that allows duplicate keys
	multimap<char, int> mymap2;

	// map/multimap:
	//	-- keys cannot be modified
	//	type of *it: pair<const char, int>
	//(*itra).first = 'd'; -> error
	return 0;
}