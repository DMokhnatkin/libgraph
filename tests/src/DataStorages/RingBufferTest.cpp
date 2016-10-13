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

TEST_F(RingBufferTest, testPushPop) {
	coll->push(0);
	coll->push(1);
	coll->push(2);
	coll->push(3);
	ASSERT_EQ(coll->pop(), 0);
	ASSERT_EQ(coll->pop(), 1);
	coll->push(4);
	ASSERT_EQ(coll->pop(), 2);
	coll->push(5);
	ASSERT_EQ(coll->pop(), 3);
	ASSERT_EQ(coll->pop(), 4);
	ASSERT_EQ(coll->pop(), 5);
}

TEST_F(RingBufferTest, testExceptions) {
	ASSERT_THROW(coll->pop(), EmptyBufferException);
	coll->push(0);
	coll->push(1);
	coll->push(2);
	coll->push(3);
	ASSERT_THROW(coll->push(3), FullBufferException);
}

TEST_F(RingBufferTest, testCount) {
	ASSERT_EQ(coll->Count(), 0);
	coll->push(0);
	ASSERT_EQ(coll->Count(), 1);
	coll->push(1);
	ASSERT_EQ(coll->Count(), 2);
	coll->push(2);
	ASSERT_EQ(coll->Count(), 3);
	coll->push(3);
	ASSERT_EQ(coll->Count(), 4);
	coll->pop();
	ASSERT_EQ(coll->Count(), 3);
	coll->push(4);
	ASSERT_EQ(coll->Count(), 4);
}


