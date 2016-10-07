#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/Connectors/BaseConnector.h>
#include <libgraph/Globals.h>
#include <winsock.h>

using namespace libgraph;

class BaseConnectorTest : public ::testing::Test {
protected:
	BaseConnector<EmptyValue> *coll;
	void SetUp() {
		coll = new BaseConnector<EmptyValue>();
	}
	void TearDown() {
		delete coll;
	}
};

TEST_F(BaseConnectorTest, testConnect) {
	coll->connect(1, 3, EmptyValue());
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	coll->connect(4, 5, EmptyValue());
	ASSERT_TRUE(coll->areConnected(4, 5));
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(6, 7));
}

TEST_F(BaseConnectorTest, testDisconnect) {
	coll->connect(1, 3, EmptyValue());
	coll->connect(3, 1, EmptyValue());
	coll->connect(4, 5, EmptyValue());
	coll->connect(6, 7, EmptyValue());

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

TEST_F(BaseConnectorTest, testEdgeIdCreation) {
	ASSERT_EQ(coll->connect(1, 3, EmptyValue()), 0);
	ASSERT_EQ(coll->connect(3, 1, EmptyValue()), 1);
	coll->disconnect(1, 3);
	ASSERT_EQ(coll->connect(4, 5, EmptyValue()), 0);
	coll->disconnect(4, 5);
	ASSERT_EQ(coll->connect(6, 7, EmptyValue()), 0);
}

TEST_F(BaseConnectorTest, testDisconnectById) {
	coll->connect(1, 3, EmptyValue()); // EdgeId = 0
	coll->connect(3, 1, EmptyValue()); // EdgeId = 1
	coll->connect(4, 5, EmptyValue()); // EdgeId = 2

	ASSERT_FALSE(coll->disconnect(1, 3, 1));
	ASSERT_TRUE(coll->disconnect(1, 3, 0));

	ASSERT_FALSE(coll->disconnect(2, 6, 1));
	ASSERT_FALSE(coll->disconnect(4, 5, 1));
	ASSERT_TRUE(coll->disconnect(4, 5, 2));
}

TEST_F(BaseConnectorTest, testConnectDisconnect) {
	coll->connect(1, 3, EmptyValue());
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	coll->connect(3, 1, EmptyValue());
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	coll->disconnect(1, 3);
	ASSERT_FALSE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_FALSE(coll->areConnected(4, 5));

	coll->connect(4, 5, EmptyValue());
	ASSERT_FALSE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));

	coll->connect(1, 3, EmptyValue());
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_TRUE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));

	coll->disconnect(3, 1);
	ASSERT_TRUE(coll->areConnected(1, 3));
	ASSERT_FALSE(coll->areConnected(3, 1));
	ASSERT_TRUE(coll->areConnected(4, 5));
}

TEST_F(BaseConnectorTest, testIterateEdges) {
	coll->connect(2, 7, EmptyValue());
	int edge1_id = coll->connect(2, 3, EmptyValue()); // 1-st edge which will be iterated
	coll->connect(2, 5, EmptyValue());
	int edge2_id = coll->connect(2, 3, EmptyValue()); // 2-d edge which will be iterated
	int edge3_id = coll->connect(2, 3, EmptyValue()); // 3-th edge which will be iterated
	coll->connect(1, 7, EmptyValue());
	int ct = 0;
	for (auto i = coll->beginIterateEdges(2, 3); i != coll->endIterateEdges(2, 3); i++) {
		ASSERT_TRUE(*i == edge1_id || *i == edge2_id || *i == edge3_id);
		ct++;
	}
	ASSERT_EQ(ct, 3);
}