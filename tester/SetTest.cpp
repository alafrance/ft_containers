//
// Created by Alexis Lafrance on 12/9/21.
//

#include "tester.hpp"
#include "googleTestLike.cpp"
#include <set>
#include "../containers/set.hpp"

void TestConstructorSet() {
	displayLittlePart("Constructor");

	ft::set<int> first;

	first.insert(10);
	first.insert(30);
	first.insert(50);
	first.insert(70);
	ft::set<int> second(first.begin(), first.end());

	ft::set<int> third(second);

	ft::set<int, std::less<int> > fourth;	// class as Compare

	EXPECT_EQ(first.size(), static_cast<size_t>(4));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	EXPECT_EQ(third.size(), static_cast<size_t>(4));
	EXPECT_EQ(fourth.size(), static_cast<size_t>(0));
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestSwapSet() {
	displayLittlePart("Swap");
	ft::set<int> first;

	first.insert(1);
	first.insert(2);
	first.insert(3);
	first.insert(4);

	ft::set<int> second;
	second.insert(90);
	second.insert(91);
	second.insert(92);
	second.insert(93);
	second.insert(94);

	first.swap(second);
	EXPECT_EQ(*first.find(90), 90);
	EXPECT_EQ(*second.find(1), 1);
	EXPECT_EQ(first.size(), static_cast<size_t>(5));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestEmptyAndEraseSet() {
	displayLittlePart("Empty");
	displayLittlePart("Empty");
	ft::set<int> myset;
	std::set<int> stdset;

	int sum = 0;
	int stdsum = 0;

	for (int i = 1; i <= 10; i++)
	{
		myset.insert(i);
		stdset.insert(i);
	}

	int i = 1;
	while (!myset.empty())
	{
		sum += *myset.find(i);
		myset.erase(i);
		i++;
	}
	i = 1;
	while (!stdset.empty())
	{
		stdsum += *stdset.find(i);
		stdset.erase(i);
		i++;
	}
	EXPECT_EQ(stdsum, sum);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestClearSet() {
	displayLittlePart("Clear");

	ft::set<int> myset;

	myset.insert(1);
	myset.insert(2);
	myset.insert(3);
	myset.insert(4);
	myset.insert(5);

	myset.clear();
	EXPECT_EQ(static_cast<int>(myset.size()), 0);
	myset.insert(12);
	myset.insert(10);
	EXPECT_EQ(static_cast<int>(*myset.find(12)), 12);
	EXPECT_EQ(static_cast<int>(*myset.find(10)), 10);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestFindAndEraseSet() {
	displayLittlePart("Find");
	ft::set<int> myset;
	ft::set<int>::iterator it;

	myset.insert(50);
	myset.insert(100);
	myset.insert(150);
	myset.insert(200);

	it = myset.find('b');
	if (it != myset.end())
		myset.erase (it);

	// print content
	EXPECT_EQ(*myset.find(50), 50);
	EXPECT_EQ(*myset.find(100), 100);
	EXPECT_EQ(*myset.find(150), 150);
	EXPECT_EQ(*myset.find(200), 200);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestIteratorSet() {
	displayLittlePart("Basic Test");
	ft::set<int> myset;
	myset.insert(4);
	myset.insert(1);
	myset.insert(3);
	myset.insert(2);

	ft::set<int>::iterator it = myset.begin();
	EXPECT_EQ(*it, 1);
	it++;
	EXPECT_EQ(*it, 2);
	it++;
	EXPECT_EQ(*it, 3);
	it++;
	EXPECT_EQ(*it, 4);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestIterator2Set() {
	displayLittlePart("Basic Test 2");
	int myints[] = {75,23,65,42,13};
	ft::set<int> myset (myints,myints+5);
	std::set<int> set (myints,myints+5);

	ft::set<int>::iterator it = myset.begin();
	std::set<int>::iterator it2 = set.begin();
	std::cout << *(myset.begin()) << std::endl;
	std::cout << *it << std::endl;
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(*it, *it2);
		it++;
		it2++;
	}

	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestReverseIteratorSet() {
	displayLittlePart("Reverse Iterator");
	displayLittlePart("Basic Test");
	ft::set<int> myset;
	myset.insert(1);
	myset.insert(2);
	myset.insert(3);
	myset.insert(4);

	ft::set<int>::reverse_iterator rit = myset.rbegin();
	EXPECT_EQ(*rit, 4);
	rit++;
	EXPECT_EQ(*rit, 3);
	rit++;
	EXPECT_EQ(*rit, 2);
	rit++;
	EXPECT_EQ(*rit, 1);

	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestInsertIteratorSet() {
	displayLittlePart("Insert with range of iterators");
	ft::set<int> myset;
	myset.insert(4);
	myset.insert(1);
	myset.insert(3);
	myset.insert(2);

	ft::set<int> myset2;

	myset2.insert(myset.begin(), myset.end());
	ft::set<int>::iterator it = myset.begin();
	EXPECT_EQ(*it, 1);
	it++;
	EXPECT_EQ(*it, 2);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestInsertSet() {
	displayLittlePart("Insert");
	ft::set<int> myset;
	myset.insert(5);

	// ALREADY EXISTS
	ft::pair<ft::set<int>::iterator, bool > pair;
	pair = myset.insert(5);

	EXPECT_EQ(*pair.first, 5);
	EXPECT_FALSE(pair.second);

	ft::pair<ft::set<int>::iterator, bool > pair2;
	pair2 = myset.insert(1);

	EXPECT_EQ(*pair2.first, 1);
	EXPECT_TRUE(pair2.second);

	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}


void TestEqualUpperLowerBoundsSet() {
	displayLittlePart("All The Tests For Bounds");
	ft::set<int> myset;
	myset.insert(10);
	myset.insert(20);
	myset.insert(30);
	myset.insert(40);
	myset.insert(60);

	ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret = myset.equal_range(20);

	EXPECT_EQ(*ret.first, 20);

	EXPECT_EQ(*ret.second, 30);

	ret = myset.equal_range(70);
	if (ret.first != NULL)
		EXPECT_TRUE(false); // RETURN A ERROR
	if (ret.second != NULL)
		EXPECT_TRUE(false); // RETURN A ERROR

	ret = myset.equal_range(50);
	EXPECT_EQ(*ret.first, 60);
	EXPECT_EQ(*ret.second, 60);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void testAllSet() {
	displayPart("Set");

	displayShortPart("Constructor");
	TestConstructorSet();

	displayShortPart("Iterators");
	TestIteratorSet();
	TestIterator2Set();
	TestReverseIteratorSet();

	displayShortPart("Functions : Modifiers");
	TestSwapSet();
	TestEmptyAndEraseSet();
	TestClearSet();
	TestInsertSet();
	TestInsertIteratorSet();

	displayShortPart("Functions : Operations");
	TestFindAndEraseSet();
	displayShortPart("Functions : Equal-Upper-Lower Bounds");
	TestEqualUpperLowerBoundsSet();
}