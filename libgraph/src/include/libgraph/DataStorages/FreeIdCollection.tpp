#include <stdexcept>
#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;

template <typename T>
FreeIdCollection<T>::FreeIdCollection() {

}

/**
* \brief Check if given id is in collection.
* \param id element id to check.
* \return true if exists, false if not.
*/
template <typename T>
bool FreeIdCollection<T>::contains(vertex_id_t id) {
	return id < data.size() && freeId.count(id) == 0;
}

/**
* \brief Get elements count.
* \return Number of elements in collection.
*/
template <typename T>
vertex_id_t FreeIdCollection<T>::getVertexCount() {
	return vertex_ct;
}

/**
* \brief Create element with given data.
* \param data Data to store in element.
* \return ID of given element.
*/
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

/**
* \brief Get data from given element id.
* \param id Element id.
* \throw std::invalid_argument If key in not in collection.
* \return Data if key exists in collection.
*/
template <typename T>
T FreeIdCollection<T>::getData(vertex_id_t id) {
	if (!contains(id))
		throw std::invalid_argument("No key in collection");
	return data[id];
}

/**
* \brief Delete element from collection by id.
* \param v Id of element to delete.
* \return False if element is not in collection, true if deletion is successful.
*/
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

/**
* \brief Clear collection.
*/
template <typename T>
void FreeIdCollection<T>::clear() {
	data.clear();
	freeId.clear();
	vertex_ct = 0;
}
