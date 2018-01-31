#include <iostream>

#include <gio.h>
#include <graph.h>

static void dijkstra(vector<vector<uint64_t>> lengthMatrix, uint64_t vsource, uint64_t vdest){
    vector<bool> status;
    vector<uint64_t> dist;
    vector<uint64_t> prev;

    uint64_t numVertices = lengthMatrix.size();

#ifdef DEBUG
    cout << "\nLength matrix : \n";
    for(auto i : lengthMatrix){
        for(auto j : i){
            if(j == DISTANCE_INF)
                cout << "inf ";
            else
                cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
#endif

    status.resize(numVertices);
    dist.resize(numVertices);
    prev.resize(numVertices);
    
    for(uint64_t i = 0;i < numVertices;i++){
        if(i != vsource){
            status[i] = false;
            dist[i] = lengthMatrix[vsource][i];
            prev[i] = vsource;
        }
    }

    status[vsource] = true;
    dist[vsource] = 0;
    prev[vsource] = 0;

#ifdef DEBUG
        cout << "\nStatus   : ";
        for(auto it = status.begin();it != status.end();it++)
            cout << (*it) << " ";
        cout << "\nDistance : ";
        for(auto it = dist.begin();it != dist.end();it++)
            if((*it) == DISTANCE_INF)
                cout << "inf ";
            else
                cout << (*it) << " ";
        cout << "\nPrevious : ";
        for(uint64_t i = 0;i < prev.size();i++)
            if(i == vsource)
                cout << "* ";
            else
                cout << prev[i] << " ";
        cout << "\n\n";
#endif

    while(!status[vdest]){
        uint64_t vstar, tempdis;
        bool init = false;
        for(uint64_t i = 0;i < numVertices;i++){
            if(status[i] == false){
                if(!init || dist[i] < tempdis){
                    vstar = i;
                    tempdis = dist[i];
                    init = true;
                }
            }
        }

#ifdef DEBUG
        cout << "\n<" << __func__ << ":" << __LINE__ << "> vstar = " << vstar << "\n";
#endif

        status[vstar] = true;
        for(uint64_t i = 0;i < numVertices;i++){
            if(status[i] == false && dist[i] > dist[vstar] + lengthMatrix[vstar][i]){
                    dist[i] = dist[vstar] + lengthMatrix[vstar][i];
                    prev[i] = vstar;
                }
        }

#ifdef DEBUG
        cout << "\nStatus   : ";
        for(auto it = status.begin();it != status.end();it++)
            cout << (*it) << " ";
        cout << "\nDistance : ";
        for(auto it = dist.begin();it != dist.end();it++)
            if((*it) == DISTANCE_INF)
                cout << "inf ";
            else
                cout << (*it) << " ";
        cout << "\nPrevious : ";
        for(uint64_t i = 0;i < prev.size();i++)
            if(i == vsource)
                cout << "* ";
            else
                cout << prev[i] << " ";
        cout << "\n\n";
#endif
    }

    cout << "\nMinimum distance : " << dist[vdest];
}

int test(){
    vector<vector<uint64_t>> t = {{0, 1, 3, 10, DISTANCE_INF},
                                    {1, 0, DISTANCE_INF, 12, DISTANCE_INF},
                                    {3, DISTANCE_INF, 0, 5, 15},
                                    {10, 12, 5, 0, 7},
                                    {DISTANCE_INF, DISTANCE_INF, 15, 7, 0}};
    dijkstra(t, 1, 4);
    return 0;
}

int main(){
    uint64_t length;
    cout << "\nEnter number of vertices : ";
    cin >> length;
    cout << "\nEnter the length matrix : ";
    vector<vector<uint64_t>> lengthMatrix = inputLengthMatrix(length);
    uint64_t vsource, vdest;
sdv:
    cout << "\nEnter source and destination vertices : ";
    cin >> vsource >> vdest;
    if(vsource >= length || vdest >= length){
        cout << "\n[Error] Invalid source or destination vertex!";
        goto sdv;
    }
    dijkstra(lengthMatrix, vsource, vdest);
    cout << "\n";
    return 0;
}
