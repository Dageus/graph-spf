//include the header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// struct for the graph
struct Graph{
    int V, E;
    vector<int> adj;
};

// struct for the weight
struct Weight{
    int vertice;
    int weight;
};

// declare macros


// declare global variables
int V, E;
// find graph representation
// -> use list of adjacencies <-
vector<int> adj;


// declare functions
void readInput(){
    cin >> V;
    cin >> E;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        cout << "arco (" << u << ", " << v << ") com peso " << w << endl;
    }
}


// main function
int main() {
    readInput();

    return 0;
}
