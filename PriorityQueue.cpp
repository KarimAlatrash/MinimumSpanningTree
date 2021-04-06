//
// Created by Karim Alatrash on 2021-04-02.
//

#include "PriorityQueue.h"
using namespace std;

Vertex* PriorityQueue::extract_min() {
    Vertex* min = pq[0];
    pq[0] = pq[pq_size-1];
    pq[pq_size-1] = min;
    pq_size--;
    min->set_member_of_pq(false);
    if(pq_size != 0)
        heapify(0);
    //build_heap();
    return min;
}

//heapify to create min heap
void PriorityQueue::heapify(unsigned int index) {
    unsigned int left_child = 2*index+1;
    unsigned int right_child = 2*index+2;
    unsigned int smallest_index = index;

    if(left_child < pq_size && pq[left_child]->get_key() < pq[smallest_index]->get_key() && pq[left_child]->is_pq_member()) {
        smallest_index = left_child;
    }

    if(right_child <= pq_size && pq[right_child]->get_key() < pq[smallest_index]->get_key() && pq[right_child]->is_pq_member()) {
        smallest_index = right_child;
    }
    if(smallest_index != index) {
        Vertex* temp = pq[index];
        pq[index] = pq[smallest_index];
        pq[smallest_index] = temp;
        heapify(smallest_index);
    }
    //return;
}



PriorityQueue::PriorityQueue(unsigned int size, Vertex **element_array) {
    pq_size = size;
    pq = element_array;
    build_heap();
}

bool PriorityQueue::is_empty() {
    if(pq_size == 0) {
        return true;
    }
    return false;
}

//change this to be optimized for a PQ
/*
Vertex* PriorityQueue::find_vertex(unsigned int name) {
    for(unsigned int i{0}; i<pq_size; i++) {
        if(name == pq[i]->get_name() )
            return pq[i];
    }
    //in case the vertex could not be found
    return nullptr;
}

bool PriorityQueue::is_member(unsigned int name) {
    if (find_vertex(name) != nullptr ) {
        return true;
    }
    return false;
}

void PriorityQueue::modify_key(unsigned int name, double weight) {

}*/

void PriorityQueue::build_heap() {
    for(unsigned int i{(pq_size)/2}; i>=0 && i<pq_size; --i) {
        heapify(i);
    }
}


