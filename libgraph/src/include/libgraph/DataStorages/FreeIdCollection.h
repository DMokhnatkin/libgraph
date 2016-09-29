#pragma once

#include <unordered_set>
#include <vector>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

#include <libgraph/IDataStorage.h>

namespace libgraph {
	template <typename T>
	class libgraph_API FreeIdCollection : public IDataStorage<T> {
	private:
		std::vector<T> data;
		std::unordered_set<vertex_id_t> freeId;
		vertex_id_t vertex_ct = 0;
	public:
		FreeIdCollection();
		virtual vertex_id_t getVertexCount();
		virtual vertex_id_t createVertex(T);
		virtual bool contains(vertex_id_t);
		virtual T getData(vertex_id_t);
		virtual bool deleteVertex(vertex_id_t);
		virtual void clear();
		virtual ~FreeIdCollection() { };
	};
}

#include <libgraph/DataStorages/FreeIdCollection.tpp>
