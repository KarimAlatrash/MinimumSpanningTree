//
// Created by Karim Alatrash on 2021-04-02.
//

#ifndef P3_VERTEX_H
#define P3_VERTEX_H


class Vertex {
private:
    double key_;
    const unsigned int index; //stores the index of the current vertex in the adjacency matrix so it can be accessed
    Vertex* parent =nullptr;

public:
    Vertex(unsigned int key);
    void setKey(double weight);

};


#endif //P3_VERTEX_H
