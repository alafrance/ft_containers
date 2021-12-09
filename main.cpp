
#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include "containers/map.hpp"
#include "containers/set.hpp"
#include <vector>
#include <map>
#include <set>
#include <list>
#include <random>
#include "tester/tester.hpp"
#ifdef BLABLA
	#include "tester/VectorTest.cpp"
	#include "tester/MapTest.cpp"
	#include "tester/SetTest.cpp"
	#include "tester/displayTest.cpp"
#endif
int  main() {
	testAllVector();
}
