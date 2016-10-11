#include <libgraph/Searches/DFS/BaseDFS.h>
using namespace libgraph;

template <typename _State, typename _VertexVal, typename _EdgeVal>
void BaseDFS<_State, _VertexVal, _EdgeVal>::doSearch(
		IGraph<_VertexVal, _EdgeVal> &graph,
		vertex_id_t start,
		_State &st, search_fn_t<_State> fn){

	std::unordered_set<vertex_id_t> v_list;

	doSearchInner(graph, start, st, fn, v_list);
}

template <typename _State, typename _VertexVal, typename _EdgeVal>
void BaseDFS<_State, _VertexVal,  _EdgeVal>::doSearchInner(
		IGraph<_VertexVal, _EdgeVal> &graph,
		vertex_id_t start,
		_State &st, search_fn_t<_State> fn,
		std::unordered_set<vertex_id_t> &v_list){
	v_list.insert(start);
	auto it = graph.createEdgesIter(start);
	for(; !it->isDone(); it->next()){
		auto cur = it->currentItem();
		fn(cur.getV1(), cur.getV2(), cur.getEdgeId(), st);
		if( v_list.count(cur.getV2()) == 0 ){
			doSearchInner(graph, cur.getV2(), st, fn, v_list);
		}
	}
	delete it;
}
