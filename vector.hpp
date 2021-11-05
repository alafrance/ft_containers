//
// Created by Alexis Lafrance on 11/3/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP
#include <iostream>
#include "iterator.hpp"
namespace ft {
	template<typename T, class Alloc = std::allocator<T> >
class vector
	{
	public:
		typedef T value_type;
		typedef std::allocator<T> allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef ft::bidirectional_iterator<T> iterator;
//		typedef '?' const_iterator;
//		typedef '?' reverse_iterator;
//		typedef '?' const_reverse_iterator;
		typedef ptrdiff_t  difference_type;
		typedef size_t size_type;

		explicit vector (const allocator_type& alloc = allocator_type()) {
			(void)alloc;
		}

		vector(value_type *value) { // FOR TEST
			_value = value;
		}
		virtual ~vector() {

		};
		vector &operator=(vector const &inst) {
			(void)inst;
			return (*this);
		};
		iterator begin() {
			return (*_value);
		}
private:
		value_type *_value; // FOR TEST
		Alloc _alloc;
	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
