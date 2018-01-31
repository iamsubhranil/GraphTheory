#pragma once

#include <vector>
#include <cstdint>

using namespace std;

#define DISTANCE_INF 1234567 // if we choose UINT_MAX, we can't perform dijsktra as it is, as adding something
                            // will make it zero

vector<vector<bool>> inputIncidenceMatrix(uint64_t numVertices, uint64_t numEdges);
vector<vector<bool>> inputAdjacencyMatrix(uint64_t numVertices);
vector<vector<uint64_t>> inputLengthMatrix(uint64_t numVertices);
