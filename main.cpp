#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include "pair.hpp"
#include "map.hpp"
int main() {
	ft::stack<int> a;

	a.push(4);
	a.push(5);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	std::cout << a.size() << std::endl;
}
