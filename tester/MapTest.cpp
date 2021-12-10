//
// Created by Alexis Lafrance on 12/9/21.
//

#include "../containers/map.hpp"
#include "tester.hpp"
#include "googleTestLike.cpp"
#include <map>

void TestConstructor() {
	displayLittlePart("Constructor");

	ft::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	ft::map<char, int> second(first.begin(), first.end());

	ft::map<char, int> third(second);

	ft::map<char, int, std::less<int> > fourth;	// class as Compare

	EXPECT_EQ(first.size(), static_cast<size_t>(4));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	EXPECT_EQ(third.size(), static_cast<size_t>(4));
	EXPECT_EQ(fourth.size(), static_cast<size_t>(0));
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestSwapMap() {
	displayLittlePart("Swap");
	ft::map<char, int> first;

	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;

	ft::map<char, int> second;

	second['a'] = 90;
	second['b'] = 91;
	second['c'] = 92;
	second['d'] = 92;
	second['e'] = 93;

	first.swap(second);
	EXPECT_EQ(first['a'], 90);
	EXPECT_EQ(second['a'], 1);
	EXPECT_EQ(first['e'], 93);
	EXPECT_EQ(first.size(), static_cast<size_t>(5));
	EXPECT_EQ(second.size(), static_cast<size_t>(4));
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestEmptyAndEraseMap() {
	displayLittlePart("Empty");
	ft::map<char, int> mymap;
	std::map<char, int> stdmap;

	for (int i = 1; i <= 10; i++)
	{
		mymap['a' + i] = i;
		stdmap['a' + i] = i;
	}
	int i  = 0;
	while (!mymap.empty())
	{
		mymap.erase('a' + i);
		i++;
	}
	i = 0;
	while (!stdmap.empty())
	{
		stdmap.erase('a' + i);
		i++;
	}
	EXPECT_EQ(static_cast<int>(mymap.size()), 0);
	EXPECT_EQ(static_cast<int>(stdmap.size()), 0);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestClearMap() {
	displayLittlePart("Clear");

	ft::map<char, int> mymap;

	mymap['a'] = 1;
	mymap['b'] = 2;
	mymap['c'] = 3;
	mymap['d'] = 4;
	mymap['e'] = 5;

	mymap.clear();
	EXPECT_EQ(static_cast<int>(mymap.size()), 0);
	mymap['a'] = 12;
	mymap['f'] = 10;
	EXPECT_EQ(static_cast<int>(mymap['a']), 12);
	EXPECT_EQ(static_cast<int>(mymap['f']), 10);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestFindAndEraseMap() {
	displayLittlePart("Find");
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content
	EXPECT_EQ(mymap.find('a')->second, 50);
	EXPECT_EQ(mymap.find('c')->second, 150);
	EXPECT_EQ(mymap.find('d')->second, 200);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestIteratorMap() {
	displayLittlePart("Basic Test");
	ft::map<char,int> mymap;
	mymap['a'] = 1;
	mymap['d'] = 4;
	mymap['b'] = 2;
	mymap['c'] = 3;

	ft::map<char,int>::iterator it = mymap.begin();
	EXPECT_EQ(it->first, 'a');
	EXPECT_EQ(it->second, 1);
	it++;
	EXPECT_EQ(it->first, 'b');
	it++;
	EXPECT_EQ(it->first, 'c');
	it++;
	ft::pair<char, int> pair = *it;
	EXPECT_EQ(pair.first, 'd');
	EXPECT_EQ(pair.second, 4);

	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestReverseIteratorMap() {
	displayLittlePart("Reverse Iterator");
	ft::map<char,int> mymap;
	mymap['a'] = 1;
	mymap['d'] = 4;
	mymap['b'] = 2;
	mymap['c'] = 3;

	ft::reverse_iterator<ft::map<char,int>::iterator> revit = mymap.rbegin();
	ft::map<char, int>::reverse_iterator revit2 = mymap.rbegin();

	// WITH FT::REVERSE_ITERATOR
	EXPECT_EQ(revit->first, 'd');
	EXPECT_EQ(revit->second, 4);
	revit++;
	EXPECT_EQ(revit->first, 'c');
	revit++;
	EXPECT_EQ(revit->first, 'b');
	revit++;
	ft::pair<char, int> pair = *revit;
	EXPECT_EQ(pair.first, 'a');
	EXPECT_EQ(pair.second, 1);

	// WITH FT::MAP::REVERSE_ITERATOR

	EXPECT_EQ(revit2->first, 'd');
	EXPECT_EQ(revit2->second, 4);
	revit2++;
	EXPECT_EQ(revit2->first, 'c');
	revit2++;
	EXPECT_EQ(revit2->first, 'b');
	revit2++;
	ft::pair<char, int> pair2 = *revit2;
	EXPECT_EQ(pair2.first, 'a');
	EXPECT_EQ(pair2.second, 1);

	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestInsertIteratorMap() {
	displayLittlePart("Insert with range of iterators");
	ft::map<char, int> map;
	map['a'] = 1;
	map['b'] = 2;
	map['c'] = 3;
	map['d'] = 4;

	ft::map<char, int> map2;

	map2.insert(map.begin(), map.end());
	ft::map<char, int>::iterator it = map.begin();
	EXPECT_EQ(it->first, 'a');
	EXPECT_EQ(it->second, 1);
	it++;
	EXPECT_EQ(it->first, 'b');
	EXPECT_EQ(it->second, 2);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestInsertMap() {
	displayLittlePart("Insert");
	ft::map<char, int> map;
	map['a'] = 5;


	// ALREADY EXISTS
	ft::pair<ft::map<char, int>::iterator, bool > pair;
	pair = map.insert(ft::pair<char, int>('a', 1));

	EXPECT_EQ(pair.first->first, 'a');
	EXPECT_EQ(pair.first->second, 5);
	EXPECT_FALSE(pair.second);

	ft::pair<ft::map<char, int>::iterator, bool > pair2;
	pair2 = map.insert(ft::pair<char, int>('b', 1));

	EXPECT_EQ(pair2.first->first, 'b');
	EXPECT_EQ(pair2.first->second, 1);
	EXPECT_TRUE(pair2.second);

	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}


void TestEqualUpperLowerBounds() {
	displayLittlePart("All The Tests For Bounds");
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['e']=40;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	EXPECT_EQ(ret.first->first, 'b');
	EXPECT_EQ(ret.first->second, 20);

	EXPECT_EQ(ret.second->first, 'c');
	EXPECT_EQ(ret.second->second, 30);

	ret = mymap.equal_range('g');
	if (ret.first != NULL)
		EXPECT_TRUE(false); // RETURN A ERROR
	if (ret.second != NULL)
		EXPECT_TRUE(false); // RETURN A ERROR

	ret = mymap.equal_range('d');
	EXPECT_EQ(ret.first->first, 'e');
	EXPECT_EQ(ret.first->second, 40);
	EXPECT_EQ(ret.second->first, 'e');
	EXPECT_EQ(ret.second->second, 40);
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void TestMaxSizeMap() {
	displayLittlePart("Max size");
	ft::map<int, int> mymap;
	std::map<int, int> stdmap;
	EXPECT_EQ(mymap.max_size(), stdmap.max_size());
	ft::map<double, double> mymap2;
	std::map<double, double> stdmap2;
	EXPECT_EQ(mymap2.max_size(), stdmap2.max_size());
	ft::map<char, char> mymap3;
	std::map<char, char> stdmap3;
	EXPECT_EQ(mymap3.max_size(), stdmap3.max_size());
	if (global_error == 0)
		displayTestOk();
	else
		global_error = 0;
}

void testAllMap() {
	displayPart("Map");

	displayShortPart("Constructor");
	TestConstructor();

	displayShortPart("Iterators");
	TestIteratorMap();
	TestReverseIteratorMap();

	displayShortPart("Functions : Capacity");
	TestMaxSizeMap();
	displayShortPart("Functions : Modifiers");
	TestSwapMap();
	TestEmptyAndEraseMap();
	TestClearMap();
	TestInsertMap();
	TestInsertIteratorMap();

	displayShortPart("Functions : Operations");
	TestFindAndEraseMap();
	displayShortPart("Functions : Equal-Upper-Lower Bounds");
	TestEqualUpperLowerBounds();
}