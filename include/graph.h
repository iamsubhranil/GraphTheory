#pragma once

#include <vector>
#include <string>
#include <cstdint>

#include "vertex.h"
#include "edge.h"

class Graph{
    public:
        static Graph* fromIncidenceMatrix(vector<vector<bool>> matrix, bool isDirected);
        static Graph* fromAdjacencyMatrix(vector<vector<bool>> matrix, uint64_t numVertices, bool isDirected);
        vector<Vertex*> vertices();
        vector<Edge*> edges();

    private:
        vector<Vertex*> vs;
        vector<Edge*> es;
        bool isd;
        friend std::ostream& operator<<(std::ostream&, const Graph&);
};
