//
// Created by Alexis Lafrance on 12/9/21.
//
#include "tester.hpp"
#include <iostream>
static int countTest = 1;
void displayTestOk(std::string msg) {
	std::cout << GREEN << "✅️️️ " << countTest++ << " OK : " << msg << RESET << std::endl;
	global_error = 0;
}

void displayTestError(std::string msg) {
	std::cout << RED << "🔴" << countTest++ << "ERROR : " << msg << RESET << std::endl;
	global_error = 0;
}

void displayPart(std::string msg) {
	std::cout << BLUE << "------------------- " << msg << " -------------------" << RESET << std::endl;
}

void displayShortPart(std::string msg) {
	std::cout << BLUE << "\n-------- " << msg << " --------" << RESET << std::endl;
}

void displayMsgError(e_error error) {
	switch (error) {
		case e_equal:
			std::cout << RED << "TEST ERROR : " << "TWO VALUES NEED TO BE EQUALS : " << RESET << std::endl;
			break;
		case e_same_type:
			std::cout << RED << "TEST ERROR : " <<  "TWO VALUES ARE NOT THE SAME TYPES FOR TEST" << RESET << std::endl;
		case e_nequal:
			std::cout << RED << "TEST ERROR : " << "TWO VALUES NEED TO BE NOT EQUALS: " << RESET << std::endl;
			break;
		case e_true:
			std::cout << RED << "TEST ERROR : " << "NEED TO BE TRUE" << RESET << std::endl;
			break;
		case e_false:
			std::cout << RED << "TEST ERROR : " << "NEED TO BE FALSE" << RESET << std::endl;
			break;
		default:
			std::cout << RED << "NOT A VALID ERROR " << RESET << std::endl;
	}
}
