#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

#include <libgraph/Connectors/IConnector.h>

namespace libgraph{
	template<typename _EdgeVal>
	class libgraph_API IGraph{
	public:
		virtual IConnector<_EdgeVal> & getConnector() = 0;
		virtual ~IGraph(){ };
	};
}
