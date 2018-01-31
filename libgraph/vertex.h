#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include <cstdint>
#include <tuple>

using namespace std;

class Edge;

class Vertex{
    public:
        Vertex(string name);
        void addEdge(Edge* e); // Equivalent to addOutgoingEdge
        void addIncomingEdge(Edge* e);

        string name();
        unordered_set<Edge*> edges();
        unordered_set<Edge*> inEdges();
        unordered_set<Edge*> outEdges();
        unordered_set<Vertex*> getNeighbours();
        uint64_t degree();
        uint64_t inDegree();
        uint64_t outDegree();

        // Index will be calculated from the first outgoing edge added
        // to the last incoming edge added
        //Edge* getEdge(uint64_t index);
        //uint64_t indexOfEdge(Edge* edge);

        bool operator==(const Vertex& v1);

    private:
        string nam;
        static uint64_t vid;
        unordered_set<Edge*> inEdgeSet;
        unordered_set<Edge*> outEdgeSet;
        friend std::ostream& operator<<(std::ostream&, const Vertex&);
};
