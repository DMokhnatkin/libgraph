#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

namespace libgraph{
	class libgraph_API IGraph{
	public:
		virtual IDataStorage * const getData() = 0;
		virtual IConnectStorage * const getConnectStorage() = 0;
		virtual ~IGraph(){ };
	};
}
