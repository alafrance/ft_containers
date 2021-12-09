//
// Created by Alexis Lafrance on 12/9/21.
//

#ifndef FT_CONTAINERS_TESTER_HPP
#define FT_CONTAINERS_TESTER_HPP
// GENERAL
#include <iostream>
#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define RESET "\e[0m"
static int global_error = 0;
enum e_error {e_none, e_same_type, e_equal, e_nequal, e_false, e_true};

// displayTest
void displayTestOk();
void displayPart(std::string msg);
void displayShortPart(std::string msg);
void displayLittlePart(std::string msg);
void displayMsgError(e_error error);
// VectorTest
void testAllVector();

#endif //FT_CONTAINERS_TESTER_HPP
