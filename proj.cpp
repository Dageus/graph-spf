//include the header files
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
Edge *aux;
int result = 0;

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
    scanf("%d", &V);
    scanf("%d", &E);
    g.vertices = new Set*[V];
    g.edges = new Edge[E];
    aux = new Edge[E];
    alloc_vertices();

    for(int i = 0; i < E; i++){
        int v1, v2, w;
        scanf("%d", &v1);
        scanf("%d", &v2);
        scanf("%d", &w);
        g.edges[i].u = g.vertices[v1 - 1];
        g.edges[i].v = g.vertices[v2 - 1];
        g.edges[i].weight = w;
        }
}

// sort edges by weight
void merge_arrays(Edge *edges, int left, int m, int right){
    int i, j;
    for (i = m + 1; i > left; i--){
        aux[i - 1] = edges[i - 1];
    }
    for (j = m; j < right; j++){
        aux[right + m - j] = edges[j + 1];
    }
    for (int k = left; k <= right; k++)
        if (aux[j].weight > aux[i].weight || i == m + 1)
            edges[k] = aux[j--];
        else
            edges[k] = aux[i++];
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
Set* kruskal_find_set(Set* x){
    if (x != x->parent)
        x->parent = kruskal_find_set(x->parent);
    return (x->parent);
}

// link
Set* kruskal_link(Set* u, Set* v){
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
Set* kruskal_unite(int index){
    return kruskal_link(kruskal_find_set(g.edges[index].u), kruskal_find_set(g.edges[index].v));
}

// Kruskal algorithm
void kruskal(){
    sort_edges(g.edges, 0, E - 1);
    for (int i = 0; i < E; i++){
        if (kruskal_find_set(g.edges[i].u) != kruskal_find_set(g.edges[i].v)){ // compare sets
            result += g.edges[i].weight; // add edge to result
            kruskal_unite(i);
        }
    }
}


// main function
int main() {
    
    readInput();

    kruskal();

    cout << result << endl;

    return 0;
}