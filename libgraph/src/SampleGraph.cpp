#include <cstddef>

#include <libgraph/IVertexData.h>
#include <libgraph/IEdge.h>
#include <libgraph/IConnector.h>
#include <libgraph/IGraph.h>
#include <libgraph/SampleGraph.h>
using namespace libgraph;

SampleGraph::SampleGraph(){

}

SampleGraph::~SampleGraph(){

}

int SampleGraph::getVertexCount(){
	return 0;
}

vertex_id_t SampleGraph::createVertex(IVertexData *v){
	return 0;
}

bool SampleGraph::deleteVertex(vertex_id_t v){

}

IConnector *const SampleGraph::getConnector(){
	return NULL;
}
