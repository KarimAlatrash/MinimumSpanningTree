//
// Created by Karim Alatrash on 2021-04-02.
//

#include "Graph.h"
#include "illegal_exception.h"
#include <iostream>
#include <iomanip>

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

        V->insert_edge(key1, key2, weight);
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

        if(V->edge_weight(key1, key2) - weight < 0.01) {
            cout << "adjacent" << fixed << setprecision(2) << key1 << " "<< key2 << " "<< weight << endl;
            return true;
        }
        cout << "not adjacent" << fixed << setprecision(2) << key1 << " "<< key2 << " "<< weight << endl;
        return false;
    }
    catch (illegal_exception& e){
        cout<<e.msg()<<endl;
    }


}
