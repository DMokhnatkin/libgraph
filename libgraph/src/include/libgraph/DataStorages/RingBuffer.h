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
		int top, back;
		std::vector<_ValType> data;
	public:
		RingBuffer(int size);
		/**
		 * \brief push value in buffer's back.
		 * 
		 * O(1) time complexity.
		 * \param val 
		 */
		void push_back(_ValType val);

		/**
		* \brief push value in buffer's top.
		*
		* O(1) time complexity.
		* \param val
		*/
		void push_top(_ValType val);

		/**
		* \brief get value from buffer's top.
		* 
		* O(1) time complexity.
		*/
		_ValType pop_top();

		/**
		* \brief get value from buffer's back.
		*
		* O(1) time complexity.
		*/
		_ValType pop_back();


		/**
		 * \brief is buffer empty.
		 * 
		 * O(1) time complexity.
		 */
		bool isEmpty();


		/**
		 * \brief is buffer full.
		 * 
		 * O(1) time complexity.
		 */
		bool isFull();

		/**
		* \brief get count if items in buffer.
		*
		* O(1) time complexity.
		*/
		int count();
	};
}

#include <libgraph/DataStorages/RingBuffer.tpp>