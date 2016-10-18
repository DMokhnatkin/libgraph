#pragma once

#include <functional>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/Globals.h>
#include <iterator>
#include <libgraph/Connectors/IConnector.h>
#include <unordered_set>

namespace libgraph {
	template <typename _EdgeVal>
	class IGraphConnector : public IConnector<_EdgeVal> {
	private:
	public:
		/**
		* \brief Connect two vertices.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeVal some value to add to created edge.
		* \return an id of created edge.
		*/
		virtual edge_id_t connect(vertex_id_t v1, vertex_id_t v2, _EdgeVal edgeVal) = 0;

		/**
		* \brief Remove one edge with specifed id.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeId an edge to remove.
		* \return true if succesed.
		*/
		virtual void disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) = 0;

		/**
		* \brief Are two vertecies connected by specifed edge.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeId an id of specifed edge.
		* \return true if are connected by edge with id=edgeId.
		*/
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) = 0;

		/**
		* \brief get value saved in edge.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeId an id of edge.
		* \return value which is saved in edge
		*/
		virtual _EdgeVal getEdgeVal(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) = 0;

		/**
		* \brief iterate throw edges started in v1 and ended in v2.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \return an iterator.
		*/
		virtual IIterator<EdgeTuple> * createEdgesIter(vertex_id_t v1, vertex_id_t v2) = 0;

		virtual void disconnect(vertex_id_t v1, vertex_id_t v2) override = 0;
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2) override = 0;
		virtual IIterator<EdgeTuple>* createEdgesIter(vertex_id_t v1) override = 0;
		virtual void clear() override = 0;

		virtual ~IGraphConnector() { }
	};
}
