#include <libgraph/Connectors/BaseConnector.h>
#include <algorithm>

using namespace libgraph;

template <typename _EdgeVal>
BaseConnector<_EdgeVal>::BaseConnector() {
	edges = new FreeIdCollection<_EdgeVal>();
	connections = new std::unordered_map<vertex_id_t, std::unordered_map<vertex_id_t, std::unordered_set<edge_id_t>>>();
}

template<typename _EdgeVal>
edge_id_t BaseConnector<_EdgeVal>::connect(vertex_id_t v1, vertex_id_t v2, _EdgeVal edgeVal) {
	vertex_id_t newEdgeId = edges->createVertex(edgeVal);
	(*connections)[v1][v2].insert(newEdgeId);
	return newEdgeId;
}

template<typename _EdgeVal>
void BaseConnector<_EdgeVal>::disconnect(vertex_id_t v1, vertex_id_t v2) {
	// Remove edges ids and edges data from FreeIdCollection
	std::for_each((*connections)[v1][v2].begin(), (*connections)[v1][v2].end(), [&edges = this->edges](edge_id_t x) { edges->deleteVertex(x); });
	(*connections)[v1][v2].clear();
}

template <typename _EdgeVal>
bool BaseConnector<_EdgeVal>::disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	if (!areConnected(v1, v2, edgeId))
		return false;
	edges->deleteVertex(edgeId);
	(*connections)[v1][v2].erase(edgeId);
	return true;
}

template<typename _EdgeVal>
bool BaseConnector<_EdgeVal>::areConnected(vertex_id_t v1, vertex_id_t v2) {
	return  !(*connections)[v1][v2].empty();
}

template <typename _EdgeVal>
bool BaseConnector<_EdgeVal>::areConnected(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	return  (*connections)[v1][v2].count(edgeId) != 0;
}

template <typename _EdgeVal>
_EdgeVal BaseConnector<_EdgeVal>::getEdgeVal(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	return edges->getData(edgeId);
}

template <typename _EdgeVal>
typename IConnector<_EdgeVal>::edge_iterator BaseConnector<_EdgeVal>::beginIterateEdges(vertex_id_t v1, vertex_id_t v2) {
	return (*connections)[v1][v2].begin();
}

template <typename _EdgeVal>
typename IConnector<_EdgeVal>::edge_iterator BaseConnector<_EdgeVal>::endIterateEdges(vertex_id_t v1, vertex_id_t v2) {
	return (*connections)[v1][v2].end();
}

template <typename _EdgeVal>
typename IConnector<_EdgeVal>::out_edges_iterator BaseConnector<_EdgeVal>::beginIterateEdges(vertex_id_t v1) {
	return EmptyValue(); // TODO: Not implemented
}

template <typename _EdgeVal>
typename IConnector<_EdgeVal>::out_edges_iterator BaseConnector<_EdgeVal>::endIterateEdges(vertex_id_t v1) {
	return EmptyValue(); // TODO: Not implemented
}

template<typename _EdgeVal>
void BaseConnector<_EdgeVal>::clear() {
	edges->clear();
	connections->clear();
}
