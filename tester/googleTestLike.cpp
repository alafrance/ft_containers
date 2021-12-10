//
// Created by Alexis Lafrance on 09/12/2021.
//

#include "tester.hpp"
// ------------------ EXPECT : GOOGLE TEST LIKE ------------------

template<typename T>
void EXPECT_EQ(T a, T b) {
	(void)a;
	(void)b;
	if (a != b) {
		displayMsgError(e_equal);
		global_error = 1;
	}
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

