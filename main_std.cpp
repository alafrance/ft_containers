#include "tester/tester.hpp"
int  main() {
	const clock_t begin_time = clock();
	global_error = 0;
	testAllVector();
	std::cout << std::endl << std::endl;
	testAllStack();
	std::cout << std::endl << std::endl;
	testAllMap();
	std::cout << std::endl << std::endl;
	testAllSet();
	float time = float(clock () - begin_time) / CLOCKS_PER_SEC;
	std::cout << "TIME : " << time << std::endl;
	std::cout << "MAX TIME FOR FT : " << time * 20 << std::endl;
}
