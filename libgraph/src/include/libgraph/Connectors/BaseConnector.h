#pragma once

#include <functional>
#include <unordered_map>

#include <libgraph/private/constants.h>
#include <libgraph/private/windll.h>

#include <libgraph/Connectors/IConnector.h>
#include <libgraph/DataStorages/FreeIdCollection.h>
#include <libgraph/Globals.h>

namespace libgraph {
	template <typename _EdgeVal>
	class BaseConnector : public IConnector<_EdgeVal> {
	private:
		FreeIdCollection<_EdgeVal> *edges;
		std::unordered_map<vertex_id_t, std::unordered_map<vertex_id_t, std::unordered_set<edge_id_t>>> *connections;
	public:
		BaseConnector();

		/**
		 * \brief Connect two vertices.
		 * \param v1 a source vertex.
		 * \param v2 a destination vertex.
		 * \param edgeVal some value to add to created edge.
		 * \return an id of created edge. Id is unique for all collection.
		 */
		virtual edge_id_t connect(vertex_id_t v1, vertex_id_t v2, _EdgeVal edgeVal) override;

		/**
		 * \brief Remove all edges between two vertices.  
		 * \param v1 a source vertex.
		 * \param v2 a destination vertex.
		 */
		virtual void disconnect(vertex_id_t v1, vertex_id_t v2) override;

		/**
		* \brief Remove one edge with specifed id.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeId an edge to remove.
		* \return true if succesed.
		*/
		virtual bool disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;

		/**
		* \brief Are two vertecies connected.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \return true if are connected.
		*/
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2) override;

		/**
		* \brief Are two vertecies connected by specifed edge.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeId an id of specifed edge.
		* \return true if are connected by edge with id=edgeId.
		*/
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;


		/**
		 * \brief get value saved in edge.
		 * \param v1 a source vertex. (In this connector doesn't use, because edge Id is unique)
		 * \param v2 a destination vertex. (In this connector doesn't use, because edge Id is unique)
		 * \param edgeId an id of edge. (In this connector is unique, so it's enough to get value)
		 * \return value which is saved in edge
		 */
		virtual _EdgeVal getEdgeVal(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;

		/**
		 * \brief iterate throw edges between 2 vertecies.
		 * \param v1 a source vertex.
		 * \param v2 a destination vertex.
		 * \return an iterator to the beginning
		 */
		virtual typename IConnector<_EdgeVal>::edge_iterator beginIterateEdges(vertex_id_t v1, vertex_id_t v2) override;

		/**
		* \brief iterate throw edges between 2 vertecies.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \return an iterator to the end.
		*/
		virtual typename IConnector<_EdgeVal>::edge_iterator endIterateEdges(vertex_id_t v1, vertex_id_t v2) override;

		virtual typename IConnector<_EdgeVal>::out_edges_iterator beginIterateEdges(vertex_id_t v1) override;

		virtual typename IConnector<_EdgeVal>::out_edges_iterator endIterateEdges(vertex_id_t v1) override;

		/**
		 * \brief clear collection.
		 */
		virtual void clear() override;

		virtual ~BaseConnector() { }
	};
}

#include <libgraph/Connectors/BaseConnector.tpp>
