#include <stdexcept>
#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;

template <typename T>
libgraph::FreeIdCollection<T>::FreeIdCollection() {

}

template <typename T>
bool FreeIdCollection<T>::contains(vertex_id_t id) {
	return id < data.size() && freeId.count(id) == 0;
}

template <typename T>
vertex_id_t FreeIdCollection<T>::getVertexCount() {
	return vertex_ct;
}

template <typename T>
vertex_id_t FreeIdCollection<T>::createVertex(T data) {
	vertex_id_t id;
	if (freeId.empty()){
		id = vertex_ct;
		this->data.push_back(data);
	} else {
		id = *freeId.begin();
		freeId.erase(id);
		this->data[id] = data;
	}
	vertex_ct++;
	return id;
}

template <typename T>
T FreeIdCollection<T>::getData(vertex_id_t id) {
	if (!contains(id))
		throw std::invalid_argument("No key in collection");
	return data[id];
}

template <typename T>
bool FreeIdCollection<T>::deleteVertex(vertex_id_t v) {
	// if v is not in collection, return false
	if (!contains(v))
		return false;
	if (v == data.size() - 1)
		// if v is last in vector, reduce vector size
		data.pop_back();
	else {
		// add v to free id collection
		freeId.insert(v);
	}
	vertex_ct--;
	return true;
}

template <typename T>
void FreeIdCollection<T>::clear() {
	data.clear();
	freeId.clear();
	vertex_ct = 0;
}
