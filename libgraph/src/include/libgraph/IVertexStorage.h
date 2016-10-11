#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

namespace libgraph {
	template <typename _VertexValue>
	class IVertexStorage {
	public:
		virtual vertex_id_t getVertexCount() = 0;
		virtual vertex_id_t createVertex(_VertexValue) = 0;
		virtual bool containsVertex(vertex_id_t id) = 0;
		virtual void removeVertex(vertex_id_t id) = 0;
		virtual ~IVertexStorage() { };
	};
}
#pragma once
