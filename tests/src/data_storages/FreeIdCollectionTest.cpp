#include <iostream>


#include <gtest/gtest.h>

#include <libgraph/data_storages/FreeIdCollection.h>
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

TEST_F(FreeIdCollectionTest, test1) {
	ASSERT_EQ(coll->getVertexCount(), 0);
}

TEST_F(FreeIdCollectionTest, test2) {
	ASSERT_TRUE(coll->createVertex(NULL) == 0);
}