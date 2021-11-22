//
// Created by Alexis Lafrance on 11/17/21.
//

#ifndef FT_CONTAINERS_REDBLACKTREE_HPP
#define FT_CONTAINERS_REDBLACKTREE_HPP

#include "utility.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <stdlib.h>
#include <sstream>

enum e_color { black, red };
enum e_direction { left, right };

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

	explicit RBTree(T data): root(createNode(data, black)) {}

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

	node<T> *createNode(T data) const{
		node<T> *tmp;
		tmp = new node<T>;
		tmp->data = data;
		tmp->color = red;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->parent = nullptr;
		return (tmp);
	}
	node<T> *createNode(T data, e_color color) const{
		node<T> *tmp;
		tmp = new node<T>;
		tmp->data = data;
		tmp->color = color;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->parent = nullptr;
		return (tmp);
	}

	void insert(node<T> *add) {
		insert(root, add);
	}

	void display() const{
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

	void rotate(node<T> *node, e_direction direction) {
		if (node == nullptr || node->parent == nullptr)
			return ;
		::node<T> *gp = node->parent->parent;
		::node<T> *p = node->parent;
		::node<T> **gpLink = nullptr;
		if (gp)
			gpLink = (gp->left == p) ? &gp->left : &gp->right;

		if ((p->right == node && direction == right) ||
				(p->left == node && direction == left) ) {
			std::cerr << "wrong direction" << std::endl;
			return ;
		}
		// ROTATE PARENT CHILD AND NODE CHILD LEFT
		if (direction == left) {
			p->right = node->left;
			if (node->left)
				node->left->parent = p;
			node->left = p;
		} else { // ROTATE PARENT CHILD AND NODE CHILD RIGHT
			p->left = node->right;
			if (node->right)
				node->right->parent = p;
			node->right = p;
		}
		// MODIFY POINTER OF GP AND MAKE NODE AS PARENT IF NECESSARY
		if (gp == nullptr)
			root = node;
		else
			*gpLink = node; // WHY DUDE
		// MODIFY THE PARENT
		p->parent = node;
		node->parent = gp;
	}

	void displayTree() const{
		printHelper(root, "", true);
	}
	node<T> *getRoot() const {
		return root;
	}

private:
	node<T>* root;
	void postOrderDisplay(node<T> *node, int depth) const {
		if (node == nullptr) {
			return;
		}
		displayTree(node->left, depth + 1);
		displayTree(node->right, depth + 1);
		std::cout << node->data << " ";
	}

	void printHelper(node<T>* root, std::string indent, bool last) const{
		if (root != nullptr) {
			std::cout << indent;
			if (last) {
				std::cout << "R----";
				indent += "   ";
			} else {
				std::cout << "L----";
				indent += "|  ";
			}
			if (root->color == red)
				std::cout << "\e[0;31m";
			else
				std::cout << "\e[0;37m";
			std::cout << root->data << "\e[0m" << std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}
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
public:
	void insertFix(node<T> *node){
		if (node == nullptr)
			return ;
		if (node->parent == nullptr)
		{
			node->color = black;
			return ;
		}
		if (node->parent->parent == nullptr)
			return ;
		while(node->parent->color == red) {
			// IF PARENT == LEFT CHILD GRAND PARENT DOING THIS :
			if (node->parent == node->parent->parent->left) {
				// CASE 1
				if (node->parent->parent->right->color == red) {
					std::cout << "Case 1" << std::endl;
					node->parent->color = black; // Equal to parent
					node->parent->parent->right->color = black;
					node->parent->parent->color = red;
					node = node->parent->parent;
				}
				// CASE 2
				else if (node == node->parent->right) {
					std::cout << "Case 2" << std::endl;
					rotate(node, left);
					node = node->left;
				}
				// CASE 3
				else {
					std::cout << "Case 3" << std::endl;
					node->parent->color = black;
					node->parent->parent->color = black;
					rotate(node->parent, right);
					//TODO: NEED TO CHANGE NODE
					node = node->parent;
					std::cout << "node: " << node->data << std::endl;
					break;
				}
			}
			// ELSE
			else {
				std::cout << "ELSE BRO\n";
				// CASE 1
				// CASE 2
			}
			// LOOK THE CHECK ON THE WHILE
			if (node == root) {
				std::cout << "Break\n";
				break;
			}
		}
		// MAKE ROOT BLACK (FIRST PROPERTIES OF R-D-TREE)
	}
private:

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
//				insertFix(node->left);
			} else
				insert(node->left, add);
		}
		else {
			if (node->right == nullptr) {
				node->right = add;
				node->right->parent = node;
//				insertFix(node->right);
			} else
				insert(node->right, add);
		}
	}
};

#endif //FT_CONTAINERS_REDBLACKTREE_HPP
