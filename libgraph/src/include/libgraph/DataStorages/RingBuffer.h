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

	/**
	 * \brief Queue implementation using ring buffer.
	 * \tparam _ValType a type of values in buffer.
	 */
	template<typename _ValType>
	class RingBuffer {
	private:
		int front, back;
		std::vector<_ValType> data;
	public:
		RingBuffer(int size);
		/**
		 * \brief push value in buffer.
		 * 
		 * O(1) time complexity.
		 * \param val 
		 */
		void push(_ValType val);

		/**
		* \brief get value from buffer.
		* 
		* O(1) time complexity.
		*/
		_ValType pop();

		/**
		* \brief get count if items in buffer.
		*
		* O(1) time complexity.
		*/
		int Count();
	};
}

#include <libgraph/DataStorages/RingBuffer.tpp>