//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
#define FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
#include "../RedNWARTree.hpp"
#include "iterator.hpp"

namespace ft {
	template<typename T, typename U>
	class bidirectional_iterator : virtual public iterators_traits<iterator<bidirectional_iterator_tag, node<T, U> > > {
	public:
		/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */

		/* -------  CANONICAL FORM ------- */
		bidirectional_iterator() : _p(0) {};

		~bidirectional_iterator() {};

		bidirectional_iterator(typename bidirectional_iterator::pointer a) {
			_p = a;
		}

		bidirectional_iterator(bidirectional_iterator const &src) {
			*this = src;
		}

		bidirectional_iterator &operator=(bidirectional_iterator const &inst) {
			_p = inst._p;
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
			if (_p == NULL)
				return (*this);
			if (_p->left == NULL) {
				node<T, U> *parent = _p->parent;
				while (parent && _p == parent->left) {
					_p = parent;
					parent = parent->parent;
				}
				_p = parent;
				return (*this);
			} else {
				_p = _p->left;
				while (_p && _p->right != NULL)
					_p = _p->right;
			}
			return (*this);
		}

		bidirectional_iterator operator--(int) {//a--
			bidirectional_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		bidirectional_iterator &operator++() { //++a
			if (_p == NULL)
				return (*this);
			if (_p->right == NULL) {
				node<T, U> *parent = _p->parent;
				while (parent && _p == parent->right) {
					_p = parent;
					parent = parent->parent;
				}
				_p = parent;
				return (*this);
			} else {
				_p = _p->right;
				while (_p && _p->left != NULL)
					_p = _p->left;
			}
			return (*this);
		}

		bidirectional_iterator operator++(int) {//a++
			bidirectional_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		/* 		------- REFERENCE / DEREFERENCE ------- */
		typename bidirectional_iterator::reference operator*() const {
			return _p;
		}

		pair<T, U> *operator->() const {
			return &_p->data;
		}

	protected:
		typename bidirectional_iterator::pointer _p;
	};
}
#endif //FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
