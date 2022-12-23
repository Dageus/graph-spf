//include the header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// declare structs
typedef struct Edge{
    int u;
    int v;
    int weight;
}Edge ;

typedef struct Graph{
    int *vertices;
    Edge *edges;
} Graph;

typedef struct Node{
    int data; // see what data to put
    struct Node *representative;
    struct Node *next;
} *Set;

// declare global variables
int V, E;
Graph g;

// declare functions
void readInput(){
    cin >> V;
    cin >> E;
    g.vertices = (int *) malloc(V * sizeof(int));
    g.edges = (Edge *) malloc(E * sizeof(Edge));

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        g.edges[i].u = u;
        g.edges[i].v = v;
        g.edges[i].weight = w;
        cout << "arco (" << u << ", " << v << ") com peso " << w << endl;
    }
}

// sort edges by weight
Edge *sortEdges(Edge *edges){
    Edge *sortedEdges = (Edge *) malloc(E * sizeof(Edge));
    
    //make function

    return sortedEdges;
}

// find representative
Node *find_representative(Node *x){
    return x->representative;
}

// make-set
Set make_set(int x){
    Set s = (Set ) malloc(sizeof(Set));
    s->data = x;
    s->representative = s;
    s->next = NULL;
    return s;
}

// union
void unite(Set *u, Set *v){


}

// Kruskal algorithm
Set kruskal(){

    Set A = NULL;
    for (int i = 0; i <= V; i++)
        make_set(g.vertices[i]);
    Edge *sortedEdges = (Edge *) malloc(E * sizeof(Edge));
    sortedEdges = sortEdges(g.edges);
    for (int i = 0; i < E; i++){
        Edge e = sortedEdges[i]
        if (find_representative(e.u) != find_representative(e.v)){
            
            // unite(e.u, e.v)
        }
    }

    return A;
}


// main function
int main() {
    
    readInput();

    Set MST = kruskal();

    cout << "MST: " << sumWeights(MST) <<endl;

    return 0;
}