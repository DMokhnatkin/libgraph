#include <typeinfo>
#include <libgraph/Searches/DFS/IDFS.h>
#include <libgraph/Searches/DFS/DFS.h>
using namespace libgraph;

template <typename _State, typename _VertexVal, typename _EdgeVal>
IDFS<_State, _VertexVal, _EdgeVal> *DFS<_State, _VertexVal, _EdgeVal>::get(
										IGraph<_VertexVal, _EdgeVal> *graph){
	// TODO: Use typeid(graph).name()
	return new BaseDFS<_State, _VertexVal, _EdgeVal>();
}
