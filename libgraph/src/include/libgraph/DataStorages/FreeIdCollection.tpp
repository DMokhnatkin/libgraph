#include <stdexcept>
#include <libgraph/DataStorages/FreeIdCollection.h>

using namespace libgraph;

template <typename T>
FreeIdCollection<T>::FreeIdCollection() {

}

template <typename T>
bool FreeIdCollection<T>::contains(unsigned int id) {
	return id < data.size() && freeId.count(id) == 0;
}

template <typename T>
unsigned int FreeIdCollection<T>::getCount() {
	return ct;
}

template <typename T>
unsigned FreeIdCollection<T>::getMaxId() {
	return data.size();
}

template <typename T>
unsigned int FreeIdCollection<T>::addData(T data) {
	vertex_id_t id;
	if (freeId.empty()){
		id = ct;
		this->data.push_back(data);
	} else {
		id = *freeId.begin();
		freeId.erase(id);
		this->data[id] = data;
	}
	ct++;
	return id;
}

template <typename T>
T FreeIdCollection<T>::getData(unsigned int id) {
	if (!contains(id))
		throw std::invalid_argument("No key in collection");
	return data[id];
}

template <typename T>
bool FreeIdCollection<T>::removeData(unsigned int v) {
	// if v is not in collection, return false
	if (!contains(v))
		return false;
	// add v to free id collection
	freeId.insert(v);
	ct--;
	return true;
}

template <typename T>
void FreeIdCollection<T>::clear() {
	data.clear();
	freeId.clear();
	ct = 0;
}
