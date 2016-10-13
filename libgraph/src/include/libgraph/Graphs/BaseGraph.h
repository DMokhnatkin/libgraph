#pragma once

#include <libgraph/private/constants.h>
#include <libgraph/IGraph.h>
#include <libgraph/Connectors/BaseConnector.h>
#include <array>

namespace libgraph {
	template <typename _VertexVal, typename _EdgeVal>
	class BaseGraph : public IGraph<_VertexVal, _EdgeVal> {
	private:
		BaseConnector<_EdgeVal> * connector;
		FreeIdCollection<_VertexVal> * vertices;
	public:
		using EdgeInitTuple = std::tuple<vertex_id_t, vertex_id_t, _EdgeVal>;

		BaseGraph() :
			connector(new BaseConnector<_EdgeVal>()),
			vertices(new FreeIdCollection<_VertexVal>()) {
		}
		template<typename _VertCollectionType, typename _EdgeCollectionType>
		void initialize(_VertCollectionType initVert, _EdgeCollectionType initEdges);
		virtual edge_id_t connect(vertex_id_t v1, vertex_id_t v2, _EdgeVal edgeVal) override;
		virtual void disconnect(vertex_id_t v1, vertex_id_t v2) override;
		virtual void disconnect(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2) override;
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;
		virtual _EdgeVal getEdgeVal(vertex_id_t v1, vertex_id_t v2, edge_id_t edgeId) override;
		virtual IIterator<EdgeTuple>* createEdgesIter(vertex_id_t v1) override;
		virtual IIterator<EdgeTuple>* createEdgesIter(vertex_id_t v1, vertex_id_t v2) override;
		virtual void clear() override;
		virtual vertex_id_t getVertexCount() override;
		virtual vertex_id_t createVertex(_VertexVal) override;
		virtual _VertexVal getVertexValue(vertex_id_t id) override;
		virtual bool containsVertex(vertex_id_t id) override;
		virtual void removeVertex(vertex_id_t id) override;
		virtual ~BaseGraph() {
			delete connector;
			delete vertices;
		}
	};
};

#include <libgraph/Graphs/BaseGraph.tpp>