#include <cstddef>

#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;

libgraph::FreeIdCollection::FreeIdCollection() {
	
}

vertex_id_t FreeIdCollection::getVertexCount() {
	return _vertex_ct;
}

vertex_id_t FreeIdCollection::createVertex(IVertexData *data) {
	vertex_id_t id;
	if (_freeId.empty()){
		id = _vertex_ct;
		_data.push_back(data);
	} else {
		id = _freeId.back();
		_freeId.pop();
		_data[id] = data;
	}
}

bool FreeIdCollection::deleteVertex(vertex_id_t v) {
	// if v is not in collection, return false
	if (v >= _data.size() || _data[v] == NULL)
		return false;
	if (v == _data.size() - 1)
		// if v is last in vector, reduce vector size
		_data.pop_back();
	else {
		// remove ref to data from vector
		_data[v] = NULL;
		// add v to free id collection
		_freeId.push(v);
	}
}
