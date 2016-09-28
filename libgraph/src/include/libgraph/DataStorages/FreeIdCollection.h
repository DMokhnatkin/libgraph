#pragma once

#include <deque>
#include <vector>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

#include <libgraph/IDataStorage.h>

namespace libgraph {
	class libgraph_API FreeIdCollection : public IDataStorage {
	private:
		std::vector<void*> _data;
		std::deque<vertex_id_t> _freeId;
		vertex_id_t _vertex_ct = 0;
	public:
		FreeIdCollection();
		virtual int getVertexCount();
		virtual vertex_id_t createVertex(void*);
		virtual bool isInCollection(vertex_id_t);
		virtual void* getData(vertex_id_t);
		virtual bool deleteVertex(vertex_id_t);
		virtual void clear();
		virtual ~FreeIdCollection() { };
	};
}
