//
// Created by Karim Alatrash on 2021-04-02.
//

#ifndef P3_GRAPH_H
#define P3_GRAPH_H


#include "VertexSet.h"

class Graph {
private:
    VertexSet* V= nullptr;
    const unsigned int size_;
    unsigned int edge_count{0};
public:
    Graph(unsigned size);
    ~Graph();
    void insert_edge(unsigned int key1, unsigned int key2, double weight);
    void delete_edge(unsigned int key1, unsigned int key2);
    bool is_adjacent(unsigned int key1, unsigned int key2, double weight);
    unsigned int degree(unsigned int key);
    void print_edge_count();
    void clear_edges();
    double mst_weight(unsigned int source_key);

};


#endif //P3_GRAPH_H
