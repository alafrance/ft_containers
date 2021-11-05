#include <iostream>
#include <vector>
#include <map>
#include "vector.hpp"
int main() {
	int *a = new int[2];
	a[0] = 42;
	a[1] = 21;
	ft::vector<int> myvector(a);
	(void)myvector.begin();
//	ft::bidirectional_iterator<int> it = myvector.begin();
//	++it;
//	std::cout << *it << std::endl;
}

