#pragma once

#include <cstdint>
#include <string>

using namespace std;

class Vertex;

class Edge{
    public:
        Edge(Vertex* source, Vertex* dest);
        Edge(Vertex* source, Vertex* dest, string n);
        Edge(Vertex* source, Vertex* dest, bool isDirected);
        Edge(Vertex* source, Vertex* dest, uint64_t weight);
        Edge(Vertex* source, Vertex* dest, string n, bool isDirected);
        Edge(Vertex* source, Vertex* dest, string n, uint64_t weight);;
        Edge(Vertex* source, Vertex* dest, string n, bool isDirected, uint64_t weight);

        void setWeight(uint64_t w);

        string name();
        Vertex* sourceVertex();
        Vertex* destVertex();
        bool isDirected();
        uint64_t weight();

        bool operator==(const Edge& e);

    private:
        string nam;
        static uint64_t eid;
        Vertex* source;
        Vertex* dest;
        uint64_t wt;
        bool isDirectd;

};
