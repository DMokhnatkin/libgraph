#include <libgraph/Connectors/BaseConnector.h>
#include <algorithm>
#include <libgraph/private/contracts.h>
#include <string>

using namespace libgraph;

template <typename _EdgeVal>
BaseConnector<_EdgeVal>::BaseConnector() {
	edges = new FreeIdCollection<_EdgeVal>();
	connections = new std::unordered_map<vertex_id_t, std::unordered_map<vertex_id_t, std::unordered_set<edge_id_t>>>();
}

template<typename _EdgeVal>
edge_id_t BaseConnector<_EdgeVal>::connect(vertex_id_t v1, vertex_id_t v2, _EdgeVal edgeVal) {
	vertex_id_t newEdgeId = edges->addData(edgeVal);
	(*connections)[v1][v2].insert(newEdgeId);
	return newEdgeId;
}

template<typename _EdgeVal>
void BaseConnector<_EdgeVal>::disconnect(vertex_id_t v1, vertex_id_t v2) {
	LG_REQ_COND(
		areConnected(v1, v2),
		std::invalid_argument("Vertecies " + std::to_string(v1) + " " + std::to_string(v2) + " not connected"));

	// Remove edges ids and edges data from FreeIdCollection
	std::for_each((*connections)[v1][v2].begin(), (*connections)[v1][v2].end(), [&edges = this->edges](edge_id_t x) { edges->removeData(x); });
	(*connections)[v1][v2].clear();
}

template <typename _EdgeVal>
void BaseConnector<_EdgeVal>::disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	LG_REQ_COND(
		areConnected(v1, v2, edgeId),
		std::invalid_argument("Vertecies " + std::to_string(v1) + " " + std::to_string(v2) + " not connected"));

	edges->removeData(edgeId);
	(*connections)[v1][v2].erase(edgeId);
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
IIterator<EdgeTuple>* BaseConnector<_EdgeVal>::createEdgesIter(vertex_id_t v1, vertex_id_t v2) {
	auto iter = new BaseConnectorEdgesIter<_EdgeVal>(*this, v1, v2);
	iter->first();
	return iter;
}

template <typename _EdgeVal>
IIterator<EdgeTuple> * BaseConnector<_EdgeVal>::createEdgesIter(vertex_id_t v1) {
	auto iter = new BaseConnectorOutEdgesIter<_EdgeVal>(*this, v1);
	iter->first();
	return iter;
}

template<typename _EdgeVal>
void BaseConnector<_EdgeVal>::clear() {
	edges->clear();
	connections->clear();
}

template<typename _EdgeVal>
void BaseConnectorOutEdgesIter<_EdgeVal>::first() {
	v2_iter = (*connector.connections)[v1].begin();
	if (!isDone())
		edge_iter = (std::get<1>(*v2_iter)).begin();
}

template<typename _EdgeVal>
void BaseConnectorOutEdgesIter<_EdgeVal>::next() {
	if (++edge_iter == (std::get<1>(*v2_iter)).end()) {
		++v2_iter;
		if (!isDone()) {
			edge_iter = (std::get<1>(*v2_iter)).begin();
		}
	}
}

template<typename _EdgeVal>
bool BaseConnectorOutEdgesIter<_EdgeVal>::isDone() {
	return v2_iter == (*connector.connections)[v1].end();
}

template<typename _EdgeVal>
EdgeTuple BaseConnectorOutEdgesIter<_EdgeVal>::currentItem() {
	return EdgeTuple(v1, (std::get<0>(*v2_iter)), *edge_iter);
}

template <typename _EdgeVal>
void BaseConnectorEdgesIter<_EdgeVal>::first() {
	if (connector.areConnected(v1, v2))
		edge_iter = (*connector.connections)[v1][v2].begin();
}

template <typename _EdgeVal>
void BaseConnectorEdgesIter<_EdgeVal>::next() {
	edge_iter++;
}

template <typename _EdgeVal>
bool BaseConnectorEdgesIter<_EdgeVal>::isDone() {
	if (!connector.areConnected(v1, v2))
		return true;
	return edge_iter == (*connector.connections)[v1][v2].end();
}

template <typename _EdgeVal>
EdgeTuple BaseConnectorEdgesIter<_EdgeVal>::currentItem() {
	return EdgeTuple(v1, v2, *edge_iter);
}
