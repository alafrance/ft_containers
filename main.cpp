#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include "containers/map.hpp"
#include "iterator/bidirectional_iterator.hpp"
#include <vector>
#include "RedBlackTree.hpp"
int main() {
	RBTree<int>	tree(5);

	tree.display(tree.getRoot());
}
