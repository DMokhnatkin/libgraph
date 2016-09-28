#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;

libgraph::FreeIdCollection::FreeIdCollection() {
	
}

bool FreeIdCollection::isInCollection(vertex_id_t id)
{
	return id < _data.size() && _data[id] != nullptr;
}

vertex_id_t FreeIdCollection::getVertexCount() {
	return _vertex_ct;
}

vertex_id_t FreeIdCollection::createVertex(void *data) {
	vertex_id_t id;
	if (_freeId.empty()){
		id = _vertex_ct;
		_data.push_back(data);
	} else {
		id = _freeId.back();
		_freeId.pop_back();
		_data[id] = data;
	}
	_vertex_ct++;
	return id;
}

void* FreeIdCollection::getData(vertex_id_t id)
{
	if (!isInCollection(id))
		return nullptr;
	return _data[id];
}

bool FreeIdCollection::deleteVertex(vertex_id_t v) {
	if (!isInCollection(v)) 
		return false;
	if (v == _data.size() - 1)
		// if v is last in vector, reduce vector size
		_data.pop_back();
	else {
		// remove ref to data from vector
		_data[v] = nullptr;
		// add v to free id collection
		_freeId.push_back(v);
	}
	return true;
}

void FreeIdCollection::clear()
{
	_data.clear();
	_freeId.clear();
	_vertex_ct = 0;
}
