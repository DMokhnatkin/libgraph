#pragma once

#include <iostream>
#include <cstdlib>
#include <libgraph/private/windll.h>
#include <vector>

namespace libgraph {
	class libgraph_API FullBufferException : public std::exception
	{
		virtual const char* what() const throw() override
		{
			return "Buffer if full";
		}
	};

	class libgraph_API EmptyBufferException : public std::exception
	{
		virtual const char* what() const throw() override
		{
			return "Buffer if empty";
		}
	};

	template<typename _ValType>
	class RingBuffer {
	private:
		int front, back;
		std::vector<_ValType> data;
	public:
		RingBuffer(int size);
		void push(_ValType val);
		_ValType pop();
		int Count();
	};
}

#include <libgraph/DataStorages/RingBuffer.tpp>