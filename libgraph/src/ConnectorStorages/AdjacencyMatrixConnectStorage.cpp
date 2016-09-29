#include <libgraph/ConnectorStorages/AdjacencyMatrixConnectStorage.h>

using namespace libgraph;

bool AdjacencyMatrixConnectStorage::isValidId(vertex_id_t v) {
	if (v >= vertexCt || v < 0)
		return false;
	return true;
}

AdjacencyMatrixConnectStorage::AdjacencyMatrixConnectStorage(vertex_id_t vertexCt) {
	setVertexCt(vertexCt);
}

bool libgraph::AdjacencyMatrixConnectStorage::connect(vertex_id_t v1, vertex_id_t v2) {
	if (!isValidId(v1) || !isValidId(v2))
		return false;

	data[v1 * vertexCt + v2]++;
	return true;
}

bool AdjacencyMatrixConnectStorage::disconnect(vertex_id_t v1, vertex_id_t v2) {
	if (!isValidId(v1) || !isValidId(v2))
		return false;
	if (!areConnected(v1, v2))
		return false;

	data[v1 * vertexCt + v2]--;
	return true;
}

bool AdjacencyMatrixConnectStorage::areConnected(vertex_id_t v1, vertex_id_t v2) {
	if (!isValidId(v1) || !isValidId(v2))
		return false;

	return data[v1 * vertexCt + v2] != 0;
}

void libgraph::AdjacencyMatrixConnectStorage::setVertexCt(vertex_id_t newCt) {
	vertex_id_t *newData = new vertex_id_t[newCt*newCt];
	std::fill(newData, newData + newCt * newCt, 0);
	if (data == nullptr)
		this->data = newData;
	else {
		// copy old array
		for (vertex_id_t i = 0; i < vertexCt; i++) {
			for (vertex_id_t j = 0; j < vertexCt; j++) {
				newData[i * vertexCt + j] = data[i * vertexCt + j];
			}
		}
	}
	this->vertexCt = newCt;
}




