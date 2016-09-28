#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

namespace libgraph{
	class libgraph_API IGraph{
	public:
		virtual int getVertexCount() = 0;
		virtual vertex_id_t createVertex(IVertexData*) = 0;
		virtual bool deleteVertex(vertex_id_t) = 0;
		virtual IConnector *const getConnector() = 0;
		virtual ~IGraph(){ };
	};
}
