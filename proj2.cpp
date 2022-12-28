//include the header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// declare structs
typedef struct Set{
    int vertice; 
    int rank;
    struct Set *parent;
} Set;

typedef struct Edge{
    Set* u;
    Set* v;
    int weight;
} Edge;

typedef struct Graph{
    Set* *vertices;
    Edge *edges;
} Graph;


// declare global variables
int V, E;
Graph g;
Edge *sortedEdges;
Edge* aux;
vector<Edge> result;
int counter = 0;

//declare functions
void readInput();
void alloc_vertices();
void sort_edges(Edge *edges, int left, int right);
void merge_arrays(Edge *edges, int left, int m, int right);
Set* find_set(Set* x);
Set* link(Set* u, Set* v);
Set* unite(Set* u, Set* v);
void print_edges(Edge *edges);
void kruskal();
int sumWeights(vector<Edge> result);

// make set
Set* make_set(int x){
    Set* s = new Set();
    s->vertice = x;
    s->rank = 0;
    s->parent = s;
    return s;
}

void alloc_vertices(){
    for (int i = 0; i < V; i++)
        g.vertices[i] = make_set(i + 1);
}

// declare functions
void readInput(){
    cin >> V;
    cin >> E;
    g.vertices = new Set*[V];
    g.edges = new Edge[E];
    aux = new Edge[E];
    alloc_vertices();
    result = vector<Edge>(V - 1);

    for(int i = 0; i < E; i++){
        int v1, v2, w;
        cin >> v1;
        cin >> v2;
        cin >> w;
        g.edges[i].u = g.vertices[v1 - 1];
        g.edges[i].v = g.vertices[v2 - 1];
        g.edges[i].weight = w;
        cout << "arco (" << g.edges[i].u->vertice << ", " << g.edges[i].v->vertice << ") com peso " << w << endl;
    }
}

// sort edges by weight
void merge_arrays(Edge *edges, int left, int m, int right){
    cout << "merge" << endl;
    int i, j;
    for (i = m + 1; i > left; i--)
        aux[i - 1] = edges[i - 1];
    for (j = m; j < right; j++)
        aux[right + m - j] = edges[j + 1];
    for (int k = left; k <= right; k++)
        if (aux[j].weight < aux[i].weight || i == m + 1)
            edges[k] = aux[j--];
        else
            edges[k] = aux[i--];
}

void sort_edges(Edge *edges, int left, int right){
    int m = (left + right)/2;
    if (right <= left)
        return;
    sort_edges(edges, left, m);
    sort_edges(edges, m + 1, right);
    merge_arrays(edges, left, m, right);
}

// find representative
Set* find_set(Set* x){
    if (x != x->parent)
        x->parent = find_set(x->parent);
    return (x->parent);
}

// link
Set* link(Set* u, Set* v){
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
Set* unite(Set* u, Set* v){
    return link(find_set(u), find_set(v));
}

void print_edges(Edge *edges){
    for (int i = 0; i < E; i++){
        cout << "arco (" << edges[i].u->vertice << ", " << edges[i].v->vertice << ") com peso " << edges[i].weight << endl;
    }
}

// Kruskal algorithm
void kruskal(){
    cout << "kruskal" << endl;
    sortedEdges = new Edge[E];
    sortedEdges = g.edges;
    print_edges(sortedEdges);
    sort_edges(sortedEdges, 0, E);
    print_edges(sortedEdges);
    for (int i = 0; i < E; i++){
        Edge e = sortedEdges[i];
        cout << "arco (" << e.u->vertice << ", " << e.v->vertice << ") com peso " << e.weight << endl;
        if (find_set(e.u) != find_set(e.v)){ // compare sets
            cout << "representante de u: " << find_set(e.u)->vertice << endl;
            cout << "representante de v: " << find_set(e.v)->vertice << endl;
            result[counter] = e; // add edge to result
            cout << result[counter].weight << endl;
            counter++;
            unite(e.u, e.v);
        }
    }
}

// sum weights
int sumWeights(vector<Edge> result){
    int sum = 0;
    for (int i = 0; i < V - 1; i++){
        sum += result[i].weight;
        cout << result[i].weight << endl;
    }
    cout << "soma: ";
    return sum;
}


// main function
int main() {
    
    readInput();

    kruskal();

    cout << sumWeights(result) <<endl;

    return 0;
}