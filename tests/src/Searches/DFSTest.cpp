#include <iostream>

#include <gtest/gtest.h>

#include <libgraph/Searches/DFS/DFS.h>
#include <libgraph/Graphs/BaseGraph.h>

#include <libgraph/Globals.h>

using namespace libgraph;

class DFSTest : public ::testing::Test {
protected:
	BaseGraph<EmptyValue, EmptyValue> *coll;

	void SetUp() {
		coll = new BaseGraph<EmptyValue, EmptyValue>();
	}
	void TearDown() {
		delete coll;
	}
};

TEST_F(DFSTest, testSearch) {
	coll->connect(0, 1, EmptyValue());
	coll->connect(0, 2, EmptyValue());
	coll->connect(1, 2, EmptyValue());

	int ct = 0;
	auto specDFS = DFS<int, EmptyValue, EmptyValue>::get(coll);
	specDFS->doSearch(*coll, 0, ct,
					[](vertex_id_t v1, vertex_id_t v2, edge_id_t e, int &ct){
		ct += v2;
	});
	ASSERT_EQ(ct, 5);
	delete specDFS;
}
