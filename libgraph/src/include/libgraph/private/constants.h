#pragma once
#include <functional>

namespace libgraph {
	/// Type of vertex id
	using vertex_id_t = unsigned int;

	/// Type of edge id
	using edge_id_t = unsigned int;

	/// Type of callback used in searches
	template <typename _State>
	using search_fn_t = std::function<void(
		vertex_id_t,
		vertex_id_t,
		edge_id_t,
		_State&
	)>;


}
