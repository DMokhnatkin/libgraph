#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

#include <libgraph/Connectors/IConnector.h>

namespace libgraph{
	template<typename edgeVal_t>
	class libgraph_API IGraph{
	public:
		virtual IConnector<edgeVal_t> & getConnector() = 0;
		virtual ~IGraph(){ };
	};
}
