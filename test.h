#ifndef KRCLIB_TEST_H_INCLUDED
#define KRCLIB_TEST_H_INCLUDED

#include "krclib.h"

typedef struct {
	int test_count, failure_count;
	const char *test_name;
} TestCounter;

typedef void (*TestCase)(TestCounter*);

#define TEST_CASE(TEST_NAME_) \
	void TestCase_##TEST_NAME_(TestCounter *test_counter)

void Test_assert(bool condition, TestCounter *counter, const char *file, int line, const char *msg);

#define TEST(CONDITION_)  Test_assert((CONDITION_), test_counter, __FILE__, __LINE__, #CONDITION_)


#endif
