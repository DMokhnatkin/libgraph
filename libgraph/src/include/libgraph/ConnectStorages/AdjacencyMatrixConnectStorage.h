#pragma once
#include <functional>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>
#include <libgraph/ConnectStorages/IConnectStorage.h>

namespace libgraph {
	class libgraph_API AdjacencyMatrixConnectStorage : public IConnectStorage {
	private:
		// in each cell[i,j] we will store how many edges are between i and j vertices 
		vertex_id_t *data = nullptr;
		vertex_id_t vertexCt;

		// Is id valid to store in data?
		bool isValidId(vertex_id_t v);
	public:
		/// vertexCt - initial count of vertecies. You can change it after initialization, 
		/// but it is O(vertexCt^2) operation
		AdjacencyMatrixConnectStorage(vertex_id_t vertexCt);

		virtual bool connect(vertex_id_t v1, vertex_id_t v2);
		virtual bool disconnect(vertex_id_t v1, vertex_id_t v2);

		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2);

		virtual void clear();

		/// Set new vertex count. It will copy current data array, so complexity is O(vertexCt^2)
		virtual void setVertexCt(vertex_id_t newCt);
		virtual ~AdjacencyMatrixConnectStorage() { };
	};
}

