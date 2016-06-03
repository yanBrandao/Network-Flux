//
//  graph.cpp
//  Fluxo-de-Redes
//
//  Created by Yan Brandão Diniz on 5/31/16.
//  Copyright © 2016 UFAM. All rights reserved.
//

#include "graph.hpp"

void Graph::init(){
    vector<node> newNodes = *new vector<node>();
    nodes = newNodes;
}

void Graph::add(int v, int weight, int adj){
    int verify = 0;
    //Verification if this vertex is already added.
    for (auto it = begin(this->nodes); it != end(this->nodes); it++) {
        if (v == it->value) {
            node* nodeAdj = new node();
            nodeAdj->value = adj;
            nodeAdj->weight = weight;
            (*it).neighbors.push_back(nodeAdj);
            verify = 1;
        }
    }
    if (verify != 1) {
        node* nodeN = new node();
        node* nodeAdj = new node();
        nodeAdj->value = adj;
        nodeAdj->weight = weight;
        nodeN->value = v;
        nodeN->weight = -1; //Root node.
        nodeN->neighbors = *new vector<node*>();
        nodeN->neighbors.push_back(nodeAdj);
        
        nodes.push_back(*nodeN);
    }
    
}

void Graph::show(){
    vector<node>::iterator it;
    vector<node*> neihbors;
    vector<node*>::iterator jt;
    for (it = this->nodes.begin(); it != end(nodes); it++) {
        cout <<  it->value << ' ';
        neihbors = it->neighbors;
        for (jt = neihbors.begin(); jt != end(neihbors); jt++) {
            cout << "{ [" << (*jt)->value << ", " << (*jt)->weight << "] } ";
        }
    }
    cout << endl;
    
}