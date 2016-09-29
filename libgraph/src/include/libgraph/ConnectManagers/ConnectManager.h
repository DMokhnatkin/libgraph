#pragma once
#include <functional>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/private/decls.h>
#include <libgraph/ConnectManagers/IConnectManager.h>

namespace libgraph {
	class libgraph_API ConnectManager : public IConnectManager {
	private:
		IConnectStorage *storage;
	public:
		struct ConnectManagerSettings {
		public:
			bool connectConsiderDirection = false;
			bool lookupConsiderDirection = false;
		};
		ConnectManagerSettings settings;

		ConnectManager(IConnectStorage *storage);

		/// Connect two vertices
		/// If settings.connectConsiderDirection is false, v1->v2 and v2->v1 connection will be created, otherwise only v1->v2
		virtual bool connect(vertex_id_t v1, vertex_id_t v2);

		/// Disconnect two vertices
		virtual bool disconnect(vertex_id_t v1, vertex_id_t v2);

		/// Are vertices connected. 
		/// If settings.lookupConsiderDirection is false, v1->v2 and v2->v1 will be considered, otherwise only v1->v2
		virtual bool areConnected(vertex_id_t v1, vertex_id_t v2);


		/// call callback for each connected to 'v' vertex
		/// callback(from, to) where from = 'v', to = some connected with 'v' vertex
		virtual void forEachConnected(vertex_id_t v, std::function<void(vertex_id_t from, vertex_id_t to)>);

		virtual ~ConnectManager() { };
	};
}
