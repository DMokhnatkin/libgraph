#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

namespace libgraph {
	template <typename T>
	class IDataStorage {
	public:
		virtual unsigned int getCount() = 0;
		virtual unsigned int addData(T) = 0;
		virtual bool removeData(unsigned int id) = 0;
		virtual ~IDataStorage() { };
	};
}
