#pragma once

#include <functional>
#include <unordered_map>

#include <libgraph/private/constants.h>
#include <libgraph/private/windll.h>

#include <libgraph/Connectors/IGraphConnector.h>
#include <libgraph/DataStorages/FreeIdCollection.h>
#include <libgraph/Globals.h>
#include <libgraph/Globals.h>

namespace libgraph {
	template<typename _EdgeVal>
	class BaseConnectorOutEdgesIter;
	template<typename _EdgeVal>
	class BaseConnectorEdgesIter;

	template <typename _EdgeVal>
	class BaseConnector : public IGraphConnector<_EdgeVal> {
	private:
		FreeIdCollection<_EdgeVal> *edges;
		std::unordered_map<vertex_id_t, std::unordered_map<vertex_id_t, std::unordered_set<edge_id_t>>> *connections;
	public:
		friend class BaseConnectorOutEdgesIter<_EdgeVal>;
		friend class BaseConnectorEdgesIter<_EdgeVal>;

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
		virtual void disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;

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

		virtual IIterator<EdgeTuple> * createEdgesIter(vertex_id_t v1, vertex_id_t v2) override;

		/**
		* \brief iterate throw edges which out from v1.
		* \param v1 a source vertex.
		* \return an iterator.
		*/
		virtual IIterator<EdgeTuple> * createEdgesIter(vertex_id_t v1) override;

		/**
		 * \brief clear collection.
		 */
		virtual void clear() override;

		virtual ~BaseConnector() { }
	};

	/**
	 * \brief iterator over edges which out from specifed vertex.
	 * \tparam _EdgeVal type of data stored in edges.
	 */
	template<typename _EdgeVal>
	class BaseConnectorOutEdgesIter : public IIterator<EdgeTuple> {
	private:
		BaseConnector<_EdgeVal> & connector;
		vertex_id_t v1;
		std::unordered_map<vertex_id_t, std::unordered_set<edge_id_t>>::iterator v2_iter;
		std::unordered_set<edge_id_t>::iterator edge_iter;
	public:
		BaseConnectorOutEdgesIter(
			BaseConnector<_EdgeVal> & connector,
			vertex_id_t v1) :
			connector(connector), v1(v1) {  }
		void first() override;
		void next() override;
		bool isDone() override;
		EdgeTuple currentItem() override;
		~BaseConnectorOutEdgesIter() { }
	};

	/**
	* \brief iterator over edges which out from and ended specifed vertecies.
	* \tparam _EdgeVal type of data stored in edges.
	*/
	template<typename _EdgeVal>
	class BaseConnectorEdgesIter : public IIterator<EdgeTuple> {
	private:
		BaseConnector<_EdgeVal> & connector;
		vertex_id_t v1, v2;
		std::unordered_set<edge_id_t>::iterator edge_iter;
	public:
		BaseConnectorEdgesIter(
			BaseConnector<_EdgeVal> & connector,
			vertex_id_t v1,
			vertex_id_t v2) :
			connector(connector), v1(v1), v2(v2) {  }
		void first() override;
		void next() override;
		bool isDone() override;
		EdgeTuple currentItem() override;
		~BaseConnectorEdgesIter() { }
	};
}

#include <libgraph/Connectors/BaseConnector.tpp>
