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

template<typename T, typename U>
struct node {
	// TODO: CHANGE STD TO FT
	std::pair<T, U> data;
	e_color color;
	node *left;
	node *right;
	node *parent;
};

template<typename T, typename U>
class RBTree {
public:

	typedef node<T, U> * nodePtr;
	// ---------------- CANONICAL FORM ----------------
	RBTree() : root(nullptr) {}

	explicit RBTree(T key) : root(createNode(key, black)) {}

	RBTree(RBTree const &tree) : root(nullptr) { root = tree.root; }

	~RBTree() {
//		deleteTree(root);
	}

	RBTree &operator=(RBTree<T, U> const &tree) {
		deleteTree();
		if (tree.root != nullptr) {
			root = new node<T, U>;
			root = tree.root;
		}
		return (*this);
	}
	// ---------------- UTILITY COPY / CREATE ----------------

	nodePtr createNode(T key) const {
		nodePtr tmp;
		tmp = new node<T, U>;
		tmp->data.first = key;
		tmp->color = red;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->parent = nullptr;
		return (tmp);
	}

	nodePtr createNode(T key, U data) const {
		nodePtr tmp;
		tmp = new node<T, U>;
		tmp->data.first = key;
		tmp->data.second = data;
		tmp->color = red;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->parent = nullptr;
		return (tmp);
	}

	nodePtr createNode(T key, e_color color) const {
		nodePtr tmp;
		tmp = new node<T, U>;
		tmp->data.first = key;
		tmp->color = color;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->parent = nullptr;
		return (tmp);
	}

	// ---------------- GETTER  ----------------
	nodePtr getRoot() const {
		return root;
	}

	// ---------------- HELPER ----------------

	void insert(T key) {
		insert(root, createNode(key));
	}

	void displayOrder() const {
		iter(root, &RBTree::displayNode);
	};

	void display() const {
		printHelper(root, "", true);
	}

	// ---------------- DISPLAY ----------------

	void postOrderDisplay(nodePtr node, int depth) const {
		if (node == nullptr) {
			return;
		}
		displayTree(node->left, depth + 1);
		displayTree(node->right, depth + 1);
		std::cout << node->data << " ";
	}

	void printHelper(nodePtr root, std::string indent, bool last) const {
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
			std::cout << root->data.first << "\e[0m" << std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}

	void displayNode(nodePtr node) {
		std::cout << "color: " << node->color << ", data : " << node->data << std::endl;
	}

	void iter(nodePtr pRoot, void (RBTree<T, U>::*fct)(nodePtr )) {
		if (pRoot == nullptr)
			return;
		iter(pRoot->left, fct);
		(this->*fct)(pRoot);
		iter(pRoot->right, fct);
	};

	// ---------------- SEARCH ----------------

	nodePtr search_key(T key) {
		return (search_key(root, key));
	}

	nodePtr search_key(nodePtr node, T key) {
		nodePtr find = nullptr;
		if (node == nullptr)
			return nullptr;
		if (key == node->data.first)
			return node;
		if (key < node->data.first)
			find = search_key(node->left, key);
		else
			find = search_key(node->right, key);
		return find;
	}

	// ---------------- INSERT  ----------------
	void insert(nodePtr node, nodePtr add) {
		if (search_key(add->data.first)) {
			std::cerr << "KEY UNIQUE : " << add->data.first << std::endl;
			return;
		}
		if (root == nullptr) {
			root = add;
			return;
		}
		if (add == nullptr || node == nullptr)
			return;
		if (add->data.first < node->data.first) {
			if (node->left == nullptr) {
				node->left = add;
				node->left->parent = node;
//				insertFix(node->left);
			} else
				insert(node->left, add);
		} else {
			if (node->right == nullptr) {
				node->right = add;
				node->right->parent = node;
//				insertFix(node->right);
			} else
				insert(node->right, add);
		}
	}

	// ---------------- INSERT UTILITIES ----------------
private:
	void rotate(nodePtr node, e_direction direction) {
		if (node == nullptr || node->parent == nullptr)
			return;
		nodePtr gp = node->parent->parent;
		nodePtr p = node->parent;
		nodePtr *gpLink = nullptr;
		if (gp)
			gpLink = (gp->left == p) ? &gp->left : &gp->right;
		if ((p->right == node && direction == right) ||
			(p->left == node && direction == left)) {
			std::cerr << "wrong direction" << std::endl;
			std::cerr << "node wrong direction : " << node->data.first << " and direction : " << direction << std::endl;
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

	void insertFix(nodePtr node) {
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
			nodePtr uncle = (gp_to_p_direction == left) ? node->parent->parent->right : node->parent->parent->left;
			// CASE 1 UNCLE IS RED : MODIFY THE CHILD OF GRAND PARENT BLACK AND GRAND PARENT RED, AND GO TO GP
			if (uncle && uncle->color == red) { // CASE IF UNCLE RED => COLOR BLACK PARENTS OF GP AND GP TO RED, GO TO GP
				std::cout << "Case 1 node : " << node->data.first << std::endl;
				node->parent->color = black;
				uncle->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
			} else {
				// NO UNCLE RED OR NO UNCLE TRY TO ROTATE IF POSSIBLE
				if ((gp_to_p_direction == right && node == node->parent->left)
					|| (gp_to_p_direction == left && node == node->parent->right)) {
					nodePtr tmp = node->parent;
					rotate(node, gp_to_p_direction);
					node = tmp;
				}
				// MODIFY PARENT COLOR AND GRAND PARENT COLOR AND ROTATE
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

public:

	// ---------------- DELETE  ----------------

	void deleteTree(nodePtr node) {
		if (node == nullptr) {
			return;
		}
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	void deleteNode(nodePtr node) {
		if (node == nullptr)
			return ;
		std::cout << "DELETE : " << std::endl;
		nodePtr nodeReplace, nodeMin;
		e_color nodeMin_originalColor = node->color;
		if (node->left == nullptr) {
			nodeReplace = node->right;
			std::cout << "TRANSPLANT\n";
			transplant(node, node->right);
		}
		else if (node->right == nullptr) {
			nodeReplace = node->left;
			std::cout << "TRANSPLANT ELSE IF\n";
			transplant(node, node->left);
		} else {
			std::cout << "TRANSPLANT ELSE\n";
			// CHANGE MINIMUM IN BRANCH RIGHT
			nodeMin = minimum(node->right);
			// STOCK ORIGINAL COLOR TO KNOW IF WE NEED TO
			// CALL DELETE FIX
			nodeMin_originalColor = node->color;
			nodeReplace = nodeMin->right;
			// IF NODE MIN IS NOT CHILD OF NODE WE NEED TO REMOVE NODE MIN
			// AND MODIFY RIGHT NODEMIN TO NODE RIGHT AND PARENT NODE TO NODEMIN
			if (nodeMin->parent != node) {
				transplant(nodeMin, nodeMin->right);
				nodeMin->right = node->right;
				nodeMin->right->parent = nodeMin;
			}
			// WE CAN, FINALLY, REMOVE NODE AND PUT NODE MIN
			// AND WE CAN MODIFY LEFT NODE MIN TO OLD NODE LEFT AND NODE LEFT CHANGE PARENT
			transplant(node, nodeMin);
			nodeMin->left = node->left;
			nodeMin->left->parent = nodeMin;
			nodeMin->color = node->color;
		}
		// WE CAN DELETE THE NODE AND LOOK IF IS NECESSARY TO CALL DELETE FIX
		delete node;
		if (nodeMin_originalColor == black)
			std::cout << "WE NEED TO CALL DELETE FIX" << std::endl;
		std::cout << "END DELETE" << std::endl;
	}

	// ---------------- DELETE UTILITIES  ----------------

	void deleteFix(nodePtr node) {

	}
	nodePtr minimum(nodePtr node) {
		if (node == nullptr)
			return (nullptr);
		if (node->left == nullptr)
			return (node);
		else
			return(minimum(node->left));
	}

	void transplant(nodePtr uncle, nodePtr node) {
		std::cout << "BOnsoir 1" << std::endl;
		if (uncle == nullptr)
			std::cerr << "Transplant no uncle or uncle invalid" << std::endl;
		else if (uncle->parent == nullptr)
			root = node;
		else if (uncle == uncle->parent->left)
			uncle->parent->left = node;
		else if(uncle == uncle->parent->right)
			uncle->parent->right = node;
		if (node != nullptr)
			node->parent = uncle->parent;
	}
	// ---------------- ATTRIBUTES  ----------------
private:
	nodePtr root;
};

#endif //FT_CONTAINERS_REDBLACKTREE_HPP
