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
		std::unordered_set<int> freeId;
		int ct = 0;
	public:
		FreeIdCollection();
		virtual int getCount() override;
		virtual int addData(T) override;
		virtual bool contains(int);
		virtual T getData(int);
		virtual bool removeData(int) override;
		virtual void clear();
		virtual ~FreeIdCollection() { };
	};
}

#include <libgraph/DataStorages/FreeIdCollection.tpp>
