#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;
class FreeIdCollectionTest : public ::testing::Test {
protected:
	FreeIdCollection<int> *coll;
	void SetUp() {
		coll = new FreeIdCollection<int>();
	}
	void TearDown() {
		delete coll;
	}
};

TEST_F(FreeIdCollectionTest, testClear) {
	int v1 = 3, v2 = 5;

	int v1_id = coll->createVertex(v1);
	int v2_id = coll->createVertex(v2);

	coll->clear();
	ASSERT_EQ(coll->getVertexCount(), 0);
	ASSERT_EQ(coll->contains(v1_id), false);
	ASSERT_EQ(coll->contains(v2_id), false);
}

TEST_F(FreeIdCollectionTest, testAdding) {
	int v1 = 3, v2 = 5;

	int v1_id = coll->createVertex(v1);
	ASSERT_EQ(coll->getVertexCount(), 1);
	ASSERT_EQ(coll->contains(v1_id), true);
	ASSERT_EQ(coll->getData(v1_id), 3);

	int v2_id = coll->createVertex(v2);
	ASSERT_EQ(coll->getVertexCount(), 2);
	ASSERT_EQ(coll->contains(v2_id), true);
	ASSERT_EQ(coll->getData(v2_id), 5);

	ASSERT_EQ(coll->contains(3), false);
}

TEST_F(FreeIdCollectionTest, testDelete) {
	int v1 = INT_MAX;
	int v1_id = coll->createVertex(v1);
	ASSERT_EQ(coll->getVertexCount(), 1);
	ASSERT_EQ(coll->contains(v1_id), true);
	ASSERT_EQ(coll->deleteVertex(v1_id), true);

	ASSERT_EQ(coll->deleteVertex(v1_id), false);
	int v2 = INT_MIN;
	coll->createVertex(v2);
	ASSERT_EQ(coll->deleteVertex(v1_id), true);

}

TEST_F(FreeIdCollectionTest, testDeleteMinKey) {
	int v1 = INT_MAX, v2 = INT_MIN, v3 = 0;

	int v1_id = coll->createVertex(v1);
	ASSERT_EQ(coll->getVertexCount(), 1);
	(void)coll->createVertex(v2);
	ASSERT_EQ(coll->getVertexCount(), 2);
	ASSERT_EQ(coll->deleteVertex(v1_id), true);
	ASSERT_EQ(coll->getVertexCount(), 1);
	int v3_id = coll->createVertex(v3);
	ASSERT_EQ(v3_id, v1_id);
}
