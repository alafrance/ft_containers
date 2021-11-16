//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
#define FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP

class bidirectional_iterator : virtual public iterators_traits< iterator<bidirectional_iterator_tag, T> > {
public:
	/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */

	/* -------  CANONICAL FORM ------- */
	bidirectional_iterator(): _p(0) {};

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

	bool operator==(bidirectional_iterator inst) const{
		return (_p == inst._p);
	}

	bool operator!=(bidirectional_iterator inst) const{
		return (_p != inst._p);
	}

	/* 		------- (INCRE/DECRE)MENT ------- */
	bidirectional_iterator &operator--() { //--a
		_p--;
		return (*this);
	}

	bidirectional_iterator operator--(int) {//a--
		bidirectional_iterator tmp(*this);
		this->_p--;
		return (tmp);
	}

	bidirectional_iterator &operator++() { //--a
		_p++;
		return (*this);
	}

	bidirectional_iterator operator++(int) {//a--
		bidirectional_iterator tmp(*this);
		this->_p++;
		return (tmp);
	}

	/* 		------- REFERENCE / DEREFERENCE ------- */
	typename bidirectional_iterator::reference operator* () const {
		return *_p;
	}

	typename bidirectional_iterator::pointer operator-> () const {
		return _p;
	}

	protected:
		typename bidirectional_iterator::pointer _p;
};
#endif //FT_CONTAINERS_BIDIRECTIONNAL_ITERATOR_HPP
