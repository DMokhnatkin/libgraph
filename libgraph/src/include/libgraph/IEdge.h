#pragma once

#include <libgraph/private/windll.h>

namespace libgraph{
	class libgraph_API IEdge{
	public:
		virtual IVertex *const getFirstVertex() = 0;
		virtual IVertex *const getLastVertex() = 0;
		virtual ~IEdge(){ };
	};
}
