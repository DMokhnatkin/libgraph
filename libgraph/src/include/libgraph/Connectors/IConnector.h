#pragma once

#include <functional>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/Globals.h>
#include <iterator>
#include "libgraph/IDataStorage.h"
#include <unordered_set>

namespace libgraph {
	template <typename _EdgeVal>
	class IConnector {
	private:
	public:
		/**
		 * \brief iterator for edges.
		 */
		typedef std::unordered_set<edge_id_t>::iterator edge_iterator;

		/**
		 * \brief const iterator for edges.
		 */
		typedef std::unordered_set<edge_id_t>::const_iterator const_edge_iterator;

		/**
		* \brief iterator for edges from some vertex.
		*/
		typedef EmptyValue out_edges_iterator; // TODO: not implemented

		/**
		* \brief const iterator for edges from some vertex.
		*/
		typedef EmptyValue const_out_edges_iterator; // TODO: not implemented

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
		* \brief Remove one edge with specifed id.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeId an edge to remove.
		* \return true if succesed.
		*/
		virtual bool disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) = 0;

		/**
		* \brief Are two vertecies connected.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \return true if are connected.
		*/
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2) = 0;

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
		 * \brief iterate throw edges between 2 vertecies.
		 * \param v1 a source vertex.
		 * \param v2 a destination vertex.
		 * \return an iterator to the beginning
		 */
		virtual edge_iterator beginIterateEdges(vertex_id_t v1, vertex_id_t v2) = 0;

		/**
		* \brief iterate throw edges between 2 vertecies.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \return an iterator to the end.
		*/
		virtual edge_iterator endIterateEdges(vertex_id_t v1, vertex_id_t v2) = 0;

		/**
		* \brief iterate throw edges started in v1.
		* \param v1 a source vertex.
		* \return an iterator to the beginning.
		*/
		virtual out_edges_iterator beginIterateEdges(vertex_id_t v1) = 0;

		/**
		* \brief iterate throw edges started in v1.
		* \param v1 a source vertex.
		* \return an iterator to the end.
		*/
		virtual const_out_edges_iterator endIterateEdges(vertex_id_t v1) = 0;

		virtual void clear() = 0;
		virtual ~IConnector() { };
	};
}