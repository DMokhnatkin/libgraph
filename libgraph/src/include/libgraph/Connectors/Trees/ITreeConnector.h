#pragma once

#include <functional>

#include <libgraph/private/windll.h>
#include <libgraph/private/constants.h>
#include <libgraph/Globals.h>
#include <unordered_set>
#include <libgraph/Connectors/IConnector.h>

namespace libgraph {
	template <typename _EdgeVal>
	class ITreeConnector : IConnector<_EdgeVal> {
	private:
	public:
		/**
		* \brief Connect two vertices.
		* \param v1 a source vertex.
		* \param v2 a destination vertex.
		* \param edgeVal some value to add to created edge.
		* \return an id of created edge.
		*/
		virtual void connect(vertex_id_t v1, vertex_id_t v2, _EdgeVal edgeVal) = 0;

		/**
		 * \brief get root of tree
		 */
		virtual vertex_id_t getRoot() = 0;

		/**
		 * \brief get edge value
		 * \param parent a vertex 1
		 * \param child a vertex 2
		 * \return value in edge which connect 'parent' and 'child' vertices
		 */
		virtual _EdgeVal getEdgeVal(vertex_id_t parent, vertex_id_t child) = 0;

		/**
		 * \brief alias for createEdgesIter
		 * \param p a vertex id
		 * \return iterator to vertex childs
		 */
		virtual inline IIterator<EdgeTuple> * getChilds(vertex_id_t p) = 0;

		virtual void disconnect(vertex_id_t parent, vertex_id_t child) override = 0;
		virtual bool areConnected(vertex_id_t parent, vertex_id_t child) override = 0;
		virtual IIterator<EdgeTuple> * createEdgesIter(vertex_id_t parent) override = 0;
		virtual void clear() override = 0;

		virtual ~ITreeConnector() { };
	};
}
#pragma once
