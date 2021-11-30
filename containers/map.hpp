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
#include "../iterator/bidirectional_iterator.hpp"

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
	typedef reverse_iterator<bidirectional_iterator> reverse_iterator;

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

	~

	map() {}

	/* -------  ITERATORS ------- */

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

	private:
	RNWARTree<Key, T, Alloc> tree;
	Alloc _alloc;
	Compare comp;
};
}
#endif //FT_CONTAINERS_MAP_HPP
