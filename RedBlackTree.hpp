//
// Created by Alexis Lafrance on 11/17/21.
//

#ifndef FT_CONTAINERS_REDBLACKTREE_HPP
#define FT_CONTAINERS_REDBLACKTREE_HPP

#include "utility.hpp"
#include <iostream>
enum e_color { black, red };

template<typename T>
struct node {
	T element;
	bool empty;
	e_color color;
	node* left;
	node* right;

};

template<typename T>
class RBTree{
	node<T>* root;
public:
	RBTree(): root(createNode()) {}

	explicit RBTree(T element): root(createNode(element)) {}
	RBTree(RBTree const& tree): root(createNode()) { root = tree.root; }

	RBTree &operator=(RBTree<T> const& tree) {
		deleteTree();
		if (tree.root != nullptr) {
			root = new node<T>; // DEEP COPY
			root = tree.root;
		}
		return (*this);
	}

	node<T> *createNode(T element) {
		root = new node<T>;
		root->element = element;
		root->empty = false;
		root->color = black;
		root->left = nullptr;
		root->right = nullptr;
		return (root);
	}
	node<T> *createNode() {
		root = new node<T>;
		root->element = 0;
		root->empty = true;
		root->color = black;
		root->left = nullptr;
		root->right = nullptr;
		return (root);
	}

	void insert(node<T> *node, ::node<T> *add) {
		if (add == nullptr)
			return ;
		if (node == nullptr) {
			node = add;
			return ;
		}
		if (ft::lexicographical_compare(*add->element, *add->element, *node->element, *node->element)) {
			std::cout << "test";
		}
	}

	// TODO: DELETE STD::COUT EMPTY NODE WHEN I'M NOT IN THE TEST PART
	node<T>* display(node<T> *node) {
		if (node == nullptr || (node != nullptr && root->empty)) {
			std::cout << "Empty node" << std::endl;
			return root;
		}
		root->left = display(node->left);
		std::cout << "\nNode :" << std::endl;
		std::cout << "color: " << root->color << ", element : " << root->element << "\n" << std::endl;
		root->right = display(node->right);
		return (nullptr);

	};
	// TODO: DELETE NODES WITH RECURSIVE FUNCTIONS
	void deleteTree() {
		if (root == nullptr) {
			std::cout << "ALREADY EMPTY\n";
			return ;
		}
		std::cout << "DELETE TREE BIP BIP" << std::endl;
	}
	void deleteNode() {
		std::cout << "DELETE NODE BIP BIP" << std::endl;
	}

	node<T> *getRoot() const {
		return root;
	}
};

#endif //FT_CONTAINERS_REDBLACKTREE_HPP
