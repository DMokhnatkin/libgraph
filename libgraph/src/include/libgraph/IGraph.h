#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

#include <libgraph/Connectors/IConnector.h>
#include "IVertexStorage.h"

namespace libgraph{
	template<typename _VertexVal, typename _EdgeVal>
	class libgraph_API IGraph : public IVertexStorage<_VertexVal>, public IConnector<_EdgeVal> {
	public:
		virtual ~IGraph() { };
	};
}
