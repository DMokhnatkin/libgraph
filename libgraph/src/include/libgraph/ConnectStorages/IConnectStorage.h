#pragma once

#pragma once
#include <functional>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>

namespace libgraph {
	class libgraph_API IConnectStorage{
	private:
	public:
		virtual bool connect(vertex_id_t v1, vertex_id_t v2) = 0;
		virtual bool disconnect(vertex_id_t v1, vertex_id_t v2) = 0;
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2) = 0;
		virtual void clear() = 0;
		virtual ~IConnectStorage() { };
	};
}
