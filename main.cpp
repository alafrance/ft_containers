//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include <vector>
#include <map>
#include "RedBlackTree.hpp"

int main() {
	RBTree<int> tree(10);
	tree.insert(tree.createNode(13));
	tree.insert(tree.createNode(20));
	tree.insert(tree.createNode(30));
	tree.insert(tree.createNode(53));
	tree.insert(tree.createNode(11));
	tree.insert(tree.createNode(21));
	tree.insert(tree.createNode(41));
	tree.insert(tree.createNode(61));
	tree.insert(tree.createNode(15));
	tree.insert(tree.createNode(31));
	tree.insert(tree.createNode(42));
	tree.insert(tree.createNode(43));
	tree.insert(tree.createNode(56));
	tree.insert(tree.createNode(36));
	tree.insert(tree.createNode(27));
	tree.insert(tree.createNode(52));
	tree.insert(tree.createNode(45));
	tree.insert(tree.createNode(78));
	tree.insert(tree.createNode(100));
	tree.displayTree();
}
