#pragma once

#include <libgraph/private/windll.h>

namespace libgraph{
	class libgraph_API IConnector{
	public:
		virtual IEdge *const getEdge(IVertex *v1, IVertex *v2) = 0;
		virtual void forEachEdge(IVertex *v, void (*func)(IEdge *e)) = 0;
		virtual ~IConnector(){ };
	};
}
