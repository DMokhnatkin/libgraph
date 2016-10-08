#pragma once

#include <unordered_set>
#include <vector>

#include <libgraph/private/constants.h>

#include <libgraph/IDataStorage.h>

namespace libgraph {
	template <typename T>
	class FreeIdCollection : public IDataStorage<T> {
	private:
		std::vector<T> data;
		std::unordered_set<unsigned int> freeId;
		int ct = 0;
	public:
		FreeIdCollection();
		virtual unsigned int getCount() override;
		virtual unsigned int addData(T) override;
		virtual bool contains(unsigned int);
		virtual T getData(unsigned int);
		virtual bool removeData(unsigned int) override;
		virtual void clear();
		virtual ~FreeIdCollection() { };
	};
}

#include <libgraph/DataStorages/FreeIdCollection.tpp>
