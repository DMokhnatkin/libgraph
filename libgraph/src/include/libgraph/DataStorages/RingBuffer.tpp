#pragma once

#include <libgraph/DataStorages/RingBuffer.h>

using namespace libgraph;

template<typename _ValType>
RingBuffer<_ValType>::RingBuffer(int size) {
	if (size < 2)
		throw std::invalid_argument("Buffer min size = 2");

	front = back = -1;
	data.reserve(size);
	data.resize(size);
}

template<typename _ValType>
void RingBuffer<_ValType>::push(_ValType val) {
	// Buffer is empty
	if (front == -1 && back == -1) {
		front = 0;
		back = 1;
		data[front] = val;
		return;
	}

	if (front == back) {
		throw FullBufferException();
	}

	data[back] = val;
	if (back == data.size() - 1)
		back = 0;
	else
		back++;
}

template<typename _ValType>
_ValType RingBuffer<_ValType>::pop() {
	if (front == -1 && back == -1) {
		throw EmptyBufferException();
	}

	if (front + 1 == back) {
		// Only 1 element in data
		_ValType temp = data[front];
		front = -1;
		back = -1;
		return temp;
	}
	_ValType temp = data[front];
	if (front == data.size() - 1)
		front = 0;
	else 
		front++;
	return temp;
}

template <typename _ValType>
int RingBuffer<_ValType>::Count() {
	if (front == - 1 && back == -1)
		return 0;

	int temp = back - front;
	if (temp <= 0)
		temp += data.size();
	return temp;
}
