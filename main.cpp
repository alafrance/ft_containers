//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include <vector>
#include <map>
#include "RedBlackTree.hpp"
int main() {
	RBTree<int>	tree(500);

	tree.insert(tree.createNode(50));
	tree.insert(tree.createNode(60));
	tree.insert(tree.createNode(40));
	tree.insert(tree.createNode(30));
	tree.insert(tree.createNode(45));
	tree.insert(tree.createNode(44));
	tree.insert(tree.createNode(46));

	tree.rotate(tree.getRoot()->left->left->right,left);
	tree.rotate(tree.getRoot()->left->left,right);
	tree.displayTree();
}
/*
	p = 500
 	z = 50
 	δ = 60
 	x = 40
 	y = 45
 	α = 30
 	β = 44
 	γ = 46
*/