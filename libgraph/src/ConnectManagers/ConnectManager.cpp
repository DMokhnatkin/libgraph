#include <libgraph/ConnectManagers/ConnectManager.h>
#include <libgraph/ConnectStorages/IConnectStorage.h>

using namespace libgraph;

ConnectManager::ConnectManager(IConnectStorage * storage) {
	this->storage = storage;
}

void ConnectManager::forEachConnected(vertex_id_t v, std::function<void(vertex_id_t from, vertex_id_t to)>) {
	// TODO: body
}

bool ConnectManager::connect(vertex_id_t v1, vertex_id_t v2) {
	bool res;
	if (!storage->connect(v1, v2))
		return false;
	if (!settings.connectConsiderDirection)
		if (!storage->connect(v2, v1)) return false;
	return true;
}

bool ConnectManager::disconnect(vertex_id_t v1, vertex_id_t v2) {
	return false;
	// TODO: more then one edge
}

bool ConnectManager::areConnected(vertex_id_t v1, vertex_id_t v2) {
	if (!settings.lookupConsiderDirection) {
		return storage->areConnected(v1, v2) || storage->areConnected(v2, v1);
	} else {
		return storage->areConnected(v1, v2);
	}
}
