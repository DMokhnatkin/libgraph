#pragma once

#include <libgraph/private/windll.h>

namespace libgraph{
	class libgraph_API IGraph{
	public:
		virtual int getVertexCount() = 0;
		virtual IVertex *const createVertex(IVertex*) = 0;
		virtual void deleteVertex(IVertex*) = 0;
		virtual IConnector *const getConnector() = 0;
		virtual ~IGraph(){ };
	};
}
