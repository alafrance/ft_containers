//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP
#include <iostream>
#include "../iterator/iterator.hpp"
#include "../metafunctions.hpp"
#include "../pair.hpp"
#include "../RedNWARTree.hpp"

namespace ft {
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map : public iterators_traits<iterator<bidirectional_iterator_tag, T> > {
		/* -------  ITERATOR ------- */

		class bidirectional_iterator : virtual public iterators_traits<iterator<bidirectional_iterator_tag, pair<const Key, T> > > {

			typedef node<const Key, T> * nodePtr;
			/* -------  ATTRIBUTES ------- */
		protected:
			nodePtr _node;
			typename bidirectional_iterator::pointer _p;
		public:
			/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */

			/* -------  CANONICAL FORM ------- */
			bidirectional_iterator() : _node(NULL), _p(0) {};

			~bidirectional_iterator() {};

			bidirectional_iterator(node<const Key, T> *nodeCopy): _node(nodeCopy) {
				modifyValueType();
			}

			bidirectional_iterator(bidirectional_iterator const &src) {
				*this = src;
			}

			bidirectional_iterator &operator=(bidirectional_iterator const &inst) {
				_p = inst._p;
				_node = inst._node;
				return (*this);
			}

			/* -------  OPERATOR OVERLOAD ------- */

			/* 		-------  RELATIONAL ------- */

			bool operator==(bidirectional_iterator inst) const {
				return (_p == inst._p);
			}

			bool operator!=(bidirectional_iterator inst) const {
				return (_p != inst._p);
			}

			/* 		------- (INCRE/DECRE)MENT ------- */
			bidirectional_iterator &operator--() { //--a
				if (_node == NULL)
					return (*this);
				if (_node->left == NULL) {
					nodePtr parent = _node->parent;
					while (parent && _node == parent->left) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
					modifyValueType();
					return (*this);
				} else {
					_node = _node->left;
					while (_node && _node->right != NULL)
						_node = _node->right;
					modifyValueType();
				}
				return (*this);
			}

			bidirectional_iterator operator--(int) {//a--
				bidirectional_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			bidirectional_iterator &operator++() { //++a
				if (_node == NULL)
					return (*this);
				if (_node->right == NULL) {
					nodePtr parent = _node->parent;
					while (parent && _node == parent->right) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
					modifyValueType();
					return (*this);
				} else {
					_node = _node->right;
					while (_node && _node->left != NULL)
						_node = _node->left;
					modifyValueType();

				}
				return (*this);
			}

			bidirectional_iterator operator++(int) {//a++
				bidirectional_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/* 		------- REFERENCE / DEREFERENCE ------- */
			typename bidirectional_iterator::reference operator*() {
				return *_p;
			}

			typename bidirectional_iterator::pointer operator->() {
				return _p;
			}
		private:
			/* 		------- UTILITY ------- */
			void modifyValueType() {
				if (_node)
					_p = &_node->data;
				else
					_p = NULL;
			}
		};
	public:
	/* -------  TYPEDEF ------- */

	typedef pair<const Key, T> value_type;
	typedef Key key_type;
	typedef T mapped_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename iterators_traits<iterator<bidirectional_iterator_tag, T> >::difference_type difference_type;
	typedef size_t size_type;
	typedef bidirectional_iterator iterator;
	typedef bidirectional_iterator const_iterator;
	typedef reverse_iterator<const_iterator> const_reverse_iterator;
	typedef reverse_iterator<iterator> reverse_iterator;

	/* -------  ATTRIBUTES ------- */
	private:
		size_type _size;
		RNWARTree<Key, T, Alloc> tree;
		Alloc _alloc;
		Compare comp;
	public:
	/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */
	explicit map(const key_compare &comp = key_compare(),
				 const allocator_type &alloc = allocator_type()) : _alloc(alloc), comp(comp) {
	}

	template<class InputIterator>
	map(typename enable_if<(is_same<InputIterator, pointer>::value
							|| is_same<InputIterator, iterator>::value), InputIterator>::type first, InputIterator last,
		const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()): _alloc(alloc), comp(comp) {
		(void) first;
		(void) last;
	}

	map(const map &x) : tree(x.tree), _alloc(x._alloc), comp(x.comp) {
	}

	~map() {}

	/* ------- ITERATORS ------- */

	iterator begin() {
		return (tree.minimum());
	}

	const_iterator begin() const {
		return (tree.getRoot());
	}

	iterator end() {
		return (NULL);
	}

	const_iterator end() const {
		return (NULL);
	}
	reverse_iterator rbegin() {
		return (reverse_iterator(end()));
	}

	const_reverse_iterator rbegin() const {
		return (reverse_iterator(end()));
	}

	reverse_iterator rend() {
		return (reverse_iterator(begin()));
	}
	const_reverse_iterator rend() const {
		return (reverse_iterator(begin()));
	}

	/* ------- CAPACITY ------- */

	bool empty() const {
		return (tree == NULL);
	}

	size_type size() const {
		return (_size);
	}

	size_type max_size() const {
		return (-1); // TODO: RETURN GOOD MAX SIZE
	}
	/* ------- MODIFIERS ------- */

	void myinsert(const value_type& val) { // TODO: DELETE JUST FOR TEST
		tree.insert(val);
	}

	void mydisplay() {
		tree.display();
	} //TODO: DELETE JUST FOR TEST
	/* ------- GETTERS ------- */
	allocator_type get_allocator() const {
		return (_alloc);
	}
};
}
#endif //FT_CONTAINERS_MAP_HPP
