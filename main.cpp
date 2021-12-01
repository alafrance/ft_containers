
#include "containers/vector.hpp"
//#include "containers/stack.hpp"
#include "containers/map.hpp"
#include <vector>
#include <map>
#include <list>
#include <random>




int main() {
	ft::map<int, char> map;
	map.myinsert(ft::pair<int, char>(4, 'a'));
	map.myinsert(ft::pair<int, char>(5, 'a'));
	map.myinsert(ft::pair<int, char>(6, 'a'));
	map.myinsert(ft::pair<int, char>(7, 'a'));
	map.myinsert(ft::pair<int, char>(8, 'a'));

//	ft::map<int, char>::reverse_iterator it = map.rbegin();

//	ft::reverse_iterator<ft::map<int, char>::iterator> it;

	// ITERATORS BASICS
//	ft::map<int, char>::iterator it = map.begin();
//	ft::map<int, char>::iterator ite = map.end();
//
//	while(it != ite) {
//		if (it->first == 8)
//			break;
//		std::cout << it->first << std::endl;
//		++it;
//	}
//	--it;
//	--it;
//	std::cout << it->first << std::endl;
//	ft::pair<int, char> pair = *it;
//	std::cout << pair.first << std::endl;
	//	std::cout << pair.first << ", " << pair.second << std::endl;
//	std::cout << pair.first << ", " << pair.second << std::endl;



	// REVERSE ITERATOR
	ft::map<int, char>::iterator it = map.begin();
	ft::map<int, char>::iterator ite = map.end();

//	it++;
	std::cout << it->first << ", " << it->second << std::endl;
//	std::cout << pair.first << ", " << pair.second << std::endl;

}

// TEST REVERSE ITERATORS
//int main() {
//	ft::map<int, char> mymap;
//	mymap.myinsert(ft::pair<int, char>(4, 'a'));
//	mymap.myinsert(ft::pair<int, char>(5, 'a'));
//	mymap.myinsert(ft::pair<int, char>(6, 'a'));
//	mymap.myinsert(ft::pair<int, char>(7, 'a'));
//	for (ft::map<int, char>::reverse_iterator it = mymap.rbegin() ; it != mymap.rend() ; ++it) {
//		std::cout << it->color << std::endl;
//	}
//	mymap.mydisplay();
//}


// TEST ITERATORS MAPS
//int main() {
//	ft::RNWARTree<int, char> tree(ft::make_pair(55, 0));
//	tree.insert(ft::make_pair(53, 0));
//	tree.insert(ft::make_pair(54, 0));
//	// 55
//	tree.insert(ft::make_pair(56, 0));
//	tree.insert(ft::make_pair(58, 0));
//	tree.insert(ft::make_pair(59, 0));
//	tree.insert(ft::make_pair(60, 0));
//	tree.insert(ft::make_pair(65, 0));
//	tree.insert(ft::make_pair(66, 0));
//	tree.insert(ft::make_pair(67, 0));
//	tree.insert(ft::make_pair(68, 0));
//	tree.insert(ft::make_pair(70, 0));
//	tree.insert(ft::make_pair(71, 0));
//	tree.insert(ft::make_pair(72, 0));
//	tree.insert(ft::make_pair(73, 0));
//	tree.insert(ft::make_pair(74, 0));
//	tree.display();
//	ft::bidirectional_iterator<int, char> it = tree.minimum();
//	while(it!= NULL) {
//		std::cout << it->first << std::endl;
//		if (it->first == 74)
//			break;
//		++it;
//	}
//	std::cout << "\n AND WITH IT--\n";
//	while (it != tree.minimum()) {
//		std::cout << it->first << std::endl;
//		it--;
//	}
//	return (0);
//}

//int main() {
//	ft::vector<int> a(1, 400);
//	a.push_back(300);
//	a.push_back(200);
//	a.push_back(100);
//	for (ft::vector<int>::reverse_iterator it = a.rbegin(); it != a.rend() ; it++)
//	std::cout << *it << std::endl;
//}