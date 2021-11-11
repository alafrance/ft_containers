//
// Created by Alexis Lafrance on 11/3/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP
#include <iostream>
#include <cmath>
#include "iterator.hpp"
#include "metafunctions/metafunctions.hpp"

namespace ft {
	class OutOfRangeException : public std::exception {
	public:
		const char *what () const throw ()
		{
			return "Your grade is too high (grade >= 1)";
		}
	};
	template<typename T, class Alloc = std::allocator<T> >
	class vector {
		/* ----------------------------------------------------------------
								RANDOM ACCESS ITERATOR
		---------------------------------------------------------------- */
		class random_access_iterator : virtual public iterator<random_access_iterator_tag, T> {
		public:
			/* -------  CONSTRUCTOR AND DESTRUCTOR ------- */

				/* -------  CANONICAL FORM ------- */
			random_access_iterator() {};

			~random_access_iterator() {};

			random_access_iterator(typename random_access_iterator::pointer a) { // FOR TEST
				_p = a;
			}

			random_access_iterator(random_access_iterator const &src) {
				*this = src;
			}

			random_access_iterator &operator=(random_access_iterator const &inst) {
				_p = inst._p;
				return (*this);
			}
			/* -------  OPERATOR OVERLOAD ------- */

			/* 		-------  RELATIONAL ------- */

			bool operator==(random_access_iterator inst) {
				return (_p == inst._p);
			}

			bool operator!=(random_access_iterator inst) {
				return (_p != inst._p);
			}

			bool operator<(random_access_iterator inst) {
				return (_p < inst._p);
			}

			bool operator<=(random_access_iterator inst) {
				return (_p <= inst._p);
			}

			bool operator>(random_access_iterator inst) {
				return (_p > inst._p);
			}

			bool operator>=(random_access_iterator inst) {
				return (_p >= inst._p);
			}


			/* 		------- (INCRE/DECRE)MENT ------- */
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

			/* 		------- REFERENCE / DEREFERENCE ------- */
			typename random_access_iterator::value_type operator* (){
				return *_p;
			}

			typename random_access_iterator::value_type operator-> (){
				return *_p;
			}

			/* 		------- ARITHMETIC arithmetic ------- */
			typename random_access_iterator::iterator operator+ (int a){
				return _p + a;
			}

			typename random_access_iterator::iterator operator- (int a){
				return _p - a;
			}

			typename random_access_iterator::difference_type operator- (typename random_access_iterator::iterator it){
				return _p - it._p;
			}

			typename random_access_iterator::iterator operator+= (int a){
				_p += a;
				return (*this);
			}

			typename random_access_iterator::iterator operator-= (int a){
				_p -= a;
				return (*this);
			}

			typename random_access_iterator::value_type operator[] (int a){
				return (_p[a]);
			}
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
				: _alloc(alloc), _size(n), _capacity(capacity(n)) {
			std::cout << "int\n";
			_array = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size ; i++) {
				_alloc.construct(&_array[i], val);
			}
		}

		// RANGE


		template <class InputIterator>
		vector (InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::type, InputIterator>::type last, const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _size(0), _capacity(0) {
//					std::cout << ft::is_integral<InputIterator>::value << std::endl;
			for (InputIterator it = first; it < last; it++) {
				_size++;
			}
			std::cout << "input Iterator\n";
			_capacity = capacity(_size);
			_array = _alloc.allocate(_capacity);
			size_type i = 0;
			for (InputIterator it = first; first != last ; first++) {
				_alloc.construct(&_array[i++], *it);
			}
		}

		// COPY
		vector (const vector& x): _size(0), _capacity(0) {
			*this = x;
		}

		// DESTRUCTOR
		virtual ~vector() {
			clear();
		};

		/* -------  OPERATOR OVERLOAD ------- */
		vector &operator=(vector const &inst) { // DEM
			clear();
			_alloc = inst._alloc;
			_capacity = inst._capacity;
			_size = inst._size;
			_array = _alloc.allocate(_capacity);
			insert(begin(), inst.begin(), inst.end());
			return (*this);
		};

		/* -------  ITERATOR ------- */

		iterator begin() {
			return (&_array[0]);
		}

		iterator end() {
			return (&_array[_size]);
		}

		/* -------  CAPACITY ------- */

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(T));
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n <= _size) // LOWER SIZE NEED TO DESTROY SURPLUS
				while (n < _size)
					_alloc.destroy(&_array[n++]);
			else if (n > _size && n <= _capacity) // HAVE SIZE TO CONSTRUCT SO LETS GOO
				while (_size < n)
					_alloc.construct(&_array[_size], val);
			else { // THE CAPACITY ISN'T ENOUGH SO WE NEED TO CLEAR AND ALLOCATE AND CONSTRUCT
				clear();
				_capacity = capacity(n);
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n ; ++i) {
					_alloc.construct(&_array[_size], val);
				}
			}
		}

		size_type capacity() const {
			return _capacity;
		}

		bool empty() const {
			return (_size == 0);
		}

		void reserve(size_type n) {
				if (n > _capacity) { // IF N IS BIGGER THAN CAPACITY RESERVE
					typename random_access_iterator::pointer tmpMemory;
					tmpMemory = _alloc.allocate(capacity(n));
					for (size_type i = 0; i < _size; ++i) {
						_alloc.construct(&tmpMemory[i], _array[i]);
						_alloc.destroy(&_array[i]);
					}
					_alloc.deallocate(_array, _capacity);
					_capacity = capacity(n);
					_size = n;
					_array = tmpMemory;
				}
		}
		void clear() {
			for (size_type i = 0; i < _size; ++i)
				_alloc.destroy(&_array[i]);
			if (_capacity > 0) // IF WE HAVE ALLOCATE MEMORY IN CONSTRUCTOR
				_alloc.deallocate(_array, _capacity);
			_size = 0;
			_capacity = 0;
		}

		/* -------  Element access ------- */
		reference operator[] (size_type n) {
			if (n >= _size)
				throw OutOfRangeException();
			return (_array[n]);
		}

		const_reference operator[] (size_type n) const{
			if (n >= _size)
				throw OutOfRangeException();
			return (static_cast<const_reference>(_array[n]));
		}

		reference at(size_type n) {
			if (n >= _size)
				throw OutOfRangeException();
			return (_array[n]);
		}

		const_reference at(size_type n) const {
			if (n >= _size)
				throw OutOfRangeException();
			return (static_cast<const_reference>(_array[n]));
		}

		reference front() {
			return (_array[0]);
		}

		const_reference front() const {
			return (static_cast<const_reference >(_array[0]));
		}

		reference back() {
			return (_array[_size - 1]);
		}

		const_reference back() const{
			return (static_cast<const_reference >(_array[_size - 1]));
		}

		/* -------  MODIFIERS ------- */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			size_type count = 0;
			for (InputIterator it = first; it < last; it++)
				count++;
			reserve(count);
			size_type before_size = _size;
			_size = 0;
			for (InputIterator it = first; it < last; it++){
				if (_size < before_size)
					_alloc.destroy(&_array[_size]);
				_alloc.construct(&_array[_size++], *it);
			}
			while (_size < before_size)
					_alloc.destroy(&_array[_size++]);
		}

		void assign (size_type n, const value_type& val) {
			size_type i = 0;
			reserve(n);
			for (i = 0; i < n; i++){
				if (i < _size)
					_alloc.destroy(&_array[i]);
				_alloc.construct(&_array[i], val);
			}
			while (i < _size)
				_alloc.destroy(&_array[i]);
		}

		void push_back(const value_type& val) {
			reserve(_size + 1);
			_alloc.construct(&_array[_size++], val);
		}

		void pop_back() {
			_alloc.destroy(&_array[--_size]);
		}

		iterator insert (iterator position, const value_type& val) {
			typename random_access_iterator::difference_type diff_p = position - begin();
			typename random_access_iterator::pointer it = &_array[_size];
			while(it != &_array[diff_p]) {
				_alloc.construct(it, *(it - 1));
				_alloc.destroy(--it);
			}
			_alloc.construct(it, val);
		}
		void insert (iterator position, size_type n, const value_type& val) {
			for (int i = 0; i < n; i++) {
				position = insert(position, val);
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
			for (first; first < last; first++) {
				position = insert(position, *first);
			}
		}

		iterator erase (iterator position) {
			typename random_access_iterator::difference_type pos = position - begin();
			typename random_access_iterator::pointer ptr_it = &_array[pos];
			_alloc.destroy(&_array[pos]);
			while(ptr_it < &_array[_size]) {
				_alloc.construct(ptr_it, *(ptr_it + 1));
				_alloc.destroy(++ptr_it);
			}
			return (position);
		}

		iterator erase (iterator first, iterator last) {
			typename random_access_iterator::difference_type p = (last - first) - 1;
			while(--p)
				erase(first);
			return (first);
		}

		void swap(vector& x) {
			vector<T> tmp(*this);

			*this = x;
			x = tmp;
		}

		allocator_type get_allocator() const {
			return (_alloc);
		}


		/* -------  UTILITY ------- */
	private:
		size_t 	capacity(size_t n) const {
			return (n * static_cast<size_t>(roundf(static_cast<float>(2 + (n * 0.1)))));
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
