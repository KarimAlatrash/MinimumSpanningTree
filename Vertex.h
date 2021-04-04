//
// Created by Karim Alatrash on 2021-04-02.
//

#ifndef P3_VERTEX_H
#define P3_VERTEX_H


class Vertex {
private:
    double key_=0;
    unsigned int name; //stores the name of the current vertex in the adjacency matrix so it can be accessed
    Vertex* parent =nullptr;

public:
    unsigned int degree = 0;

    Vertex(unsigned int key);
    void set_key(double weight);
    double get_key();
    unsigned int get_name();
    Vertex &operator= (const Vertex &rhs_vertex);
};


#endif //P3_VERTEX_H
