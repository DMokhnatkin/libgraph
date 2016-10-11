#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

#include <libgraph/IGraph.h>

namespace libgraph {
	template <typename _State, typename _VertexVal, typename _EdgeVal>
	class IDFS {
	public:
		/**
		* \brief Perform depth-first search
		* \param graph Graph to perform search
		* \param start Start vertex
		* \param st Abstract state used in callback
		* \param fn Callback, which is called at every iteration
		*/
		virtual void doSearch(IGraph<_VertexVal, _EdgeVal> &graph,
							 vertex_id_t start,
							 _State &st, search_fn_t<_State> fn) = 0;
		virtual ~IDFS() {};
	};
}
