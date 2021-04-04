//
// Created by Karim Alatrash on 2021-04-02.
//

#include "VertexSet.h"
#include "illegal_exception.h"
#include <iostream>

using namespace std;
VertexSet::VertexSet(unsigned int size) {
    size_ = size;
    adjacency_matrix = new double[size*size]{0}; //0 represents no connection between the two vertices, some number represents a weight
    //creates an array of vertices
    for(int i{0}; i<size; i++) {
        element.push_back( Vertex(i) );
    }
}
VertexSet::~VertexSet() {
    delete[] adjacency_matrix;
}

void VertexSet::insert_edge(unsigned int key1, unsigned int key2, double weight) {
    adjacency_matrix[key1*size_ + key2] = weight;
    adjacency_matrix[key2*size_ + key1] = weight;
    if(weight != 0.0) {
        element[key1].degree++;
        element[key2].degree++;
    }
    else {
        element[key1].degree--;
        element[key2].degree--;
    }

}

double VertexSet::edge_weight(unsigned int key1, unsigned int key2) {
    return adjacency_matrix[key1*size_ + key2];
}

unsigned int VertexSet::degree(unsigned int key) {
    return element[key].degree;
}

void VertexSet::clear_edges() {
    delete[] adjacency_matrix;
    adjacency_matrix = new double[size_*size_]{0};
}

