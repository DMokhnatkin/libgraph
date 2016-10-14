#pragma once

#include <libgraph/private/constants.h>
#include <libgraph/IGraph.h>

namespace libgraph {
	template <typename _VertexVal, typename _EdgeVal>
	class LevitsAlgorithm {
	private:
	public:

		/**
		 * \brief find shortest ways from one vertex to others
		 * \param graph a graph to find ways
		 * \param v0 a vertex. Shortest way to each other vertex will be found.
		 * \param[out] length 
		 * length[i] - length of shortest way from v0 to i. You should pass to method already created vector with
		 * size = maximum vertex id (in graph) + 1, and method will fill it by right values.
		 * If some vertex v is unreachable, length[v] = max value of _EdgeVal type.
		 * \param[out]
		 * previous[i] - previous to i vertex in shortest way from v0 to i. You should pass to method already created vector with
		 * size = maximum vertex id (in graph) + 1, and method will fill it by right values.
		 * If some vertex v is unreachable, previous[v] is undefined.
		 */
		static void calcWays(
			IGraph<_VertexVal, _EdgeVal> & graph, 
			vertex_id_t v0, 
			std::vector<_EdgeVal> & length,
			std::vector<vertex_id_t> & previous);
	};
}

#include <libgraph/Paths/Shortest/FromOneVertex/LevitsAlgorithm.tpp>