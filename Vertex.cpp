//
// Created by Karim Alatrash on 2021-04-02.
//

#include "Vertex.h"
#include <limits>
using namespace std;

Vertex::Vertex(unsigned int key) : name(key) {
    key_ = key;
}

void Vertex::set_key(double weight) {
    key_ = weight;
}

double Vertex::get_key() {
    return key_;
}

Vertex &Vertex::operator=(const Vertex &rhs_vertex) {
    key_ = rhs_vertex.key_;
    name = rhs_vertex.name;
    parent = rhs_vertex.parent;
    degree = rhs_vertex.degree;

    return *this;
}

unsigned int Vertex::get_name() {
    return name;
}

Vertex::Vertex() {

}

unsigned int Vertex::get_degree() {
    return degree;
}

void Vertex::set_parent(Vertex *new_parent) {
    parent = new_parent;
}

Vertex *Vertex::get_parent() {
    return parent;
}
void Vertex::add_adjacent_vertex(Vertex *new_adjacency) {
    adjacency_list.push_back(new_adjacency);
}
void Vertex::remove_adjacent_vertex(unsigned int name) {
    for(int i {0}; i<adjacency_list.size(); i++) {
        if(adjacency_list[i]->name == name) {
            adjacency_list.erase(adjacency_list.begin()+i);
            return;
        }
    }
}

Vertex *Vertex::get_adjacent_vertex(unsigned int index) {
    return adjacency_list[index];
}

