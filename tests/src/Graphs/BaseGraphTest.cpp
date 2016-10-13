#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/Graphs/BaseGraph.h>

using namespace libgraph;
class BaseGraphTest : public ::testing::Test {
protected:
	BaseGraph<std::string, std::string> *graph;
	virtual void SetUp() override {
		graph = new BaseGraph<std::string, std::string>();
	}
	virtual void TearDown() override {
		delete graph;
	}
};

TEST_F(BaseGraphTest, initialization) {
	std::array<std::string, 4> initVertices { 
		"v0", "v1", "v2", "v3"
	};
	std::array<std::tuple<vertex_id_t, vertex_id_t, std::string>, 3> initEdges { 
		std::make_tuple(0 , 1, std::string("e0")), 
		std::make_tuple(2 , 3, std::string("e1")),
		std::make_tuple(3 , 0, std::string("e2"))
	};

	graph->initialize(initVertices, initEdges);
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
