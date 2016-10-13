#pragma once

#include <libgraph/DataStorages/RingBuffer.h>

using namespace libgraph;

template<typename _ValType>
RingBuffer<_ValType>::RingBuffer(int size) {
	if (size < 2)
		throw std::invalid_argument("Buffer min size = 2");

	top = back = -1;
	data.reserve(size);
	data.resize(size);
}

template<typename _ValType>
void RingBuffer<_ValType>::push_back(_ValType val) {
	if (isEmpty()) {
		top = 0;
		back = 0;
		data[top] = val;
		return;
	}

	if (isFull()) {
		throw FullBufferException();
	}

	back = (back + 1) % data.size();
	data[back] = val;
}

template<typename _ValType>
void RingBuffer<_ValType>::push_top(_ValType val) {
	if (isEmpty()) {
		top = 0;
		back = 0;
		data[top] = val;
		return;
	}

	if (isFull()) {
		throw FullBufferException();
	}

	if (top == 0)
		top = data.size();
	else
		top--;
	data[top] = val;
}

template<typename _ValType>
_ValType RingBuffer<_ValType>::pop_top() {
	if (isEmpty()) {
		throw EmptyBufferException();
	}

	if (top == back) {
		// Only 1 element in data
		_ValType temp = data[top];
		top = -1;
		back = -1;
		return temp;
	}
	_ValType temp = data[top];
	if (top == data.size() - 1)
		top = 0;
	else 
		top++;
	return temp;
}

template <typename _ValType>
_ValType RingBuffer<_ValType>::pop_back() {
	if (isEmpty()) {
		throw EmptyBufferException();
	}

	if (top == back) {
		// Only 1 element in data
		_ValType temp = data[back];
		top = -1;
		back = -1;
		return temp;
	}

	_ValType temp = data[back];
	if (back == 0)
		back = data.size() - 1;
	else
		back--;
	return temp;
}

template <typename _ValType>
bool RingBuffer<_ValType>::isEmpty() {
	return top == -1 && back == -1;
}

template <typename _ValType>
bool RingBuffer<_ValType>::isFull() {
	return (back + 1) % data.size() == top;
}

template <typename _ValType>
int RingBuffer<_ValType>::count() {
	if (isEmpty())
		return 0;

	int temp = back - top;
	if (temp < 0)
		temp += data.size();
	return temp + 1;
}
