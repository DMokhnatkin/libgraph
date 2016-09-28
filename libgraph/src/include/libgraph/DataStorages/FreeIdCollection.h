#pragma once

#include <queue>
#include <vector>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

#include <libgraph/IDataStorage.h>

namespace libgraph {
	class libgraph_API FreeIdCollection : public IDataStorage {
	private:
		std::vector<IVertexData*> _data;
		std::queue<vertex_id_t> _freeId;
		vertex_id_t _vertex_ct = 0;
	public:
		FreeIdCollection();
		virtual int getVertexCount();
		virtual vertex_id_t createVertex(IVertexData*);
		virtual bool deleteVertex(vertex_id_t);
		virtual ~FreeIdCollection() { };
	};
}
