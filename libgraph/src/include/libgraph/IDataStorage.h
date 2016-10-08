#pragma once

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>

namespace libgraph {
	template <typename T>
	class IDataStorage {
	public:
		virtual int getCount() = 0;
		virtual int addData(T) = 0;
		virtual bool removeData(int id) = 0;
		virtual ~IDataStorage() { };
	};
}
