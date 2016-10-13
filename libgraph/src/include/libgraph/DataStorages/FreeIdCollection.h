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
		unsigned int ct = 0;
	public:
		FreeIdCollection();

		/**
		* \brief Get elements count.
		* 
		* Θ(1) time complexity.
		* \return Number of elements in collection.
		*/
		virtual unsigned int getCount() override;

		/**
		 * \brief Get max id in collection.
		 * 
		 * Max id can be currently used id or free id. 
		 * So data with this id сan not exist in collection now (but it was exist some time before).
		 * Θ(1) time complexity.
		 * \return max ever existed in collection id.
		 */
		virtual unsigned int getMaxId();

		/**
		* \brief Create element with given data.
		* 
		* O(1) time complexity (amortized).
		* \param data Data to store in element.
		* \return ID of given element.
		*/
		virtual unsigned int addData(T data) override;

		/**
		* \brief Check if given id is in collection.
		* 
		* O(1) time complexity (amortized).
		* \param id element id to check.
		* \return true if exists, false if not.
		*/
		virtual bool contains(unsigned int id);

		/**
		* \brief Get data from given element id.
		* 
		* O(1) time complexity (amortized).
		* \param id Element id.
		* \throw std::invalid_argument If key is not in collection.
		* \return Data if key exists in collection.
		*/
		virtual T getData(unsigned int id);

		/**
		* \brief Delete element from collection by id.
		* 
		* Delete element from collection by id. By default,
		* element will be removed from collection, and it's id will be pushed to free ids.
		* (so collection size will not be reduced).
		* O(1) time complexity (amortized).
		* \param v Id of element to delete.
		* \return False if element is not in collection, true if deletion is successful.
		*/
		virtual bool removeData(unsigned int v) override;

		/**
		* \brief Clear collection.
		* 
		*/
		virtual void clear();
		virtual ~FreeIdCollection() { };
	};
}

#include <libgraph/DataStorages/FreeIdCollection.tpp>
