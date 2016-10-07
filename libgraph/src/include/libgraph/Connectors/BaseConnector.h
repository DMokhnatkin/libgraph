#pragma once

#include <functional>
#include <unordered_map>

#include <libgraph/private/constants.h>
#include <libgraph/private/windll.h>

#include <libgraph/Connectors/IConnector.h>
#include <libgraph/DataStorages/FreeIdCollection.h>
#include <libgraph/Globals.h>

namespace libgraph {
	struct pair_hash {
		template <typename T1, typename T2>
		std::size_t operator () (const std::pair<T1, T2> &p) const {
			auto h1 = std::hash<T1>{}(p.first);
			auto h2 = std::hash<T2>{}(p.second);
			return h1 ^ h2;
		}
	};

	template <typename edgeVal_t>
	class BaseConnector : public IConnector<edgeVal_t> {
	private:
		FreeIdCollection<edgeVal_t> *edges;
		std::unordered_map<std::pair<vertex_id_t, vertex_id_t>, std::unordered_set<edge_id_t>, pair_hash> *connections;
	public:
		BaseConnector();

		/**
		 * \brief Connect two vertices.
		 * \param v1 a source vertex.
		 * \param v2 a destination vertex.
		 * \param edgeVal some value to add to created edge.
		 * \return an id of created edge. Id is unique for all collection.
		 */
		virtual edge_id_t connect(vertex_id_t v1, vertex_id_t v2, edgeVal_t edgeVal) override;

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
		virtual edgeVal_t getEdgeVal(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;

		/**
		 * \brief clear collection.
		 */
		virtual void clear() override;

		virtual ~BaseConnector() { };
	};
}

#include <libgraph/Connectors/BaseConnector.tpp>
