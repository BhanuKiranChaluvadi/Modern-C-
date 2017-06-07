#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
* Properties of Unordered Containers
* 1. Fastest search/insert at any place: O(1)
*     Associative Containers take O(log(n))
*     Vector, deque takes O(n)
*     list takes O(1) to insert, O(n) to search
* 2. Unordered set/multiset: element values can't be changed.
	 Unordered map/multimap: elements key cannot be changed.
*/

int main() {
	unordered_set<string> myset = {"red", "green", "blue", "Bhanu", "clinton", "Shanu"};
	unordered_set <string>::const_iterator itr = myset.find("green"); //O(1)

	if (itr != myset.end())		// Important check
		cout << *itr << endl;	
	myset.insert("yellow");		// O(1)

	vector<string> vec = { "purple", "pink" };
	myset.insert(vec.begin(), vec.end());

	cout << endl;
	sort(vec.begin(), vec.end());
	for (itr = myset.begin(); itr != myset.end(); ++itr) {
		cout << *itr << endl;
	}

	// Hash table specific APIs
	cout << "load_factor = " << myset.load_factor() << endl;
	string x = "red";
	cout << x << "is in bucket #" << myset.bucket(x) << endl;
	cout << "Total bucket # " << myset.bucket_count() << endl;

	/*
	* unordered multiset: allows duplicate elements
	* unordered map: unordered set of pairs
	* unordered multimap: unordered map that allows duplicate keys
	*
	* hash collision => performance degrade
	*/

	/*
	* Notes about associative array:
	* 1. Search time: unordered_map, O(1); map, O(log(n));
	* 2. Unorderd_map may degrade to O(n);
	3. Can't use multimap and unordered_multimap, they dont have [] operator
	*/
	unordered_map <char, string> day = { {'S', "Sunday"}, {'M', "Monday"} };

	cout << day['S'] << endl; // No range check
	cout << day.at('S');		// has range check

	vector <int> vec = {1, 2, 3};
	//vec[5] = 89;	// Compile error

	day['W'] = "Wednesday";		// Insert {'W', "Wednesday"}
	day.insert(make_pair('F', "Friday"));		// Insert {'F', "Friday"}

	// day.insert(make_pair('M', "Monday")); // Fail to modify .Its an unordered map
	day['M'] = "Monday";	//Succeed to modify

	return 0;
}

void foo(const unordered_map<char, string> & m) {
	// m['S'] = "Sunday"
	// cout << m['S'] << endl;
	auto itr = m.find('S');
	if (itr != m.end())
		cout << itr->second << endl;
}