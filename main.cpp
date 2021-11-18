#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include "containers/map.hpp"
#include "iterator/bidirectional_iterator.hpp"
#include <vector>
#include <map>
#include "RedBlackTree.hpp"
int main() {
	RBTree<int>	tree;

	tree.insert(tree.createNode(7));
	tree.insert(tree.createNode(8));
	tree.insert(tree.createNode(9));
	tree.display();

}
