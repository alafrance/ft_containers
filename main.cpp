//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include <vector>
#include <map>
#include "RedBlackTree.hpp"
int main() {
	RBTree<int>	tree(33);

	tree.insert(tree.createNode(13, red));
	tree.insert(tree.createNode(53, black));
	tree.insert(tree.createNode(11, black));
	tree.insert(tree.createNode(21, black));
	tree.insert(tree.createNode(41, red));
	tree.insert(tree.createNode(61, red));
	tree.insert(tree.createNode(15, red));
	tree.insert(tree.createNode(31, red));
	tree.insert(tree.createNode(20));
	tree.insertFix(tree.getRoot()->left->right->left->right);
	tree.displayTree();
//	tree.insertFix()
	//	tree.rotate(tree.getRoot()->left->left->right,left);
	//	tree.rotate(tree.getRoot()->left->left,right);
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