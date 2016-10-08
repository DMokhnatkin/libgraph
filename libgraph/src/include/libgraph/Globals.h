#pragma once

#include <libgraph/private/windll.h>

/**
* \brief Empty value. Can be used in templates.
*/
class libgraph_API EmptyValue {
};


/**
 * \brief an iterator interface. All iterators must implement it.
 * \tparam _Val a type of object which can be iterated.
 */
template <typename _Val>
class IIterator {
public:
	IIterator() { };

	/**
	 * \brief move iterator to first element.
	 */
	virtual void first() = 0;

	/**
	* \brief move iterator to next element.
	*/
	virtual void next() = 0;

	/**
	* \brief is iteration ended .
	*/
	virtual bool isDone() = 0;

	/**
	 * \brief access to current iterable item.
	 * \return value of current iterable item.
	 */
	virtual _Val currentItem() = 0;

	virtual ~IIterator() { };
};