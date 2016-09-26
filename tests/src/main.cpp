#include <libgraph/igraph.h>
#include <libgraph/samplegraph.h>
#include <gtest/gtest.h>
#include <iostream>

class TestGraph : public ::testing::Test{
protected:
	libgraph::SampleGraph *graph;
	void SetUp() {
		graph = new libgraph::SampleGraph();
	}
	void TearDown(){
		delete graph;
	}
};

TEST_F(TestGraph, test1){
	ASSERT_EQ(graph->getNumber(), 5);
}

TEST_F(TestGraph, test2){
	ASSERT_EQ(graph->getNumber(), 5);
}

int main(int argc, char *argv[]){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
