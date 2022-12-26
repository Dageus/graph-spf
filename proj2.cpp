//include the header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

// declare structs
typedef struct Edge{
    Set u;
    Set v;
    int weight;
} *Edge;

typedef struct Graph{
    Set *vertices;
    Edge *edges;
} *Graph;

typedef struct Set{
    int vertice; 
    int rank;
    struct Set *parent;
} *Set;

// declare global variables
int V, E;
Graph g;
Edge *sortedEdges;
Edge *result;

void alloc_vertices(){
    for (int i = 0; i < V; i++)
        g->vertices[i] = make_set(i + 1);
}

// declare functions
void readInput(){
    cin >> V;
    cin >> E;
    g->vertices = (Set *) malloc(V * sizeof(Set));
    g->edges = (Edge *) malloc(E * sizeof(Edge));
    alloc_vertices();
    result[V - 1];

    for(int i = 0; i < E; i++){
        int v1, v2, w;
        cin >> v1;
        cin >> v2;
        cin >> w;
        g->edges[i]->u = g->vertices[v1 - 1];
        g->edges[i]->v = g->vertices[v2 - 1];
        g->edges[i]->weight = w;
        cout << "arco (" << v1 << ", " << v2 << ") com peso " << w << endl;
    }
}

void sort_edges(Edge *edges, int left, int right, Edge *aux){
    int m = (left + right)/2;
    if (right <= left)
        return;
    sort_edges(edges, left, m, aux);
    sort_edges(edges, m + 1, right, aux);
    merge(edges, left, m, right, aux);
}

// sort edges by weight
void merge(Edge *edges, int left, int m, int right, Edge *aux){
    int i, j;
    for (i = m + 1; i > left; i--)
        aux[i - 1] == edges[i - 1];
    for (j = m; j < right; j++)
        aux[right + m - j] = edges[j + 1];
    for (int k = left; k <= right; k++)
        if (aux[j]->weight < aux[i]->weight || i == m + 1)
            edges[k] = aux[j--];
        else
            edges[k] = aux[i--];
}

bool compare_edges(Edge edge1, Edge edge2){
    // make function
    return NULL;
}

// find representative
Set find_set(Set x){
    if (x->vertice != x->parent->vertice)
        x->parent = find_set(x->parent);
    return x->parent;
}

// make set
Set make_set(int x){
    Set s = (Set) malloc(sizeof(Set));
    s->vertice = x;
    s->rank = 0;
    s->parent = s;
    return s;
}

// link
Set link(Set u, Set v){
    if (u->rank > v->rank){
        v->parent = u;
        return v;
    } else{
        u->parent = v;
        if (u->rank == v->rank)
            v->rank++;
        return u;
    }
}   

// union
Set unite(Set u, Set v){
    return link(find_set(u), find_set(v));
}

// Kruskal algorithm
void kruskal(){
    sortedEdges = (Edge *) malloc(E * sizeof(Edge));
    sortedEdges = g->edges;
    Edge aux[E];
    sort_edges(sortedEdges, 0, E, aux);
    for (int i = 0; i < E; i++){
        Edge e = sortedEdges[i];
        if (find_set(e->u) != find_set(e->v)){
            // unite(e.u, e.v)
        }
    }
}

// sum weights
int sumWeights(Edge *result){
    int sum = 0;
    for (int i = 0; i < V - 1; i++)
        sum += result[i]->weight;
    return sum;
}


// main function
int main() {
    
    readInput();

    kruskal();

    cout << "result: " << sumWeights(result) <<endl;

    return 0;
}