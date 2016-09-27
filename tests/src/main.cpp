#include <cstddef>
#include <iostream>

#include <gtest/gtest.h>

#include <libgraph/IVertex.h>
#include <libgraph/IEdge.h>
#include <libgraph/IConnector.h>
#include <libgraph/IGraph.h>
#include <libgraph/SampleGraph.h>
using namespace libgraph;

class TestGraph : public ::testing::Test{
protected:
	SampleGraph *graph;
	void SetUp() {
		graph = new SampleGraph();
	}
	void TearDown(){
		delete graph;
	}
};

TEST_F(TestGraph, test1){
	ASSERT_EQ(graph->getVertexCount(), 0);
}

TEST_F(TestGraph, test2){
	ASSERT_TRUE(graph->createVertex(NULL) == NULL);
}

int main(int argc, char *argv[]){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
