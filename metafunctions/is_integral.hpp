//
// Created by Alexis Lafrance on 11/9/21.
//

#ifndef FT_CONTAINERS_IS_INTEGRAL_HPP
#define FT_CONTAINERS_IS_INTEGRAL_HPP
#include "metafunctions.hpp"

namespace ft {
	// ----- TRUE AND FALSE TYPE -----
	struct false_type {
		static const bool value = false;
	};

	struct true_type {
		static const bool value = true;
	};

	template<typename T>
	struct is_integral {
		static const bool value_type = false;
		typedef false_type type;
	};

	template<>
	struct is_integral<bool> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<char> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<char16_t> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<char32_t> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<wchar_t> {
		static const bool value_type = true;
		typedef true_type type;
	};
	template<>
	struct is_integral<signed char> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<short int> {
		static const bool value_type = true;
		typedef true_type type;
	};
	template<>
	struct is_integral<int> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<long int> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<long long int> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<unsigned char> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<unsigned short int> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<unsigned int> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<unsigned long int> {
		static const bool value_type = true;
		typedef true_type type;
	};

	template<>
	struct is_integral<unsigned long long int> {
		static const bool value_type = true;
		typedef true_type type;
	};
};






#endif //FT_CONTAINERS_IS_INTEGRAL_HPP
