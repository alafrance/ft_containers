
#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include "iterator/bidirectional_iterator.hpp"
#include <vector>
#include <map>
#include <list>
#include <random>
#include "iterator/bidirectional_iterator.hpp"

int main() {
	ft::RNWARTree<int, char> tree(ft::make_pair(55, 0));
	tree.insert(ft::make_pair(53, 0));
	tree.insert(ft::make_pair(54, 0));
	// 55
	tree.insert(ft::make_pair(56, 0));
	tree.insert(ft::make_pair(58, 0));
	tree.insert(ft::make_pair(59, 0));
	tree.insert(ft::make_pair(60, 0));
	tree.insert(ft::make_pair(65, 0));
	tree.display();
	ft::bidirectional_iterator<int, char> it = tree.minimum();
	std::cout << it->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
}

//int main() {
//	ft::vector<int> a(1, 400);
//	a.push_back(300);
//	a.push_back(200);
//	a.push_back(100);
//	for (ft::vector<int>::reverse_iterator it = a.rbegin(); it != a.rend() ; it++)
//	std::cout << *it << std::endl;
//}