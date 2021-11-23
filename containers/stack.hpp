//
// Created by Alexis Lafrance on 11/16/21.
//

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP
#include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
	public:
		typedef Container container_type;
		typedef size_t size_type;
		typedef T value_type;

		explicit stack(const container_type &ctnr = container_type()) : container(ctnr) {}

		bool empty() const { return container.empty(); }

		size_type size() const { return container.size(); }

		value_type &top() { return container.back(); }

		const value_type &top() const { return container.back(); }

		void push(const value_type &val) { return container.push_back(val); }

		void pop() { return container.pop_back(); }

		friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return (lhs.container == rhs.container);
		}

		friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return (lhs.container != rhs.container);
		}

		friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return (lhs.container < rhs.container);
		}

		friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return (lhs.container <= rhs.container);
		}

		friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return (lhs.container > rhs.container);
		}

		friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return (lhs.container >= rhs.container);
		}

	private:
		container_type container;
	};
}
#endif //FT_CONTAINERS_STACK_HPP
