//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include <vector>
#include <map>
#include <list>
#include <random>
#include "RedBlackTree.hpp"



//int main() {
//	RBTree<int, char> tree(55);
//	tree.insert(40);
//	tree.insert(65);
//	tree.insert(60);
//	tree.insert(75);
//	tree.insert(52);
//	tree.insert(23);
//	tree.insert(45);
//	tree.insert(42);
//	tree.insert(12);
//	tree.insert(26);
//	tree.insert(56);
//	tree.insert(48);
//	tree.insert(2);
//	tree.insert(57);
//	std::cout << "\n-------- DELETE -------- " << std::endl;
//	std::cout << "DELETE 55 :" << std::endl;
//	tree.deleteNode(55);
//	std::cout << "\n";
//	tree.display();
//	std::cout << "DELETE 40 :" << std::endl;
//	tree.deleteNode(40);
//	std::cout << "-------- DELETE --------\n" << std::endl;
//	tree.display();
//	// DELETE TREE UNCOMMENT BE CAREFUL
//}

int main() {
	RBTree<int, char> tree(55);
	std::vector<int> vec;
	srand (time(NULL));
	for (int i = 0; i < 100; ++i) {
		vec.push_back(rand() % 1000);
		tree.insert(*(--vec.end()));
	}
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << ", ";
	}
	int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen = std::default_random_engine(seed);
	std::shuffle(vec.begin(), vec.end(), gen);
	std::cout << std::endl << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << "\n-------- DELETE -------- " << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		tree.deleteNode(*it);
	}
	std::cout << "\n-------- END DELETE -------- " << std::endl;
	tree.display();
	tree.deleteNode(55);
	std::cout << "DELETE 55 :" << std::endl;
	tree.display();
	std::cout << "\n";
	std::cout << "-------- DELETE --------\n" << std::endl;
	tree.display();
//	 DELETE TREE UNCOMMENT BE CAREFUL
}
