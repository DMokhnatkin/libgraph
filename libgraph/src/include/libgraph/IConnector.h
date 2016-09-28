#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

namespace libgraph{
	class libgraph_API IConnector{
	public:
		virtual IEdge *const getEdge(vertex_id_t v1, vertex_id_t v2) = 0;
		virtual void forEachEdge(vertex_id_t v, void (*func)(IEdge *e)) = 0;
		virtual ~IConnector(){ };
	};
}
