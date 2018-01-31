#include <iostream>
#include "graph.h"

using namespace std;

Graph* Graph::fromIncidenceMatrix(vector<vector<bool>> matrix, bool isDirected){
    vector<vector<bool>>::iterator it = matrix.begin();
    uint64_t numEdges = (*it).size();
    it++;
    while(it != matrix.end()){
        if((*it).size() != numEdges){
#ifdef DEBUG
            cout << "<" << __func__ << ":" << __LINE__ << "> matrix_col.size() != numEdges";
#endif
            return NULL;
        }
        it++;
    }
    
    uint64_t i = 0, j = 0;
    Graph* g = new Graph();
    g->isd = isDirected;
    g->vs.resize(matrix.size());
    for(it = matrix.begin();it != matrix.end();it++){
        vector<bool>::iterator colit = it->begin();
        g->vs[i] = new Vertex("");;
        j = 0;
        while(colit != it->end()){
            if(j >= (g->es).size()){
                g->es.resize(j+1);
                g->es[j] = new Edge(); 
            }
            if((*colit)){
                Edge *e = g->es[j];
                if(e->sourceVertex() == NULL)
                    e->setSource(g->vs[i]);
                else
                    e->setDest(g->vs[i]);
            }
            colit++;
            j++;
        }
        i++;
    }
    return g;
}

Graph* Graph::fromAdjacencyMatrix(vector<vector<bool>> matrix, uint64_t numVertices, bool isDirected){}

vector<Vertex*> Graph::vertices(){
    return vs;
}

vector<Edge*> Graph::edges(){
    return es;
}

std::ostream& operator<<(std::ostream &strm, const Graph &g) {
    if(g.vs.size() == 0)
        return strm << "Null Graph!";
    strm << "G = { V = {";
    auto vit = g.vs.begin();
    strm << *(*vit);
    vit++;
    while(vit != g.vs.end()){
        strm << ", " << *(*vit);
        vit++;
    }
    strm << "}, E = {";
    auto eit = g.es.begin();
    strm << *(*eit);
    eit++;
    while(eit != g.es.end()){
        strm << ", " << *(*eit);
        eit++;
    }
    return strm << "} }";
}

int main(){
    vector<vector<bool>> mat = {{ false, false, false, true, false, true, false, false},
                                { false, false, false, false, true, true, true, true},
                                { false, false, false, false, false, false, false, true},
                                { true, true, true, false, true, false, false, false},
                                { false, false, true, true, false, false, true, false},
                                { true, true, false, false, false, false, false, false}};
    Graph *g = Graph::fromIncidenceMatrix(mat, false);
    cout << *g;
    return 0;
}
