//
// Created by Karim Alatrash on 2021-04-02.
//

#ifndef P3_VERTEXSET_H
#define P3_VERTEXSET_H


#include "Vertex.h"
#include <vector>
using namespace std;

class VertexSet {
private:
    double* adjacency_matrix; //array of size*size to simulate a 2D array where name [i,j] = [i*size+j]
    vector<Vertex> element;
    unsigned int size_;
public:
    VertexSet(unsigned int size);
    ~VertexSet();
    bool insert_edge(unsigned int key1, unsigned int key2, double weight);
    double edge_weight(unsigned int key1, unsigned int key2);
    unsigned int degree(unsigned int key);
    void clear_edges();
    Vertex* get_element(unsigned int name);
};


#endif //P3_VERTEXSET_H
