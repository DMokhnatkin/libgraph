#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

#include <libgraph/Connectors/IGraphConnector.h>
#include "IVertexStorage.h"

namespace libgraph{
	template<typename _VertexVal, typename _EdgeVal>
	class IGraph : public IVertexStorage<_VertexVal>, public IGraphConnector<_EdgeVal> {
	public:
		virtual ~IGraph() { };
	};
}
