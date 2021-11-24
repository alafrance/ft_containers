//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include <vector>
#include <map>
#include "RedBlackTree.hpp"

int main() {
	RBTree<int> tree(55);
	tree.insert(40);
	tree.insert(65);
	tree.insert(60);
	tree.insert(75);
	tree.insert(57);
	tree.display();
	tree.deleteTree(tree.getRoot()->left);
	// DELETE TREE UNCOMMENT BE CAREFUL
}
