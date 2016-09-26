#pragma once

#include <libgraph/private/windll.h>

namespace libgraph{
	class libgraph_API IGraph{
	public:
		virtual int getNumber() const = 0;
		virtual ~IGraph(){ };
	};
}
