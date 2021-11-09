//
// Created by Alexis Lafrance on 11/9/21.
//

#ifndef FT_CONTAINERS_PAIR_HPP
#define FT_CONTAINERS_PAIR_HPP
#include <iostream>
namespace ft {
	template<typename T1, typename T2>
	class pair {
	public:
		pair() { };
		template<typename V, typename W>
		pair(const pair<V, W>& pr) {
			first = pr.first;
			second = pr.second;
		}
		pair(T1 first, T2 second) {
			this->first = first;
			this->second = second;
		}
		pair& operator= (const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
//		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//		{ return lhs.first==rhs.first && lhs.second==rhs.second; }
//
//		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//		{ return !(lhs==rhs); }
//
//		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//		{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
//
//		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//		{ return !(rhs<lhs); }
//
//		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//		{ return rhs<lhs; }
//
//		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//		{ return !(lhs<rhs); }
	public:
		T1 first;
		T2 second;
	};
	pair<T1, T2> make_pair (T1 x, T2 y) {
		ft::pair<T1, T2> pair(x, y);
		return pair;
	}

}
#endif //FT_CONTAINERS_PAIR_HPP
