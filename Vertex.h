//
// Created by Karim Alatrash on 2021-04-02.
//

#ifndef P3_VERTEX_H
#define P3_VERTEX_H
#include <vector>
using namespace std;

class Vertex {
private:
    double key_=0.0;
    unsigned int name; //stores the name of the current vertex in the adjacency matrix so it can be accessed
    Vertex* parent =nullptr;
    bool member_of_pq;
    vector<Vertex*> adjacency_list;

public:
    unsigned int degree = 0;

    Vertex(unsigned int key);
    ~Vertex();
    void set_key(double weight);
    double get_key();
    unsigned int get_name();
    void add_adjacent_vertex(Vertex* new_adjacency);
    void remove_adjacent_vertex(unsigned int name);
    Vertex* get_adjacent_vertex(unsigned int index);
    void clear_adjacency(){
        adjacency_list.clear();
    }

    void set_member_of_pq(bool status) {
        member_of_pq = status;
    }
    bool is_pq_member() {
        return member_of_pq;
    }
    void set_name(unsigned int name_) {
        name = name_;
    }
    void set_degree(unsigned int degree_) {
        degree = degree_;
    }
    unsigned int get_degree();
    void set_parent(Vertex* new_parent);
    Vertex* get_parent();
    Vertex &operator= (const Vertex &rhs_vertex);

    Vertex();
};


#endif //P3_VERTEX_H
