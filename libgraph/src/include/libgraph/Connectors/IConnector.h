#pragma once

#include <functional>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/Globals.h>
#include "libgraph/IDataStorage.h"
#include <unordered_set>

namespace libgraph {

	/**
	* \brief an edge tuple. Used to store (v1, v2, edgeId).
	*/
	class EdgeTuple {
	private:
		vertex_id_t v1, v2;
		edge_id_t edgeId;
	public:
		EdgeTuple(
			vertex_id_t v1,
			vertex_id_t v2,
			edge_id_t edgeId) :
			v1(v1), v2(v2), edgeId(edgeId) { }

		vertex_id_t getV1() const { return v1; };

		vertex_id_t getV2() const { return v2; };

		edge_id_t getEdgeId() const { return edgeId; };
	};

	template <typename _EdgeVal>
	class IConnector {
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
		* \brief Remove all edges between two vertices.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		*/
		virtual void disconnect(vertex_id_t v1, vertex_id_t v2) = 0;

		/**
		* \brief Are two vertecies connected.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \return true if are connected.
		*/
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2) = 0;

		/**
		* \brief iterate throw edges started in v1.
		* \param v1 a source vertex.
		* \return an iterator.
		*/
		virtual IIterator<EdgeTuple> * createEdgesIter(vertex_id_t v1) = 0;

		virtual void clear() = 0;
		virtual ~IConnector() { };
	};
}
#pragma once
