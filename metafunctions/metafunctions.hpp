//
// Created by Alexis Lafrance on 11/9/21.
//

#ifndef FT_CONTAINERS_METAFUNCTIONS_HPP
#define FT_CONTAINERS_METAFUNCTIONS_HPP
#include "is_integral.hpp"
//#include "pair.hpp"
namespace ft{
	template <class U, class V>

	// ----- IS SAME -----
	struct is_same {
		static const bool value = false;
	};

	template <class U>
	struct is_same<U, U> {
		static const bool value = true;
	};

	template <bool b, typename Type>
	struct enable_if {
		typedef Type type;
	};

	template<class Type>
	struct enable_if<false, Type> {

	};

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
							   		InputIterator2 first2, InputIterator2 last2);

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  	InputIterator2 first2, InputIterator2 last2,
								  		Compare comp);


}

#endif //FT_CONTAINERS_METAFUNCTIONS_HPP
