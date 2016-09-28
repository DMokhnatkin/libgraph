#pragma once

#include <deque>
#include <vector>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

#include <libgraph/IDataStorage.h>

namespace libgraph {
	template <typename T>
	class libgraph_API FreeIdCollection : public IDataStorage<T> {
	private:
		std::vector<T> _data;
		std::queue<vertex_id_t> _freeId;
		vertex_id_t _vertex_ct = 0;
	public:
		FreeIdCollection();
		virtual int getVertexCount();
		virtual vertex_id_t createVertex(T);
		virtual bool isInCollection(vertex_id_t);
		virtual T getData(vertex_id_t);
		virtual bool deleteVertex(vertex_id_t);
		virtual void clear();
		virtual ~FreeIdCollection() { };
	};
}

#include <libgraph/DataStorages/FreeIdCollection.tpp>
