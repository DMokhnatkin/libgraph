#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

#include <libgraph/IGraph.h>
#include <libgraph/Searches/DFS/BaseDFS.h>
#include <libgraph/Searches/DFS/IDFS.h>

namespace libgraph {
	template <typename _State, typename _VertexVal, typename _EdgeVal>
	class DFS{
	public:
		/**
		* \brief Get specific DFS for given graph
		* \param graph Graph
		*/
		static IDFS<_State, _VertexVal, _EdgeVal> *get(
								IGraph<_VertexVal, _EdgeVal> *graph);
	};
}

#include <libgraph/Searches/DFS/DFS.tpp>
