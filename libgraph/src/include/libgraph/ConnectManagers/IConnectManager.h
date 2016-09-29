#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>
#include <functional>

namespace libgraph{
	class libgraph_API IConnectManager {
	public:
		virtual bool connect(vertex_id_t v1, vertex_id_t v2) = 0;
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2) = 0;
		virtual void forEachConnected(vertex_id_t, std::function<void(vertex_id_t from, vertex_id_t to)>) = 0;
		virtual ~IConnectManager(){ };
	};
}
