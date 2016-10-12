#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/Graphs/BaseGraph.h>

using namespace libgraph;
class BaseGraphTest : public ::testing::Test {
protected:
	BaseGraph<std::string, int> *graph;
};

TEST_F(BaseGraphTest, initialization) {
	std::array<std::string, 4> init { 
		"v0", "v1", "v2", "v3"
	};
	graph = new BaseGraph<std::string, int>(init);
	EXPECT_TRUE(graph->containsVertex(0));
	EXPECT_TRUE(graph->containsVertex(1));
	EXPECT_TRUE(graph->containsVertex(2));
	EXPECT_TRUE(graph->containsVertex(3));
	EXPECT_FALSE(graph->containsVertex(4));

	EXPECT_EQ(graph->getVertexValue(0), "v0");
	EXPECT_EQ(graph->getVertexValue(1), "v1");
	EXPECT_EQ(graph->getVertexValue(2), "v2");
	EXPECT_EQ(graph->getVertexValue(3), "v3");
}
