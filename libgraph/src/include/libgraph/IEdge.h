#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

namespace libgraph{
	class libgraph_API IEdge{
	public:
		virtual vertex_id_t getFirstVertex() = 0;
		virtual vertex_id_t getLastVertex() = 0;
		virtual ~IEdge(){ };
	};
}
