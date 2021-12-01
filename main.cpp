
#include "containers/vector.hpp"
//#include "containers/stack.hpp"
#include "containers/map.hpp"
#include <vector>
#include <map>
#include <list>
#include <random>



int main() {
	ft::map<char, int> map;

	map.myinsert(ft::pair<char, int>('a', 1));
	map.myinsert(ft::pair<char, int>('b', 1));
	map.myinsert(ft::pair<char, int>('c', 1));
	map.myinsert(ft::pair<char, int>('d', 1));
	map.myinsert(ft::pair<char, int>('e', 1));

	for (ft::map<char, int>::reverse_iterator it = map.begin(); it != map.end() ; ++it) {
		std::cout << it->first << std::endl;
	}
}