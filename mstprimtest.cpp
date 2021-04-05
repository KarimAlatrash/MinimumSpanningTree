#include <iostream>
#include "Graph.h"
using namespace std;
int main() {
    string line;
    Graph* grph = nullptr;

    while(true ) {
        if(cin.eof() )
            break;
        getline(cin, line);

        if(line == "exit")
            break;

        size_t pos=line.find(" ");
        string cmd = line.substr(0,pos);
        string obj = line.substr(pos+1, line.length()-1 );
        if(cmd == "n" && grph == nullptr) {
            grph = new Graph(stoi(obj));
            //cout<<"success"<<endl;
        }
        if(cmd == "i"){
            unsigned int u = stoi(obj.substr(0, obj.find(";")));
            unsigned int v = stoi(obj.substr(obj.find(";") + 1, obj.find(";", obj.find(";") + 1) - obj.find(";") - 1));
            double w = stod(obj.substr(obj.find(";", obj.find(";") + 1) + 1));

            grph->insert_edge(u, v, w);
        }
        if(cmd == "e"){
            unsigned int u = stoi(obj.substr(0, obj.find(";")));
            unsigned int v = stoi(obj.substr(obj.find(";") + 1, obj.find(";", obj.find(";") + 1) - obj.find(";") - 1));

            grph->delete_edge(u, v);
        }
        if(cmd == "adjacent"){
            unsigned int u = stoi(obj.substr(0, obj.find(";")));
            unsigned int v = stoi(obj.substr(obj.find(";") + 1, obj.find(";", obj.find(";") + 1) - obj.find(";") - 1));
            double w = stod(obj.substr(obj.find(";", obj.find(";") + 1) + 1));

            grph->is_adjacent(u, v, w);
        }
        if(cmd == "degree"){
            unsigned int u = stoi(obj.substr(0, obj.find(";")));
            grph->degree(u);
        }
        if(cmd == "edge_count"){
            grph->print_edge_count();
        }
        if(cmd == "clear"){
            grph->clear_edges();
        }
        if(cmd == "mst"){
            unsigned int u = stoi(obj.substr(0, obj.find(";")));
            grph->mst_weight(u);
        }

    }

    delete grph;

    return 0;
}
