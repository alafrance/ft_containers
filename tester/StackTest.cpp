//
// Created by Alexis Lafrance on 09/12/2021.
//

#include "tester.hpp"
#include "googleTestLike.cpp"
#include "../containers/vector.hpp"
#include "../containers/stack.hpp"
#include <deque>

void TestConstructorAndSize() {
	displayLittlePart("Test Constructors And Size");
	ft::vector<int> myvector (2,200);        // vector with 2 elements
	std::deque<int> mydeque (3,100);          // deque with 3 elements

	ft::stack<int> first;                    // empty stack
	ft::stack<int> second (myvector);         // stack initialized to copy of deque

	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,std::deque<int> > fourth (mydeque);
	EXPECT_EQ(static_cast<int>(first.size()), 0);
	EXPECT_EQ(static_cast<int>(second.size()), 2);
	EXPECT_EQ(static_cast<int>(third.size()), 0);
	EXPECT_EQ(static_cast<int>(fourth.size()), 3);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestEmptyPopAndPush() {
	displayLittlePart("Empty, Pop and Push");
	ft::stack<int> mystack;
	ft::stack<int> stdstack;

	int sum = 0;
	int stdsum = 0;

	for (int i = 1; i <= 10; i++)
	{
		mystack.push(i);
		stdstack.push(i);
	}

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	while (!stdstack.empty())
	{
		stdsum += stdstack.top();
		stdstack.pop();
	}
	EXPECT_EQ(stdsum, sum);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void testAllStack() {
	displayPart("Stack");
	displayShortPart("STACK FUNCTIONS");
	TestConstructorAndSize();
	TestEmptyPopAndPush();
}