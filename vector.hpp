//
// Created by Alexis Lafrance on 11/3/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP
#include <iostream>
#include "iterator.hpp"
namespace ft {
	template<typename T, class Alloc = std::allocator<T> >
	class vector {
		/* ----------------------------------------------------------------
								RANDOM ACCESS ITERATOR
		---------------------------------------------------------------- */
		class random_access_iterator : virtual public iterator<bidirectional_iterator_tag, T> {
		public:
			/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */
			random_access_iterator() {std::cout << "Default constructor" << std::endl;};

			~random_access_iterator() {std::cout << "Destructor called" << std::endl;};
			random_access_iterator(typename random_access_iterator::pointer a) { // FOR TEST
				std::cout << "T constructor called" << std::endl;
				_p = a;
			}

			random_access_iterator(random_access_iterator const &src) {
				std::cout << "copy-constructible" << std::endl;
				*this = src;
			}
			void display() {
				T a = *_p;
				std::cout << a << std::endl;
			}

			/* -------  OPERATOR OVERLOAD ------- */
			random_access_iterator &operator=(random_access_iterator const &inst) {
				_p = inst._p;
				return (*this);
			}
			bool operator==(random_access_iterator inst) {
				return (_p == inst._p);
			}
			//		bool operator!=(bidirectional_iterator<T> const& inst) {
			//			return (_p != inst._p);
			//		}
			//		random_access_iterator<T>::value_type operator* (){
			//			return *_p;
			//		}
			//		typename ft::bidirectional_iterator<T>::pointer operator-> () {
			//			return _p;
			//		}

			//		bidirectional_iterator<T> &operator++() { // ++it
			//			_p++;
			//			return (*this);
			//		}
			//		bidirectional_iterator<T> operator++(int) { // it++
			//			bidirectional_iterator<T> const& tmp(*this);
			//			_p++;
			//			return (tmp);
			//		}

		private:
			typename random_access_iterator::pointer _p;
		};
		/* ----------------------------------------------------------------
							VECTOR SOURCE CODE
		---------------------------------------------------------------- */
	public:
		/* -------  TYPEDEF  ------- */

		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef random_access_iterator iterator;
		//		typedef '?' const_iterator;
		//		typedef '?' reverse_iterator;
		//		typedef '?' const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */
		// DEFAULT
		explicit vector(const allocator_type &alloc = allocator_type()):
			_alloc(alloc), _array(NULL), _size(0), _capacity(0) {}

		// FILL
		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type())
						 : _size(n), _capacity(n), _alloc(alloc) {
			_array = _alloc.allocate(_size);
			for (int i = 0; i < _size ; i++) {
				 _alloc.construct(_array[i], val);
			}
		}

		// RANGE
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(0), _alloc(alloc){
			for (InputIterator it = first; it < last; it++) {
				_size++;
			}
			_capacity = _size;
			_array = _alloc.allocate(_size);
			size_type i = 0;
			for (first; first != last ; first++) {
				_alloc.construct(_array[i++], *first);
			}
		}

		// COPY
		vector (const vector& x) {
			*this = x;
		}

		// DESTRUCTOR
		virtual ~vector() {

		};

		/* -------  OPERATOR OVERLOAD ------- */
		vector &operator=(vector const &inst) {
			(void)inst;
			return (*this);
		};

		/* -------  ITERATOR ------- */

		iterator begin() {
			return (&_array[0]);
		}

	/* -------  ATTRIBUTES ------- */
	private:
		Alloc	_alloc;
		typename random_access_iterator::pointer	_array;
		size_type _size;
		size_type _capacity;

	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
