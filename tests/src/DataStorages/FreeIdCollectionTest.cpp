#include <iostream>

#include <gtest/gtest.h>

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

TEST_F(FreeIdCollectionTest, test1) {
	ASSERT_EQ(coll->getVertexCount(), 0);
}

TEST_F(FreeIdCollectionTest, test2) {
	ASSERT_TRUE(coll->createVertex(NULL) == 0);
}
