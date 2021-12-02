
//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
#include "containers/map.hpp"
#include "containers/set.hpp"
#include <vector>
#include <map>
#include <set>
#include <list>
#include <random>

int main() {
	ft::set<int> set;

	set.insert(42);
	set.insert(43);
	set.insert(44);

	ft::set<int> set2;

	set2.insert(1);
	set2.insert(2);
	set2.insert(3);
	set.insert(set2.begin(), set2.end());

//	set.erase(1);
//	set.erase(set.begin());
//	set.erase(set.begin(), set.end());
	set.swap(set2);
	set.swap(set2);
	set.key_comp();
	set.value_comp()(1, 2);
	set.lower_bound(3);
	set.upper_bound(3);
	set.equal_range(3);
	for (ft::set<int>::iterator it = set.find(3); it != set.end() ; ++it) {
		std::cout << *it << std::endl;
	}
	//	map.erase(--map.end()); //TODO: A REGLER ? OU PAS HA HA FLEMMARD QUE JE SUIS
//	for (ft::map<char, int>::iterator it = map.
//		begin(); it != map.end(); ++it) {
//		std::cout << it->first << std::endl;
//	}
//	map.mydisplay();
//	it++;
//	it++;

//	ft::map<char, int>::iterator it2 = map.insert(it, ft::pair<char, int>('a', 9));

//	std::cout << it2->first << std::endl;

//	map.mydisplay();
}

//int main() {
//	ft::map<char, int> map;
//
//	ft::pair<ft::map<char, int>::iterator, bool > pair;
//
//	map['a'] = 5;
//	pair = map.insert(ft::pair<char, int>('a', 1));
//	std::cout << pair.first->first << " bool " << pair.second << std::endl;
////	map['b'] = 4;
////	map['c'] = 4;
////	map['d'] = 4;
//
//	map.mydisplay();
//}