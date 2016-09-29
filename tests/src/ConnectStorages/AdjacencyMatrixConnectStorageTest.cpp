#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/ConnectorStorages/AdjacencyMatrixConnectStorage.h>

using namespace libgraph;

class AdjacencyMatrixConnectStorageTest : public ::testing::Test {
protected:
	AdjacencyMatrixConnectStorage *coll;
	void SetUp() {
		coll = new AdjacencyMatrixConnectStorage(10);
	}
	void TearDown() {
		delete coll;
	}
};

TEST_F(AdjacencyMatrixConnectStorageTest, testConnect) {
	ASSERT_TRUE(coll->connect(1, 3));
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	ASSERT_TRUE(coll->connect(4, 5));
	ASSERT_TRUE(coll->areConnected(4, 5));
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(6, 7));
}

TEST_F(AdjacencyMatrixConnectStorageTest, testDisconnect) {
	coll->connect(1, 3);
	coll->connect(3, 1);
	coll->connect(4, 5);
	coll->connect(6, 7);

	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));
	ASSERT_TRUE(coll->areConnected(6, 7));

	coll->disconnect(1, 3);
	ASSERT_FALSE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));
	ASSERT_TRUE(coll->areConnected(6, 7));

	coll->disconnect(4, 5);
	ASSERT_FALSE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));
	ASSERT_TRUE(coll->areConnected(6, 7));
}

TEST_F(AdjacencyMatrixConnectStorageTest, testConnectDisconnect) {
	coll->connect(1, 3);
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	coll->connect(3, 1);
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	coll->disconnect(1, 3);
	ASSERT_FALSE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	coll->connect(4, 5);
	ASSERT_FALSE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));

	coll->connect(1, 3);
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));

	coll->disconnect(3, 1);
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));
}