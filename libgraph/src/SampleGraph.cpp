#include <cstddef>

#include <libgraph/IVertex.h>
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

IVertex *const SampleGraph::createVertex(IVertex *v){
	return NULL;
}

void SampleGraph::deleteVertex(IVertex *v){

}

IConnector *const SampleGraph::getConnector(){
	return NULL;
}
