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
    Vertex* pq;

    void heapify(unsigned int index);

public:
    PriorityQueue(unsigned int size, Vertex* element_array);
    Vertex extract_min();
    void insert(Vertex );
    bool is_empty();
    Vertex * find_vertex(unsigned int name);
    bool is_member(unsigned int name);
};


#endif //P3_PRIORITYQUEUE_H
