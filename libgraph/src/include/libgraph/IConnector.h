#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>
#include <functional>

namespace libgraph{
	class libgraph_API IConnector{
	public:
		virtual IEdge *const getEdge(vertex_id_t, vertex_id_t) = 0;
		virtual void forEachEdge(vertex_id_t, std::function<void(IEdge* const)>) = 0;
		virtual ~IConnector(){ };
	};
}
