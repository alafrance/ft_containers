//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include <vector>
#include <map>
#include "RedBlackTree.hpp"

int main() {
	RBTree<int, char> tree(55);
	tree.insert(40);
	tree.insert(30);
	tree.insert(45);
	tree.insert(65);
	tree.insert(60);
	tree.insert(75);
	tree.insert(57);
	std::cout << "BEFORE DELETE 40" << std::endl;
	tree.display();
	tree.deleteNode(tree.getRoot()->left);
	std::cout << "AFTER DELETE 40" << std::endl;
	tree.display();
	// DELETE TREE UNCOMMENT BE CAREFUL
}
