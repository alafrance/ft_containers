#include "vector.hpp"
#include <vector>
#include "pair.hpp"
#include <map>
int main() {


//	ft::vector<std::string> okay;
//	okay.push_back("a");
//	okay.push_back("b");
//	okay.push_back("c");
//	ft::vector<std::string>::iterator it = okay.begin();
//	*it = "coucou";


// REFERENCE TEST
//	ft::vector<int> okay;
//	okay.push_back(4);
//	okay.push_back(5);
//	okay.push_back(6);
//	ft::vector<int>::iterator it = okay.begin();
//	*it = 4;
//	std::cout << *it++ << std::endl;
//	std::cout << *it << std::endl;
//	ft::vector<int> hola(okay.begin(), okay.end());

// int myints[] = {1, 2,3,4,5};
//
	ft::vector<int> myvec;
	for (int i = 0; i < 10; ++i) myvec.push_back(i);
	ft::reverse_iterator<ft::vector<int>::iterator> beginBase(myvec.begin());
	ft::reverse_iterator<ft::vector<int>::iterator> endBase(myvec.end());
	while (endBase != beginBase) {
		std::cout << *endBase << std::endl;
		*endBase++;
	}
}
