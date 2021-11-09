//
// Created by Alexis Lafrance on 11/4/21.
//

#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP
namespace ft {
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};

	template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct iterator {
		typedef T	value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};


}
#endif //FT_CONTAINERS_ITERATOR_HPP
