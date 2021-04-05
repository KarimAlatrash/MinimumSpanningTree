//
// Created by Karim Alatrash on 2021-04-02.
//

#ifndef P3_PRIORITYQUEUE_H
#define P3_PRIORITYQUEUE_H
#include <vector>
#include "Vertex.h"
using namespace std;

class PriorityQueue {
private:
    unsigned int pq_size;
    Vertex **pq;

public:
    PriorityQueue(unsigned int size, Vertex **element_array);
    Vertex* extract_min();
    void insert(Vertex );
    bool is_empty();
    void rebuild_heap();
    unsigned int current_size () {
        return pq_size;
    }
    Vertex * find_vertex(unsigned int name);
    bool is_member(unsigned int name);
    void modify_key(unsigned int name, double weight);

    void heapify(unsigned int index);
};


#endif //P3_PRIORITYQUEUE_H
