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

bool VertexSet::insert_edge(unsigned int name1, unsigned int name2, double weight) {
    double old_weight = edge_weight(name1, name2);

    if(weight != 0.0 && old_weight == 0.0) {
        element[name1].add_adjacent_vertex(&element[name2]);
        element[name2].add_adjacent_vertex(&element[name1]);
        element[name1].degree++;
        element[name2].degree++;
        adjacency_matrix[name1 * size_ + name2] = weight;
        adjacency_matrix[name2 * size_ + name1] = weight;
        return true;
    }
    else if(weight==0.0) {
        element[name1].remove_adjacent_vertex(name2);
        element[name2].remove_adjacent_vertex(name1);
        element[name1].degree--;
        element[name2].degree--;
        adjacency_matrix[name1 * size_ + name2] = weight;
        adjacency_matrix[name2 * size_ + name1] = weight;
        return true;
    }
    else if(old_weight != 0.0) {
        adjacency_matrix[name1 * size_ + name2] = weight;
        adjacency_matrix[name2 * size_ + name1] = weight;
    }
    return false;

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
    //creates an array of vertices
    for(int i{0}; i<size_; i++) {
        element[i].set_degree(0);
        element[i].clear_adjacency();
    }

}

Vertex *VertexSet::get_element(unsigned int name) {
    if(name >element.size()-1) {
        return nullptr;
    }
    return &element[name];
}

