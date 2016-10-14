#pragma once

#include <libgraph/Paths/Shortest/FromOneVertex/LevitsAlgorithm.h>

#include <array>
#include <limits>
#include <vector>

#include <libgraph/DataStorages/RingBuffer.h>

using namespace libgraph;

template <typename _VertexVal, typename _EdgeVal>
void LevitsAlgorithm<_VertexVal, _EdgeVal>::calcWays(
		IGraph<_VertexVal, _EdgeVal> & graph,
		vertex_id_t v0,
		std::vector<_EdgeVal> & length,
		std::vector<vertex_id_t> & previous) {
	// previous[i] - current previous vertex in shortest way from v0 to i.
	// length[i] - length of shortest way from v0 to i.

	std::fill(length.begin(), length.end(), std::numeric_limits<_EdgeVal>::max());
	length[v0] = 0;

	// Store group for each vertex. m0  - 2; m1 - 1; m2 - 0;
	// At the begining all vertices (except v0) are in m2 group.
	
	std::vector<unsigned char> group(graph.getMaxId() + 1, 0);
	group[v0] = 1;

	RingBuffer<vertex_id_t> queue(graph.getVertexCount());
	queue.push_back(v0);

	while (!queue.isEmpty()) {
		vertex_id_t v = queue.pop_top();
		group[v] = 1;
		auto iter = graph.createEdgesIter(v);
		for (; !iter->isDone(); iter->next()) {
			EdgeTuple cur = iter->currentItem();
			_EdgeVal edgeLength = graph.getEdgeVal(cur.getV1(), cur.getV2(), cur.getEdgeId());
			if (length[cur.getV2()] > length[cur.getV1()] + edgeLength) {
				length[cur.getV2()] = length[cur.getV1()] + edgeLength;

				if (group[cur.getV2()] == 0)
					queue.push_back(cur.getV2());
				else if (group[cur.getV2()] == 1)
					queue.push_top(cur.getV2());

				previous[cur.getV2()] = v;
				group[cur.getV2()] = 1;
			}
		}
		delete iter;
	}
}