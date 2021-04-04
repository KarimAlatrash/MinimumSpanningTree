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
}

unsigned int Vertex::get_name() {
    return name;
}

