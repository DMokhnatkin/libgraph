#include <iostream>
#include <array>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/Connectors/IConnector.h>
#include <libgraph/Connectors/BaseConnector.h>
#include <libgraph/Graphs/BaseGraph.h>
#include <libgraph/Globals.h>

using namespace libgraph;

using testing::Types;
// Implementations of IConnecter to test 
typedef Types<BaseConnector<EmptyValue>, BaseGraph<EmptyValue, EmptyValue>> Implementations;

template <typename T>
class IConnectorTest : public ::testing::Test {
protected:
	virtual void SetUp() override {
		coll = new T();
		if (std::is_same<T, BaseGraph<EmptyValue, EmptyValue>>::value) {
			std::array<EmptyValue, 8> vert;
			vert.fill(EmptyValue());
			std::array<BaseGraph<EmptyValue, EmptyValue>::EdgeInitTuple, 0> edges;
			static_cast<BaseGraph<EmptyValue, EmptyValue>*>(coll)->initialize(vert, edges);
		}
	};
	virtual void TearDown() override{
		delete coll;
	};
public:
	IConnector<EmptyValue> * coll;
};

TYPED_TEST_CASE(IConnectorTest, Implementations);

TYPED_TEST(IConnectorTest, testConnect) {
	this->coll->connect(1, 3, EmptyValue());
	EXPECT_TRUE(this->coll->areConnected(1, 3));
	EXPECT_FALSE(this->coll->areConnected(3, 1));
	EXPECT_FALSE(this->coll->areConnected(4, 5));

	this->coll->connect(4, 5, EmptyValue());
	EXPECT_TRUE(this->coll->areConnected(4, 5));
	EXPECT_TRUE(this->coll->areConnected(1, 3));
	EXPECT_FALSE(this->coll->areConnected(6, 7));
}

TYPED_TEST(IConnectorTest, testDisconnect) {
	this->coll->connect(1, 3, EmptyValue());
	this->coll->connect(3, 1, EmptyValue());
	this->coll->connect(4, 5, EmptyValue());
	this->coll->connect(6, 7, EmptyValue());

	EXPECT_TRUE(this->coll->areConnected(1, 3));
	EXPECT_TRUE(this->coll->areConnected(3, 1));
	EXPECT_TRUE(this->coll->areConnected(4, 5));
	EXPECT_TRUE(this->coll->areConnected(6, 7));

	this->coll->disconnect(1, 3);
	EXPECT_FALSE(this->coll->areConnected(1, 3));
	EXPECT_TRUE(this->coll->areConnected(3, 1));
	EXPECT_TRUE(this->coll->areConnected(4, 5));
	EXPECT_TRUE(this->coll->areConnected(6, 7));

	this->coll->disconnect(4, 5);
	EXPECT_FALSE(this->coll->areConnected(1, 3));
	EXPECT_TRUE(this->coll->areConnected(3, 1));
	EXPECT_FALSE(this->coll->areConnected(4, 5));
	EXPECT_TRUE(this->coll->areConnected(6, 7));
}

TYPED_TEST(IConnectorTest, testEdgeIdCreation) {
	EXPECT_EQ(this->coll->connect(1, 3, EmptyValue()), 0);
	EXPECT_EQ(this->coll->connect(3, 1, EmptyValue()), 1);
	this->coll->disconnect(1, 3);
	EXPECT_EQ(this->coll->connect(4, 5, EmptyValue()), 0);
	this->coll->disconnect(4, 5);
	EXPECT_EQ(this->coll->connect(6, 7, EmptyValue()), 0);
}

TYPED_TEST(IConnectorTest, testDisconnectById) {
	this->coll->connect(1, 3, EmptyValue()); // EdgeId = 0
	this->coll->connect(3, 1, EmptyValue()); // EdgeId = 1
	this->coll->connect(4, 5, EmptyValue()); // EdgeId = 2

	EXPECT_TRUE(this->coll->areConnected(1, 3, 0));
	this->coll->disconnect(1, 3, 0);
	EXPECT_FALSE(this->coll->areConnected(1, 3, 0));

	EXPECT_TRUE(this->coll->areConnected(4, 5, 2));
	this->coll->disconnect(4, 5, 2);
	EXPECT_FALSE(this->coll->areConnected(4, 5, 2));
}

TYPED_TEST(IConnectorTest, testConnectDisconnect) {
	this->coll->connect(1, 3, EmptyValue());
	EXPECT_TRUE(this->coll->areConnected(1, 3));
	EXPECT_FALSE(this->coll->areConnected(3, 1));
	EXPECT_FALSE(this->coll->areConnected(4, 5));

	this->coll->connect(3, 1, EmptyValue());
	EXPECT_TRUE(this->coll->areConnected(1, 3));
	EXPECT_TRUE(this->coll->areConnected(3, 1));
	EXPECT_FALSE(this->coll->areConnected(4, 5));

	this->coll->disconnect(1, 3);
	EXPECT_FALSE(this->coll->areConnected(1, 3));
	EXPECT_TRUE(this->coll->areConnected(3, 1));
	EXPECT_FALSE(this->coll->areConnected(4, 5));

	this->coll->connect(4, 5, EmptyValue());
	EXPECT_FALSE(this->coll->areConnected(1, 3));
	EXPECT_TRUE(this->coll->areConnected(3, 1));
	EXPECT_TRUE(this->coll->areConnected(4, 5));

	this->coll->connect(1, 3, EmptyValue());
	EXPECT_TRUE(this->coll->areConnected(1, 3));
	EXPECT_TRUE(this->coll->areConnected(3, 1));
	EXPECT_TRUE(this->coll->areConnected(4, 5));

	this->coll->disconnect(3, 1);
	EXPECT_TRUE(this->coll->areConnected(1, 3));
	EXPECT_FALSE(this->coll->areConnected(3, 1));
	EXPECT_TRUE(this->coll->areConnected(4, 5));
}

TYPED_TEST(IConnectorTest, testIterateEdges) {
	this->coll->connect(2, 7, EmptyValue());
	edge_id_t edge1_id = this->coll->connect(2, 3, EmptyValue()); // 1-st edge which will be iterated
	this->coll->connect(2, 5, EmptyValue());
	edge_id_t edge2_id = this->coll->connect(2, 3, EmptyValue()); // 2-d edge which will be iterated
	edge_id_t edge3_id = this->coll->connect(2, 3, EmptyValue()); // 3-th edge which will be iterated
	this->coll->connect(1, 7, EmptyValue());
	int ct = 0;
	for (auto i = this->coll->createEdgesIter(2, 3); !i->isDone(); i->next()) {
		auto cur = i->currentItem();
		EXPECT_TRUE(
			(cur.getV1() == 2 && cur.getV2() == 3 && cur.getEdgeId() == edge1_id) ||
			(cur.getV1() == 2 && cur.getV2() == 3 && cur.getEdgeId() == edge2_id) ||
			(cur.getV1() == 2 && cur.getV2() == 3 && cur.getEdgeId() == edge3_id)
		);
		ct++;
	}
	EXPECT_EQ(ct, 3);
}

TYPED_TEST(IConnectorTest, testOutEdgesIterate) {
	this->coll->connect(3, 7, EmptyValue());
	edge_id_t edge1_id = this->coll->connect(2, 3, EmptyValue()); // 1-st edge which will be iterated
	this->coll->connect(3, 2, EmptyValue());
	edge_id_t edge2_id = this->coll->connect(2, 3, EmptyValue()); // 2-d edge which will be iterated
	edge_id_t edge3_id = this->coll->connect(2, 5, EmptyValue()); // 3-th edge which will be iterated
	this->coll->connect(1, 7, EmptyValue());
	edge_id_t edge4_id = this->coll->connect(2, 1, EmptyValue()); // 4-th edge which will be iterated
	int ct = 0;
	for (auto i = this->coll->createEdgesIter(2); !i->isDone(); i->next()) {
		auto cur = i->currentItem();
		EXPECT_TRUE(
			(cur.getV1() == 2 && cur.getV2() == 3 && cur.getEdgeId() == edge1_id) ||
			(cur.getV1() == 2 && cur.getV2() == 3 && cur.getEdgeId() == edge2_id) ||
			(cur.getV1() == 2 && cur.getV2() == 5 && cur.getEdgeId() == edge3_id) ||
			(cur.getV1() == 2 && cur.getV2() == 1 && cur.getEdgeId() == edge4_id)
		);
		ct++;
	}
	EXPECT_EQ(ct, 4);
}