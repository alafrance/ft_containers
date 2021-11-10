//
// Created by Alexis Lafrance on 11/3/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP
#include <iostream>
#include "iterator.hpp"
#include "metafunctions/metafunctions.hpp"

namespace ft {
	template<typename T, class Alloc = std::allocator<T> >
	class vector {
		/* ----------------------------------------------------------------
								RANDOM ACCESS ITERATOR
		---------------------------------------------------------------- */
		class random_access_iterator : virtual public iterator<bidirectional_iterator_tag, T> {
		public:
			/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */
			random_access_iterator() {};

			~random_access_iterator() {};

			random_access_iterator(typename random_access_iterator::pointer a) { // FOR TEST
				_p = a;
			}

			random_access_iterator(random_access_iterator const &src) {
				*this = src;
			}

			/* -------  OPERATOR OVERLOAD ------- */
			random_access_iterator &operator=(random_access_iterator const &inst) {
				_p = inst._p;
				return (*this);
			}

			bool operator==(random_access_iterator inst) {
				return (_p == inst._p);
			}

			random_access_iterator &operator--() { //--a
				_p--;
				return (*this);
			}

			random_access_iterator operator--(int) {//a--
				random_access_iterator tmp(*this);
				this->_p--;
				return (tmp);
			}

			random_access_iterator &operator++() { //--a
				_p++;
				return (*this);
			}

			random_access_iterator operator++(int) {//a--
				random_access_iterator tmp(*this);
				this->_p++;
				return (tmp);
			}

			typename random_access_iterator::value_type operator* (){
				return *_p;
			}

//			bool operator!=(random_access_iterator const& inst) {
//				return (_p != inst._p);
//			}

			//		typename ft::bidirectional_iterator<T>::pointer operator-> () {
			//			return _p;
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
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _size(n), _capacity(n) {
			std::cout << "int\n";
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size ; i++) {
				_alloc.construct(&_array[i], val);
			}
		}

		// RANGE
		//TODO: - InputIterator doesn't work with pointers
		template <class InputIterator>
		vector (InputIterator first,  typename std::enable_if<!std::is_integral<InputIterator>::type, InputIterator>::type last, const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _size(0), _capacity(0) {
//					std::cout << ft::is_integral<InputIterator>::value << std::endl;
			for (InputIterator it = first; it < last; it++) {
				_size++;
			}
			std::cout << "input Iterator\n";
			_capacity = _size;
			_array = _alloc.allocate(_size);
			size_type i = 0;
			for (InputIterator it = first; first != last ; first++) {
				_alloc.construct(&_array[i++], *it);
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
