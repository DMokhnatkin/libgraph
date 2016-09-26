#pragma once

#include <libgraph/private/windll.h>

namespace libgraph{
	class libgraph_API SampleGraph : public IGraph{
	public:
		SampleGraph();
		~SampleGraph();
		int getNumber() const;
	};
}
