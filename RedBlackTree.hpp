//
// Created by Alexis Lafrance on 11/17/21.
//

#ifndef FT_CONTAINERS_REDBLACKTREE_HPP
#define FT_CONTAINERS_REDBLACKTREE_HPP
#include "utility.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

enum e_color {
	black, red
};
enum e_direction {
	left, right
};
template<typename T>
struct node {
	T data;
	e_color color;
	node *left;
	node *right;
	node *parent;
};

template<typename T>
class RBTree {
public:
	RBTree() : root(nullptr) {}

	explicit RBTree(T data) : root(createNode(data, black)) {}

	RBTree(RBTree const &tree) : root(nullptr) { root = tree.root; }

	~RBTree() {
		deleteTree(root);
	}

	RBTree &operator=(RBTree<T> const &tree) {
		deleteTree();
		if (tree.root != nullptr) {
			root = new node<T>;
			root = tree.root;
		}
		return (*this);
	}

	node<T> *createNode(T data) const {
		node<T> *tmp;
		tmp = new node<T>;
		tmp->data = data;
		tmp->color = red;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->parent = nullptr;
		return (tmp);
	}

	node<T> *createNode(T data, e_color color) const {
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

	void display() const {
		iter(root, &RBTree::displayNode);
	};

	void deleteTree(node<T> *node) {
		if (node == nullptr) {
			return;
		}
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	void leftRotate(node<T> *x) {
		node<T> *y = x->right;
		x->right = y->left;
		if (y->left != nullptr) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void rightRotate(node<T> *x) {
		node<T> *y = x->left;
		x->left = y->right;
		if (y->right != nullptr) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	void rotate(node<T> *node, e_direction direction) {
		if (node == nullptr || node->parent == nullptr)
			return;
		::node<T> *gp = node->parent->parent;
		::node<T> *p = node->parent;
		::node<T> **gpLink = nullptr;
		if (gp)
			gpLink = (gp->left == p) ? &gp->left : &gp->right;
		if ((p->right == node && direction == right) ||
			(p->left == node && direction == left)) {
			std::cout << "wrong direction" << std::endl;
			std::cout << "node wrong direction : " << node->data << " and direction : " << direction << std::endl;
			displayTree();
			return;
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
			*gpLink = node;
		// MODIFY THE PARENT
		p->parent = node;
		node->parent = gp;
	}

	void displayTree() const {
		printHelper(root, "", true);
	}

	node<T> *getRoot() const {
		return root;
	}

private:
	node<T> *root;

	void postOrderDisplay(node<T> *node, int depth) const {
		if (node == nullptr) {
			return;
		}
		displayTree(node->left, depth + 1);
		displayTree(node->right, depth + 1);
		std::cout << node->data << " ";
	}

	void printHelper(node<T> *root, std::string indent, bool last) const {
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
			return;
		iter(pRoot->left, fct);
		(this->*fct)(pRoot);
		iter(pRoot->right, fct);
	};
public:
	void insertFix(node<T> *node, bool debug) {
		if (node == nullptr)
			return;
		if (node->parent == nullptr) {
			node->color = black;
			return;
		}
		if (node->parent->parent == nullptr)
			return;
		e_direction gp_to_p_direction;
		while (node->parent->color == red) {
			if (node->parent == node->parent->parent->left) // CHOOSE GPLINK DIRECTION
				gp_to_p_direction = left;
			else
				gp_to_p_direction = right;
			// FIND THE GOOD UNCLE WITH THE GPLINK DIRECTION
			::node<T> *uncle = (gp_to_p_direction == left) ? node->parent->parent->right : node->parent->parent->left;
			// CASE 1 UNCLE IS RED : MODIFY THE CHILD OF GRAND PARENT BLACK AND GRAND PARENT RED, AND GO TO GP
			if (!uncle)
				std::cout << "NO UNCLE\n";
			if (uncle && uncle->color == red) {
				std::cout << "Case 1 node : " << node->data << std::endl;
				if (debug) {
					displayTree();
				}
				node->parent->color = black;
				uncle->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
			} else {
				// CASE 2 : IF
				if ((gp_to_p_direction == right && node == node->parent->left)
					|| (gp_to_p_direction == left && node == node->parent->right)) {
					::node<T> *tmp = node->parent;
					rotate(node, gp_to_p_direction);
					node = tmp;
				}
				// CASE 3
				if (node->parent)
					node->parent->color = black;
				if (node->parent && node->parent->parent)
					node->parent->parent->color = red;
				rotate(node->parent, (gp_to_p_direction == left) ? right : left);
			}
			// LOOK IF WE ARE INTO ROOT OR IF WE HAVE NULLPTR
			if (node == root || node == nullptr || node->parent == nullptr
				|| node->parent->parent == nullptr) {
				root->color = black; // MAKE ROOT BLACK (FIRST PROPERTIES OF R-D-TREE)
				break;
			}
		}
	}

	node<T> *search_key(T data) {
		return (search_key(root, data));
	}

	node<T> *search_key(node<T> *node, T data) {
		::node<T> *find = nullptr;
		if (node == nullptr)
			return nullptr;
		if (data == node->data)
			return node;
		if (data < node->data)
			find = search_key(node->left, data);
		else
			find = search_key(node->right, data);
		return find;
	}

private:
	void insert(node<T> *node, ::node<T> *add) {
		if (search_key(add->data)) {
			std::cerr << "KEY UNIQUE : " << add->data << std::endl;
			return;
		}
		if (root == nullptr) {
			root = add;
			return;
		}
		if (add == nullptr || node == nullptr)
			return;
		if (add->data < node->data) {
			if (node->left == nullptr) {
				node->left = add;
				node->left->parent = node;
				if (add->data == 45)
					insertFix(node->left, 1);
				else
					insertFix(node->left, 0);
			} else
				insert(node->left, add);
		} else {
			if (node->right == nullptr) {
				node->right = add;
				node->right->parent = node;
				if (add->data == 45)
					insertFix(node->right, 1);
				else
					insertFix(node->right, 0);
			} else
				insert(node->right, add);
		}
	}
};

#endif //FT_CONTAINERS_REDBLACKTREE_HPP
