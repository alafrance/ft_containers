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
	T data;
	e_color color;
	node* left;
	node* right;
	node* parent;
};

template<typename T>
class RBTree{
public:
	RBTree(): root(nullptr) {}

	explicit RBTree(T data): root(createNode(data)) {}

	RBTree(RBTree const& tree): root(nullptr) { root = tree.root; }

	~RBTree() {
		deleteTree(root);
	}

	RBTree &operator=(RBTree<T> const& tree) {
		deleteTree();
		if (tree.root != nullptr) {
			root = new node<T>;
			root = tree.root;
		}
		return (*this);
	}

	node<T> *createNode(T data) {
		node<T> *tmp;
		tmp = new node<T>;
		tmp->data = data;
		tmp->color = black;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->parent = nullptr;
		return (tmp);
	}

	void insert(node<T> *add) {
		insert(root, add);
	}

	void display() {
		iter(root, &RBTree::displayNode);
	};

	void	deleteTree(node<T> *node) {
		if (node == nullptr) {
			return ;
		}
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	void rotateLeft(node<T> *(*node)) {
		if ((*node)->parent == nullptr)
			return ;
		// X = node->parent
		// Y = node && (node->parent->left || node->parent->right)
		// p = node->parent->parent
		// alpha = (node->parent->left || node->parent->right)
		// beta = node->left
		// Y = node->right

		// Assign x as the parent of the left subtree of y
		if ((*node)->parent->left == (*node))
			(*node)->parent->left = (*node)->left;
		else
			(*node)->parent->right = (*node)->right;
		// Change the parent of x to that of y
		if ((*node)->parent->parent == nullptr)
			root = (*node);
		else {
			(*node)->parent->parent = (*node);
		}
		(*node)->left = (*node)->parent

	}

private:
	node<T>* root;

	void displayNode(node<T> *node) {
		std::cout << "color: " << node->color << ", data : " << node->data << std::endl;
	}

	void iter(node<T> *pRoot, void (RBTree<T>::*fct)(node<T> *)) {
		if (pRoot == nullptr)
			return ;
		iter(pRoot->left, fct);
		(this->*fct)(pRoot);
		iter(pRoot->right, fct);
	};

	void insert(node<T> *node, ::node<T> *add) {
		if (root == nullptr) {
			root = add;
			return ;
		}
		if (add == nullptr || node == nullptr)
			return ;
		if (add->data < node->data) {
			if (node->left == nullptr) {
				node->left = add;
				node->left->parent = node;
			} else
				insert(node->left, add);
		}
		else {
			if (node->right == nullptr) {
				node->right = add;
				node->right->parent = node;
			} else
				insert(node->right, add);
		}
	}
};

#endif //FT_CONTAINERS_REDBLACKTREE_HPP
