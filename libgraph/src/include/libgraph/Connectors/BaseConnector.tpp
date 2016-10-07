#include <libgraph/Connectors/BaseConnector.h>
#include <algorithm>

using namespace libgraph;

template <typename edgeVal_t>
BaseConnector<edgeVal_t>::BaseConnector() {
	edges = new FreeIdCollection<edgeVal_t>();
	connections = new std::unordered_map<std::pair<vertex_id_t, vertex_id_t>, std::unordered_set<edge_id_t>, pair_hash>();
}

template<typename edgeVal_t>
edge_id_t BaseConnector<edgeVal_t>::connect(vertex_id_t v1, vertex_id_t v2, edgeVal_t edgeVal) {
	vertex_id_t newEdgeId = edges->createVertex(edgeVal);
	std::pair<vertex_id_t, vertex_id_t> p(v1, v2);
	(*connections)[p].insert(newEdgeId);
	return newEdgeId;
}

template<typename edgeVal_t>
void BaseConnector<edgeVal_t>::disconnect(vertex_id_t v1, vertex_id_t v2) {
	std::pair<vertex_id_t, vertex_id_t> p(v1, v2);
	// Remove edges ids and edges data from FreeIdCollection
	std::for_each((*connections)[p].begin(), (*connections)[p].end(), [&edges = this->edges](edge_id_t x) { edges->deleteVertex(x); });
	(*connections)[p].clear();
}

template <typename edgeVal_t>
bool BaseConnector<edgeVal_t>::disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	std::pair<vertex_id_t, vertex_id_t> p(v1, v2);
	if (!areConnected(v1, v2, edgeId))
		return false;
	edges->deleteVertex(edgeId);
	(*connections)[p].erase(edgeId);
	return true;
}

template<typename edgeVal_t>
bool BaseConnector<edgeVal_t>::areConnected(vertex_id_t v1, vertex_id_t v2) {
	std::pair<vertex_id_t, vertex_id_t> p(v1, v2);
	return  !(*connections)[p].empty();
}

template <typename edgeVal_t>
bool BaseConnector<edgeVal_t>::areConnected(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	std::pair<vertex_id_t, vertex_id_t> p(v1, v2);
	return  (*connections)[p].count(edgeId) != 0;
}

template <typename edgeVal_t>
edgeVal_t BaseConnector<edgeVal_t>::getEdgeVal(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId)
{
	return edges->getData(edgeId);
}

template<typename edgeVal_t>
void BaseConnector<edgeVal_t>::clear() {
	edges->clear();
	connections->clear();
}
