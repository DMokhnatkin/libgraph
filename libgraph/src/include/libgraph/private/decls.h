#pragma once

namespace libgraph{

	template <typename T>
	class FreeIdCollection;
	template <typename T>
	class IDataStorage;
	template <typename T>
	class IGraph;

	class IEdge;
	
	// Connect Storages
	class IConnectStorage;
	class AdjacencyMatrixConnectStorage;

	// ConnectManagers
	class IConnectManager;
	class ConnectManager;
}
