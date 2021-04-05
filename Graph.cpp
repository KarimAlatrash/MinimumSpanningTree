//
// Created by Karim Alatrash on 2021-04-02.
//

#include "Graph.h"
#include "PriorityQueue.h"
#include "illegal_exception.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Graph::Graph(unsigned int size) : size_(size) {
    V = new VertexSet(size);
    cout<< "success" <<endl;
}

Graph::~Graph() {
    delete V;
}

void Graph::insert_edge(unsigned int key1, unsigned int key2, double weight) {

    try {
        if( (0 > key1 || size_-1< key1) || (0 > key2 || size_-1< key2) || weight <= 0.0 || key1 == key2)
            throw illegal_exception();

        bool new_edge = V->insert_edge(key1, key2, weight);
        if(new_edge)
            edge_count+=2;
        cout<<"success"<<endl;

    }
    catch (illegal_exception& e){
        cout<<e.msg()<<endl;
    }
}

void Graph::delete_edge(unsigned int key1, unsigned int key2) {
    try {
        if( (0 > key1 || size_-1< key1) || (0 > key2 || size_-1< key2) || key1 == key2)
            throw illegal_exception();

        if(V->edge_weight(key1, key2) != 0) {
            V->insert_edge(key1, key2, 0);
            cout<<"success"<<endl;
            edge_count-=2;
        }
        else {
            cout<<"failure"<<endl;
        }

    }
    catch (illegal_exception& e){
        cout<<e.msg()<<endl;
    }
}

bool Graph::is_adjacent(unsigned int key1, unsigned int key2, double weight) {
    try {
        if( (0 > key1 || size_-1< key1) || (0 > key2 || size_-1< key2) || weight <= 0.0 || key1 == key2)
            throw illegal_exception();

        if(abs(V->edge_weight(key1, key2) - weight) < 0.01) {
            cout << "adjacent " << fixed << setprecision(2) << key1 << " "<< key2 << " "<< weight << endl;
            return true;
        }
        cout << "not adjacent " << fixed << setprecision(2) << key1 << " "<< key2 << " "<< weight << endl;
        return false;
    }
    catch (illegal_exception& e){
        cout<<e.msg()<<endl;
    }
    return false;

}

unsigned int Graph::degree(unsigned int key) {
    try {
        if(0 > key || size_-1< key)
            throw illegal_exception();
        unsigned int key_degree = V->degree(key);
        cout << "degree of " << key << " is " << key_degree <<endl;
        return key_degree;
    }
    catch (illegal_exception& e){
        cout<<e.msg()<<endl;
    }
    return 0;
}

void Graph::print_edge_count() {
    cout<<"edge count is "<<edge_count <<endl;
}

void Graph::clear_edges() {
    V->clear_edges();
    edge_count = 0;
    cout<<"success"<<endl;
}

double Graph::mst_weight(unsigned int source_key) {
    try {
        if(0 > source_key || size_-1< source_key)
            throw illegal_exception();
    }
    catch (illegal_exception& e) {
        cout << e.msg() << endl;
        return 0;
    }

    double total_weight=0;
    //create a new array to be passed by reference to the priority queue
    Vertex** mst_tree = new Vertex*[size_];

    for(int i{0}; i<size_; i++) {
        //sets members of array to point to elements in the vertex set
        mst_tree[i] = V->get_element(i);
        mst_tree[i]->set_key(numeric_limits<double>::infinity() );
        mst_tree[i]->set_parent(nullptr);
        mst_tree[i]->set_member_of_pq(true);
    }

    mst_tree[source_key]->set_key(0.0);
    PriorityQueue mst_pq{size_, mst_tree};
    while(!mst_pq.is_empty()) {
        //extracts a pointer which will be the new last element in mst_tree
        Vertex* current_min = mst_pq.extract_min();
        total_weight += current_min->get_key();

        //only loops through current elements of the pq, we would have to do this check anyways
        for(int i{0}; i<current_min->degree; i++) {
            unsigned int edge_weight = V->edge_weight(current_min->get_name(), current_min->get_adjacent_vertex(i)->get_name());
            //this should work because we are directly manipulating the array stored here
            if(edge_weight > 0.0 &&
                edge_weight < current_min->get_adjacent_vertex(i)->get_key() &&
                    current_min->get_adjacent_vertex(i)->is_pq_member()) {

                V->get_element(current_min->get_adjacent_vertex(i)->get_name())->set_key(edge_weight);//mst_tree[i].set_key(edge_weight);
                V->get_element(current_min->get_adjacent_vertex(i)->get_name())->set_parent(current_min);//mst_tree[i].set_parent(current_min);
                mst_pq.rebuild_heap(); //rebuilds min heap
            }
        }


    }
    if(total_weight != std::numeric_limits<double>::infinity() ) {
        cout<<"mst "<<  std::fixed << std::setprecision(2) << total_weight <<endl;
    }
    else {
        cout << "not connected" <<endl;
    }

    delete[] mst_tree;
    return total_weight;
}
