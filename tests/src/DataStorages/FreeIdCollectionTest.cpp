#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;

class FreeIdCollectionTest : public ::testing::Test {
protected:
	FreeIdCollection *coll;
	void SetUp() {
		coll = new FreeIdCollection();
	}
	void TearDown() {
		delete coll;
	}
};

TEST_F(FreeIdCollectionTest, testClear) {
	float v1 = 3;
	float v2 = 5;

	int v1_id = coll->createVertex(&v1);
	int v2_id = coll->createVertex(&v2);

	coll->clear();
	ASSERT_EQ(coll->getVertexCount(), 0);
	ASSERT_EQ(coll->isInCollection(v1_id), false);
	ASSERT_EQ(coll->isInCollection(v2_id), false);
}

TEST_F(FreeIdCollectionTest, testAdding) {
	float v1 = 3;
	float v2 = 5;

	int v1_id = coll->createVertex(&v1);
	ASSERT_EQ(coll->getVertexCount(), 1);
	ASSERT_EQ(coll->isInCollection(v1_id), true);
	ASSERT_EQ(*(float*)coll->getData(v1_id), 3);

	int v2_id = coll->createVertex(&v2);
	ASSERT_EQ(coll->getVertexCount(), 2);
	ASSERT_EQ(coll->isInCollection(v2_id), true);
	ASSERT_EQ(*(float*)coll->getData(v2_id), 5);

	ASSERT_EQ(coll->isInCollection(3), false);

	coll->clear();
}
