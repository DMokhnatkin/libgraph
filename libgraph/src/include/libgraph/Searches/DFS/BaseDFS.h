#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

#include <libgraph/IGraph.h>
#include <libgraph/Searches/DFS/IDFS.h>

namespace libgraph {
	template <typename _State, typename _VertexVal, typename _EdgeVal>
	class BaseDFS : public IDFS<_State, _VertexVal, _EdgeVal>{
	private:
		void doSearchInner(IGraph<_VertexVal, _EdgeVal> &graph,
							vertex_id_t start,
							_State &st, search_fn_t<_State> fn,
							std::unordered_set<vertex_id_t> &v_list);
	public:
		virtual void doSearch(IGraph<_VertexVal, _EdgeVal> &graph,
					 vertex_id_t start,
					 _State &st, search_fn_t<_State> fn) override;
	};
}

#include <libgraph/Searches/DFS/BaseDFS.tpp>
