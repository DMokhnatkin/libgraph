#pragma once

#include <libgraph/private/windll.h>

namespace libgraph{
	class libgraph_API SampleGraph : public IGraph{
	public:
		SampleGraph();
		~SampleGraph();
		int getVertexCount();
		vertex_id_t createVertex(IVertexData*);
		bool deleteVertex(vertex_id_t);
		IConnector *const getConnector();
	};
}
