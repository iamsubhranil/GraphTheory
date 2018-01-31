#include <edge.h>
#include <vertex.h>

Edge::Edge() : Edge(NULL, NULL) {}
Edge::Edge(Vertex* s, Vertex* d) : Edge(s, d, "", false, UINT64_MAX){}
Edge::Edge(Vertex* s, Vertex* d, string name) : Edge(s, d, name, false, UINT64_MAX){}
Edge::Edge(Vertex* s, Vertex* d, uint64_t w) : Edge(s, d, "", false, w){}
Edge::Edge(Vertex* s, Vertex* d, bool isDirected) : Edge(s, d, "", isDirected, UINT64_MAX){}
Edge::Edge(Vertex* s, Vertex* d, string name, uint64_t w) : Edge(s, d, name, false, w){}
Edge::Edge(Vertex* s, Vertex* d, string name, bool isDirected) : Edge(s, d, name, isDirected, UINT64_MAX){}

uint64_t Edge::eid = 0;

Edge::Edge(Vertex* s, Vertex* d, string name, bool isDirected, uint64_t weight){
    if(name.empty())
        name = "e" + to_string(eid++);
    nam = name;

    source = s;
    if(source != NULL)
        source->addEdge(this);

    dest = d;
    if(dest != NULL)
        dest->addIncomingEdge(this);

    isDirectd = isDirected;
    wt = weight;
}

Vertex* Edge::destVertex(){
    return Edge::dest;
}

Vertex* Edge::sourceVertex(){
    return Edge::source;
}

void Edge::setWeight(uint64_t w){
    wt = w;
}

uint64_t Edge::weight(){
    return Edge::wt;
}

string Edge::name(){
    return Edge::nam;
}

bool Edge::isDirected(){
    return Edge::isDirectd;
}

bool Edge::operator==(const Edge& e){
    if(!isDirectd && !e.isDirectd){
        if(*source == *e.source && *dest == *e.dest)
            return true;
        if(*dest == *e.source && *source == *e.dest)
            return true;
    }
    else if(isDirectd && e.isDirectd){ 
        if(*source == *e.source && *dest == *e.dest)
            return true;
    }

    return false;
}

void Edge::setSource(Vertex* v){
    source = v;
    v->addEdge(this);
}

void Edge::setDest(Vertex* v){
    dest = v;
    dest->addIncomingEdge(this);
}

std::ostream& operator<<(std::ostream &strm, const Edge& e) {
  return strm << "(" << *e.source << ", " << *e.dest << ")";
}
