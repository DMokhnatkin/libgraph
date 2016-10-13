#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/DataStorages/RingBuffer.h>

using namespace libgraph;
class RingBufferTest : public ::testing::Test {
protected:
	RingBuffer<int> *coll;
	void SetUp() override {
		coll = new RingBuffer<int>(4);
	}
	void TearDown() override {
		delete coll;
	}
};

TEST_F(RingBufferTest, testEmpty) {
	ASSERT_TRUE(coll->isEmpty());
	coll->push_back(0);
	ASSERT_FALSE(coll->isEmpty());
	ASSERT_EQ(coll->pop_top(), 0);
	ASSERT_TRUE(coll->isEmpty());
	coll->push_top(1);
	ASSERT_FALSE(coll->isEmpty());
	ASSERT_EQ(coll->pop_back(), 1);
	ASSERT_TRUE(coll->isEmpty());
}

TEST_F(RingBufferTest, testPushPop) {
	coll->push_back(0); // 0***
	coll->push_back(1); // 01**
	coll->push_back(2); // 012*
	coll->push_back(3); // 0123
	ASSERT_EQ(coll->pop_top(), 0); // *123
	ASSERT_EQ(coll->pop_top(), 1); // **23
	coll->push_back(4); // 4*23
	ASSERT_EQ(coll->pop_top(), 2); // 4**3
	coll->push_back(5); // 45*3
	ASSERT_EQ(coll->pop_back(), 5); // 4**3
	coll->push_top(6); // 4*63
	ASSERT_EQ(coll->pop_back(), 4); // **63
	coll->push_top(7); // *763
	ASSERT_EQ(coll->pop_back(), 3); // *76*
}

TEST_F(RingBufferTest, testExceptions) {
	ASSERT_THROW(coll->pop_top(), EmptyBufferException);
	coll->push_back(0);
	coll->push_back(1);
	coll->push_back(2);
	coll->push_back(3);
	ASSERT_THROW(coll->push_back(3), FullBufferException);
}

TEST_F(RingBufferTest, testCount) {
	ASSERT_EQ(coll->count(), 0);
	coll->push_back(0);
	ASSERT_EQ(coll->count(), 1);
	coll->push_back(1);
	ASSERT_EQ(coll->count(), 2);
	coll->push_back(2);
	ASSERT_EQ(coll->count(), 3);
	coll->push_back(3);
	ASSERT_EQ(coll->count(), 4);
	coll->pop_top();
	ASSERT_EQ(coll->count(), 3);
	coll->push_back(4);
	ASSERT_EQ(coll->count(), 4);
}


