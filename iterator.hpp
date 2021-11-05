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

	// I NEED TO COPY IN ONLY FUNCTIONS THAT CAN USED WHEN I FINISHED IN VECTOR AND MAP
	template<typename T>
	class bidirectional_iterator : virtual public iterator<bidirectional_iterator_tag, T> {
	public:
		bidirectional_iterator() {};
		~bidirectional_iterator() {};
		bidirectional_iterator(ft::bidirectional_iterator<T> &src) {
			*this = src;
		}
//		bidirectional_iterator<T> &operator=(bidirectional_iterator<T> inst) {
//			_p = inst._p;
//			return (*this);
//		}
//		bidirectional_iterator<T> &operator=(bidirectional_iterator<T> inst) {
//			(void)inst;
//			return (*this);
//		}
//		bool operator==(bidirectional_iterator<T> const& inst) {
//			return (_p == inst._p);
//		}
//		bool operator!=(bidirectional_iterator<T> const& inst) {
//			return (_p != inst._p);
//		}
		typename ft::bidirectional_iterator<T>::value_type operator* (){
			return *_p;
		}
//		typename ft::bidirectional_iterator<T>::pointer operator-> () {
//			return _p;
//		}

		bidirectional_iterator<T> &operator++() { // ++it
			_p++;
			return (*this);
		}
		bidirectional_iterator<T> operator++(int) { // it++
			bidirectional_iterator<T> const& tmp(*this);
			_p++;
			return (tmp);
		}

	private:
		typename bidirectional_iterator<T>::pointer _p;
	};

	template<typename T>
	class Random_Access_Iterator : virtual public bidirectional_iterator<T>, iterator<random_access_iterator_tag, T> {
	public:
	};
}
#endif //FT_CONTAINERS_ITERATOR_HPP
