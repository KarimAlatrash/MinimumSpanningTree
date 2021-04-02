//
// Created by Karim Alatrash on 2021-04-02.
//

#include "Vertex.h"
#include <limits>
using namespace std;

Vertex::Vertex(unsigned int key) : index(key) {
    key_ = key;
}

void Vertex::setKey(double weight) {
    key_ = weight;
}
