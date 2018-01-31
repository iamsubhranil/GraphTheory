#include <gio.h>
#include <iostream>

static vector<bool> inputVector(uint64_t numVector){
    vector<bool> ret;
    ret.resize(numVector);
    int64_t input;
    bool showWarning = false;
    while(numVector > 0){
        cin >> input;
        if(input < 0 || input > 1)
            showWarning = true;
        ret.push_back(input == 0 ? false  : true);
        numVector--;
    }
    if(showWarning){
        cout << " (Warning : Invalid values read as 'true' by default!) \n";
    }
    cin.ignore(INTMAX_MAX, '\n');    
    return ret;
}

static void showHeader(uint64_t numVertices, char sym){
    uint64_t i = 0;
    cout << "      ";
    while(i < numVertices){
        cout << sym ;
        cout << i++ << " ";
    }
    cout << "\n";
    i = 0;
    cout << "      ";
    while(i < numVertices){
        cout << "__ ";
        i++;
    }
    cout << "\n";
}

vector<vector<bool>> inputIncidenceMatrix(uint64_t numVertices, uint64_t numEdges){
    showHeader(numEdges, 'e');
    uint64_t i = 0;
    vector<vector<bool>> ret;
    while(i < numVertices){
        cout << "\n v" << i++ << " | ";
        ret.push_back(inputVector(numEdges));
    }

    return ret;
}

vector<vector<bool>> inputAdjacencyMatrix(uint64_t numVertices){
    showHeader(numVertices, 'v');
    uint64_t i = 0;
    vector<vector<bool>> ret;
    while(i < numVertices){
        cout << "\n v" << i++ << " | ";
        ret.push_back(inputVector(numVertices));
    }
    return ret;
}

int test_gio(){
    inputIncidenceMatrix(5, 4);
    return 0;
}
