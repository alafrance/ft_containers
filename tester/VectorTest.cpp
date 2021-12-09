//
// Created by Alexis Lafrance on 12/9/21.
//
#include <iostream>
#include "../containers/vector.hpp"
#include "tester.hpp"
#include <vector>


// ------------------ EXPECT : GOOGLE TEST LIKE ------------------
template<typename T, typename U>
void EXPECT_EQ(T a, U b) {
	(void)a;
	(void)b;
	displayMsgError(e_same_type);
	global_error = 1;
}

template<typename T>
void EXPECT_EQ(T a, T b) {
	(void)a;
	(void)b;
	if (a != b) {
		displayMsgError(e_equal);
		global_error = 1;
	}
}

template<typename T, typename U>
void EXPECT_NE(T a, U b) {
	displayMsgErrorNotSameType(a, b);
	global_error = 1;
}

template<typename T>
void EXPECT_NE(T a, T b) {
	if (a == b) {
		displayMsgError(e_nequal);
		global_error = 1;
	}
}
template<typename T>
void EXPECT_FALSE(T a) {
	if (a) {
		displayMsgError(e_false);
		global_error = 1;
	}
}

template<typename T>
void EXPECT_TRUE(T a) {
	if (!a) {
		displayMsgError(e_true);
		global_error = 1;
	}
}


// ------------------ UTILITY TEST ------------------

template<typename T>
void testContentOfVector(T content, size_t size, ft::vector<T> a) {
	size_t count = 0;
	T *array;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename ft::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
		if (count > size)
			break;
		EXPECT_EQ(*it, array[count]);
		count++;
	}
	EXPECT_EQ(count, size);
	if (std::is_integral<T>::value)
		delete[] array;
}

template<typename T>
void testContentOfVector(T content, size_t size) {
	size_t count = 0;
	ft::vector<T> a(size, content);
	T *array = nullptr;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename ft::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
		if (count > size)
			break;
		EXPECT_EQ(*it, array[count]);
		count++;
	}
	EXPECT_EQ(count, size);
	if (std::is_integral<T>::value)
		delete[] array;
	if (size != 0)
		EXPECT_FALSE(a.empty());
	else
		EXPECT_TRUE(a.empty());
}

// ------------------ TEST CONSTRUCTOR ------------------

void testConstructorWithDifferentsTypes() {
	displayLittlePart("Differents Types");
	ft::vector<int> g;
	EXPECT_EQ(g.empty(), true);
	EXPECT_EQ(g.size(), (size_t)0);
	EXPECT_EQ(g.capacity(), (size_t)0);

	size_t size_a = 1000;
	ft::vector<char> a(size_a, 'b');
	testContentOfVector('b', size_a, a);
	const ft::vector<char>& c(a);
	EXPECT_EQ(a, c);
	const ft::vector<char>& d = a;
	EXPECT_EQ(a, d);

	testContentOfVector(1, 4200);
	testContentOfVector("blablou", 0);
	testContentOfVector(true, 4200);
	testContentOfVector(static_cast<unsigned long long int>(199), 100);

	ft::vector<std::string> testVec(2, static_cast<std::string>("coucou"));
	EXPECT_EQ(static_cast<std::string>(*testVec.begin()), static_cast<std::string>("coucou"));
	std::string end = *(testVec.end() - 1);
	EXPECT_EQ(end, static_cast<std::string>("coucou"));
	EXPECT_NE(*testVec.end() , static_cast<std::string>("coucou"));

	int myints[] = {1, 2, 3, 4};
	ft::vector<int> john(myints, myints + 3);
	displayTestOk();
}

// ------------------ TEST REVERSE_ITERATOR ------------------

void TestReverseIteratorForVector() {
	displayLittlePart("Basic Test");
	ft::vector<int> vector;   // three ints with a value of 100
	std::vector<int> svector; // three ints with a value of 100
	for (int i = 0; i < 10000; ++i)
	{
		vector.push_back(i);
		svector.push_back(i);
		vector.push_back(i);
		svector.push_back(i);
	}
	ft::vector<int>::reverse_iterator rit = vector.rbegin();
	std::vector<int>::reverse_iterator srit = svector.rbegin();
	int r = rit[10];
	int sr = srit[10];
	EXPECT_EQ(r, sr);

	EXPECT_EQ(*(rit + 5), *(srit + 5));
	EXPECT_EQ(*(rit + 205), *(srit + 205));
	while (rit != vector.rend())
	EXPECT_EQ(*srit++, *rit++);
	int r2 = rit[-10];
	int sr2 = srit[-10];
	EXPECT_EQ(r2, sr2);
	EXPECT_EQ(rit.base(), vector.begin());

	EXPECT_EQ(*(rit -= 5), *(srit -= 5));
	EXPECT_EQ(*rit--, *srit--);
	EXPECT_EQ(*--rit, *--srit);
	EXPECT_EQ(rit, rit);
	EXPECT_FALSE(rit < rit);
	EXPECT_TRUE(rit <= ++rit);
	EXPECT_TRUE(rit < (rit + 1));
	EXPECT_TRUE(rit > (rit - 1));
	EXPECT_FALSE(rit != rit);
	EXPECT_TRUE(rit != (rit + 1));
	displayTestOk();

}

void TestReverseConstIterator() {
	displayLittlePart("Const Reverse Iterator");
	ft::vector<int> vector;  // three ints with a value of 100
	std::vector<int> svector;         // three ints with a value of 100
	for (int i = 0; i < 10000; ++i)
	{
	vector.push_back(i);
	svector.push_back(i);
	vector.push_back(i);
	svector.push_back(i);
	}
	ft::vector<int>::const_reverse_iterator rit;
	ft::vector<int>::const_reverse_iterator rit2(rit);
	std::vector<int>::const_reverse_iterator srit;

	srit = svector.rbegin();
	rit = vector.rbegin();
	while (rit != vector.rend())
		EXPECT_EQ(*srit++, *rit++);
	displayTestOk();
}

// ------------------ TEST ITERATORS ------------------



void TestIteratorAllOperators()
{
	displayLittlePart("Test Iterator All Operators");
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::vector<int> stdvector;
	std::vector<int>::iterator stdit;

	for (int i = 0; i < 20; ++i)
	{
	myvector.push_back(i);
	stdvector.push_back(i);
	}
	EXPECT_EQ(myvector.front(), stdvector.front());
	EXPECT_EQ(myvector.back(), stdvector.back());
	EXPECT_EQ(myvector.size(), stdvector.size());

	it = myvector.begin();
	stdit = stdvector.begin();
	EXPECT_EQ(*it, *stdit);
	it += 10;
	stdit += 10;
	EXPECT_EQ(*it, *stdit);
	it -= 5;
	stdit -= 5;
	EXPECT_EQ(*it, *stdit);
	it -= 5;
	stdit -= 5;
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(*(it + 10), *(stdit + 10));
	EXPECT_EQ(it[10], stdit[10]);
	displayTestOk();
}



void TestIteratorWithPairs()
{
	displayLittlePart("Test Iterator With Pairs");

	ft::vector<std::pair<int, int> > myvector2;
	ft::vector<std::pair<int, int> >::iterator it2;
	std::vector<std::pair<int, int> > stdvector2;
	std::vector<std::pair<int, int> >::iterator stdit2;

	std::pair<int, int> p(1, 2);
	myvector2.push_back(p);
	stdvector2.push_back(p);
	it2 = myvector2.begin();
	stdit2 = stdvector2.begin();
	EXPECT_EQ(it2->first, stdit2->first);
	EXPECT_EQ(it2->second, stdit2->second);
	displayTestOk();
}
void TestIteratorsWithInverseOperators() {
	displayLittlePart("Test Iterator With Inverse Operators");

	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	ft::vector<int>::const_iterator cit;
	std::vector<int> stdvector;
	std::vector<int>::iterator stdit;
	std::vector<int>::const_iterator cstdit;

	for (int i = 0; i < 10; ++i)
	{
		myvector.push_back(i);
		stdvector.push_back(i);
	}
	it = myvector.begin();
	stdit = stdvector.begin();
	cit = myvector.begin();
	cstdit = stdvector.begin();
	EXPECT_EQ(*(5 + it), *(5 + stdit));
	EXPECT_EQ(*(5 + cit), *(5 + cstdit));
	EXPECT_EQ(cit, it);
	EXPECT_EQ(it, cit);
	displayTestOk();

}
void TestRelationalOperator() {
	displayLittlePart("Basic Test");

	int myint[] = {0, 1, 2, 3, 4};
	ft::vector<int> foo(3, 100);                          // three ints with a value of 100
	ft::vector<int> bar(2, 200);                          // two ints with a value of 200
	ft::vector<int> three(myint, myint + 3);  // three ints with a value of 100
	ft::vector<int> four(myint, myint + 4);   // two ints with a value of 200

	EXPECT_FALSE(foo == bar);
	EXPECT_TRUE(foo != bar);
	EXPECT_FALSE(foo > bar);
	EXPECT_TRUE(foo < bar);
	EXPECT_FALSE(foo >= bar);
	EXPECT_TRUE(foo <= bar);
	EXPECT_FALSE(three == four);
	EXPECT_TRUE(three != four);
	EXPECT_FALSE(three > four);
	EXPECT_TRUE(three < four);
	EXPECT_FALSE(three >= four);
	EXPECT_TRUE(three <= four);
	displayTestOk();
}
void TestClear() {
	displayLittlePart("Clear");
	ft::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);

	EXPECT_EQ(myvector.front(), 1101);
	EXPECT_EQ(myvector.back(), 2202);
	EXPECT_EQ(myvector.size(), size_t(2));
	displayTestOk();
}

void TestSwap() {
	displayLittlePart("Swap");
	ft::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);

	EXPECT_EQ(myvector.front(), 1101);
	EXPECT_EQ(myvector.back(), 2202);
	EXPECT_EQ(myvector.size(), size_t(2));
	displayTestOk();
}

void TestErase() {
	displayLittlePart("Erase");
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin() + 5);
	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);
	int resultarr[] = {4, 5, 7, 8, 9, 10};
	for (size_t i = 0; i < myvector.size(); ++i)
		EXPECT_EQ(myvector[i], resultarr[i]);
	displayTestOk();
}

void TestInsert() {
	displayLittlePart("Insert");
	ft::vector<int> myvector(3, 100);
	ft::vector<int>::iterator it;

//	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 503};
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	// 503, 502, 501, 300, 300, 400, 400, 200, 100, 100, 100,
	int resultarr[] = {501, 502, 503, 300, 300, 400, 400, 200, 100, 100, 100};
	for (size_t i = 0; i < myvector.size(); ++i)
		// std::cout << myvector[i] << ", ";
		EXPECT_EQ(myvector[i], resultarr[i]);
	displayTestOk();
}


void Test() {
	displayLittlePart("");

	displayTestOk();
}
void testAllVector() {
	displayPart("VECTOR");

	displayShortPart("CONSTRUCTOR");
	testConstructorWithDifferentsTypes();

	displayShortPart("REVERSE ITERATOR");
	TestReverseIteratorForVector();
	TestReverseConstIterator();

	displayShortPart("ITERATORS");
	TestIteratorAllOperators();
	TestIteratorWithPairs();
	TestIteratorsWithInverseOperators();

	displayShortPart("RELATIONAL OPERATORS");
	TestRelationalOperator();

	displayShortPart("VECTOR FUNCTIONS");

}

void TestInsertWithIterators()
{
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::vector<int> stdvector;
	std::vector<int>::iterator sit;

	it = myvector.end();
	sit = stdvector.end();
	for (int i = 0; i < 20; ++i)
	{
		it = myvector.insert(it, i);
		sit = stdvector.insert(sit, i);
	}
	EXPECT_EQ(myvector.back(), *(--(myvector.end())));
}