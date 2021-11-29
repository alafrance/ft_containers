//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "containers/map.hpp"
#include <vector>
#include <map>
#include <list>
#include <random>
#include "RedBlackTree.hpp"



//int main() {
//	RBTree<int, char> tree(55);
//	tree.insert(40);
//	tree.insert(65);
//	tree.insert(60);
//	tree.insert(75);
//	tree.insert(52);
//	tree.insert(23);
//	tree.insert(45);
//	tree.insert(42);
//	tree.insert(12);
//	tree.insert(26);
//	tree.insert(56);
//	tree.insert(48);
//	tree.insert(2);
//	tree.insert(57);
//	std::cout << "\n-------- DELETE -------- " << std::endl;
//	std::cout << "DELETE 55 :" << std::endl;
//	tree.deleteNode(55);
//	std::cout << "\n";
//	tree.display();
//	std::cout << "DELETE 40 :" << std::endl;
//	tree.deleteNode(40);
//	std::cout << "-------- DELETE --------\n" << std::endl;
//	tree.display();
//	// DELETE TREE UNCOMMENT BE CAREFUL
//}

//int main() {
//	RBTree<int, char> tree(55);
//	std::vector<int> vec;
//	srand (time(NULL));
//	for (int i = 0; i < 100; ++i) {
//		vec.push_back(rand() % 1000);
//		tree.insert(*(--vec.end()));
//	}
//	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
//		std::cout << *it << ", ";
//	}
//	int seed = std::chrono::system_clock::now().time_since_epoch().count();
//	std::default_random_engine gen = std::default_random_engine(seed);
//	std::shuffle(vec.begin(), vec.end(), gen);
//	std::cout << std::endl << std::endl;
//	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
//		std::cout << *it << ", ";
//	}
//	std::cout << "\n-------- DELETE -------- " << std::endl;
//	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
//		tree.deleteNode(*it);
//	}
//	std::cout << "\n-------- END DELETE -------- " << std::endl;
//	tree.display();
//	tree.deleteNode(55);
//	std::cout << "DELETE 55 :" << std::endl;
//	tree.display();
//	std::cout << "\n";
//	std::cout << "-------- DELETE --------\n" << std::endl;
//	tree.display();
////	 DELETE TREE UNCOMMENT BE CAREFUL
//}


// SEED WITH BUGS
int main() {

	int myints[] = {796, 655, 445, 732, 159, 266, 126, 644, 907, 832, 226, 921, 558, 436, 703, 79, 775, 581, 27, 323,
					352, 374, 37, 663, 271, 567, 260, 786, 781, 944, 276, 696, 411, 823, 185, 536, 276, 913, 318, 1,
					531, 644, 1, 758, 176, 434, 528, 991, 259, 406, 439, 579, 625, 120, 636, 737, 506, 273, 685, 750,
					324, 785, 231, 567, 361, 479, 254, 667, 820, 177, 723, 17, 816, 180, 876, 215, 468, 671, 412, 454,
					593, 133, 986, 811, 577, 437, 902, 697, 188, 558, 853, 312, 7, 939, 216, 167, 212, 19, 350, 926,
	};
	int myints2[] = {902, 188, 832, 528, 655, 644, 260, 579, 350, 758, 663, 312, 796, 820, 271, 437, 216, 939, 667, 406,
					 323, 1, 811, 732, 479, 506, 785, 27, 636, 921, 17, 276, 644, 185, 374, 750, 159, 685, 226, 180, 133,
					 434, 531, 786, 212, 454, 775, 816, 361, 926, 991, 266, 352, 37, 558, 324, 411, 737, 167, 907, 558, 1,
					 577, 567, 823, 254, 259, 853, 7, 436, 215, 986, 913, 276, 273, 120, 468, 231, 703, 671, 723, 412, 79,
					 944, 697, 567, 126, 439, 176, 536, 19, 781, 445, 177, 318, 696, 876, 625, 581, 593,
	};
	RBTree<int, char> tree(55);
	for (int *i = myints; i < myints + 100; i++) {
		tree.insert(*i);
	}
	for (int *i = myints2; i < myints2 + 100; i++) {
		tree.deleteNode(*i);
	}
}
/*
796, 655, 445, 732, 159, 266, 126, 644, 907, 832, 226, 921, 558, 436, 703, 79, 775, 581, 27, 323, 352, 374, 37, 663, 271, 567, 260, 786, 781, 944, 276, 696, 411, 823, 185, 536, 276, 913, 318, 1, 531, 644, 1, 758, 176, 434, 528, 991, 259, 406, 439, 579, 625, 120, 636, 737, 506, 273, 685, 750, 324, 785, 231, 567, 361, 479, 254, 667, 820, 177, 723, 17, 816, 180, 876, 215, 468, 671, 412, 454, 593, 133, 986, 811, 577, 437, 902, 697, 188, 558, 853, 312, 7, 939, 216, 167, 212, 19, 350, 926,

902, 188, 832, 528, 655, 644, 260, 579, 350, 758, 663, 312, 796, 820, 271, 437, 216, 939, 667, 406, 323, 1, 811, 732, 479, 506, 785, 27, 636, 921, 17, 276, 644, 185, 374, 750, 159, 685, 226, 180, 133, 434, 531, 786, 212, 454, 775, 816, 361, 926, 991, 266, 352, 37, 558, 324, 411, 737, 167, 907, 558, 1, 577, 567, 823, 254, 259, 853, 7, 436, 215, 986, 913, 276, 273, 120, 468, 231, 703, 671, 723, 412, 79, 944, 697, 567, 126, 439, 176, 536, 19, 781, 445, 177, 318, 696, 876, 625, 581, 593,

 */