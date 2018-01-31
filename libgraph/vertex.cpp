#include <unordered_set>
#include "vertex.h"
#include "edge.h"

uint64_t Vertex::vid = 0;

Vertex::Vertex(string name){
    if(name.empty())
        name = "v"+to_string(vid++);
    nam = name;
    inEdgeSet.clear();
    outEdgeSet.clear();
}

void Vertex::addEdge(Edge* e){
    outEdgeSet.insert(e);
}

void Vertex::addIncomingEdge(Edge* e){
    inEdgeSet.insert(e);
}

string Vertex::name(){
    return nam;
}

unordered_set<Edge*> Vertex::edges(){
    unordered_set<Edge*> ret;
    ret.insert(inEdgeSet.begin(), inEdgeSet.end());
    ret.insert(outEdgeSet.begin(), outEdgeSet.end());
    return ret;
}

unordered_set<Edge*> Vertex::inEdges(){
    return inEdgeSet;
}

unordered_set<Edge*> Vertex::outEdges(){
    return outEdgeSet;
}

unordered_set<Vertex*> Vertex::getNeighbours(){
    unordered_set<Vertex*> ret;
    for(auto init = inEdgeSet.begin(); init != inEdgeSet.end(); ++init){
       ret.insert((*init)->destVertex());
    };
    for(auto init = outEdgeSet.begin(); init != outEdgeSet.end(); ++init){
       ret.insert((*init)->sourceVertex());
    };
    return ret;
}

uint64_t Vertex::inDegree(){
    return inEdgeSet.size();
}

uint64_t Vertex::outDegree(){
    return outEdgeSet.size();
}

// Yet not implemented
bool Vertex::operator==(const Vertex& v1){
    return false;
}

std::ostream& operator<<(std::ostream &strm, const Vertex &v) {
  return strm << v.nam;
}
