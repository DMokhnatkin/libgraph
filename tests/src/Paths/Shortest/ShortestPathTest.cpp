#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/Graphs/BaseGraph.h>
#include <libgraph/Paths/Shortest/FromOneVertex/LevitsAlgorithm.h>
#include <libgraph/Globals.h>

using namespace libgraph;

using testing::Types;
 
typedef Types<LevitsAlgorithm<EmptyValue, int>> IShortestFOVImplementations;

template <typename T>
class IShortestFOVTest : public ::testing::Test {
protected:
	virtual void SetUp() override {
		graph = new BaseGraph<EmptyValue, int>();

		using edgetpl = std::tuple<vertex_id_t, vertex_id_t, int>;
		std::array<EmptyValue, 6> initVert;
		initVert = {
			EmptyValue(), EmptyValue(), EmptyValue(), 
			EmptyValue(), EmptyValue(), EmptyValue()
		};
		std::array<edgetpl, 18> initEdges {
			edgetpl(0, 1, 7), edgetpl(1, 0, 7),
			edgetpl(0, 2, 9), edgetpl(2, 0, 9),
			edgetpl(0, 5, 14), edgetpl(5, 0, 14),
			edgetpl(1, 2, 10), edgetpl(2, 1, 10),
			edgetpl(1, 3, 15), edgetpl(3, 1, 15),
			edgetpl(2, 3, 11), edgetpl(3, 2, 11),
			edgetpl(2, 5, 2), edgetpl(5, 2, 2),
			edgetpl(5, 4, 9), edgetpl(4, 5, 9),
			edgetpl(4, 3, 6), edgetpl(3, 4, 6)
		};
		graph->initialize(initVert, initEdges);
	}
	virtual void TearDown() override {
		delete graph;
	}
public:
	BaseGraph<EmptyValue, int> * graph;
};

TYPED_TEST_CASE(IShortestFOVTest, IShortestFOVImplementations);

TYPED_TEST(IShortestFOVTest, testLengths) {
	std::vector<int> length(this->graph->getMaxId() + 1);
	std::vector<vertex_id_t> previous(this->graph->getMaxId() + 1);
	TypeParam::calcWays(*this->graph, 0, length, previous);
	ASSERT_EQ(length[1], 7);
	ASSERT_EQ(length[2], 9);
	ASSERT_EQ(length[3], 20);
	ASSERT_EQ(length[4], 20);
	ASSERT_EQ(length[5], 11);
}

TYPED_TEST(IShortestFOVTest, testWays) {
	std::vector<int> length(this->graph->getMaxId() + 1);
	std::vector<vertex_id_t> previous(this->graph->getMaxId() + 1);
	TypeParam::calcWays(*this->graph, 0, length, previous);
	ASSERT_EQ(previous[1], 0);
	ASSERT_EQ(previous[2], 0);
	ASSERT_EQ(previous[3], 2);
	ASSERT_EQ(previous[4], 5);
	ASSERT_EQ(previous[5], 2);
}