//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP
#include "../iterator/iterator.hpp"
#include "../metafunctions.hpp"
#include "../pair.hpp"
#include "iostream"
namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >

	class map : public iterators_traits<iterator<bidirectional_iterator_tag, T> > {
		#include "../iterator/bidirectional_iterator.hpp"
	public:
		typedef pair<const Key, T> value_type;
		typedef Key key_type;
		typedef T mapped_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename iterators_traits< iterator<bidirectional_iterator_tag, T> >::difference_type difference_type;
		typedef size_t size_type;
//		typedef '?' iterator;
//		typedef '?' const_iterator;
//		typedef '?' reverse_iterator;
//		typedef '?' const_reverse_iterator;
	private:
	};
}
#endif //FT_CONTAINERS_MAP_HPP
