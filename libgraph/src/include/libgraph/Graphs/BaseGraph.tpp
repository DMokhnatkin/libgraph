#include  <libgraph/Globals.h>
#include <libgraph/Graphs/BaseGraph.h>
#include <sstream>
#include <libgraph/private/contracts.h>

using namespace libgraph;

template <typename _VertexVal, typename _EdgeVal>
edge_id_t BaseGraph<_VertexVal, _EdgeVal>::connect(vertex_id_t v1, vertex_id_t v2, _EdgeVal edgeVal) {
	LG_REQ_COND(
		!vertices->contains(v1), 
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	LG_REQ_COND(
		!vertices->contains(v2), 
		std::invalid_argument("Vertex " + std::to_string(v2) + " is not in graph"));

	return connector->connect(v1, v2, edgeVal);
}

template <typename _VertexVal, typename _EdgeVal>
void BaseGraph<_VertexVal, _EdgeVal>::disconnect(vertex_id_t v1, vertex_id_t v2) {
	LG_REQ_COND(
		!vertices->contains(v1),
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	LG_REQ_COND(
		!vertices->contains(v2),
		std::invalid_argument("Vertex " + std::to_string(v2) + " is not in graph"));

	connector->disconnect(v1, v2);
}

template <typename _VertexVal, typename _EdgeVal>
void BaseGraph<_VertexVal, _EdgeVal>::disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	LG_REQ_COND(
		!vertices->contains(v1),
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	LG_REQ_COND(
		!vertices->contains(v2),
		std::invalid_argument("Vertex " + std::to_string(v2) + " is not in graph"));
	
	connector->disconnect(v1, v2, edgeId);
}

template <typename _VertexVal, typename _EdgeVal>
bool BaseGraph<_VertexVal, _EdgeVal>::areConnected(vertex_id_t v1, vertex_id_t v2) {
	LG_REQ_COND(
		!vertices->contains(v1),
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	LG_REQ_COND(
		!vertices->contains(v2),
		std::invalid_argument("Vertex " + std::to_string(v2) + " is not in graph"));

	return connector->areConnected(v1, v2);
}

template <typename _VertexVal, typename _EdgeVal>
bool BaseGraph<_VertexVal, _EdgeVal>::areConnected(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	LG_REQ_COND(
		!vertices->contains(v1),
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	LG_REQ_COND(
		!vertices->contains(v2),
		std::invalid_argument("Vertex " + std::to_string(v2) + " is not in graph"));

	return connector->areConnected(v1, v2, edgeId);
}

template <typename _VertexVal, typename _EdgeVal>
_EdgeVal BaseGraph<_VertexVal, _EdgeVal>::getEdgeVal(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) {
	LG_REQ_COND(
		!vertices->contains(v1),
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	LG_REQ_COND(
		!vertices->contains(v2),
		std::invalid_argument("Vertex " + std::to_string(v2) + " is not in graph"));

	return connector->getEdgeVal(v1, v2, edgeId);
}

template <typename _VertexVal, typename _EdgeVal>
IIterator<EdgeTuple>* BaseGraph<_VertexVal, _EdgeVal>::createEdgesIter(vertex_id_t v1) {
	LG_REQ_COND(
		!vertices->contains(v1),
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	
	return connector->createEdgesIter(v1);
}

template <typename _VertexVal, typename _EdgeVal>
IIterator<EdgeTuple>* BaseGraph<_VertexVal, _EdgeVal>::createEdgesIter(vertex_id_t v1, vertex_id_t v2) {
	LG_REQ_COND(
		!vertices->contains(v1),
		std::invalid_argument("Vertex " + std::to_string(v1) + " is not in graph"));
	LG_REQ_COND(
		!vertices->contains(v2),
		std::invalid_argument("Vertex " + std::to_string(v2) + " is not in graph"));

	return connector->createEdgesIter(v1, v2);
}

template <typename _VertexVal, typename _EdgeVal>
void BaseGraph<_VertexVal, _EdgeVal>::clear() {
	connector->clear();
	vertices->clear();
}

template <typename _VertexVal, typename _EdgeVal>
vertex_id_t BaseGraph<_VertexVal, _EdgeVal>::getVertexCount() {
	return vertices->getCount();
}

template <typename _VertexVal, typename _EdgeVal>
vertex_id_t BaseGraph<_VertexVal, _EdgeVal>::createVertex(_VertexVal val) {
	return vertices->addData(val);
}

template <typename _VertexVal, typename _EdgeVal>
bool BaseGraph<_VertexVal, _EdgeVal>::containsVertex(vertex_id_t id) {
	LG_REQ_COND(
		!vertices->contains(id),
		std::invalid_argument("Vertex " + std::to_string(id) + " is not in graph"));

	return vertices->contains(id);
}

template <typename _VertexVal, typename _EdgeVal>
void BaseGraph<_VertexVal, _EdgeVal>::removeVertex(vertex_id_t id) {
	LG_REQ_COND(
		!vertices->contains(id),
		std::invalid_argument("Vertex " + std::to_string(id) + " is not in graph"));

	vertices->removeData(id);
}