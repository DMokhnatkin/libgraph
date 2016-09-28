#include <cstddef>

#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;

template <typename T>
libgraph::FreeIdCollection<T>::FreeIdCollection() {

}

template <typename T>
vertex_id_t FreeIdCollection<T>::getVertexCount() {
	return _vertex_ct;
}

template <typename T>
vertex_id_t FreeIdCollection<T>::createVertex(T data) {
	vertex_id_t id;
	if (_freeId.empty()){
		id = _vertex_ct;
		_data.push_back(data);
	} else {
		id = _freeId.back();
		_freeId.pop();
		_data[id] = data;
	}
	return id;
}

template <typename T>
bool FreeIdCollection<T>::deleteVertex(vertex_id_t v) {
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
