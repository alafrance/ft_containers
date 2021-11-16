//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP
#include "iterator.hpp"
#include "metafunctions/metafunctions.hpp"

namespace ft {
	template<typename T>
	class map : public iterators_traits<iterator<bidirectional_iterator_tag, T> > {
	public:
		
	private:
	};
}
#endif //FT_CONTAINERS_MAP_HPP
